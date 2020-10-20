#include <iostream>
using namespace std;

int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int arr[n];
    int z = 0, o = 0, t = 0;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      if (temp == 0)
        z++;
      if (temp == 1)
        o++;
      if (temp == 2)
        t++;
    }
    for (int i = 0; i < z; i++) {
      cout << 0 << " ";
    }
    for (int i = z; i < z + o; i++) {
      cout << 1 << " ";
    }
    for (int i = z + o; i < z + t + o; i++) {
      cout << 2 << " ";
    }
    cout << "\n";
  }
  return 0;
}