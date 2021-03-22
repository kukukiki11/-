#include<stdio.h>
int Search(int t[], int i, int j, int x){
    if(i > j)
        return -1;
    int mid = (i+j)/2;
    if(x == t[mid])
        return mid;
    else if(x <t[mid])
        return Search(t,i,mid-1,x);
    else
        return Search(t,mid+1,j,x);
}
int main(){
	int n = 10;
    int t[n] = {12,23,34,45,56,67,78,89,90,100};
    
    int x,re;
    printf("请输入要查找的x:");
    scanf("%d",&x);
    re=Search(t,0,n-1,x);
    if(re==-1)
    	printf("j=0");
    else
    	printf("%d",re);
}
