#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 10019;

struct Node
{
	int next;
	int len;
	Node(){}
	Node(int n, int l):next(n),len(l){}
	bool operator < (const Node &other) const
	{
		return this->len > other.len;
	}
};

vector<Node> adj[N];


int dist[N];
bool isv[N]; //表示该点是否已经确定最短距离
//在优先队列中, len表示起始点到该点的距离
priority_queue<Node> q;

void dijkstra(int start)
{
	memset(dist, -1, sizeof(dist));
	memset(isv, false, sizeof(isv));
	dist[start] = 0;
	isv[start] = true;
	for(size_t i=0; i<adj[start].size(); ++i)
	{
		int next = adj[start][i].next;
		int len = adj[start][i].len;
		dist[next] = len;
		q.push(Node(next, len));
	}
	while(!q.empty())
	{
		Node tt = q.top();
		q.pop();
		int index = tt.next;
		if(false == isv[index])	//说明该点还没确定最短距离
		{
			isv[index] = true;	//该点正式确定最短距离
			for(size_t i=0; i<adj[index].size(); ++i)
			{
				int next = adj[index][i].next;
				int len = adj[index][i].len;
				if(dist[next]==-1 || dist[next]>dist[index]+len)
				{
					dist[next] = dist[index]+len;
					q.push(Node(next, dist[next]));
				}
			}
		}
	}
}

int main(void)
{
	int i,j,n,m,k,L;
	scanf("%d %d %d %d", &n, &m, &k, &L);

	int t1,t2,t3;
	char str1[5], str2[5];
	for(i=0; i<k; ++i)
	{
		scanf("%s %s %d", str1, str2, &t3);
		if(str1[0]=='G')
			t1 = n+atoi(str1+1);
		else
			t1 = atoi(str1);
		if(str2[0]=='G')
			t2 = n+atoi(str2+1);
		else
			t2 = atoi(str2);

		adj[t1].push_back(Node(t2, t3));
		adj[t2].push_back(Node(t1, t3));
	}

	int ansIndex = -1;
	int ansMin = -1;
	double ansAvg = 0;
	for(i=m; i>=1; --i)
	{
		dijkstra(n+i);
		int state = 0;
		int localMin = 0x7fffffff;
		double localSum = 0;
		for(j=1; j<=n; ++j)
		{
			if(dist[j] > L)
			{
				state = 1;
				break;
			}
			if(dist[j] < localMin)
				localMin = dist[j];
			localSum += dist[j];
		}
		if(state==0)
		{
			double localAvg = localSum / n;
			if(localMin > ansMin)
			{
				ansIndex = i;
				ansMin = localMin;
				ansAvg = localAvg;
			}
			else if(localMin==ansMin && localAvg<ansAvg)
			{
				ansIndex = i;
				ansMin = localMin;
				ansAvg = localAvg;
			}
			else if(localMin==ansMin && localAvg==ansAvg)
			{
				ansIndex = i;
			}
		}
	}
	if(ansIndex==-1)
		printf("No Solution\n");
	else
	{
		printf("G%d\n", ansIndex);
		printf("%.1lf %.1lf\n", ansMin*1.0, ansAvg);
	}

	return 0;
}
