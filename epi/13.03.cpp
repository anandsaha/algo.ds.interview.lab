#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool anonymous(const string& mag, const string& letter) 
{
    unordered_map<char, int> mag_char_count;

    for(const char& c: mag)
        mag_char_count[c]++;


    for(const char& c: letter) {
        mag_char_count[c]--;

        if(mag_char_count[c] < 0)
            return false;
    }

    return true;
}


int main()
{
    string letter = "a great day.";
    string mag = "Today is a great day.";
    cout << boolalpha << anonymous(mag, letter)  << endl;
}
