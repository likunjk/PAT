#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

const int N = 1100000;

char pstr[N];
unordered_map<string, int> ump;
string str;

int main(void)
{
	int i;

	gets(pstr);
	str = string(pstr);

	int begin = 0;
	for(i=0; pstr[i]!=0; ++i)
	{
		if(str[i]>='A' && str[i]<='Z')
		{
			str[i] = 'a'+(str[i]-'A');
			continue;
		}
		else if(str[i]>='a' && str[i]<='z')
			continue;
		else if(str[i]>='0' && str[i]<='9')
			continue;
		else
		{
			if(i>begin)
			{
				string s = str.substr(begin, i-begin);
				ump[s]++;
			}
			begin = i+1;
		}
	}
	if(i+1 > begin)
	{
		string s = str.substr(begin, i-begin);
		ump[s]++;
	}

	int ansMax = 0;
	string res;
	for(unordered_map<string,int>::iterator it = ump.begin(); it!=ump.end(); ++it)
	{
		if(it->second > ansMax)
		{
			ansMax = it->second;
			res = it->first;
		}
	}

	cout<<res<<" "<<ansMax<<endl;

	return 0;
}
