#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<int>  v1 {1, 2, 3, 4, 5};
    vector<char> v2 {'a', 'b', 'c', 'd', 'e'};

    // Map

    map<int, char, greater<int> > m1;

    for(size_t i = 0; i < v1.size(); ++i) {
        m1[v1[i]] = v2[i];
    }

    m1.insert(pair<int, char>(6, 'f'));
    m1.erase(4);
    m1.emplace(4, 'x');

    for_each(m1.begin(), m1.end(), [](pair<const int, char>& i) { cout << i.first << ", " << i.second << endl; });

    cout << "------" << endl;

    cout << (*m1.find(4)).second << endl;

    cout << "Map Size: " << m1.size() << endl;
    cout << "Map Max Size: " << m1.max_size() << endl;

    cout << m1.upper_bound(3)->first << endl;

    cout << "------" << endl;

    // Multimap

    multimap<int, char> m2;
    for(size_t i = 0; i < v1.size(); ++i) {
        m2.insert(make_pair(v1[i], v2[i]));
    }

    for(size_t i = 0; i < v1.size(); ++i) {
        m2.insert(make_pair(v1[i], v2[i]));
    }

    for(auto k: m2) {
        cout << k.first  << ", " << k.second << endl;
    }

    cout << m2.count(1) << endl;

    return 0;
}
