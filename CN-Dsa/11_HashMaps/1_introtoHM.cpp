#include <iostream>
#include <unordered_map> //hashtable wala O(1)

using namespace std;

int main()
{
    unordered_map<int, int> map; // its just a key value pair

    // How to Insert ?
    pair<int, int> p(2, 3);
    map.insert(p);

    /*--------------OR---------------*/
    map[5] = 6;
    // How to find or acess
    cout << map[2];
    cout << map.begin()->first;
    cout << map.at(2);

    /*check presense of an element*/
    if (map.count(2))
    {
        cout << "\nElement Found" << endl;
    }
    /* Map size*/
    cout << map.size();
    /*Erase from map*/
    map.erase(2);
    cout << map.count(2);

    return 0;
}