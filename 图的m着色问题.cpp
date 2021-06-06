#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n;//n个节点
int m;//m种颜色
int mm[100][100];//记录图的邻接矩阵
int x[100];//记录色的一种可能性，x[i]=1,2,3..k..n代表第节点i颜色为k
int best[100];
int sum=0;//用来记录当前可行的着色
bool a(int i){
    int j;
    for(j=1;j<=n;j++){
        if((mm[i][j]==1)&&(x[i]==x[j]))
            return false;
    }
    return true;
}
void dd(int i){
    int j;
    if(i>n){
        sum++;
        for(j=1;j<=n;j++)
            best[j]=x[j];//记录一条枝(记录一种着色的可能性)
    }
    else{
        for(j=1;j<=m;j++){//在i节点处检测它的m种可能性
             x[i]=j;//i节点选定了一种颜色
            if(a(i)){//通过约束函数去掉不合理的颜色
                 dd(i+1);//转移到下一层的第i+1个节点
            }
             x[i]=0;//为i继续换别的颜色
        }
    }
}
int main(){
    int t,k;
    int i,j;
    scanf("%d%d%d",&n,&k,&m);//k是k条边
    for(t=0;t<k;t++){
        scanf("%d%d",&i,&j);
        mm[i][j]=1;
        mm[j][i]=1;
    }
    dd(1);
    if (sum)
    	printf("%d",sum);
    else
    	printf("NO");
    return 0;
}

