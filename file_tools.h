//
// Created by nagi on 19-4-22.
//

#ifndef NEWPTL_FILE_TOOLS_H
#define NEWPTL_FILE_TOOLS_H
#include <fstream>
#include <vector>
#include "map_tools.h"

map fmkmap() {
    std::ifstream fin("data");
    bool lable=0;
    int n;
    int x=0,y=0;
    map temp;
    while (fin) {
        int idata;
        fin >> idata;
        if(lable==0) {
            temp.mini(idata);
            lable=1;
            n=idata-1;
        }
        else
        {
            temp[x][y]=idata;
            if(y<n)
                y++;
            else if(x<n)
            {
                y=0;
                x++;
            }
        }
    }
    return temp;
}
#endif //NEWPTL_FILE_TOOLS_H
