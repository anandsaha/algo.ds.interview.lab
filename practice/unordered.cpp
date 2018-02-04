#include <typeinfo>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 {1, 2, 3, 4, 5, 6};
    vector<int> v2 {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<string> s {"first", "second", "third", "forth", "fifth"};


    unordered_set<int> us(100);

    for(size_t i = 0; i < 99999; ++i)
        us.insert(i);

    cout << *us.find(88) << endl;
    cout << us.bucket_count() << endl;
    cout << us.load_factor() << endl;

    cout << "-----------------------------------" << endl;

    unordered_map<int, string> um;
    um.insert(make_pair(1, "red"));
    um.insert(make_pair(2, "green"));
    um.insert(make_pair(3, "blue"));
    um.insert(make_pair(4, "yellow"));

    for(auto c: um)
        cout << c.first << ", " << c.second << endl;

    cout << um.find(2)->second << endl;

}
