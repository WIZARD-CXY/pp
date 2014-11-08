/*************************************************************************
	> File Name: 1080.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Nov 2014 08:34:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXSCHOOL 101

int quota[MAXSCHOOL];

struct stu{
    int id;
    int ge;
    int gi;
    int choice[5];
    int rank;
};

vector<int> schoolRes[MAXSCHOOL];
int lastrank[MAXSCHOOL];
bool cmp(const stu &a, const stu &b){
    if((a.ge+a.gi) > (b.ge+b.gi)){
        return true;
    } else if( (a.ge+a.gi) == (b.ge+b.gi) ){
        if(a.ge>b.ge){
            return true;
        }
        else{
            return false;
        }
    } else {
        return false;
    }
}
int main(){
    freopen("1080.txt","r",stdin);

    int n,m,k;

    cin>>n>>m>>k;

    for(int i=0; i<m; i++){
        scanf("%d",&quota[i]);
    }

    vector<stu> stu_vec(n);

    for(int i=0; i<n; i++){
        stu_vec[i].id=i;
        scanf("%d%d", &stu_vec[i].ge, &stu_vec[i].gi);
        for(int j=0; j<k; j++){
            scanf("%d",&stu_vec[i].choice[j]);
        }
    }

    sort(stu_vec.begin(),stu_vec.end(),cmp);

    stu_vec[0].rank=0;
    for(int i=1; i<n; i++){
        if(stu_vec[i].ge == stu_vec[i-1].ge && stu_vec[i].gi == stu_vec[i-1].gi){
            stu_vec[i].rank = stu_vec[i-1].rank;
        }else{
            stu_vec[i].rank=i;
        }

    }

    
    for(int i=0; i<stu_vec.size(); i++){
        int currid=stu_vec[i].id;

        for(int j=0; j<k; j++){
            int currchoice=stu_vec[i].choice[j];
            
            if(schoolRes[currchoice].size() < quota[currchoice]){
                schoolRes[currchoice].push_back(currid);
                lastrank[currchoice]=stu_vec[i].rank;
                break;

            } else if(schoolRes[currchoice].size() > 0){
                if(stu_vec[i].rank == lastrank[currchoice]){
                schoolRes[currchoice].push_back(currid);
                break;
                    
                }
            }
            
        }
    }

    for(int i=0; i<m; i++){
        if(schoolRes[i].empty()){
            printf("\n");
        } else {
            sort(schoolRes[i].begin(),schoolRes[i].end());
            for(int j=0; j < schoolRes[i].size(); j++){
                if(j==0){
                    printf("%d",schoolRes[i][j]);
                }else{
                    printf(" %d",schoolRes[i][j]);
                }
            }
            printf("\n");
        }
    }
}
