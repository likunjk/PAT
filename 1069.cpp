#include<iostream>
#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;

void help(char *tt, char *str)
{
	int i;
	int len = strlen(tt);
	for(i=0; i<4-len; ++i)
		str[i] = '0';
	for(i=0; i<len; ++i)
		str[4-len+i] = tt[i];
	str[4] = '\0';
}

int helper(char *str)
{
	int ans = 0;
	for(int i=0; i<4; ++i)
	{
		ans = ans*10 + (str[i]-'0');
	}
	return ans;
}

inline bool comp(char a, char b)
{
	return a > b;
}

int main(void)
{
	char tt[9];
	char str[9];
	scanf("%s", tt);

	help(tt, str);

	if(str[0]==str[1] && str[2]==str[3] && str[0]==str[2])
	{
		printf("%s - %s = 0000\n", str, str);
	}
	else
	{
		while(true)
		{
			sort(str, str+4, comp);
			int t1 = helper(str);
			printf("%s", str);

			sort(str, str+4);
			int t2 = helper(str);
			printf(" - %s = ", str);

			int t3 =  t1 - t2;
			printf("%04d\n", t3);
			
			if(t3==6174)
				break;

			char tmp[9];
			sprintf(tmp, "%04d", t3);
			help(tmp, str);
		}
	}

	return 0;
}

