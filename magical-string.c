#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second


int main()
{
	string str;
	cin>>str;
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int l,p,j;
		int n = str.size();
		cin>>l>>p;
		map<string,int> mp;
		for(j=0;j<n;++j)
		{
			if(j+l > n) break;
			string nstr = str.substr(j,l);
			mp[nstr]++;
		}
		//cout<<i<<endl;
		set<string> vt;
		for(map<string,int>::iterator xx = mp.begin(); xx != mp.end(); ++xx)
			if((*xx).se == p) vt.insert((*xx).fi);
		for(j=0;j<n;++j)
		{
			if(j+l > n) break;
			string nstr = str.substr(j,l);
			if(vt.count(nstr))
			{
				printf("%s\n",nstr.c_str());
				vt.erase(nstr);
			}
		}
		printf("\n");
	}
}
