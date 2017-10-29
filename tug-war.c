#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second

int a[202][202];
vi vt[202];
int mark[202], isp;
void isb(int v, int p)
{
	for(auto g : vt[v])
	{
		if(mark[g])
		{
			if(mark[g] == mark[v]) isp = -1;
		}
		else
		{
			mark[g] = mark[v]==1?2:1;
			isb(g,v);
		}
	}
}
int main()
{
	int n,m,i,j,u,v;
	cin>>n>>m;
	for(i=0;i<m;++i)
	{
		cin>>u>>v;
		a[u][v] = a[v][u] = 1;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(i == j or a[i][j]) continue;
			vt[i].push_back(j);
			//cout<<i<<" "<<j<<endl;
		}
	}
	isp = 1;
	mark[1] = 1;
	isb(1,0);
	for(i=1;i<=n;++i)
	{
		if(mark[i]) continue;
		mark[i] = 1;
		isb(i,0);
	}
	if(isp == -1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
