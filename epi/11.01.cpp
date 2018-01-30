#include "lib.h"

int main()
{
    size_t num = 10;
    vector<int> source;
    
    getvect(source, num);

    Heap h(source);

    for(size_t i = 0; i < num; i++){
        cout << h.top() << ",";
        h.pop();
    }

    cout << endl;

    return 0;
}
