// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution {
public:
  int getPairsCount(int nums[], int n, int k) {
    map<int, int> store;
    int result = 0;
    for (int i = 0; i < n; i++) {
      store[nums[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (store.find(k - nums[i]) != store.end()) {
        if (k - nums[i] != nums[i]) {
          result += (store.find(k - nums[i]))->second;
        } else {
          result += (store.find(k - nums[i]))->second - 1;
        }
      }
    }
    return result / 2;
  }
};

// { Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.getPairsCount(arr, n, k);
    cout << ans << "\n";
  }

  return 0;
} // } Driver Code Ends