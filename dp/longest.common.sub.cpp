#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int lcs(const string& a, const string& b)
{
    vector<vector<int> > matrix(a.length() + 1);

    for(auto& v: matrix)
        v.resize(b.length() + 1);

    size_t max = 0;

    for(size_t i = 1; i < (a.length() + 1); ++i){
        for(size_t j = 1; j < (b.length() + 1); ++j){
            if(a[i-1] == b[j-1]) {
                matrix[i][j] = 1 + matrix[i-1][j-1];
                cout << a[i-1] << endl;
            }
            else
                matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);

            if(matrix[i][j] > max)
                max = matrix[i][j];

        }
    }

    return max;
}

int main()
{
    string a = "ABCDGHLQR";
    string b = "AEDPHR";
    cout << lcs(a, b) << endl;
    return 0;
}
