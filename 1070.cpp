#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1009;

struct Node
{
	double inventory;
	double price;
	bool operator < (const Node &other) const
	{
		return this->price/this->inventory > other.price/other.inventory;
	}
};

Node data[N];

int main(void)
{
	int i,n,d;
	scanf("%d %d", &n,&d);
	for(i=0; i<n; ++i)
		scanf("%lf", &data[i].inventory);
	for(i=0; i<n; ++i)
		scanf("%lf", &data[i].price);

	sort(data, data+n);

	double ans = 0;
	double ret = d;
	for(i=0; i<n; ++i)
	{
		if(ret >= data[i].inventory)
		{
			ans += data[i].price;
			ret -= data[i].inventory;
		}
		else
		{
			ans += ret*(data[i].price/data[i].inventory);
			break;
		}
	}

	printf("%.2lf\n", ans);

	return 0;
}

