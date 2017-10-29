
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define MAX 100005
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mt make_tuple
#define eb emplace_back
#define INF 1e9
#define PI 3.141592653589793238
#define EPS 1e-9
#define pii pair<int,int>
#define BLOCK 555
ll modexp(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res = (res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}

int lp[MAX], phi[MAX];
void sieve()
{
	int i,j;
	for(i=1;i<MAX;++i)
	{
		for(j=i;j<MAX;j+=i)
		{
			//phi[j]/=i;
			//phi[j]*=(i-1);
			phi[j]++;
			lp[j] = 1;
		}
	}
	//for(i=1;i<=10;++i)
	//    cout<<phi[i]<<endl;
}


int a[MAX], b[MAX], as, sol[MAX];
vector<pair<pii,int>> vt;
bool cmp(pair<pii,int> pa, pair<pii,int> pb)
{
	if(pa.fi.se/BLOCK != pb.fi.se/BLOCK) return pa.fi.se/BLOCK < pb.fi.se/BLOCK;
	if(pa.fi.fi != pb.fi.fi) return pa.fi.fi < pb.fi.fi;
	return pa.fi.se < pb.fi.se;
}
ll cnt,  mark[MAX];
void add(int i)
{
	cnt -= mark[a[i]]*(mark[a[i]]-1)/2;
	mark[a[i]]++;
	cnt += mark[a[i]]*(mark[a[i]]-1)/2;

}
void del(int i)
{
	cnt -= mark[a[i]]*(mark[a[i]]-1)/2;
	mark[a[i]]--;
	cnt += mark[a[i]]*(mark[a[i]]-1)/2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int n,i;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		a[i] = phi[a[i]];
	}
	int q;
	cin>>q;
	for(i=0;i<q;++i)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		vt.eb(mk(mk(l,r),i));
	}
	sort(vt.begin(), vt.end(), cmp);

	int cl,cr,left,right,ai;
	int pb = -1;
	cr = -1;
	cl = 0;
	for(auto xx : vt)
	{
		left = xx.fi.fi;
		right = xx.fi.se;
		ai = xx.se;
		while(cr < right)
		{
			++cr;
			add(cr);
		}
		while(cr > right)
		{
			del(cr);
			cr--;
		}
		while(cl < left)
		{
			del(cl);
			cl++;
		}
		while(cl > left)
		{
			cl--;
			add(cl);
		}
		sol[ai] = cnt;
	}
	for(i=0;i<q;++i)
		cout<<sol[i]<<endl;
	return 0;
}
