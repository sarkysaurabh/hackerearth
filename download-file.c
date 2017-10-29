#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000006
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second

ll a[MAX], og[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,s,i,t,d,pt,pd;
	cin>>n>>s;
	for(i=0;i<n;++i)
	{
		cin>>t>>d;
		if(!i)
		{
			pt = t;
			pd = d;
			continue;
		}
		while(pt<t)
		{
			a[pt++] = pd;
			og[pt-1] = pd;
		}
		pd = d;
	}
	while(pt<MAX)
	{
		a[pt++] = pd;
		og[pt-1] = pd;
	}
	for(i=1;i<MAX;++i)
		a[i] += a[i-1];
	ll x,mn,md,cn,cd,l,r,mid,ans;
	mn = INF;
	md = 1;
	for(i=0;i<MAX;++i)
	{
		l = i;
		r = MAX;
		ans = -1;
		while(l <= r)
		{
			mid = (l+r)>>1;
			x = a[mid] - (i>0?a[i-1]:0);
			if(x>=s)
			{
				r = mid-1;
				ans = mid;
			}
			else
			{
				l = mid+1;
			}
		}
		if(ans == -1) continue;
		cn = (ans-i)*og[ans] + (s-(x-og[ans]));
		cd = og[ans];

		if(cn*md < mn*cd)
		{
			mn = cn;
			md = cd;
		}
	}
	x = __gcd(mn,md);
	mn /= x;
	md /= x;
	cout<<mn<<"/"<<md<<endl;
}
