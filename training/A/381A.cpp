/*
***********************
******* sadn1ck *******
******** IIEST ********
***********************
*/
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;
#define ins insert
#define mp make_pair
#define on cout << "\n";
#define os cout << " ";
#define all(v) v.begin(), v.end()
#define len(s) s.length()
#define mem(n, m) memset(n, m, sizeof(n))
#define fo(n) for (ll i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int>
#define vpll vector<pair<long long, long long>>
#define vll vector<long long>
#define mll map<long long, long long>

#define MOD 1000000007
#define EPSILON 1e-9
#define inf 999999999999999999

#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

void solve()
{
#ifndef ONLINE_JUDGE
    freopen("/home/anik/projects/learning/dsa/input.txt", "r", stdin);
    freopen("/home/anik/projects/learning/dsa/output.txt", "w", stdout);
#endif
    ll t = 0;
    cin >> t;
    ll arr[t];
    fo(t)
    {
        cin >> arr[i];
    }
    ll l = 0, r = t - 1;
    ll s = 0, d = 0;
    ll count = 0;
    while (l <= r)
    {
        if (count % 2 == 0)
        {
            if (arr[l] > arr[r])
            {
                s += arr[l];
                l++;
            }
            else
            {
                s += arr[r];
                r--;
            }
            count++;
        }
        else
        {
            if (arr[l] > arr[r])
            {
                d += arr[l];
                l++;
            }
            else
            {
                d += arr[r];
                r--;
            }
            count++;
        }
    }
    cout << s << " " << d;
    on;
}
int main()
{
    fastio;
    solve();

    return 0;
}