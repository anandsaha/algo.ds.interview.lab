#ifndef _GRAPH
#define _GRAPH

#include <vector>
#include <map>
#include <set>
#include <list>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
    private:
        map<int, list<int>> g;

    public:
        explicit Graph(const vector<int>& nodes){
            for(const auto& n: nodes)
                g[n] = {};
        }

        void addedge(int source, int dest) {
            auto it = g.find(source);
            auto it2 = g.find(dest);
            if(it  == g.end()) throw runtime_error("Invalid source");
            if(it2 == g.end()) throw runtime_error("Invalid destination");
            it->second.push_back(it2->first);
        }

        void print() const {
            for(const auto& n: g) {
                cout << n.first << ": ";
                for(const auto& n1: n.second)
                    cout << n1 << ", ";
                cout << endl;
            }
        }

        const list<int>& get_adj(int node) const{
            auto it = g.find(node);
            if(it == g.end()) throw runtime_error("Invalid node id");
            return it->second;
        }
};


void DFS(const Graph& g, int start)
{
    stack<int> s;
    s.push(start);
    set<int> visited;

    while(!s.empty()) {
        int curr = s.top(); s.pop();

        if(visited.find(curr) == visited.end())
            cout << "Visited " << curr << endl;

        visited.insert(curr);

        const list<int>& adj = g.get_adj(curr);
        for(const auto& i: adj)
            s.emplace(i);
    }
}

void BFS(const Graph& g, int start)
{
    queue<int> q;
    q.push(start);
    set<int> visited;

    while(!q.empty()) {
        int curr = q.front(); q.pop();

        if(visited.find(curr) == visited.end())
            cout << "Visited " << curr << endl;

        visited.insert(curr);

        const list<int>& adj = g.get_adj(curr);
        for(const int& i: adj)
            q.emplace(i);
    }
}

#endif
