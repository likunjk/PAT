#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;



int main(void)
{
	char str[20009];

	scanf("%s", str);
	if(str[0]=='-')
		printf("-");

	int i;
	for(i=1; ; ++i)
	{
		if(str[i]=='E')
			break;
	}
	int Pos = i;
	//利用库函数将字符串转化为整数
	int E = atoi(str+i+1);
	if(E < 0)
	{
		printf("0.");
		for(i=1; i<-E; ++i)
			printf("0");
		printf("%c", str[1]);
		for(i=3; i<Pos; ++i)
			printf("%c", str[i]);
	}
	else if(E > 0)
	{
		printf("%c", str[1]);
		if(E >= Pos-3)
		{
			for(i=3; i<Pos; ++i)
				printf("%c", str[i]);
			for(i=0; i<E-(Pos-3); ++i)
				printf("0");
		}
		else
		{
			int j=0;
			for(i=3; i<Pos && j<E; ++i, ++j)
				printf("%c", str[i]);
			printf(".");
			for( ; i<Pos; ++i)
				printf("%c", str[i]);
		}
	}
	else
	{
		for(i=1; i<Pos; ++i)
			printf("%c", str[i]);
	}


	return 0;
}

