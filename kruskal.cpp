#include <stdio.h>
#include <algorithm>
#define maxn 20
using namespace std;
typedef struct{
    int x, y;
    int w;
}edge;
edge e[maxn];
int rank[maxn], father[maxn];
int cmp(edge a, edge b){ 
    if(a.w == b.w)  return a.x < b.x;
    return a.w < b.w;
}
void make(int x){
    father[x] = x;
    rank[x] = 0;
}
int f(int x){
    return  x != father[x] ? f(father[x]) : father[x];
}
void u(int x, int y, int w){
    if(x == y)  return ;
    if(rank[x] > rank[y])  father[y] = x;
    else{
        if(rank[x] == rank[y])  rank[y]++;
        father[x] = y;
    }
}
int main(){
    int n, x, y, i;
    char cx, cy;
    scanf("%d", &n);//nÎªÊäÈë±ßÊı 
    getchar();
    for(i = 0; i < n; i++){
        scanf("%c%c %d", &cx, &cy, &e[i].w);
        getchar();
        e[i].x = cx -'A', e[i].y = cy - 'A';
        make(i); 
    }
    sort(e, e + n, cmp);
    for(i = 0; i < n; i++){
        x = f(e[i].x), y = f(e[i].y);
        if(x != y){
            printf("%c-%c : %d\n", e[i].x + 'A', e[i].y + 'A', e[i].w);
            u(x, y, e[i].w);
        }
    }
    return 0;
}

