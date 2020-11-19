#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int counts[30000] = {0};
    for (int n : nums) {
      counts[n]++;
      if (counts[n] > 1) {
        return n;
      }
    }
    return 0;
  }
};