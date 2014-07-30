#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	int flag;
	vector<int> vec;
};

Node data[100009];

double ans = 0;

void helper(int root, double p, double r)
{
	if(data[root].flag==0)	//零售商
	{
		ans += p*data[root].vec[0];
	}
	else
	{
		for(size_t i=0; i<data[root].vec.size(); ++i)
		{
			helper(data[root].vec[i], p*(1+r*0.01), r);
		}
	}
}

int main(void)
{
	int i, j, tt, n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(i=0; i<n; ++i)
	{
		scanf("%d", &tt);
		data[i].flag = tt;
		int t2;
		if(tt > 0)
		{
			for(j=0; j<tt; ++j)
			{
				scanf("%d", &t2);
				data[i].vec.push_back(t2);
			}
		}
		else
		{
			scanf("%d", &t2);
			data[i].vec.push_back(t2);
		}
	}

	ans = 0;

	helper(0, p, r);

	printf("%.1lf\n", ans);

	return 0;
}
