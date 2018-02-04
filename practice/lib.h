#ifndef _LIB_
#define _LIB_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// To generate uniform random numbers
std::random_device rd;
std::mt19937 generator(rd());
std::uniform_int_distribution<int> dis(0, 99);
int gen() {
    return dis(generator);
}

// Helpers
////////////////////////////////////////////////////////////////////
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

// Classes
////////////////////////////////////////////////////////////////////
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

// Creating custom iterators in C++
class MyIterator
{
    public:
        MyIterator() {
            getvect(v);
        }
 
        typedef vector<int>::iterator       iterator;
        typedef vector<int>::const_iterator const_iterator;

        iterator begin()        { return v.begin();  }
        iterator end()          { return v.end();    }
        const_iterator cbegin() { return v.cbegin(); }
        const_iterator cend()   { return v.cend();   }

    private:
        vector<int> v;
};
#endif

