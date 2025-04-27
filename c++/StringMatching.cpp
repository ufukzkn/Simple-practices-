#include <iostream>
#include <string>
using namespace std;

int naiveStringMatching(string T, string p) {
    int comparisons = 0;
    int n = T.length();
    int m = p.length();
    
    for (int i = 0; i <= n-m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            comparisons++;
            if (T[i + j] != p[j])
                break;
        }
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
    return comparisons;
}

int BoyerMoore(string T, string p) {
    int comparisons = 0;
    int n = T.length();
    int m = p.length();
    int last[256];
    
    // Initialize last occurrence array
    for (int i = 0; i < 256; i++)
        last[i] = -1;
    for (int i = 0; i < m; i++)
        last[p[i]] = i;
 

    // For pattern "ABC":
    // last['A'] = 0   A appears at index 0 (rightmost/only occurrence)
    // last['B'] = 1   B appears at index 1 (rightmost/only occurrence)
    // last['C'] = 2   C appears at index 2 (rightmost/only occurrence)
    // All other characters remain -1
    // When there's a mismatch with character x, we shift by: j - last[x]
    // If x isn't in pattern (last[x] = -1), we shift by j + 1 which is the length of pattern

    
    int i = m - 1;  //to keep track
    int j = m - 1;
    
    while (i < n) {
        comparisons++;
        if (T[i] == p[j]) {
            if (j == 0) {
                cout << "Pattern found at index " << i << endl;
                i = i + m;
                j = m - 1;
            }
            else {
                i--;
                j--;
            }
        }
        else {
            i = i + m - min(j, 1 + last[T[i]]);
            j = m - 1;
        }
    }
    return comparisons;
}

int main(int argc, char** argv) {
    //Exercise 1 - tests
    cout << endl << "Exercise 1 - tests" << endl;
    {
        string text = "ABAAABCDABC";
        string pattern = "ABC";
        
        cout << "Text: " << text << endl;
        cout << "Pattern: " << pattern << endl << endl;
        
        cout << "Naive String Matching:" << endl;
        int naiveComparisons = naiveStringMatching(text, pattern);
        cout << "Number of comparisons: " << naiveComparisons << endl << endl;
        
        cout << "Boyer-Moore:" << endl;
        int bmComparisons = BoyerMoore(text, pattern);
        cout << "Number of comparisons: " << bmComparisons << endl;
    }
    return 0;
}
