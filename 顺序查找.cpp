#include<stdio.h>
int main(){
	int t[10]={12,15,23,64,66,78,84,88,92,97};
	int i,x,re=-1;
	printf("请输入需要查找的x:"); 
	scanf("%d",&x);
	for(i=0;i<10;i++){
		if(t[i]==x){
			re=i;
			break;
		}
	}
	if(re!=-1)
		printf("%d",re);
	else
		printf("j=0");
}
