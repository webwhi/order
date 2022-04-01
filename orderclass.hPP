#ifndef ORDERCLASS_HPP
#include<iostream>
using namespace std;
typedef int Type;
class SeqList
{
private:
    /* data */
    Type*data;
    int max;
    int size;

public:
    explicit SeqList(int n = 10) : max(10), size(0) { data = new Type[n]; }
    SeqList(const SeqList &l) : data(0) { *this = l; };
    ~SeqList() { delete[] data; }
    SeqList &operator=(const SeqList &l);
    void Resereve(int newmax);

    void Insert(int id, Type item);
    void PushBack(const Type &item) { Insert(size, item); }
    void PushFront(const Type &item) { Insert(0, item); }

    void Erase(int id);
    void PopFront() { Erase(0);}
    void PopBack() { Erase(size); }
    void Clear() { size = 0;}

    Type &operator[](int id) { return data[id]; }
    const Type &operator[](int id) const { return data[id]; }
    bool Empty() const { return size == 0; }
    int GetSize() const { return size; }
    const Type &GetData(int id) const { return data[id]; }
};

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
