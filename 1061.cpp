#include <iostream>
using namespace std;
#include <cstdio>
string hh[24]={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23"};

int main(){
    freopen("1061.txt","r",stdin);
    string s1,s2,s3,s4;

    cin>>s1>>s2>>s3>>s4;

    int len1=s1.size(); 
    int len2=s2.size();

    int len;
    if(len1<len2) len=len1;
    else len=len2;

    bool first=1;
    for(int i=0; i<len; i++){
        if(s1[i]==s2[i] && first){
		switch(s1[i]){
			case 'A':
				cout<<"MON ";
				first=0;
				break;
			case 'B':
				cout<<"TUE ";
				first=0;
				break;
			case 'C':
				cout<<"WED ";
				first=0;
				break;
			case 'D':
				cout<<"THU ";
				first=0;
				break;
			case 'E':
				cout<<"FRI ";
				first=0;
				break;
			case 'F':
				cout<<"SAT ";
				first=0;
				break;
			case 'G':
				cout<<"SUN ";
				first=0;
				break;
		}
	}
	else if(s1[i]==s2[i] && !first){
		if(s1[i]>='0' && s1[i] <= '9'){
			cout<<hh[s1[i]-'0']<<":";
                        break;
		} else if ( s1[i]>='A'  && s1[i] <= 'N'){
			cout<<hh[s1[i]-'A'+10]<<":";
                        break;
		}
	}

    }

    int len3=s3.size();
    int len4=s4.size();
    if(len3<len4) len=len3;
    else len=len4;

    for(int i=0; i<len; i++){
	    if(s3[i]==s4[i] && isalpha(s3[i])){
		    printf("%02d\n",i);
                    return 0;
	    }
    }
}
