#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000006
#define INF 1e9
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second

int bitl[MAX], bitr[MAX];
void upd(int *bit, int i, int v)
{
	while(i < MAX)
	{
		bit[i] += v;
		i += i&-i;
	}
}
int que(int *bit, int i)
{
	int s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= i&-i;
	}
	return s;
}
int main()
{
	int t;
	cin>>t;
	for(int _i = 1; _i<=t; ++_i)
	{
		cout<<"Case "<<_i<<":"<<endl;
		int n,i,x;
		cin>>n;
		set<int> st;
		for(i=1;i<=n;++i)
		{
			cin>>x;
			st.insert(x);
		}
		multiset<int> mt;
		vector<int> vt;
		set<int> sst[MAX];
		for(auto xx : st)
			vt.push_back(xx);
		for(i=1;i<n;++i)
		{
			mt.insert(vt[i]-vt[i-1]);
			sst[vt[i]-vt[i-1]].insert(vt[i-1]);
		}
		int q;
		cin>>q;
		while(q--)
		{
			int typ;
			cin>>typ;
			if(typ == 1)
			{
				//enter
				cin>>x;
				st.insert(x);
				auto it = st.find(x);
				if(it == st.begin())
				{
					//cout<<"case1"<<endl;
					mt.insert(*(++it) - x);
					sst[*it-x].insert(x);
				}
				else if(++it == st.end())
				{
					//cout<<"case2"<<endl;
					--it;
					mt.insert(x - *(--it));
					sst[x-*it].insert(*it);
				}
				else
				{
					--it;
					//cout<<"case3"<<endl;
					auto pi = --it; 
					it++;
					auto ni = ++it; 
					it--;
					//cout<<"pi="<<*pi<<" ni="<<*ni<<endl;
					mt.erase(mt.find(*ni - *pi));
					sst[*ni - *pi].erase(*pi);

					mt.insert(x-*pi);
					sst[x - *pi].insert(*pi);
					
					mt.insert(*ni - x);
					sst[*ni - x].insert(x);
				}
			}
			else if(typ == 2)
			{
				//output ans
				int val = *(--mt.end());
				cout<<val<<" ";
				x = *(--sst[val].end());
				int y = *st.upper_bound(x);
				cout<<x<<" "<<y<<endl;
			}
			else
			{
				//leave
				cin>>x;
				auto it = st.find(x);
				if(it == st.begin())
				{
					mt.erase(mt.find(*(++it) - x));
					sst[*it-x].erase(x);
				}
				else if(++it == st.end())
				{
					--it;
					mt.erase(mt.find(x - *(--it)));
					sst[x-*it].erase(*it);
				}
				else
				{
					--it;
					auto pi = --it; it++;
					auto ni = ++it; it--;
					mt.insert(*ni - *pi);
					sst[*ni - *pi].insert(*pi);

					mt.erase(mt.find(x-*pi));
					sst[x - *pi].erase(*pi);
					
					mt.erase(mt.find(*ni - x));
					sst[*ni - x].erase(x);
				}
				st.erase(x);
			}
		}
	}
}
