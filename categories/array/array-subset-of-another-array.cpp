#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define pf push_front

using namespace std;
#define ll long long
#define ull unsigned long long
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
    ll m = 0, n = 0;
    cin >> m >> n;
    ll arr1[m], arr2[n];
    // check if arr2 is subset of arr1
    for (int i = 0; i < m; i++) {
      cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> arr2[i];
    }
    set<ll> store;
    for (auto i : arr1) {
      store.insert(i);
    }
    for (auto j : arr2) {
      if (store.find(j) == store.end()) {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

  return 0;
}