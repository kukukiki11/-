#include <stdio.h>
#include <stdlib.h> 
int cmp(const void * a,const void * b){
	return (*(int*)a-*(int*)b);
}
int main(){
	int t[101];
	int n,i,j,x,mid,re=0;
	bool flag=false;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);
	qsort(t,n,sizeof(int),cmp);
	for(i=0;i<n;i++)
		printf("%d ",t[i]);
	printf("\n");
	j=n-1;
	i=0;
	while(i<=j){
		mid=(i+j)/2;
		if(t[mid]==x){
			re=mid;
			flag=true;
			break;
		}
		else if(t[mid]<x)
			i=mid+1;
		else 
			j=mid-1;		
	}
	if(flag)
		printf("%d的下标为：%d",x,re);
	else
		printf("未找到，j=0");
} 
