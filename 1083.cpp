#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

struct Node
{
	string name;
	string ID;
	int grade;
};

Node data[109];

inline bool comp(const Node &a, const Node &b)
{
	return a.grade > b.grade;
}

int main(void)
{
	int i,n;
	scanf("%d", &n);
	for(i=0; i<n; ++i)
	{
		cin>>data[i].name>>data[i].ID>>data[i].grade;
	}

	sort(data, data+n, comp);

	int a,b;
	scanf("%d %d",&a, &b);
	int state = 0;
	for(i=0; i<n; ++i)
	{
		if(data[i].grade>=a && data[i].grade<=b)
		{
			state = 1;
			cout<<data[i].name<<" "<<data[i].ID<<endl;
		}
	}

	if(state==0)
		printf("NONE\n");

	return 0;
}
