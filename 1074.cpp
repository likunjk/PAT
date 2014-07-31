#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	int id;
	int val;
	int next;
	Node():id(-1){}
};

Node data[100009];
vector<Node> ans, dp;

int main(void)
{
	int i,n,k;
	int addr;
	scanf("%d %d %d", &addr, &n, &k);
	
	int t1,t2,t3;
	for(i=0; i<n; ++i)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		data[t1].id = t1;
		data[t1].val = t2;
		data[t1].next = t3;
	}

	ans.reserve(n);
	dp.reserve(k);

	while(addr!=-1)
	{
		dp.push_back(data[addr]);
		addr = data[addr].next;
		if(data[addr].id==-1)	//有可能其指向的点根本不存在
			addr = -1;

		if(dp.size()==k)
		{
			//此处j不能是size_t类型，那样就无法减为负数
			for(int j=dp.size()-1; j>=0; --j)
				ans.push_back(dp[j]);
			dp.clear();
			dp.reserve(k);
		}
	}
	if(dp.size() > 0)
	{
		//后面不足k个的就不需要反转
		for(int j=0; j<dp.size(); ++j)
			ans.push_back(dp[j]);
	}

	//输出结果
	int size = ans.size();
	for(i=0; i<size-1; ++i)
		printf("%05d %d %05d\n", ans[i].id, ans[i].val, ans[i+1].id);
	printf("%05d %d -1\n", ans[size-1].id, ans[size-1].val);

	return 0;
}

