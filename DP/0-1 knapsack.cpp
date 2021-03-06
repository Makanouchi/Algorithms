// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

// Also see -
// https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed
// https://www.geeksforgeeks.org/printing-items-01-knapsack/

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int knapsack(int noOfItems, int maxCapacity, vector<int> &weight, vector<int> &value) {
    int dp[noOfItems + 1][maxCapacity + 1];

    for (int i = 0; i <= noOfItems; i++) {
        for (int w = 0; w <= maxCapacity; w++) {  // w is the max capacity for the current subproblem
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
                // max of include (i-1)th item and exclude it.
            } else {
                dp[i][w] = dp[i - 1][w];
                // exclude (i-1)th item as its weight is too much.
            }
        }
    }

    return dp[noOfItems][maxCapacity];
}

int main() {
    int t, noOfItems, maxCapacity;
    cin >> t;

    vector<int> weight, value;

    while (t--) {
        cin >> noOfItems >> maxCapacity;
        weight.resize(noOfItems);
        value.resize(noOfItems);

        for (int i = 0; i < noOfItems; i++) {
            cin >> value[i];
        }

        for (int i = 0; i < noOfItems; i++) {
            cin >> weight[i];
        }

        cout << knapsack(noOfItems, maxCapacity, weight, value) << endl;
    }

    return 0;
}