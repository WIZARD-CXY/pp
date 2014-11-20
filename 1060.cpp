#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

int convert(const char* c,int n,char* &res)
{
	int point,count; //point indicate the power number of 10, count means 
	point = count = 0;// how many digit has been copied from c to res;
	int i=0,j=0;
	while(c[i]=='0')i++;		//先略去最前面的'0'

	if(c[i]=='.')		//形式为 (0)*.##
	{		
		bool isBegin = false; //in case there is 0.00 input case
		while(c[i]!='\0')
		{
			if(c[i]=='.')
			{
				point = 1;
			}else if(c[i]!='0')
			{
				isBegin = true;
			}
			
			if(isBegin){
				if(count<n)
				{
					res[count]=c[i];
					count++;
				}
			}else
			{
				point--;
			}
			i++;
		}
		if(!isBegin) point=0;
	}else								//形式为 (0)*#.##
	{
		j=i;
		while(c[i]!='\0')
		{
			if(c[i]=='.')
			{
				point = i-j;
			}else
			{
				if(count<n)
				{
					res[count]=c[i];
					count++;
				}
			}
			i++;
		}
		if(point==0)//如果没有. 则等于数字个数(去掉前面的0)	
			point = i-j;	
	}
	
	if(count<n)			//如果数字个数不足，补'0'
	{
		i = count;
		while(i<n)
		{
			res[i]='0';
			i++;
		}
	}
    res[n]='\0';
	return point;
}

int main()
{
   freopen("1060.txt","r",stdin);
   int n;
   cin>>n;
   char A[105],B[105];
   cin>>A>>B;
   int Ac,Bc;
   char *Ares,*Bres;
   Ares = new char[n+1];
   Bres = new char[n+1];
   Ac = convert(A,n,Ares);
   Bc = convert(B,n,Bres);
   if(Ac==Bc && strcmp(Ares,Bres)==0)
   {
		cout<<"YES 0."<<Ares<<"*10^"<<Ac<<endl;
   }else
   {
		cout<<"NO 0."<<Ares<<"*10^"<<Ac<<" 0."<<Bres<<"*10^"<<Bc<<endl;
   }
   return 0;
}

