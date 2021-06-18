#include<stdio.h>

int max(int a, int b){
	if(a>b)
		return a;
	else 
		return b;
} 
int main(){
	int i,j,t=0,mid,T=0;
	int task[100]={0};
	printf("请输入任务数：");
	scanf("%d",&t);
	printf("输入各任务加工时间：\n");
	for(i=1;i<=t;i++){
		printf("t%d:",i);
		scanf("%d",&task[i]);
		T+=task[i];
	}
	mid=T/2;
	
	int dd[t+1][mid+1];
	//初始化 
	for(i=0;i<=t+1;i++){
		for(j=0;j<mid+1;j++)
			dd[i][j]=0;
	}
	for(i=1;i<=t;i++){
		for(j=1;j<mid+1;j++){
			if(task[i]>j)
				dd[i][j]=dd[i-1][j];
			else
				dd[i][j]=max(dd[i-1][j],dd[i-1][j-task[i]]+task[i]);
		}
	}
	
	
	//回溯输出方案 
	printf("\n");
	int m,n,result[t+1];
	m=t;
	n=mid;
	i=0;
	while(m>0 || n>0){
		if(dd[m][n]==dd[m-1][n])
			m--;
		else{
			i++;
			result[i]=m;
			n=n-task[i];
			m--;
		}
	}
	printf("方案：\n"); 
	printf("机器1：");
	int total=0,len=0;
	for(i=1;i<=t;i++){
		total+=task[result[i]];
		if(total>mid)
			break;
		len++;
		printf("t%d ",result[i]);		
	}
	printf("\n机器2：");
	int f=0;
	for(i=1;i<=t;i++){
		for(j=1;j<=len;j++){
			if(result[j]==i)
				f=1;
		}
		if(f==0)
			printf("t%d ",i);
		else
			f=0;
	}
	printf("\n加工时间最少为：%d\n\n",T-dd[t][mid]);
	
	//输出计算过程 
	printf("计算过程：\n"); 
	for(i=0;i<=t;i++){
		for(j=0;j<mid+1;j++)
			printf("%d ",dd[i][j]);
		printf("\n");
	}
	return 0;
}
