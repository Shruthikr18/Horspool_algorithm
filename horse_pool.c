#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *shift(char* ,int);
int horse_pool(char* b,int m,char* a,int n,int* table,int size);
int main()
{ int size=500;
char *a=(char *)(malloc(sizeof(char)*1000000));

	int i,n,m;

	scanf(" %[^\n]s",a);
	char *b=(char *)(malloc(sizeof(char)*1000000));
	scanf(" %[^\n]s",b);
	n=strlen(a);
	m=strlen(b);
    int* table=shift(b,m);
    int pos=horse_pool(b,m,a,n,table,size);
    printf("\n%d",pos+1);
    return 0;
}
int* shift(char* b,int m)
{ int i,size=500,j;
  int* table;
  table=(int*)malloc(sizeof(int)*size);
    for(i=0;i<=size-1;i++)
    {
        table[i]=m;

    }
    for(j=0;j<m-1;j++)
    {
        table[b[j]]=m-1-j;
       // printf("%d ",table[b[j]]);
    }
return table;
}
int horse_pool(char* b,int m,char* a,int n,int* table,int size)
{   int i,k;

    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while((k<=m-1)&&(b[m-1-k]==a[i-k]))
        {
            k=k+1;
        }
        if(k==m)
        {
            return i-m+1;
        }
        else{
            i=i+table[a[i]];

            }
    }
    return -1;

}

