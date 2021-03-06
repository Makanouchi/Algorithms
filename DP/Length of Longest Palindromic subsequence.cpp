
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
// https://www.geeksforgeeks.org/longest-palindrome-subsequence-space/   --> O(n) space

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

// takes O(n^2) extra space
int lps(string &s) {
    int n = s.size();
    deque<di> dp(n, di(n, -1));  // length of longest panlindromic subsequence from i to j

    for (int i = 0; i < n; i++) {  // All strings having only 1 character have lps of length 1
        dp[i][i] = 1;
    }

    for (int l = 2; l <= n; l++) {             // length 1 already taken care of, so start with 2
        for (int i = 0; i < n - l + 1; i++) {  // we dont fill below the diagonal (i < j)
            // i is the substring's starting index, max i for string of length l can be n-l
            int j = i + l - 1;

            if (s[i] == s[j] && l == 2) {  // if length is 2 and both characters are same
                dp[i][j] == 2;
            } else if (s[i] == s[j]) {  // if 1st and last letter are the same
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
}

// for printing the longest palindromic subsequence, we dont use this at all.
// we can take s and reverse(s), then print the longest common subsquence of both, this will be a palindrome

int main() {
    string s;
    cin >> s;

    cout << lps(s);

    return 0;
}
