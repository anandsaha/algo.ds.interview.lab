#include <queue>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

typedef pair<string, size_t> Elem;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top().first << ", " << q.top().second << endl;
        q.pop();
    }
    std::cout << '\n';
}

class Compare
{
    public:
        bool operator()(const Elem& a, const Elem& b) {
            return a.second > b.second;
        }
};

void k_most_used(size_t k, const vector<string>& words) 
{
    // Put them in a hash table (time: O(n), space: O(n))

    unordered_map<string, size_t> hash;

    for(const string& s: words){
        hash[s]++;
    }

    priority_queue<Elem, vector<Elem>, Compare> pq;

    for(const auto& item: hash) {
        pq.push(item);

        if(pq.size() > k)
            pq.pop();
    }

    print_queue(pq);

}

int main()
{

    vector<string> words;

    ifstream file("shakespeare.txt");
    string word;

    while(file >> word) {
        words.push_back(word);
    }
    file.close();

    k_most_used(10, words);
}
