#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int N = 100009;

struct Node
{
	int addr;
	int val;
	int next;
};

inline bool comp(const Node &a, const Node &b)
{
	return a.val < b.val;
}

Node data[N];
vector<Node> dp;
unordered_map<int,int> ump;

int main(void)
{
	int i,n,start;

	scanf("%d %d", &n, &start);
	for(i=0; i<n; ++i)
	{
		scanf("%d %d %d", &data[i].addr, &data[i].val, &data[i].next);
		ump[data[i].addr] = i;
	}
	if(start==-1)
	{
		printf("0 -1\n");
		return 0;
	}

	dp.reserve(n);

	while(true)
	{
		int index = ump[start];
		dp.push_back(data[index]);
		start = data[index].next;
		if(start==-1)
			break;
	}

	sort(dp.begin(), dp.end(), comp);

	printf("%d %05d\n", dp.size(), dp[0].addr);
	for(i=0; i+1<dp.size(); ++i)
		printf("%05d %d %05d\n", dp[i].addr, dp[i].val, dp[i+1].addr);
	printf("%05d %d -1\n", dp[i].addr, dp[i].val);
	
	return 0;
}
