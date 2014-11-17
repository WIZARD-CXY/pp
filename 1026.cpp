#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class Player
{
	public:
		int arrive;//arrive time 
		int vip;//vip flag
		int playtime;//the time player play
		bool operator<(const Player r)const
		{
			return arrive<r.arrive;
		}
};

class Table
{
	public:
		int freetime;//the time table can be used
		int vip;//vip flag
		int ID;//the number of table
		int num;//the number of players the table serve
		bool operator<(const Table r)const
		{
			if(freetime!=r.freetime)
				return freetime<r.freetime;
			else
				return ID<r.ID;
		}
};

bool cmp(Table l,Table r)
{
	return l.ID<r.ID;
}

int main(int argc,char *argv[])
{
	Table t[105];
	vector<Player> p;
	vector<Player> waiting;
	int n,i,j;
	int k,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int h,m,s;
		Player temp;
		scanf("%d:%d:%d %d %d",&h,&m,&s,&temp.playtime,&temp.vip);
		temp.arrive=h*3600+m*60+s;
		if(temp.playtime>120)
			temp.playtime=120;
		temp.playtime*=60;
		if(temp.arrive>=21*60*60||temp.arrive<8*60*60)
			continue;
		
		p.push_back(temp);
	}
	scanf("%d%d",&k,&m);
	for(i=1;i<=k;i++)
	{
		t[i].ID=i;
		t[i].vip=0;
		t[i].num=0;
		t[i].freetime=0;
	}
	for(i=0;i<m;i++)
	{
		int index;
		scanf("%d",&index);
		t[index].vip=1;
	}
	int timer=0;
	int cur=0;
	sort(p.begin(),p.end());
	sort(t+1,t+1+k);
	while(timer<21*60*60)
	{
		for(;cur<p.size();cur++)
		{
			if(p[cur].arrive<=timer)//如果此时没有空闲球桌，并且在timer
				waiting.push_back(p[cur]);//之前到达，player需在队列里等待
			else
				break;
		}
		if(!waiting.size())//如果等待对列为空，即此时有剩余球桌
		{
			if(cur<p.size())
			{
				timer=p[cur].arrive;
				for(i=1;i<=k;i++)//把无人使用球桌的freetime更新为timer
				{
					if(t[i].freetime<=timer)
						t[i].freetime=timer;
				}
				waiting.push_back(p[cur++]);
			}
			else
				break;
		}
		vector<Player>::iterator it;//find the first vip player in the queue
		for(it=waiting.begin();it!=waiting.end();it++)
			if(it->vip)
				break;
		int vipplayer=0;
		if(it!=waiting.end())
			vipplayer=1;
		int viptable=-1;//find the first vacant vip table
		for(i=1;i<=k&&t[i].freetime==timer;i++)
		{
			if(t[i].vip)
			{
				viptable=i;
				break;
			}
		}
		if(viptable>=1&&vipplayer)//队列中有vip客户，且有空闲vip桌子
		{
			int arrive=it->arrive;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",arrive/3600,
		(arrive%3600)/60,arrive%60,timer/3600,(timer%3600)/60,timer%60,
		         (timer-it->arrive+30)/60);
			t[viptable].freetime=timer+it->playtime;
			t[viptable].num++;
			waiting.erase(it);
		}
		else
		{
			int arrive=waiting[0].arrive;
			 printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",arrive/3600,
			 (arrive%3600)/60,arrive%60,timer/3600,(timer%3600)/60,timer%60,
	                 (timer-arrive+30)/60);
			 t[1].freetime=timer+waiting[0].playtime;
			 t[1].num++;
			 waiting.erase(waiting.begin());
		}
		sort(t+1,t+1+k);//对桌子的空闲时间进行排序，否则对ID进行排序
		timer=t[1].freetime;//则每次都是第一个桌子先被使用
	}
	sort(t+1,t+1+k,cmp);//恢复桌子的序号
	printf("%d",t[1].num);
	for(i=2;i<=k;i++)
		printf(" %d",t[i].num);
	printf("\n");

	return 0;
}
