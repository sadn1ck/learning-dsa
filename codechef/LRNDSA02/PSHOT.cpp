#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define ins insert
#define mp make_pair
#define len(s) s.length()
#define on cout << "\n";
#define o2(a, b) cout << a << " " << b;
#define os cout << " ";
#define all(v) v.begin(), v.end()
#define mem(n, m) memset(n, m, sizeof(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int>
#define vll vector<long long>
#define mll map<long long, long long>

#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define inf 999999999999999999

#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

void solve() {
#ifndef ONLINE_JUDGE
  freopen("/home/anik/projects/learning/dsa/input.txt", "r", stdin);
  freopen("/home/anik/projects/learning/dsa/output.txt", "w", stdout);
#endif
  ll t = 0;
  cin >> t;
  while (t--) {
    ll n = 0;
    cin >> n;
    string shots = "";
    cin >> shots;
    ll goalA, goalB, A = 0, B = 0, goal;
    goal = 2 * n;
    goalA = n;
    goalB = n;
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0) {
        if (shots[i] == '1') {
          A++;
        }
        goalA--;
      } else {
        if (shots[i] == '1') {
          B++;
        }
        goalB--;
      }
      if (A > (B + goalB) || B > (A + goalA)) {
        goal = i + 1;
        break;
      }
    }
    cout << goal;
    on;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

  return 0;
}