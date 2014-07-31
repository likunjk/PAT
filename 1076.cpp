#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> data[1009];
int isv[1009];

struct Node
{
	int root;
	int level;
	Node(int r, int l):root(r),level(l){}
};
queue<Node> qu;

int helper(int root, int L)
{
	int ans = 0;
	memset(isv, 0, sizeof(isv));
	isv[root] = 1;
	qu.push(Node(root,0));
	while(!qu.empty())
	{
		Node tt = qu.front();
		qu.pop();
		if(tt.level>=L)
			continue;

		root = tt.root;
		for(size_t i=0; i<data[root].size(); ++i)
		{
			if(isv[data[root][i]]==0)
			{
				ans++;
				isv[data[root][i]] = 1;
				qu.push(Node(data[root][i], tt.level+1));
			}
		}
	}

	return ans;
}

int main(void)
{
	int N,L;
	int i,j,t1,t2;
	scanf("%d %d",&N,&L);
	for(i=1; i<=N; ++i)
	{
		scanf("%d", &t1);
		for(j=0; j<t1; ++j)
		{
			scanf("%d", &t2);
			data[t2].push_back(i);
		}
	}
	scanf("%d", &t1);
	for(i=0; i<t1; ++i)
	{
		scanf("%d", &t2);
		printf("%d\n", helper(t2, L));
	}

	return 0;
}
