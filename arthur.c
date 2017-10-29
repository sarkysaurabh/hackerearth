#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second

int v[20], vis[20], k, n;
vi vt[20];
void dfs(int x, int p)
{
	vis[x] = 0;
	for(auto g : vt[x])
	{
		if(g == p) continue;
		dfs(g,x);
	}
}
vector<pair<int,int>> ed;
int ck()
{
	memset(vis,0,sizeof vis);
	int i;
	set<int> st;
	for(i=1;i<=n;++i)
		if(vt[i].size())
		{
			vis[i] = 1;
			//cout<<"insert "<<v[i]<<endl;
			st.insert(v[i]);
		}
	for(i=1;i<=n;++i)
		if(vis[i])
		{
			dfs(i,0);
			break;
		}
	for(i=1;i<=n;++i)
		if(vis[i]) return 0;
	
	return st.size();
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int cnt = 0;
		int i,j,u,x;
		ed.clear();
		cin>>n>>k;
		for(i=1;i<=n;++i)
			cin>>v[i];

		for(i=1;i<n;++i)
		{
			cin>>u>>x;
			ed.push_back({u,x});
		}
		int lim = 1<<(n-1);
		for(i=1;i<lim;++i)
		{
			for(j=0;j<n;++j)
				vt[j].clear();
			//cout<<"i="<<i<<" ";
			for(j=0;j<n-1;++j)
			{
				if(i&(1<<j)) 
				{
					u = ed[j].fi;
					x = ed[j].se;
					//cout<<"u: "<<u<<" x: "<<x<<endl;
					vt[u].push_back(x);
					vt[x].push_back(u);
				}
			}
			int p = ck();
			cout<<p<<endl;
			cnt += p;
			//if(p) cout<<"cnt: "<<cnt<<endl;
		}
		cout<<cnt<<endl;
	}
}
