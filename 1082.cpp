#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

//Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
string unit[9] = {"Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi",""};
string digit[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char str[19];
vector<string> ans;

void outPut(void)
{
	//输出结果
	for(size_t i=0; i<ans.size(); ++i)
	{
		//连续"ling"只输出一个
		if(i+1<ans.size() && ans[i]=="ling" && ans[i+1]=="ling")
			continue;
		if(i+1<ans.size() && ans[i]=="ling" && ans[i+1]=="Wan")
			continue;
		if(i==0)
			cout<<ans[i];
		else
			cout<<" "<<ans[i];
	}
	cout<<endl;
}

int main(void)
{
	while(scanf("%s", str)!=EOF)
	{
		ans.clear();
		int i = 0;
		int len = strlen(str);
		//处理符号位
		if(str[0]=='-')
		{
			++i;
			--len;
			ans.push_back("Fu");
		}
		//去掉前导0,至少保留一位
		while(str[i]=='0' && str[i+1]!='\0')
		{
			++i;
			--len;
		}
		//对0特殊处理
		if(len==1 && str[i]=='0')
		{
			ans.push_back(digit[0]);
			outPut();
			continue;
		}
		int k = 9-len;
		for( ; str[i]!='\0'; ++i, ++k)
		{
			int tt = str[i]-'0';
			
			if(tt!=0)
			{
				ans.push_back(digit[tt]);
				ans.push_back(unit[k]);
			}
			else
			{
				if(unit[k]=="Wan")	//当前位是万位，但是值等于0
				{ 
					int state = 0;
					//X0000XXXX像这种"Wan"就不该加进去
					for(size_t j=ans.size()-1; j>=0; --j)
					{
						if(ans[j]=="Yi")
							break;
						if(ans[j]!="ling")
						{
							state = 1;
							break;
						}
					}
					if(state==1)
						ans.push_back(unit[k]);
				}
				else
				{
					ans.push_back(digit[tt]);
				}
			}
		}
		//去掉末尾的""和"ling"
		size_t size = ans.size();
		while(ans[size-1]=="" || ans[size-1]=="ling")
		{
			ans.pop_back();
			size = ans.size();
		}

		outPut();
	}

	return 0;
}
