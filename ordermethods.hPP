#ifdef  ORDERMETHODS_HPP
#define ORDERMETHODS_HPP
#include<iostream>
using namespace std;
#include"orderclass.hpp"
void SeqList::Resereve(int newmax)
{
    if(newmax<=max)
        return;
    Type *old = data;
    max = newmax;
    data = new Type[newmax];
    for (int i = 0; i < size;i++)
        data[i] = old[i];
    delete[] old;
}

void SeqList::Insert(int id,Type item)
{
    if(id<0||id>size+1)
        cout << "Insert:Id is illegal" << endl;
        if(size==max)
            Resereve(2 * max);
        for (int i = size - 1; i > id;i--)
            data[i + 1] = data[i];
        data[id] = item;
        size++;
}

void SeqList::Erase(int id)
{
    if(id<0||id>size)
        cout << "Erase:id is illegal" << endl;
    for (int i = id + 1; i < size;i++)
        data[i - 1] = data[i];
    size--;
}

SeqList&SeqList::operator=(const SeqList&l)
{
    delete[] data;
    data = new Type[l.max];
    size = l.size;
    max = l.size;
    for (int i = 0; i < size;i++)
        data[i] = l.data[i];
    return *this;
}

#endif

