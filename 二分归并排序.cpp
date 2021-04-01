#include <stdio.h>
#include <stdlib.h>
#define N 100
void Merge(int A[], int p, int q, int r){
	int *L, *R,x,y;
	x=q-p+1,y=r-q;
	L = (int*)malloc(sizeof(int)*x);
	R = (int*)malloc(sizeof(int)*y);
	int i ,j;
	for (i=0; i <x; i++)
		L[i] = A[i + p];
	for (j=0; j < y; j++)
		R[j] = A[j + q + 1];
	i = j = 0;
	int k = p;
	while (i <x && j <y){
		if (L[i] <= R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	while (i < x)
		A[k++] = L[i++];
	while (j <y)
		A[k++] = R[j++];
	free(L);
	free(R);
}
int MergeSort(int A[],int p,int r){
	if (p < r){
		int q = (p + r) / 2;
		MergeSort(A,p, q);
		MergeSort(A,q + 1, r);
		Merge(A,p, q, r);
	}
}

int main(){
	int A[N],i=0,n;
    printf("请输入待排序数组并以-1结束：");
    while(scanf("%d",&A[i]),A[i]!=-1)
    		i++;
	n=i;
    MergeSort(A,0,n);
    for(i=1;i<=n;i++)
        printf("%d ",A[i]);
    return 0;
}

