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
	printf("��������������");
	scanf("%d",&t);
	printf("���������ӹ�ʱ�䣺\n");
	for(i=1;i<=t;i++){
		printf("t%d:",i);
		scanf("%d",&task[i]);
		T+=task[i];
	}
	mid=T/2;
	
	int dd[t+1][mid+1];
	//��ʼ�� 
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
	
	
	//����������� 
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
	printf("������\n"); 
	printf("����1��");
	int total=0,len=0;
	for(i=1;i<=t;i++){
		total+=task[result[i]];
		if(total>mid)
			break;
		len++;
		printf("t%d ",result[i]);		
	}
	printf("\n����2��");
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
	printf("\n�ӹ�ʱ������Ϊ��%d\n\n",T-dd[t][mid]);
	
	//���������� 
	printf("������̣�\n"); 
	for(i=0;i<=t;i++){
		for(j=0;j<mid+1;j++)
			printf("%d ",dd[i][j]);
		printf("\n");
	}
	return 0;
}
