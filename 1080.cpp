#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct SchoolNode
{
	int quota;
	vector<int> ans;
};

struct StudentNode
{
	int sno;
	int GE;
	int GI;
	int sum;
	vector<int> choice;
};

inline bool comp(const StudentNode &a, const StudentNode &b)
{
	if(a.sum==b.sum)
		return a.GE > b.GE;
	else
		return a.sum > b.sum;
}

StudentNode student[400009];
SchoolNode  school[109];

int main(void)
{
	int i,j,n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0; i<m; ++i)
	{
		scanf("%d", &school[i].quota);
	}
	for(i=0; i<n; ++i)
	{
		scanf("%d %d", &student[i].GE, &student[i].GI);
		student[i].sno = i;
		student[i].sum = student[i].GE+student[i].GI;
		int tt;
		for(j=0; j<k; ++j)
		{
			scanf("%d",&tt);
			student[i].choice.push_back(tt);
		}
	}
	sort(student, student+n, comp);

	for(i=0; i<n; ++i)
	{
		for(j=0; j<k; ++j)
		{
			int like = student[i].choice[j];
			if(school[like].quota > 0)
			{
				school[like].quota--;
				school[like].ans.push_back(i);
				break;
			}
			else
			{
				size_t size = school[like].ans.size();
				if(size > 0)	//这里必须要该学校有招生名额，前面已经招过学生
				{
					int tt = school[like].ans[size-1];
					//说明前面一个录取的学生成绩跟我的一样，那么我也要被录取
					if(student[tt].sum==student[i].sum && student[tt].GE==student[i].GE)
					{
						school[like].ans.push_back(i);
						break;
					}
				}
			}
		}
	}

	for(i=0; i<m; ++i)
	{
		for(j=0; j<school[i].ans.size(); ++j)
			school[i].ans[j] = student[school[i].ans[j]].sno;

		sort(school[i].ans.begin(), school[i].ans.end());
		if(school[i].ans.size() > 0)
		{
			printf("%d", school[i].ans[0]);
			for(j=1; j<school[i].ans.size(); ++j)
				printf(" %d",school[i].ans[j]);
		}
		printf("\n");
	}

	return 0;
}
