#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

vector<int> dp;
int weight[1009];
int ans[1009];

int main(void)
{
	int i,n,k;
	int tt;

	scanf("%d %d", &n,&k);
	for(i=0; i<n; ++i)
		scanf("%d", &weight[i]);
	dp.reserve(n+9);
	for(i=0; i<n; ++i)
	{
		scanf("%d", &tt);
		dp.push_back(tt);
	}
	while(true)
	{
		int Rank = dp.size()/k;
		if(Rank*k < dp.size())
			Rank++;

		int count = 0;
		int maxWeight = -1;
		int maxIndex = -1;

		vector<int> tmp;
		tmp.reserve(n);

		for(i=0; i<dp.size(); ++i)
		{
			ans[dp[i]] = Rank+1;
			count++;
			if(weight[dp[i]] > maxWeight)
			{
				maxWeight = weight[dp[i]];
				maxIndex = dp[i];
			}
			if(count==k)
			{
				tmp.push_back(maxIndex);
				count = 0;
				maxWeight = -1;
				maxIndex = -1;
			}
		}
		if(count > 0)	//处理不足k个的情况
			tmp.push_back(maxIndex);
		if(dp.size() <= k)
		{
			ans[tmp[0]] = 1;	//处理第一名的情况
			break;
		}
		else
		{
			dp = tmp;
		}
	}

	printf("%d", ans[0]);
	for(i=1; i<n; ++i)
		printf(" %d", ans[i]);

	return 0;
}
