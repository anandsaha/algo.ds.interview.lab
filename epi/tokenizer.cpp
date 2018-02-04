#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream file("shakespeare.txt");
    string word;

    while(file >> word) {
        cout << word << endl;
    }

    file.close();
}
