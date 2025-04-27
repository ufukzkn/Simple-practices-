#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<string, int> longestCommonSubstring(const string& str1, const string& str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    
    int maxLength = 0; // Length of the longest common substring
    int endIndex = 0;  // End index of the longest common substring in str1

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    string lcs = str1.substr(endIndex - maxLength + 1, maxLength);
    return {lcs, maxLength};
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    auto result = longestCommonSubstring(str1, str2);
    cout << "Longest Common Substring: " << result.first << endl;
    cout << "Length: " << result.second << endl;

    int onlyfornotshuttingdownimmediately;
    cin>> onlyfornotshuttingdownimmediately;
    
    return 0;
}