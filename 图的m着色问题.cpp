#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n;//n���ڵ�
int m;//m����ɫ
int mm[100][100];//��¼ͼ���ڽӾ���
int x[100];//��¼ɫ��һ�ֿ����ԣ�x[i]=1,2,3..k..n����ڽڵ�i��ɫΪk
int best[100];
int sum=0;//������¼��ǰ���е���ɫ
bool a(int i){
    int j;
    for(j=1;j<=n;j++){
        if((mm[i][j]==1)&&(x[i]==x[j]))
            return false;
    }
    return true;
}
void dd(int i){
    int j;
    if(i>n){
        sum++;
        for(j=1;j<=n;j++)
            best[j]=x[j];//��¼һ��֦(��¼һ����ɫ�Ŀ�����)
    }
    else{
        for(j=1;j<=m;j++){//��i�ڵ㴦�������m�ֿ�����
             x[i]=j;//i�ڵ�ѡ����һ����ɫ
            if(a(i)){//ͨ��Լ������ȥ�����������ɫ
                 dd(i+1);//ת�Ƶ���һ��ĵ�i+1���ڵ�
            }
             x[i]=0;//Ϊi�����������ɫ
        }
    }
}
int main(){
    int t,k;
    int i,j;
    scanf("%d%d%d",&n,&k,&m);//k��k����
    for(t=0;t<k;t++){
        scanf("%d%d",&i,&j);
        mm[i][j]=1;
        mm[j][i]=1;
    }
    dd(1);
    if (sum)
    	printf("%d",sum);
    else
    	printf("NO");
    return 0;
}

