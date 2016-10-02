#pragma once
#ifndef HANOI_H
#define HANOI_H


#include <vector>
#include <sstream>
#include <list>
#include <exception>
/*
void hanoi(std::vector<int> & source,std::vector<int> & dest,std::vector<int> & pivot, std::stringstream & s, int size)
{
    int tmp;
    if(size == 1)
    {
        tmp = source[source.size()-1];
        source.pop_back();
        dest.push_back(tmp);
    }
    else if(size == 2)
    {
        hanoi(source,pivot,dest,s,1);
        hanoi(source,dest,pivot,s,1);
        hanoi(pivot,dest,source,s,1);

    }
    else
    {

        hanoi(source,pivot,dest,s,size-1);

        tmp = source[source.size()-1];
        source.pop_back();
        dest.push_back(tmp);

        hanoi(pivot,dest,source,s,pivot.size());
    }
}*/

inline void print(std::list<int> & l,std::stringstream & s)
{
    s << "--";
    for(std::list<int>::iterator it = l.begin();it!=l.end();++it)
    {
        s << *it << "--";
    }
    s << std::endl;
}

void move(std::list<int> & source,std::list<int> & dest,std::vector<std::list<int> *> & vect,std::stringstream & s)
{
    int val = source.back();
    source.pop_back();
    dest.push_back(val);

    s << "*************" << std::endl;
    for(std::vector<std::list<int> *>::iterator it = vect.begin();it!=vect.end();it++)
    {
        print(*(*it),s);
    }
}

void hanoi2(std::vector<std::list<int> *> & vect,
            std::list<int> & source,std::list<int> & dest,std::list<int> & pivot, int count,std::stringstream & s)
{
    if(count != 3)
    {
        hanoi2(vect,source,pivot,dest,count-1,s);
        move(source,dest,vect,s);
        hanoi2(vect,pivot,dest,source,count-1,s);
    }
    else if(count == 3)
    {
        move(source,pivot,vect,s);
        move(source,dest,vect,s);
        move(pivot,source,vect,s);
        move(dest,pivot,vect,s);
        move(source,pivot,vect,s);
        move(source,dest,vect,s);
        move(pivot,source,vect,s);
        move(pivot,dest,vect,s);
        move(source,dest,vect,s);
    }
    else
    {
        throw std::exception("error hanoi2 call");
     }

}


void hanoitest(std::stringstream & s)
{
    /*std::vector<int> source,dest,pivot;
    for(int i = 5; i > 0; i--)
    {
        source.push_back(i);
    }

    hanoi(source,dest,pivot,s,source.size());*/



    std::vector<std::list<int> *> piliers;
    std::list<int> p1,p2,p3;
    piliers.push_back(&p1);
    piliers.push_back(&p2);
    piliers.push_back(&p3);

    int size = 9;

    for(int i=size;i>0;--i)
        p1.push_back(i);

    try
    {
        s << "*************" << std::endl;
        for(std::vector<std::list<int> *>::iterator it = piliers.begin();it!=piliers.end();it++)
        {
            print(*(*it),s);
        }

        hanoi2(piliers,p1,p2,p3,size,s);


    }
    catch(...)
    {
        //bool error;
    }




}


#endif // HANOI_H
