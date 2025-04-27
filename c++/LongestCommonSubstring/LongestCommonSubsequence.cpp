#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute LCS length
int lcsLength(const string& X, const string& Y, string& lcsResult) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    // Reconstruct LCS, get actual subsequence
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsResult = X[i - 1] + lcsResult;
            i--;
            j--;
        } else if (c[i - 1][j] > c[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return c[m][n];
}

int main() {
    // Input sequences
    string X, Y;
    cout << "Enter first sequence: ";
    cin >> X;
    cout << "Enter second sequence: ";
    cin >> Y;

    // Compute LCS
    string lcsResult;
    int length = lcsLength(X, Y, lcsResult);

    // Output results
    cout << "Length of LCS: " << length << endl;
    cout << "LCS: " << lcsResult << endl;

    int onlyfornotshuttingdownimmediately;
    cin>> onlyfornotshuttingdownimmediately;
    return 0;
}
