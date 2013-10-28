#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;;

struct node
{
	int arrive_time;
	int serve_time;
	int play_time;
	int vip;
	int leave_time;
	int table_id;
	int vip_used;
};
inline bool operator < (const node &a, const node &b)
{
	return a.leave_time > b.leave_time;
}
inline bool comp(const node &a, const node &b)
{
	return a.arrive_time < b.arrive_time;
}
int flag[10009] = {0};
node data[10009];
priority_queue<node> q;
int vip_flag[109] = {0};
priority_queue<int,vector<int>,greater<int>> vip_table;
priority_queue<int,vector<int>,greater<int>> ger_table;
int serve_num[109] = {0};

void myPrint(int time1,int time2,int time3,int index)
{
	if(time2 >= 21*3600)
		return;
	serve_num[index]++;
	int hh,mm,ss;
	hh = time1/3600;
	time1 %= 3600;
	mm = time1/60;
	time1 %= 60;
	ss = time1;
	printf("%02d:%02d:%02d ",hh,mm,ss);
	hh = time2/3600;
	time2 %= 3600;
	mm = time2/60;
	time2 %= 60;
	ss = time2;
	printf("%02d:%02d:%02d ",hh,mm,ss);
	printf("%d\n",(int)(time3/60.0+0.5));
}

int main(void)
{
	int i,j,n,k,m;
	node tt;
	scanf("%d",&n);
	int hh,mm,ss,time,vip;
	for(i=0;i<n;i++)
	{
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&time,&vip);
		tt.arrive_time = hh*3600+mm*60+ss;
		tt.play_time = time*60;
		if(tt.play_time>2*3600)
			tt.play_time = 2*3600;
		tt.vip = vip;
		data[i] = tt;
	}
	scanf("%d %d",&k,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&j);
		vip_flag[j] = 1;
		vip_table.push(j);
	}
	for(i=1;i<=k;i++)
	{
		if(vip_flag[i]==0)
		{
			ger_table.push(i);
		}
	}
	sort(data,data+n,comp);
	int index;
	int state;
	int curr;
	for(i=0;i<n;)
	{
		if(flag[i]==1)
		{
			i++;
			continue;
		}
		curr = i;
		state = 0;
		while(!q.empty() && q.top().leave_time < data[i].arrive_time)
		{
			tt = q.top();
			q.pop();
			if(tt.vip_used==1)
				vip_table.push(tt.table_id);
			else
				ger_table.push(tt.table_id);
		}
		if(vip_table.empty() && ger_table.empty())
		{
			state = 1;	//标记此次可用的位置是从后面提前预支的
			tt = q.top();
			q.pop();
			if(tt.vip_used==1)
				vip_table.push(tt.table_id);
			else
				ger_table.push(tt.table_id);
			if(tt.vip_used==1)	//如果下一个可用的位置是VIP席位,查看后面有没有VIP成员
			{
				int local_state = 0;
				for(j=i;j<n && data[j].arrive_time<tt.leave_time;j++)
				{
					if(flag[j]==0 && data[j].vip==1)
					{
						local_state = 1;
						curr = j;
						break;
					}
				}
			}
		}
		if(curr==i)	//说明没有跳动处理
			i++;
		if(data[curr].vip==1)
		{
			if(vip_table.empty())	//没有VIP table可用
			{
				index = ger_table.top();
				ger_table.pop();
				if(state==0)
					data[curr].serve_time = data[curr].arrive_time;
				else
					data[curr].serve_time = tt.leave_time;
				data[curr].leave_time = data[curr].serve_time+data[curr].play_time;
				data[curr].table_id = index;
				data[curr].vip_used = 0;
				q.push(data[curr]);
				myPrint(data[curr].arrive_time,data[curr].serve_time,data[curr].serve_time-data[curr].arrive_time,index);
			}
			else
			{
				index = vip_table.top();
				vip_table.pop();
				if(state==0)
					data[curr].serve_time = data[curr].arrive_time;
				else
					data[curr].serve_time = tt.leave_time;
				data[curr].leave_time = data[curr].serve_time+data[curr].play_time;
				data[curr].table_id = index;
				data[curr].vip_used = 1;
				q.push(data[curr]);
				myPrint(data[curr].arrive_time,data[curr].serve_time,data[curr].serve_time-data[curr].arrive_time,index);
			}
		}
		else
		{
			if(ger_table.empty())
			{
				index = vip_table.top();
				vip_table.pop();
			}
			else if(vip_table.empty())
			{
				index = ger_table.top();
				ger_table.pop();
			}
			else
			{
				if(ger_table.top() < vip_table.top())
				{
					index = ger_table.top();
					ger_table.pop();
				}
				else
				{
					index = vip_table.top();
					vip_table.pop();
				}
			}
			if(state==0)
				data[curr].serve_time = data[curr].arrive_time;
			else
				data[curr].serve_time = tt.leave_time;
			data[curr].leave_time = data[curr].serve_time+data[curr].play_time;
			data[curr].table_id = index;
			data[curr].vip_used = vip_flag[index];
			q.push(data[curr]);
			myPrint(data[curr].arrive_time,data[curr].serve_time,data[curr].serve_time-data[curr].arrive_time,index);
		}
		flag[curr] = 1;
	}
	
	printf("%d",serve_num[1]);
	for(i=2;i<=k;i++)
		printf(" %d",serve_num[i]);

	return 0;
}
