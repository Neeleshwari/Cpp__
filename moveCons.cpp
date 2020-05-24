#include <iostream>
#include <vector>
using namespace std;

class MyVector
{
    int *elems;
    int size;
    public:
    ~MyVector()
    {
        cout<<"\nDestructor";
        delete[] elems;   
    }
    
    MyVector(int asize = 5)
    {
        cout<<"\nConstructor";
        size = asize;
        elems = new int(size);
    }
    MyVector(MyVector &other)
    {
        cout<<"\nCopy constructor";
        cout<<"\nsize : "<<other.size;
        size = other.size;
        elems = new int(size);
        for(int i=0;i<size;i++)
        {
            cout<<"\n"<<elems[i];
            elems[i] = other.elems[i];
        }
    }
    MyVector( MyVector &&other) // move constructor
    {
        cout<<"\nMove constructor";
        elems = other.elems;
        size = other.size;
        other.elems = nullptr;
    }
    void getSize()
    {
        cout<<"\nSize:"<<size;
    }
    void print()
    {
        cout<<"\n";
        for(int i=0;i<size;i++)
        {
            cout<<"\t"<<elems[i];
        }
    }
};

int main()
{
    cout<<"Hello World";
    MyVector vec;
    vec.getSize();
    MyVector vec1(vec);
    vec1.getSize();
    vector<MyVector> vect;
    vect.push_back(MyVector());
    vect.at(0).getSize();
    
    return 0;
}
