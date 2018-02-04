#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> input {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis"};
    unordered_map<string, vector<string> > sorted;

    for(const string& s: input) {
        string sorted_str(s);
        sort(sorted_str.begin(), sorted_str.end());
        sorted[sorted_str].emplace_back(s);
    }

    vector<vector<string> > anagram_groups;
    for(const pair<string, vector<string> >& p: sorted) {
        if(p.second.size() >= 2) {
            anagram_groups.emplace_back(p.second);
        }
    }

    for(const auto& v1: anagram_groups) {
        for(const auto& elem: v1)
            cout << elem << endl;
        cout << "----" << endl;
    }

}
