#include<iostream>
using namespace std;
#include<cmath>

bool isPrime(long long n)
{
	if(n==1||n==0)
		return false;
    int m=floor(sqrt(n)+0.5);
	for(int i=2; i<=m; i++)
		if(n%i==0)
			return false;
	return true;
}

int reverse(int n,int radix)
{
	int tmp=0;
	while(n)
	{
		tmp = tmp*radix + n%radix;
		n = n/radix;
	}
	return tmp;
}

int prime[10000];

int main()
{
	int num;
	int radix;



	while(1)
	{
		cin>>num;
		if(num<0)
			break;
		cin>>radix;
		if(isPrime(num)&&isPrime(reverse(num,radix)))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}

