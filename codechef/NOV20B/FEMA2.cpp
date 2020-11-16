#include<bits/stdc++.h>
#include <list>
#include <cmath>
using namespace __gnu_pbds;
using namespace std;

#define fo(n)           for(long long i = 0; i < n; i++)
#define all(v)          v.begin(),v.end() 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
	int S_H[100001]={0};
    w(t)
    {
    	int n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;
    	list <int>I,M;
    	int count=0;
    	fo(n)
    	{
    		if(s[i]==':')
    			count++;
    		S_H[i]=count;
    	}
    	// fo(n)cout<<i<<" "<<S_H[i]<<endl;
    	// cout<<"S ends here"<<endl;
    	int m_c = 0;
    	fo(n)
    	{
    		if(s[i]=='I')
    			I.push_back(i);
    		else if(s[i]=='M')
    			M.push_back(i);
    		else if(s[i]=='X')
    		{
    			I.clear();
    			M.clear();
    		}
    		if(I.size()>0 && M.size()>0)
    		{
    			while(I.size()>0 && M.size()>0)
    			{
    				int p = M.front();
    				int j = I.front();
    				int power = k+1-abs(j-p)-abs(S_H[j]-S_H[p]);
    				// cout<<p<<" "<<j<<" "<<abs(S_H[j]-S_H[p])<<" "<<power<<" "<<M.size()<<" "<<I.size()<<endl;
    				if(power>0)
    				{
    					m_c++;
    					I.pop_front();
    					M.pop_front();
    				}
    				else
    				{
    					if(p>j)
    						I.pop_front();
    					else
    						M.pop_front();
    				}
    			}
    		}
    	}
    	cout<<m_c<<endl;
    }
}