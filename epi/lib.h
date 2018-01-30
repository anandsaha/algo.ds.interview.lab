#ifndef _LIB_
#define _LIB_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// Implementation of several ADT's.

// Some use C++ classes under the hood. Will be replaced with 
// custom implementation in time to come.

using namespace std;

// To generate uniform random numbers
std::random_device rd;
std::mt19937 generator(rd());
std::uniform_int_distribution<int> dis(0, 99);
int gen() {
    return dis(generator);
}

class Heap
{
    public:
        explicit Heap() {
            make_heap(data.begin(), data.end());
        }

        explicit Heap(const vector<int>& source) {
            data.insert(data.end(), source.begin(), source.end());
            make_heap(data.begin(), data.end());
        }


        void insert(int value) {
            data.push_back(value);
            push_heap(data.begin(), data.end());
        }

        const int& top() const {
            return data.front();
        }

        size_t size() const {
            return data.size();
        }

        void pop() {
            pop_heap(data.begin(), data.end());
            data.pop_back();
        }

    private:
        vector<int> data;
};


void getvect(vector<int>& source, size_t num = 10) {
    cout << "getvect(): ";
    while(source.size() <= num) {
        int i = gen();
        if (find(source.begin(), source.end(), i) == source.end()) {
            source.push_back(i);
            cout << i << ",";
        }
    }
    cout << endl;
}

#endif

