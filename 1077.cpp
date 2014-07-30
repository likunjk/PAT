#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

string str[109];

string helper(string &s1, string &s2)
{
	int n = s1.length();
	int m = s2.length();
	int i,j;
	for(i=n-1,j=m-1; i>=0 && j>=0; --i,--j)
	{
		if(s1[i]!=s2[j])
			break;
	}
	return s1.substr(i+1);
}

int main(void)
{
	int i,n;
	scanf("%d", &n);
	getchar();

	for(i=0; i<n; ++i)
	{
		getline(cin, str[i]);
	}
	if(n==1)
		cout<<str[0];
	else
	{
		string ans = helper(str[0], str[1]);
		for(i=2; i<n; ++i)
			ans = helper(str[i], ans);
		if(ans.length()==0)
			printf("nai");
		else
			cout<<ans;
	}
	return 0;
}
