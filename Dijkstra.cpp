#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1e5+10;
const int INF = 1e9;
struct edge{
	int from,to,value;  
	edge(int a,int b,int c){
		from =a;
		to= b;
		value = c;
	}
};
vector<edge>  e[maxn]; 
int pre[maxn];
struct s_node{    
	int id,dis; 
	s_node(int a,int b){
		id= a;
		dis=b;
	}
	bool operator < (const s_node &a) const
	{  return dis>a.dis;}
};
int n,m; 
void dijkstra(int s){
	bool done[maxn]; 
	int dis[maxn];  
	for(int i=0;i<=n;i++){
		dis[i] = INF;  
		done[i] =false;
	}
	dis[s] = 0;
	s_node  u(s,0);
	priority_queue<s_node> Q;
	Q.push(u);
    while(!Q.empty()){   
    	u = Q.top();             
	    Q.pop();
	    if(done[u.id]) continue;
	    done[u.id]=true;
	    for(int i=0;i<e[u.id].size();i++){
	    	edge v=e[u.id][i];  
	    	if(done[v.to]) continue;  
	    	if(dis[v.to]>dis[v.from]+v.value){  
	    		dis[v.to] = dis[v.from] + v.value;
	    		Q.push(s_node(v.to,dis[v.to]));
	    		pre[v.to] = pre[v.from];
			}
		}
	}
	for(int i=1;i<=n;i++)
	  printf("i:%d dis:%d\n",i,dis[i]);
	  cout<<endl;
}
int main (){
	  
	  scanf("%d %d",&n,&m);
	  while(m--){
	  	  int a,b,c;
	  	  scanf("%d %d %d",&a,&b,&c); 
	  	  e[a].push_back(edge(a,b,c));  
	  }
	  dijkstra(1);
	  return 0;
	  }

