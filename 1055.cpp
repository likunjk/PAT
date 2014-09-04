#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

struct Node
{
	string name;
	int age;
	int worth;
};

inline bool comp(const Node &a, const Node &b)
{
	if(a.worth==b.worth)
	{
		if(a.age==b.age)
			return a.name < b.name;
		else
			return a.age < b.age;
	}
	else
	{
		return a.worth > b.worth;
	}
}

Node data[100009];
int ageCount[209];
int dp[100009];

int main(void)
{
	int i,n,k;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; ++i)
	{
		cin>>data[i].name;
		scanf("%d %d", &data[i].age, &data[i].worth);
	}
	sort(data, data+n, comp);
	int valid = 0;
	for(i=0; i<n; ++i)
	{
		if(ageCount[data[i].age] < 101)
		{
			ageCount[data[i].age]++;
			dp[valid++] = i;
		}
	}

	int m, localMin, localMax;
	for(int j=1; j<=k; ++j)
	{
		scanf("%d %d %d", &m, &localMin, &localMax);
		printf("Case #%d:\n", j);
		int count = 0;
		for(i=0; i<valid && count<m; ++i)
		{
			if(data[dp[i]].age>=localMin && data[dp[i]].age<=localMax)
			{
				count++;
				cout<<data[dp[i]].name;
				printf(" %d %d\n", data[dp[i]].age, data[dp[i]].worth);
			}
		}
		if(count==0)
			printf("None\n");
	}


	return 0;
}
