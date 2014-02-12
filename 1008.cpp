/*************************************************************************
	> File Name: 1008.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 12 Feb 2014 02:44:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    int curFloor=0;
    int time=0;
    int goalFloor;


    for(int i=0; i<N; i++){
        cin>>goalFloor;
        if(goalFloor>curFloor){
            time+=6*(goalFloor-curFloor);
            curFloor=goalFloor;
        } else if ( goalFloor <curFloor){
            time+=4*(curFloor-goalFloor);
            curFloor=goalFloor;
        }
    }

    time+=5*N;
    cout<<time<<endl;
}

