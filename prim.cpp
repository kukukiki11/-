#include<iostream>
#define n 7
#define INF 999
using namespace std;
typedef struct{
	int low;  
	int a;  
}t;
void Prim(int data[n][n],int w) {
	t tree[10];  
	for(int i=0;i<n;i++){
		tree[i].low = data[w][i];
		tree[i].a = w;
	}
	tree[w].low = 0; 
	int k,min;
	for(int i=0;i<n-1;i++){
		min = 500;
		for(int j=0;j<n;j++) { 
			if((tree[j].low!=0) && (tree[j].low<min)){
				min = tree[j].low;
				k = j; 
			} 
		}
		cout<<tree[k].a<<"--"<<k<<"  "<<min<<endl; 
		tree[k].low = 0; 
		for(int j=0;j<n;j++){  
			if(data[k][j]<tree[j].low){
				tree[j].low = data[k][j];
				tree[j].a = k;
			}
		} 
	} 
}
int main(){
	int data[n][n] = {{INF, 21, INF,INF,INF, 19,INF},
	                 { 21,INF,17,INF, INF,INF,14},
					 {INF,17,INF, 15,INF, INF,INF},
					 {INF,INF, 15,INF, 12, INF,18},
					 {INF, INF,INF, 12,INF, 13,23},
				     {7,INF, INF, INF, 13,INF,INF},
					 {INF,14,INF,18,23,INF,INF}};
	Prim(data,0);
	return 0;
}


