#include <stdio.h> 
#include <stdlib.h>

int cmp(const void* _a,const void* _b){
	int* a=(int*)_a;
	int* b=(int*)_b;
	return *a-*b;
}
int main(){
	int n,C,i; 
	printf("���뼯װ�����n��");
    scanf("%d",&n);
    int m[n]={0};
    printf("�����ִ����������C��");
    scanf("%d",&C);
    for(i=0;i<n;i++){
    	printf("��%d����װ������Ϊ��",i); 
    	scanf("%d",&m[i]);
	}
	qsort(m,n,sizeof(int),cmp);
	printf("��װ�صļ�װ������Ϊ��");
	for(i=0;i<n;i++){
		C-=m[i]; 
		if(C>0)
			printf("%d ",m[i]) ;
    	else
    		break;
	}
    return 0;
}

