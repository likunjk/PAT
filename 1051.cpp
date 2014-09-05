#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int N = 1009;

int main(void)
{
	int i,n,m,k,tt;

	scanf("%d %d %d", &m, &n, &k);

	while(k--)
	{
		stack<int> st;
		st.push(1);
		int cur = 1;
		int state = 0;
		for(i=0; i<n; ++i)
		{
			scanf("%d", &tt);
			if(tt > cur)
			{
				for(int j=cur+1; j<=tt; ++j)
					st.push(j);
				cur = tt;
				if(st.size() > m)
					state = 1;
				st.pop();
			}
			else
			{
				if(tt != st.top())
					state = 1;
				else
					st.pop();
			}
		}
		if(state==1)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
