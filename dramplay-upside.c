#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second

int dp[5001][5001];
int main()
{
	string str;
	int i,j,n,len;
	cin>>str;
	n=str.size();
	for(i=0;i<n;++i)
		dp[i][i] = 0;
	for(i=0;i<n-1;++i)
		dp[i][i+1] = str[i]==str[i+1]?0:1;
	for(len=3;len<=n;++len)
	{
		for(i=0;i<n;++i)
		{
			j=i+len-1;
			if(j>=n) break;
			dp[i][j] = dp[i+1][j-1] + !(str[i]==str[j]);
		}
	}
	int ans = n;
	for(i=0;i<=n;++i)
	{
		ans = min(ans, i+dp[i][n-1]);
	}
	cout<<ans<<endl;
}
