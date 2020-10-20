#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int main() {
  // code
  int t = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[100000] = {0};
    for (int i = 0; i < n; i++) {
      int temp = 0;
      cin >> temp;
      arr[temp] += 1;
    }
    int k = 0;
    cin >> k;
    bool flag = true;
    for (int i = 0; i < 100000 && flag; i++) {
      if (arr[i] >= 1) {
        // cout << i << " " << arr[i] << "\n";
        for (int j = 0; j < arr[i]; j++) {
          k--;
          if (k == 0) {
            cout << i << "\n";
            flag = false;
            break;
          }
        }
      }
    }
  }

  return 0;
}

/* Alternative solution:
int main() {
  // code
  int t = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    priority_queue<int, vector<int>> store;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      store.push(temp);
    }
    int k = 0;
    cin >> k;
    for (int i = 0; i < n - k; i++) {
      store.pop();
    }
    cout << store.top();
    cout << "\n";
  }

  return 0;
}
*/