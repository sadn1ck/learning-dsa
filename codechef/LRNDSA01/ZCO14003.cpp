#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define pf push_front
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

typedef long long ll;
typedef long double ldo;
typedef double db;
using namespace std;

void solve() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll t = 0;
  cin >> t;
  vll nums;
  while (t--) {
    ll n;
    cin >> n;
    nums.push_back(n);
  }
  sort(all(nums));
  vll profits;
  for (int i = 0; i < nums.size(); i++) {
    profits.push_back((nums.size() - i) * nums.at(i));
  }
  ll most = *max_element(profits.begin(), profits.end());
  cout << most;
  on
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

  return 0;
}