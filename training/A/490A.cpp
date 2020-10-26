/*
***********************
******* sadn1ck *******
******** IIEST ********
***********************
*/
#include "bits/stdc++.h"

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

void printTeams(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
    cout << p1.first << " " << p2.first << " " << p3.first;
    on;
}
void solve()
{
#ifndef ONLINE_JUDGE
    freopen("/home/anik/projects/learning/dsa/input.txt", "r", stdin);
    freopen("/home/anik/projects/learning/dsa/output.txt", "w", stdout);
#endif
    ll t = 0;
    cin >> t;
    ll c1 = 0, c2 = 0, c3 = 0;
    stack<pair<ll, ll>> s1, s2, s3;
    fo(t)
    {
        ll temp = 0;
        cin >> temp;
        if (temp == 1)
        {
            c1++;
            s1.push({i + 1, 1});
        }
        if (temp == 2)
        {
            c2++;
            s2.push({i + 1, 2});
        }
        if (temp == 3)
        {
            c3++;
            s3.push({i + 1, 3});
        }
    }
    ll teams = min(c1, min(c2, c3));
    cout << teams;
    on;
    fo(teams)
    {
        printTeams(s1.top(), s2.top(), s3.top());
        s1.pop(), s2.pop(), s3.pop();
    }
}
int main()
{
    fastio;
    solve();

    return 0;
}