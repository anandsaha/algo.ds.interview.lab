#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check_palindrome(const string& str) 
{
    unordered_map<char, size_t> char_freq;

    for(const char& c: str){
        char_freq[c]++;
    }

    size_t odd_count = 0;
    for(const auto& item: char_freq) {
        if (item.second == 1)
            odd_count++;
        else if (item.second != 2)
            return false;
    }

    if(odd_count > 1)
        return false;

    return true;
}


int main()
{
    cout << boolalpha << check_palindrome("level") << endl;
    cout << boolalpha << check_palindrome("anand") << endl;
    cout << boolalpha << check_palindrome("rotator") << endl;
    cout << boolalpha << check_palindrome("garbage") << endl;
}
