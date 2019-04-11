//
// Created by nagi on 19-4-12.
//

#ifndef NEWPTL_MAP_TOOLS_H
#define NEWPTL_MAP_TOOLS_H

#include <vector>
#include <iostream>
#include "general_tools.h"
using std::vector;

class map
{
    int n;
    Matrix self;
public:
    vector<double>& operator[](int i) {return self[i];}
    map()= default;
    map(int n):n(n){Matrix temp(n,n);self=temp;}
    void shwmap()
    {
        for(int x=0;x!=n;x++)
        {
            for(int y=0;y!=n;y++)
            {
                if(self[x][y]==1)
                    std::cout<<"▇|";
                else if(self[x][y]==-1)
                    std::cout<<"☆|";
                else
                    std::cout<<"_|";
            }
            std::cout<<std::endl;
        }
    }
    void rdmmkmap()
    {
        for(int x=0;x!=n;x++)
        {
            for(int y=0;y!=n;y++)
            {
                double r=rdm(1);
                if(r>0.97)
                    self[x][y]=1;
                else
                    self[x][y]=0;
            }
        }
        self[0][0]=0;
        self[n-1][n-1]=0;
        /*map[1][1]=1;
        map[1][2]=1;
        map[1][3]=1;*/

    }
    void mkmap()
    {
        for(auto &v:self)
        {
            for(auto &a:v)
                std::cin>>a;
        }
        std::cout<<"done";
    }
};
#endif //NEWPTL_MAP_TOOLS_H
