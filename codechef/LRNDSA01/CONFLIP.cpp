#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define pf push_front

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldo;
typedef double db;
using namespace std;
#define ins insert
#define mp make_pair
#define len(s) s.length()
#define on cout << "\n";
#define o2(a, b) cout << a << " " << b;
#define os cout << " "
#define all(v) v.begin(), v.end()
#define mem(n, m) memset(n, m, sizeof(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int>
#define vll vector<long long>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define ret return 0
#define present(s, x) (s.find(x) != s.end())
#define cpresent(s, x) (find(all(s), x) != s.end())

#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define inf 999999999999999999
#define siz 100001
#define SIZ 1000001
#define SIZE 200001

#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

void solve() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll t = 0;
  cin >> t;
  while (t--) {
    // number of games played
    // i -> initial state
    // n -> number of coins/rounds
    // q -> guess number of head(1) or tails(2)
    ll g, i, n, q;
    cin >> g;
    while (g--) {
      cin >> i >> n >> q;
      ll hc = 0, tc = 0;
      if (n % 2 == 0) {
        hc = tc = n / 2;
      } else {
        if (i == 2) {
          hc = (n / 2) + 1;
          tc = n / 2;
        } else {
          hc = n / 2;
          tc = (n / 2) + 1;
        }
      }
      if (q == 1) {
        cout << hc;
        on
      } else {
        cout << tc;
        on
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

  return 0;
}