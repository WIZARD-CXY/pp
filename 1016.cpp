#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[22];//名字
    int month;//月份
    int day;//天
    int hour;//时
    int minute;//分
    char tag[10];//on-line or off-line
}record;

int n;
record *rd;
int rate[24];//费率
int count, start;//记录当前处理的这个用户的记录数目，和当前这个用户的第一条记录位置
double totalCharge;//该用户该月的费用合计

double charge(int sday, int shour, int sminute, int eday, int ehour, int eminute)//计算一条有效电话记录的时长和费用，并返回费用
{
    double cost = 0;
    long time = 0;

    while(sday < eday)//先让天相等
    {
        time += (60 - sminute);
        cost += (60 - sminute) * rate[shour];
        sminute = 0; shour ++;//分化成0，时加1
        time += 60 * (24 - shour);
        while(shour < 24)
        {
            cost += 60 * rate[shour];
            shour ++;
        }
        shour = 0; sday ++;//时化成0，天加1
    }//天此时相等，时分为00:00
    while(shour < ehour)//再让时相等
    {
        time += (60 - sminute);
        cost += (60 - sminute) * rate[shour];
        sminute = 0; shour ++;
    }
    time += (eminute - sminute);
    cost += rate[ehour] * (eminute - sminute);

    printf("%ld $%.2lf\n", time, cost / 100);

    return cost / 100;
}

void totalCount()//数出当前要处理的客户的总记录数目
{
    int i;
    for(i = start + 1; i < n; i ++)
    {
        if(strcmp(rd[i].name, rd[i - 1].name) != 0)
        {
            break;
        }
        else
        {
            count ++;
        }
    }
}

int comp_name(const void *a, const void *b)
{
    record c = *(record *)a;
    record d = *(record *)b;


    if(strcmp(c.name, d.name) <= 0) return -1;
    else return 1;
}

int comp_time(const void *a, const void *b)
{
    record c = *(record *)a;
    record d = *(record *)b;

    if(c.day < d.day) return -1;
    else if(c.day > d.day) return 1;
    else
    {
        if(c.hour < d.hour) return -1;
        else if(c.hour > d.hour) return 1;
        else
        {
            if(c.minute < d.minute) return -1;
            else return 1;
        }
    }
}

int main()
{
    int i;
    int flag;//1应该出现offline, 0应该出现online
    int onpos;//记录最近有效的on-line记录位置，为了算出charge
    int sign;//0表示该客户名字和月份还没有输出，1表示已输出
    

    while(scanf("%d", &rate[0]) != EOF)
    {
        for(i = 1; i < 24; i ++)
        {
            scanf("%d", &rate[i]);
        }
        scanf("%d", &n);
        rd = (record *)malloc(n * sizeof(record));
        for(i = 0; i < n; i ++)
        {
            scanf("\n%s %d:%d:%d:%d %s", rd[i].name, &rd[i].month, &rd[i].day, &rd[i].hour, &rd[i].minute, rd[i].tag);
        }
        qsort(rd, n, sizeof(record), comp_name);//先将记录按字母表顺序分类
        count = 1; start = 0; totalCount(); sign = 0;
        while(start < n)//整个记录表还没处理完
        {
            qsort(rd + start, count, sizeof(record), comp_time);
            flag = 0;
            totalCharge = 0;
            for(i = start; i < start + count; i ++)//处理该客户
            {
                if(flag == 0)//期待出现online,如果是offline跳过
                {
                    if(rd[i].tag[1] == 'f')//off-line
                    {
                        continue;
                    }
                    else//on-line
                    {
                        onpos = i;
                        flag = 1;
                    }
                }
                else//期待出现offline，如果是online则更新onpos
                {
                    if(rd[i].tag[1] == 'n')//on-line
                    {
                        onpos = i;
                    }
                    else//off-line
                    {
                        if(sign == 0)
                        {
                            printf("%s %02d\n", rd[start].name, rd[start].month);
                            sign = 1;
                        }
                        printf("%02d:%02d:%02d %02d:%02d:%02d ", rd[onpos].day, rd[onpos].hour, rd[onpos].minute, rd[i].day, rd[i].hour, rd[i].minute);
                        totalCharge += charge(rd[onpos].day, rd[onpos].hour, rd[onpos].minute, rd[i].day, rd[i].hour, rd[i].minute);
                        flag = 0;
                    }
                }
            }
            if(sign == 1)
            {
                printf("Total amount: $%.2lf\n", totalCharge);
            }
            start += count; count = 1; totalCount(); sign = 0;
        }
    }
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[22];//名字
    int month;//月份
    int day;//天
    int hour;//时
    int minute;//分
    char tag[10];//on-line or off-line
}record;

int n;
record *rd;
int rate[24];//费率
int count, start;//记录当前处理的这个用户的记录数目，和当前这个用户的第一条记录位置
double totalCharge;//该用户该月的费用合计

double charge(int sday, int shour, int sminute, int eday, int ehour, int eminute)//计算一条有效电话记录的时长和费用，并返回费用
{
    double cost = 0;
    long time = 0;

    while(sday < eday)//先让天相等
    {
        time += (60 - sminute);
        cost += (60 - sminute) * rate[shour];
        sminute = 0; shour ++;//分化成0，时加1
        time += 60 * (24 - shour);
        while(shour < 24)
        {
            cost += 60 * rate[shour];
            shour ++;
        }
        shour = 0; sday ++;//时化成0，天加1
    }//天此时相等，时分为00:00
    while(shour < ehour)//再让时相等
    {
        time += (60 - sminute);
        cost += (60 - sminute) * rate[shour];
        sminute = 0; shour ++;
    }
    time += (eminute - sminute);
    cost += rate[ehour] * (eminute - sminute);

    printf("%ld $%.2lf\n", time, cost / 100);

    return cost / 100;
}

void totalCount()//数出当前要处理的客户的总记录数目
{
    int i;
    for(i = start + 1; i < n; i ++)
    {
        if(strcmp(rd[i].name, rd[i - 1].name) != 0)
        {
            break;
        }
        else
        {
            count ++;
        }
    }
}

int comp_name(const void *a, const void *b)
{
    record c = *(record *)a;
    record d = *(record *)b;


    if(strcmp(c.name, d.name) <= 0) return -1;
    else return 1;
}

int comp_time(const void *a, const void *b)
{
    record c = *(record *)a;
    record d = *(record *)b;

    if(c.day < d.day) return -1;
    else if(c.day > d.day) return 1;
    else
    {
        if(c.hour < d.hour) return -1;
        else if(c.hour > d.hour) return 1;
        else
        {
            if(c.minute < d.minute) return -1;
            else return 1;
        }
    }
}

int main()
{
    int i;
    int flag;//1应该出现offline, 0应该出现online
    int onpos;//记录最近有效的on-line记录位置，为了算出charge
    int sign;//0表示该客户名字和月份还没有输出，1表示已输出
    

    while(scanf("%d", &rate[0]) != EOF)
    {
        for(i = 1; i < 24; i ++)
        {
            scanf("%d", &rate[i]);
        }
        scanf("%d", &n);
        rd = (record *)malloc(n * sizeof(record));
        for(i = 0; i < n; i ++)
        {
            scanf("\n%s %d:%d:%d:%d %s", rd[i].name, &rd[i].month, &rd[i].day, &rd[i].hour, &rd[i].minute, rd[i].tag);
        }
        qsort(rd, n, sizeof(record), comp_name);//先将记录按字母表顺序分类
        count = 1; start = 0; totalCount(); sign = 0;
        while(start < n)//整个记录表还没处理完
        {
            qsort(rd + start, count, sizeof(record), comp_time);
            flag = 0;
            totalCharge = 0;
            for(i = start; i < start + count; i ++)//处理该客户
            {
                if(flag == 0)//期待出现online,如果是offline跳过
                {
                    if(rd[i].tag[1] == 'f')//off-line
                    {
                        continue;
                    }
                    else//on-line
                    {
                        onpos = i;
                        flag = 1;
                    }
                }
                else//期待出现offline，如果是online则更新onpos
                {
                    if(rd[i].tag[1] == 'n')//on-line
                    {
                        onpos = i;
                    }
                    else//off-line
                    {
                        if(sign == 0)
                        {
                            printf("%s %02d\n", rd[start].name, rd[start].month);
                            sign = 1;
                        }
                        printf("%02d:%02d:%02d %02d:%02d:%02d ", rd[onpos].day, rd[onpos].hour, rd[onpos].minute, rd[i].day, rd[i].hour, rd[i].minute);
                        totalCharge += charge(rd[onpos].day, rd[onpos].hour, rd[onpos].minute, rd[i].day, rd[i].hour, rd[i].minute);
                        flag = 0;
                    }
                }
            }
            if(sign == 1)
            {
                printf("Total amount: $%.2lf\n", totalCharge);
            }
            start += count; count = 1; totalCount(); sign = 0;
        }
    }
    return 0;
}
