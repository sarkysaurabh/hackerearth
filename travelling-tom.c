#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define MAX 100005
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
__int128 c[MAX];
int k, n;
vector<pair<int,pii>> edg;
int par[MAX];
int findset(int i)
{
	while(i != par[i])
	{
		par[i] = par[par[i]];
		i = par[i];
	}
	return i;
}
bool ck(int x)
{
	int i,j,u,v,pu,pv;
	for(i=1;i<=n;++i)
		par[i] = i;
	for(i=0;i<edg.size();++i)
	{
		if(edg[i].fi>x) continue;
		pu = findset(edg[i].se.fi);
		pv = findset(edg[i].se.se);
		if(pu == pv) continue;
		par[pu] = pv;
	}
	pv = findset(1);
	for(i=2;i<=n;++i)
	{
		pu = findset(i);
		if(pu != pv) return 0;
	}
	return 1;
}
int main()
{
	int m,i,j,u,v,x,w,mw;
	cin>>n>>m>>k;
	for(i=1;i<=k;++i)
	{
		ll val;
		cin>>val;
		c[i] = val;
		c[i]+=c[i-1];
	}
	for(i=0;i<m;++i)
	{
		cin>>u>>v>>x;
		mw = 0;
		while(x--)
		{
			cin>>w;
			mw = w>mw?w:mw;
		}
		edg.pb({mw,{u,v}});
	}
	int l,r,mid,ans;
	ans=-1;
	l=0;
	r=k;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(ck(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else 
			l=mid+1;
	}
	if(ans == -1) cout<<ans<<endl;
	else
	{
		__int128 val = c[ans];
		if(val == 0)
		{
			cout<<0<<endl;
			return 0;
		}
		string str;
		while(val > 0)
		{
			char ch = '0'+val%10;
			str = ch + str;
			val/=10;
		}
		cout<<str<<endl;
	}
}
