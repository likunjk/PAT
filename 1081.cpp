#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	long long a,b;
	Node(){}
	Node(long long _a, long long _b):a(_a),b(_b){}
};

Node data[109];

long long GCD(long long a, long long b)
{
	while(b!=0)	//此处不能是b!=0,比如例子a=4 ,b=2
	{
		long long tt = a;
		a = b;
		b = tt%b;
	}
	return a;
}

void helper(int i, int j, int k)
{
	long long a1 = data[i].a*data[j].b + data[j].a*data[i].b;
	long long b1 = data[i].b*data[j].b;
	long long com = GCD(abs(a1), abs(b1));
	a1 /= com;
	b1 /= com;
	data[k].a = a1;
	data[k].b = b1;
}

void outPut(int k)
{
	long long com = GCD(abs(data[k].a), abs(data[k].b));
	data[k].a /= com;
	data[k].b /= com;

	if(data[k].a==0)
	{
		printf("0\n");
		return;
	}

	int flag = 0;
	if(data[k].a < 0)	//处理符号
	{
		flag = 1;
		data[k].a = -data[k].a;
	}
	if(data[k].a % data[k].b == 0)	//能够整除
	{
		if(flag==1)
			printf("-");
		printf("%lld\n", data[k].a);
		return;
	}
	if(data[k].a < data[k].b)
	{
		if(flag==1)
			printf("-");
		printf("%lld/%lld\n", data[k].a,data[k].b);
	}
	else
	{
		printf("%lld ",data[k].a/data[k].b);
		data[k].a %= data[k].b;
		if(flag==1)
			printf("-");
		printf("%lld/%lld\n", data[k].a,data[k].b);
	}
}

int main(void)
{
	int i,n;
	long long a,b;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<n; ++i)
		{
			scanf("%lld/%lld", &a, &b);
			data[i] = Node(a,b);
		}
		if(n==1)
			outPut(0);
		else
		{
			helper(0,1,n);
			for(i=2; i<n; ++i)
				helper(i,n,n);
			outPut(n);
		}
	}

	return 0;
}
