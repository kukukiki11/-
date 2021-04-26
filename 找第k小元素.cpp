#include <stdio.h>
int FindK(int a[], int p, int r, int k) {
	int i = p, j = r, key = a[i];
	while (i < j) {
		while (i<j && a[j]>=key)
			--j;
		a[i] = a[j];
		while (i<j && a[i]<=key)
			++i;
		a[j]= a[i];
	}
	a[i]= key;
	int lefts= i-p+1;
	if (lefts == k) 
		return a[i];
	if (lefts > k)
		return FindK(a, p, i-1, k);
	else
		return FindK(a, i+1, r, k-lefts);
}
int main(){
	int a[10]={3,2,10,8,6,5,12,43,25,67};
	int k,i;
	printf("输入k（0<k<=10): ");
	scanf("%d",&k);
	FindK(a,0,9,k);
	printf("第%d小的元素为 %d",k,a[k-1]);
} 


