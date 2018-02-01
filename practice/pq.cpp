#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <queue>

using namespace std;


int main() 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);

    priority_queue<int, std::vector<int>, std::less<int> > q;

    int i = 0;
    while(i++ < 10)
        q.push(dis(gen));

    while(!q.empty()) {
        cout << q.top() << ", ";
        q.pop();
    }
    cout << endl;
}
