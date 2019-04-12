//
// Created by nagi on 19-3-10.
//

#ifndef KAWORU_GENERALTOOLS_H
#define KAWORU_GENERALTOOLS_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include<random>

using std::vector;

std::default_random_engine re;
std::uniform_real_distribution<double> dd(0, 1.0);

double rdm(int n)
{
   re.seed(clock()+dd(re));
	double r=dd(re);
	cout<<r<<endl;
	return r;
}

template <typename T>
void vini(vector<T> &v,T par,int n)
{
    v.clear();
	for(int i=0;i<n;i++)
		v.push_back(par);
}
template <typename T>
void vini(vector<vector<T>> &v,vector<T> &t,int n)
{
    v.clear();
	for(int i=0;i<n;i++)
		v.push_back(t);
}
class Matrix{
private:
	vector<double> row;
	vector<double> column;
	int hight,width;
public:
	vector<vector<double>> self;
	Matrix()=default;
	Matrix(int ht,int wd,int mode);
	Matrix(int ht,int wd):hight(ht),width(wd){vini(row,0.,wd);vini(self,row,ht);}
	inline int h(){return hight;}
	inline int w(){return width;}
	inline int size(){return hight*width;}
	void expand(int w,int h);
	void expand(int w,int h,double n);
    void lastExpand(int w,int h);
    void lastExpand(int w,int h,double n);
	vector<std::vector<double, std::allocator<double>>, std::allocator<std::vector<double, std::allocator<double>>>>::iterator begin(){return self.begin();}
    vector<std::vector<double, std::allocator<double>>, std::allocator<std::vector<double, std::allocator<double>>>>::iterator end(){return self.end();}
	vector<double>& operator[] (int i);
    Matrix operator+ (Matrix M1);
    Matrix operator- (Matrix M1);
    Matrix operator* (Matrix M1);
	Matrix T();
	Matrix rot180();
};
Matrix::Matrix(int ht,int wd,int mode):hight(ht),width(wd)
{
	if(mode==0)
	{
		srand(clock()+rand());
		vini(row,0.,wd);
		vini(self,row,ht);
		for(auto &r:self)
		{
			for(auto &a:r)
			{
				a=rand()%3-1;
			}
		}
	}
	else
	{
		vini(row,(double)mode,wd);
		vini(self,row,ht);
	}
};
void Matrix::expand(int w,int h)
{
	vector<double> temp(width,(double)0);
	self.insert(self.begin(),(int)(h/2),temp);
	self.insert(self.end(),h-(int)(h/2),temp);
	for(auto a:self)
	{
		a.insert(a.begin(),(int)(w/2),(double)0);
		a.insert(a.end(),w-(int)(w/2),(double)0);
	}
}
void Matrix::expand(int w,int h,double n)
{
	vector<double> temp(width,n);
	self.insert(self.begin(),(int)(h/2),temp);
	self.insert(self.end(),h-(int)(h/2),temp);
	for(auto a:self)
	{
		a.insert(a.begin(),(int)(w/2),n);
		a.insert(a.end(),w-(int)(w/2),n);
	}
}
void Matrix::lastExpand(int w,int h)
{
    vector<double> temp(width,(double)0);
    self.insert(self.end(),h,temp);
    for(auto a:self)
        a.insert(a.end(),w,(double)0);
}
void Matrix::lastExpand(int w,int h,double n)
{
    vector<double> temp(width,n);
    self.insert(self.end(),h,temp);
    for(auto a:self)
        a.insert(a.end(),w,n);
}
vector<double>& Matrix::operator[] (int i)
{
    if(i<self.size())
	return self[i];
    else
    {
        lastExpand(i-width,0);
        std::cout<<"矩阵范围溢出,已用空数组补全，请注意矩阵访问的合法性"<<std::endl;
        return self[0];
    }
}
Matrix Matrix::operator+ (Matrix M1)
{
    if(hight!=M1.h()||width!=M1.w())
    {
        std::cout << "矩阵维度不同，无法加减" << std::endl;
        return *this;
    }
    else
    {
        Matrix temp(hight,width);
        for(int x;x<width;x++)
        {
            for(int y;y<width;y++)
            {
                temp[x][y]=self[x][y]+M1[x][y];
            }
        }
        return temp;
    }
}
Matrix Matrix::operator- (Matrix M1)
{
    if(hight!=M1.h()||width!=M1.w())
    {
        std::cout << "矩阵维度不同，无法加减" << std::endl;
        return *this;
    }
    else
    {
        Matrix temp(hight,width);
        for(int x;x<width;x++)
        {
            for(int y;y<width;y++)
            {
                temp[x][y]=self[x][y]-M1[x][y];
            }
        }
        return temp;
    }
}
Matrix Matrix::operator* (Matrix M1)
{
    if(hight!=M1.h()||width!=M1.w())
    {
        std::cout << "矩阵维度不同，无法做哈达马积" << std::endl;
        return *this;
    }
    else
    {
        Matrix temp(hight,width);
        for(int x;x<width;x++)
        {
            for(int y;y<width;y++)
            {
                temp[x][y]=self[x][y]*M1[x][y];
            }
        }
        return temp;
    }
}
Matrix Matrix::T()
{
	Matrix temp(hight,width);
	for(int x;x<width;x++)
	{
		for(int y;y<hight;y++)
		{
		    for(int x;x<width;x++)
			{
				for(int y;y<hight;y++)
				{
					temp.self[x][y]=self[y][x];
				}
			}
			temp.self[x][y]=self[y][x];
		}
	}
	return temp;
}
Matrix Matrix::rot180()
{
	Matrix temp(hight,width);
	for(int x;x<width;x++)
	{
		for(int y;y<hight;y++)
		{
			temp.self[x][y]=self[width-1-x][hight-1-y];
		}
	}
	return temp;
}

template <typename T>
inline T derevition (T(*fun)(T,T),T rslt)
{
    return (fun(rslt+0.000000000001)-fun(rslt))/0.000000000001;
}
#endif //KAWORU_GENERALTOOLS_H