/*************************************************************************
	> File Name: 1019_bk.cpp
    > Author: Wizard
    > Mail: wizard_cxy@hotmail.com 
    > Created Time: Fri 14 Feb 2014 08:33:07 PM CST
    ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



int main()
{
    vector<int> v;
    vector<int> rv;
    int num;
    int base;
    cin>>num;
    cin>>base;

    while(num)
    {
        v.push_back(num%base);
        num/=base;
    }

    rv = v;
    reverse(rv.begin(),rv.end());
    if(rv==v)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;


    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i];
        if(i!=0)
        cout<<" ";
    }

    if(v.size()==0)
    cout<<0;
}
