#include <stdio.h> 
#include <stdlib.h>

int cmp(const void* _a,const void* _b){
	int* a=(int*)_a;
	int* b=(int*)_b;
	return *a-*b;
}
int main(){
	int n,C,i; 
	printf("输入集装箱个数n：");
    scanf("%d",&n);
    int m[n]={0};
    printf("输入轮船最大载重量C：");
    scanf("%d",&C);
    for(i=0;i<n;i++){
    	printf("第%d个集装箱重量为：",i); 
    	scanf("%d",&m[i]);
	}
	qsort(m,n,sizeof(int),cmp);
	printf("可装载的集装箱重量为：");
	for(i=0;i<n;i++){
		C-=m[i]; 
		if(C>0)
			printf("%d ",m[i]) ;
    	else
    		break;
	}
    return 0;
}

