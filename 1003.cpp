#include <iostream>
#include <cstdio>

using namespace std;
#define MAXNUM 502

int dist[MAXNUM];
int citynum;
int roadnum;
int w[MAXNUM][MAXNUM];
int pre[MAXNUM];//pre[j] record j-th node's  minimun path parent 
int team[MAXNUM];
bool vis[MAXNUM];
 
int maxTeamnum;
int ans;

#define MAX_INT 0x7fffffff
//O(n2) time algorithm
void dijkstra(int n, int source){

	for(int i=0; i<n; i++)
		pre[i]=-1;

    for(int i=0; i<n; i++){
       dist[i]=w[source][i];

       if(dist[i] < MAX_INT){
           pre[i]=source;
       }
    }

    vis[source]=1;
    dist[source]=0;

    for(int i=0; i<n; i++){
        
        int minDist=MAX_INT;
        int minIndex=0;

    	for(int j=0; j<n; j++){
    		if( !vis[j] && dist[j]<minDist){
    			minDist=dist[j];
    			minIndex=j;
    		}
    	}

    	vis[minIndex]=1; //mark it is visited

     
    	for(int j=0; j<n; j++){
            
    		if(w[minIndex][j] < MAX_INT && dist[j] > (dist[minIndex]+w[minIndex][j])){
                
    			dist[j]=dist[minIndex]+w[minIndex][j];
    		    pre[j]=minIndex;
    		    

    		}

    	}
        
    }
}

void dfs(int n, int src, int dst, int curDis, int curTeamnum){

	vis[src]=1;
	if(src==dst){
		if(curDis==dist[dst]){
			ans++;
			if(curTeamnum>maxTeamnum)
				maxTeamnum=curTeamnum;

		}
		return;
	}
	if(curDis>dist[dst])
		return;

	for(int i=0; i<n; i++){
		if(!vis[i] && w[src][i] <MAX_INT){
			dfs(n,i,dst,curDis+w[src][i],curTeamnum+team[i]);
			vis[i]=0;
		}
	}

}


int main(){

	//freopen("1003.txt","r",stdin);
	
	int src,dst;
    int c1,c2,l;

	cin>>citynum>>roadnum>>src>>dst;


	for(int i=0; i<citynum; i++){
	   for(int j=0; j<citynum; j++)
	       w[i][j]=MAX_INT;
	}

	for(int i=0; i<citynum; i++){
	   cin>>team[i];
	}

	for(int i=0; i<roadnum; i++){
	   cin>>c1>>c2>>l;
	   w[c1][c2]=w[c2][c1]=l;

	}

	dijkstra(citynum,src);

	for(int i=0; i<citynum; i++){
		vis[i]=0;

	}

	dfs(citynum,src,dst,0,team[src]);

	cout<<ans<<" "<<maxTeamnum<<endl;

	
}