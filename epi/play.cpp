#include "lib.h"

int main()
{
    MyIterator v;

    for(auto i: v)
        cout << i << endl;

    MyIterator::iterator it = v.begin();
    MyIterator::iterator ite = v.end();

    while(it != ite){
        cout << *it << endl;
        it++;
    }

}
