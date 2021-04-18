#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define max 1e6;
struct node {
	double x;
	double y;
}p[1000];

double distance(int l, int r){
	double re;
	re=sqrt( (p[l].x-p[r].x)*(p[l].x-p[r].x) + ((p[l].y-p[r].y)*(p[l].y-p[r].y)) );
	return re;
}
double min(double l, double r){
	if (l<r)
		return l;
	else 
		return r;
}
double getre(int l, int r){
	double d=max ;
	int i=0,j=0,k=0;
	int t[1000]={0}; 
	if (l==r)
		return d;
	if (r-l==1)
		return distance(l, r);
	double dl=getre(l, (l + r)/2);
	double dr=getre( (l + r)/2+1, r);
	d=min(dl, dr);
	for (i=l;i<=r;i++){
		if (fabs(p[(l+r)/2].x -p[i].x) <= d)
			t[k++]=i; 
	}
	for (i=0; i<=k-1; i++)
		for (j = i+1; j <= k-1;j++)
			if (p[t[j]].y-p[t[i]].y <d)
				d=min(d,distance(t[i],t[j]));
	return d;
}
int cmp(const void *a,const void *b){
	struct node aa=*(struct node *)a;
	struct node bb=*(struct node *)b;
	return aa.x-bb.x;
}

int main(){
	int n = 1,i;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
		break;
		for (i=0;i<n;i++)
			scanf("%lf %lf", &p[i].x,&p[i].y);
		qsort(p, n, sizeof(p[0]),cmp);
		printf("×î½üµã¾àÀë£º%lf\n", getre(0, n-1));
	}
	return 0;
}

