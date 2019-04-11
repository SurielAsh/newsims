//
// Created by nagi on 19-4-12.
//

#ifndef NEWPTL_PTL_TOOLS_H
#define NEWPTL_PTL_TOOLS_H
#include <vector>
#include <iostream>
#include <cmath>
#include "map_tools.h"
#include "general_tools.h"

using std::vector;

void fw(int Gmax,int gen,double &w)
{
    gen++;
    w=exp(-gen);
}

class ptl
{
private:
    int e1,e2;
    int n;
    map m;
    bool valid();
    vector<double> v;
    vector<int> pbest;
public:
    vector<int> pos;
    int fit(vector<int> pos);
    int fit();
    void ini();
    ptl()= default;
    ptl(int pe1,int pe2,int pn,map pm):e1(pe1),e2(pe2),n(pn),m(pm){vini(pos,0,n);vini(v,(double)0,n);vini(pbest,0,n);ini();}
    int& operator[](int i){return pos[i];};
    void updt(double w,ptl gbest);
};

void ptl::updt(double w,ptl gbest)
{
    if(fit(pos)< fit(pbest))
        pbest=pos;
    for(int i=0;i<n;i++)
    {
        v[i]=w*v[i]+e1*rdm(1)*(pbest[i]-pos[i])+e2*rdm(1)*(gbest[i]-pos[i]);
        pos[i]=pos[i]+v[i];
    }
    if(valid()==0)
        ini();
}

void ptl::ini()
{
    do{
        for(int i=0;i<n;i++)
        {
            do{
                srand(clock() + rand());
                pos[i] = rand() % n;
                v[i] = rand() % n;
            }while(m[i][pos[i]]==1);
        }
    }while(valid()==0);
}

bool ptl::valid()
{
    for(int i=0;i<n;i++)
    {
        if(pos[i]>=n||pos[i]<0)
            return 0;
        else if(m[i][pos[i]]==1)
            return 0;
    }
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            int t=0;
            for(int k=0;k<pos[i];k++)
                t+=m[i][k];
            if(t!=0)
                return 0;
        }
        else{
            for (int t = pos[i - 1]; t < pos[i]; t++)
                temp += m[i - 1][t];
            for (int t = pos[i - 1]; t > pos[i]; t--)
                temp += m[i - 1][t];
            if (temp != 0)
                return 0;
            if (m[i][pos[i]-1] == 1 && m[i - 1][pos[i]] == 1)
                return 0;
            if(i==n-1){
                int sum=0;
                for(int c=pos[n-1];c<n;c++)
                    sum+=m[n-1][c];
                if(sum!=0)
                    return 0;
            }
        }
    }
    return 1;
}

int ptl::fit(vector<int> pos)
{
    int Fit;
    int route=0,reg=0,cut=0,temp=0;
    for(int i=0;i<n-1;i++)
    {
        temp=pos[i+1]-pos[i];
        if(temp<0)
            temp=-temp;
        route+=temp;

        temp=0;
        temp=i-pos[i];
        if(temp<0)
            temp=-temp;
        reg+=temp;

        if(pos[i+1]>pos[i]&&(m[i+1][pos[i+1]-1]==0||m[i][pos[i]+1]==0))
        {
           route-=1;

            if(pos[i+1]-pos[i]==1)
                cut-=1;
        }
    }
    reg+=n-1-pos[n-1];
    route+=pos[0]+n-1-pos[n-1];
    return Fit=route+cut;
}

int ptl::fit()
{
    int Fit;
    int route=0,reg=0,cut=0,temp=0;
    for(int i=0;i<n-1;i++)
    {
        temp=pos[i+1]-pos[i];
        if(temp<0)
            temp=-temp;
        route+=temp;
        temp=0;
        temp=i-pos[i];
        if(temp<0)
            temp=-temp;
        reg+=temp;

        if(pos[i+1]>pos[i]&&(m[i+1][pos[i+1]-1]==0||m[i][pos[i]+1]==0))
        {
            route-=1;

            if(pos[i+1]-pos[i]==1)
                cut-=1;
        }
    }
    reg+=n-1-pos[n-1];
    route+=pos[0]+n-1-pos[n-1];
    return Fit=route+cut;
}
#endif //NEWPTL_PTL_TOOLS_H
