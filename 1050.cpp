#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int N = 10009;

char str1[N];
char str2[N];

int main(void)
{
	gets(str1);
	gets(str2);

	int flag[256];
	memset(flag, 0, sizeof(flag));

	for(int i=0; str2[i]!=0; ++i)
		flag[str2[i]] = 1;

	for(int i=0; str1[i]!=0; ++i)
	{
		if(flag[str1[i]]==1)
			continue;
		else
			printf("%c", str1[i]);
	}

	return 0;
}
