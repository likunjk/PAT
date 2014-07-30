#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int hashTable[100009] = {0};

int NextPrime(int k)
{
	if(k==1)
		return 2;

	while(true)
	{
		int state = 0;
		int m = (int)sqrt(k*1.0);
		for(int i=2; i<=m; ++i)
		{
			if(k%i==0)
			{
				state = 1;
				break;
			}
		}
		if(state==0)
			break;
		++k;
	}
	return k;
}

int main(void)
{
	int i, j, n, size;
	scanf("%d %d", &size, &n);
	size = NextPrime(size);

	int tt;
	scanf("%d", &tt);	//对第一个单独处理
	hashTable[tt%size] = 1;
	printf("%d", tt%size);

	for(i=1; i<n; ++i)
	{
		scanf("%d", &tt);
		int addr = tt%size;
		for(j=0; j<size; ++j)
		{
			addr = (tt+j*j)%size;
			if(hashTable[addr]==0)
			{
				hashTable[addr] = 1;
				break;
			}
		}
		if(j==size)
			addr = -1;

		if(addr==-1)
			printf(" -", addr);
		else
			printf(" %d", addr);
	}

	printf("\n");

	return 0;
}

