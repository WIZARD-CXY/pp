/*************************************************************************
	> File Name: 1057.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Nov 2014 11:00:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<set>
#include<stack>
#include<cstring>

stack<int> s;
multiset<int> minm,maxm;
int mid;

void adjust(){
    multiset<int>::iterator it;
    if(maxm.size()+1<minm.size()){
        // if the min part is bigger than the max part
        // move the biggest num to the max part
        it = minm.end();
        it--;
        maxm.insert(*it);
        minm.erase(it);
    } else if(maxm.size() > minm.size()){
        // if the min part is smaller than the min part 
        // move the smallest element to the min part 
        it=maxm.begin();
        minm.insert(*it);
        maxm.erase(it);
    }else{
    }
    
    if(s.size()>0){
        mid=*(--minm.end());
    }
}
int main(){
    freopen("1057.txt","r",stdin);

    char ch[15];
    int n;
    scanf("%d",&n);

    multiset<int>::iterator it;
    mid=-1;
    int top,num;

    for(int i=0; i<n; i++){
        scanf("%s",ch);

        if(strcmp(ch,"Pop")==0){
            if(s.size()==0){
                printf("Invalid\n");
            }else {
                top = s.top();
                s.pop();
                printf("%d\n",top);

                if(mid>=top){
                    it=minm.find(top);
                    minm.erase(it);
                }else{
                    it=maxm.find(top);
                    maxm.erase(it);
                }
                adjust();
            }

        }else if(strcmp(ch,"Push")==0){
            scanf("%d",&num);

            if(s.size() ==0 ){
                minm.insert(num);
                mid=num;
            }else if(num<=mid){
                minm.insert(num);
            }else{
                maxm.insert(num);
            }

            s.push(num);
            adjust();
            
        }else if(strcmp(ch,"PeekMedian")==0){
            if(s.size()==0){
                printf("Invalid\n");
            }else {
                printf("%d\n",mid);
            }
        }else{//invalid command
              printf("Invalid\n");
        }
    }
}
