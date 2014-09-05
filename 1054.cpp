#include<iostream>
#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;

const int N = 1000;

int main(void)
{
	int i,j,n,m;
	scanf("%d %d", &n,&m);

	int tt;
	int count = 0;
	int value;
	for(i=0; i<n; ++i)
	{
		for(j=0; j<m; ++j)
		{
			scanf("%d", &tt);
			if(count==0)
			{
				count = 1;
				value = tt;
			}
			else
			{
				if(tt==value)
					count++;
				else
					count--;
			}
		}
	}

	printf("%d\n", value);

	return 0;
}

