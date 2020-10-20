#include <iostream>
using namespace std;

int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; i--) {
      cout << s[i];
    }
    cout << "\n";
  }
  return 0;
}