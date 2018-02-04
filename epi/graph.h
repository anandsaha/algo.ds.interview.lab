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

        void addedge(int source, int dest, int weight = 1) {
            auto it = g.find(source);
            auto it2 = g.find(dest);
            if(it  == g.end()) throw runtime_error("Invalid source");
            if(it2 == g.end()) throw runtime_error("Invalid destination");

            it->second.push_back(it2->first);

            // Uncomment to make the graph undirected
            // it2->second.push_back(it->first);
        }

        void print() const {
            for(const auto& n: g) {
                cout << n.first << ": ";
                for(const auto& n1: n.second)
                    cout << n1 << ", ";
                cout << endl;
            }
        }

        const list<int>& get_out(int node) const{
            auto it = g.find(node);
            if(it == g.end()) throw runtime_error("Invalid node id");
            return it->second;
        }

        list<int> get_in(int node) const {
            list<int> in;
            for(const auto& n: g)
                for(const auto& i: n.second)
                    if(i == node)
                        in.push_back(n.first);
            return in;
        }

        const map<int, list<int>>& get_graph() const {
            return g;
        }
};


void DFS(const Graph& g, int start)
{
    stack<int> s;
    s.push(start);
    set<int> visited;

    while(!s.empty()) {
        int curr = s.top(); s.pop();

        if(visited.find(curr) == visited.end()) {
            cout << "Visited " << curr << endl;

            const list<int>& adj = g.get_out(curr);
            for(const auto& i: adj)
                s.emplace(i);
        }

        visited.insert(curr);
    }
}

void BFS(const Graph& g, int start)
{
    queue<int> q;
    q.push(start);
    set<int> visited;

    while(!q.empty()) {
        int curr = q.front(); q.pop();

        if(visited.find(curr) == visited.end()) {
            cout << "Visited " << curr << endl;

            const list<int>& adj = g.get_out(curr);
            for(const int& i: adj)
                q.emplace(i);
        }
        visited.insert(curr);
    }
}

map<int, int> shortest_distance(const Graph& g, int start)
{
    map<int, int> distances;

    for(const auto& p: g.get_graph())
        distances[p.first] = -1;

    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        const list<int>& adj = g.get_out(curr);
        for(const int& i: adj) {
            if(distances[i] == -1) {
                distances[i] = distances[curr] + 1;
                q.push(i);
            }
        }
    }

    return distances;
}

#endif
