#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool map[500];

char Capitalize(char c)
{
    if( c<='z' && c >= 'a')
       return c-'a'+'A';
    else 
       return c;
}
int main()
{
   freopen("1084.txt","r",stdin);

   string origin,output;
   cin>>origin>>output;
   int originIdx , outputIdx;

   vector<char> res; 
   for(originIdx=0,outputIdx=0; originIdx < origin.size() && outputIdx < output.size();)
   {
       if(origin[originIdx] != output[outputIdx])
       {
          vector<char>::iterator it;
          it=find(res.begin(),res.end(),Capitalize(origin[originIdx]));
          
          if( it == res.end()) //not found in the list
          {
              res.push_back(Capitalize(origin[originIdx]));
          }
          originIdx++;

       }
       else {
	       originIdx++;
	       outputIdx++;
           map[origin[originIdx-1]]=1;
       }
       
   } 
    if(outputIdx == output.size())
    {
        vector<char>::iterator it;
        for(;originIdx<origin.size();originIdx++){
            it=find(res.begin(),res.end(),Capitalize(origin[originIdx]));

            if( it == res.end() && !map[origin[originIdx]]) //not found in the list and not met before 
            //just new!! 
            {
                res.push_back(Capitalize(origin[originIdx]));
            }
        }
    }

    for (int i=0; i<res.size(); i++)
    {
       cout<<res[i];
    }
}  
