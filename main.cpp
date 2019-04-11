#include <iostream>
#include <vector>
#include <ctime>
#include "general_tools.h"
#include "map_tools.h"
#include "ptl_tools.h"
#include "mltrd.h"
using namespace std;

int main() {
    int n,Gmax,e1,e2,num;
    double w;
    //******************
    n=8;
    Gmax=10000;
    e1=3;
    e2=3;
    num=50;
    w=1;
    //******************
    cout<<"粒子数为"<<num<<endl;

    map map1(n);
    map1.rdmmkmap();
    map1.shwmap();
    cout<<endl;

    clock_t start,ends;
    start=clock();

    ptl gbest(e1,e2,n,map1);
    vector<ptl> vptl;
    for(int i=0;i<num;i++)
    {
        vptl.push_back(gbest);
    }
    //Dprt0(vptl);
    for(int i=0;i<num;i++) {
    	vptl[i].ini();
    }


    for(int gen=0;gen<Gmax;gen++)
    {
        //cout<<"第 "<<gen<<" 代,gbest适应度为"<<gbest.fit()<<endl;
        for (int i = 0; i < num; i++) {
            bool b = (vptl[i].fit() <= gbest.fit());
            if (b == 1)
                gbest.pos = vptl[i].pos;
            vptl[i].updt(w,gbest);
        }
        //update0(vptl,w,gbest);
        fw(Gmax,gen,w);
        map temp=map1;
        for(int i=0;i<n;i++)
        {
            temp[i][gbest.pos[i]]=-1;
        }
        temp.shwmap();
        //system("clear");
    }
    for(int i=0;i<n;i++)
    {
        map1[i][gbest.pos[i]]=-1;
    }
    map1.shwmap();

    ends=clock();
    cout<<"共用时"<<ends-start<<endl;
    return 0;
}