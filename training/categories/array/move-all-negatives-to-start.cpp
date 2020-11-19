#include <iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  long long n = 0;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long l = 0, r = n - 1;
  while (l <= r) {
    if (arr[l] < 0 && arr[r] < 0) {
      l++;
    } else if (arr[l] > 0 && arr[r] < 0) {
      swap(arr[l], arr[r]);
      l++;
      r--;
    } else if (arr[l] > 0 && arr[r] > 0) {
      r--;
    } else {
      l++;
      r--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}