/*************************************************************************
	> File Name: 1062.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sat 22 Feb 2014 09:57:47 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

struct Record{
    char id[9];
    int virtueG;
    int talentG;
};

bool cmptotal(const Record &a, const Record &b){
    if((a.virtueG+a.talentG)>(b.virtueG+b.talentG)){
        return true;
    } else if((a.virtueG+a.talentG)==(b.virtueG+b.talentG)) {
        if(a.virtueG>b.virtueG){
            return true;
        } else if(a.virtueG == b.virtueG){
            if(strcmp(a.id, b.id)<0){
                return true;
            } else {
                return false;
            }
        }else {
            return false;
        }
    } else {
        return false;
    }

}

vector<Record> rageGroup;
vector<Record> nobleGroup;
vector<Record> foolGroup;
vector<Record> otherGroup;

int main(){
    freopen("1062.txt","r",stdin);
    int n,l,h;

    int m=0;
    scanf("%d %d %d",&n,&l,&h);

    Record rec;
    for(int i=0; i<n;i++){
        
        scanf("%s %d %d",rec.id, &rec.virtueG,&rec.talentG);
        if(rec.virtueG>=h && rec.talentG >=h){
            m++;
            rageGroup.push_back(rec);
        } else if( rec.talentG<h && rec.talentG >=l && rec.virtueG>=h){
            m++;
            nobleGroup.push_back(rec);
        } else if( rec.virtueG<h && rec.talentG <h && rec.virtueG >= rec.talentG && rec.virtueG>=l && rec.talentG >=l){
            m++;
            foolGroup.push_back(rec);

        } else if( rec.virtueG >=l && rec.talentG >=l){
            m++;
            otherGroup.push_back(rec);
        }
    }

    printf("%d\n",m);

    sort(rageGroup.begin(),rageGroup.end(),cmptotal);
    vector<Record>::iterator it=rageGroup.begin();

    for( it=rageGroup.begin(); it != rageGroup.end(); it++){
        printf("%s %d %d\n", it->id,it->virtueG,it->talentG);
    }


    sort(nobleGroup.begin(),nobleGroup.end(),cmptotal);

    for( it=nobleGroup.begin(); it != nobleGroup.end(); it++){
        printf("%s %d %d\n", it->id, it->virtueG, it->talentG);
    }



    sort(foolGroup.begin(),foolGroup.end(),cmptotal);
    for( it=foolGroup.begin(); it != foolGroup.end(); it++){
        printf("%s %d %d\n", it->id, it->virtueG, it->talentG);
    }
    

    sort(otherGroup.begin(),otherGroup.end(),cmptotal);
    for( it=otherGroup.begin(); it != otherGroup.end(); it++){
        printf("%s %d %d\n", it->id, it->virtueG, it->talentG);
    }
}
