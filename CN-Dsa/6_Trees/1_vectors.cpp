#include <iostream>
#include <vector> //inbuilt dynamic array basically an array just that we dont have to tell its size in beginning
using namespace std;

//vector is a template

int main()
{
    //vector<int> *vp= new vector<int>(); //dynamically allocate ( khud se deallocate)
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30); //[] will be used for get and updation of element not use for insertion into the vector

    v.pop_back(); //remove the last ele

    //cout << v[0] << v[1] << v[8] << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << v.capacity() << endl; //gives current capacity
    cout << v.size() << endl;
    cout << v.at(0) << endl;
    cout << v.at(3); //out of range error at( ) is much safer to use bcoz when we try to acess the ele out of range it will give error
}