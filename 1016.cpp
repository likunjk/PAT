#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int rate[29];

struct node
{
	string name;
	int month;
	int day;
	int hour;
	int minute;
	int state;
	int time;
};
inline bool comp (const node &a, const node &b)
{
	if(a.name==b.name)
		return a.time < b.time;
	else
		return a.name < b.name;
}
node data[1009];

double calc(int h1,int m1,int h2,int m2)
{
	double ans = 0;
	while(h1*60+m1<h2*60+m2)
	{
		ans += rate[h1];
		m1 += 1;
		if(m1>=60)
		{
			h1++;
			m1 = 0;
		}
	}
	return ans;	
}
double calc2(int d1,int h1,int m1,int d2,int h2,int m2)
{
	double ans = 0;
	while(d1*24*60+h1*60+m1 < d2*24*60+h2*60+m2)
	{
		ans += rate[h1];
		m1 += 1;
		if(m1>=60)
		{
			h1++;
			m1 = 0;
			if(h1>=24)
			{
				d1++;
				h1 = 0;
			}
		}
	}
	return ans;	
}

int main(void)
{
	int i,j,n;
	string str;
	for(i=0;i<24;i++)
	{
		scanf("%d",&rate[i]);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>data[i].name;
		scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
		cin>>str;
		if(str=="on-line")
			data[i].state = 0;
		else
			data[i].state = 1;
		data[i].time = data[i].day*24*60+data[i].hour*60+data[i].minute;
	}
	sort(data,data+n,comp);
	int newuser = 0;
	string username="12345678901234567890123";
	double money = 0;
	double all = 0;
	for(i=0;i<n;i++)
	{
		money = 0;
		if(data[i].name!=username)
		{
			if(all!=0)
			{
				printf("Total amount: $%.2lf\n",all/100);
			}
			username = data[i].name;
			newuser = 1;
			all = 0;
		}
		if(data[i].state==0)
		{
			j = i+1;
			if(j<n && data[j].name==data[i].name && data[j].state==1)
			{
				if(newuser==1)
				{
					newuser = 0;
					cout<<username;
					printf(" %02d\n",data[i].month);
				}
				int tmp = 0;
				if(data[j].time - data[i].time >= 24*60)
				{
					tmp = (data[j].time-data[i].time)/(24*60);
					for(int k=0;k<24;k++)
						money += tmp*rate[k]*60;
					data[j].day -= tmp;
				}
				if(data[i].day == data[j].day)	//在当天
					money += calc(data[i].hour,data[i].minute,data[j].hour,data[j].minute);
				else	//隔一天
				{
					money += calc(data[i].hour,data[i].minute,24,0);
					money += calc(0,0,data[j].hour,data[j].minute);
				}
//				money += calc2(data[i].day,data[i].hour,data[i].minute,data[j].day,data[j].hour,data[j].minute);
				all += money;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",data[i].day,data[i].hour,data[i].minute,data[j].day+tmp,data[j].hour,data[j].minute,data[j].time-data[i].time,money/100);
			}
		}
	}
	if(all!=0)
	{
		printf("Total amount: $%.2lf\n",all/100);
	}

	return 0;
}
