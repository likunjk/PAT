#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

#define MAX_N 2099

struct node
{
	string name;
	int number;
};

inline int comp(const node &a, const node &b)
{
	return a.name < b.name;
}

int index = 0;
int pre[MAX_N];
int sum_each[MAX_N] = {0};
int sum_pre[MAX_N] = {0};
map<string,int> mp;
vector<string> i2s;
vector<int> gather[MAX_N];
vector<node> ans;

int find(int x)
{
	if(x == pre[x])
		return x;
	else
		return pre[x] = find(pre[x]);
}

void string2int(const string &str1, const string &str2, int time)
{
	int name1 = 0;
	int name2 = 0;
	if(mp.find(str1)==mp.end())
	{
		mp[str1] = index;
		name1 = index;
		i2s.push_back(str1);
		index++;
	}
	else
	{
		name1 = mp[str1];
	}
	if(mp.find(str2)==mp.end())
	{
		mp[str2] = index;
		name2 = index;
		i2s.push_back(str2);
		index++;
	}
	else
	{
		name2 = mp[str2];
	}
	sum_each[name1] += time;
	sum_each[name2] += time;

	pre[find(name2)] = find(name1);
}


int main(void)
{
	int i,j;
	int N,K;
	string str1,str2;
	int time;

	for(i=0;i<MAX_N;i++)
		pre[i] = i;

	scanf("%d %d",&N,&K);
	for(i=1;i<=N;i++)
	{
		cin>>str1>>str2;
		scanf("%d",&time);
		string2int(str1,str2,time);
	}

	set<int> s;
	for(i=0;i<index;i++)
	{
		pre[i] = find(i);
		s.insert(pre[i]);
		sum_pre[pre[i]] += sum_each[i];
		gather[pre[i]].push_back(i);
	}

	for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
	{
		int gang = *it;
		if(gather[gang].size() > 2 && sum_pre[gang] > 2*K)
		{
			int mmax = 0;
			int head = 0;
			for(j=0;j<gather[gang].size();j++)
			{
				if(mmax < sum_each[gather[gang][j]])
				{
					mmax = sum_each[gather[gang][j]];
					head = gather[gang][j];
				}
			}
			node tt;
			tt.name = i2s[head];
			tt.number = gather[gang].size();
			ans.push_back(tt);
		}
	}

	sort(ans.begin(), ans.end(), comp);
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i].name<<" "<<ans[i].number<<endl;
	}

	return 0;
}
