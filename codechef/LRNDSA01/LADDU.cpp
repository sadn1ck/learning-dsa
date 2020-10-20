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
    long long int k, d0, d1;
    cin >> k >> d0 >> d1;
    long long int d2 = (d0 + d1) % 10;
    long long int sum = 0;
    long long int s = d0 + d1;
    long long int c =
        ((2 * s) % 10) + ((4 * s) % 10) + ((8 * s) % 10) + ((6 * s) % 10);
    if (k == 2) {
      sum = d1 + d0;
    } else if (k > 2) {
      long long int cycle = (k - 3) / 4;
      long long int last = (k - 3) - (4 * cycle);
      sum += s + d2 + (c * cycle);
      int p = 2;
      for (long long i = 0; i < last; i++) {
        sum += ((p * s) % 10);
        p *= 2;
      }
    }

    if (sum % 3 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
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