/*************************************************************************
> File Name: 1049.cpp
> Author: 
> Mail: 
> Created Time: Mon 10 Nov 2014 11:36:26 PM CST
************************************************************************/
#include<iostream>
using namespace std;
#include<cstdio>
//reference http://blog.csdn.net/tiantangrenjian/article/details/19908885

int CountOnes(int n){
    int count = 0;
    int factor = 1;
    int higher,lower,cur;
    while(n/factor != 0){
        higher = n/(factor*10); //higher digits
        lower = n - (n/factor)*factor; //lower digit
        cur = (n/factor)%10; //current digit
        switch (cur){
            case 0:
            count += higher*factor;
            break;
            case 1:
            count += higher*factor + lower +1;
            break;
            default:
            count += higher*factor + factor;
        }
        factor = factor * 10;

    }

    return count;

}

int main()
{
    freopen("1049.txt","r",stdin);
    int n;
    scanf("%d",&n);
    printf("%d\n",CountOnes(n));
    return 0;
}

