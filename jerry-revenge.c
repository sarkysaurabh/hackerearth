#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second


int a[501][501];
int main()
{
	int n,m,i,j,k,ni,nj;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			cin>>a[i][j];
			a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
		}
	int cur,mx;
	mx = -1;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			for(k=1;;++k)
			{
				ni = i+k-1;
				nj = j+k-1;
				if(ni > n or nj > m) break;
				cur = a[ni][nj] - a[ni][j-1] - a[i-1][nj] + a[i-1][j-1];
				cur = (k*k - cur) - cur;
				mx = cur>mx?cur:mx;
			}
		}
	}
	cout<<a[n][m]+mx<<endl;
}
