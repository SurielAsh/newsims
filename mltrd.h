//
// Created by nagi on 19-4-12.
//

#ifndef NEWPTL_MLTRD_H
#define NEWPTL_MLTRD_H

#include <thread>
#include <unistd.h>
#include <iostream>
#include "ptl_tools.h"

using namespace std;

//template

void Dprt1(vector<ptl> &vptl){
    vptl[1].ini();
    vptl[11].ini();
}
void Dprt2(vector<ptl> &vptl){
    vptl[2].ini();
    vptl[12].ini();
}
void Dprt3(vector<ptl> &vptl){
    vptl[3].ini();
    vptl[13].ini();
}
void Dprt4(vector<ptl> &vptl){
    vptl[4].ini();
    vptl[14].ini();
}
void Dprt5(vector<ptl> &vptl){
    vptl[5].ini();
    vptl[15].ini();
}
void Dprt6(vector<ptl> &vptl){
    vptl[6].ini();
    vptl[16].ini();
}
void Dprt7(vector<ptl> &vptl){
    vptl[7].ini();
    vptl[17].ini();
}
void Dprt8(vector<ptl> &vptl){
    vptl[8].ini();
    vptl[18].ini();
}
void Dprt9(vector<ptl> &vptl){
    vptl[9].ini();
    vptl[19].ini();
}
void Dprt10(vector<ptl> &vptl){
    vptl[0].ini();
    vptl[10].ini();
}
void Dprt0(vector<ptl> &vptl){
    thread t1(Dprt1,ref(vptl));
    thread t2(Dprt2,ref(vptl));
    thread t3(Dprt3,ref(vptl));
    thread t4(Dprt4,ref(vptl));
    thread t5(Dprt5,ref(vptl));
    thread t6(Dprt6,ref(vptl));
    thread t7(Dprt7,ref(vptl));
    thread t8(Dprt8,ref(vptl));
    thread t9(Dprt9,ref(vptl));
    thread t10(Dprt10,ref(vptl));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
}


void update1(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[0].updt(w,gbest);
    vptl[10].updt(w,gbest);
}void update2(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[1].updt(w,gbest);
    vptl[11].updt(w,gbest);
}void update4(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[2].updt(w,gbest);
    vptl[12].updt(w,gbest);
}void update5(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[4].updt(w,gbest);
    vptl[14].updt(w,gbest);
}void update6(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[5].updt(w,gbest);
    vptl[15].updt(w,gbest);
}void update7(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[6].updt(w,gbest);
    vptl[16].updt(w,gbest);
}void update8(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[7].updt(w,gbest);
    vptl[17].updt(w,gbest);
}void update9(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[8].updt(w,gbest);
    vptl[18].updt(w,gbest);
}void update10(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[9].updt(w,gbest);
    vptl[19].updt(w,gbest);
}void update3(vector<ptl> &vptl,double w,ptl gbest)
{
    vptl[3].updt(w,gbest);
    vptl[13].updt(w,gbest);
}
void update0(vector<ptl> &vptl,double w,ptl gbest)
{
    thread t1(update1,ref(vptl),w,gbest);
    thread t2(update2,ref(vptl),w,gbest);
    thread t3(update3,ref(vptl),w,gbest);
    thread t4(update4,ref(vptl),w,gbest);
    thread t5(update5,ref(vptl),w,gbest);
    thread t6(update6,ref(vptl),w,gbest);
    thread t7(update7,ref(vptl),w,gbest);
    thread t8(update8,ref(vptl),w,gbest);
    thread t9(update9,ref(vptl),w,gbest);
    thread t10(update10,ref(vptl),w,gbest);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
}

#endif //NEWPTL_MLTRD_H
