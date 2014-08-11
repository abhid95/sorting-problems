#include<stdio.h>
#include<stdlib.h>
int prt(int a[],int first,int last)
{
    int i,j,pivot,temp;
    pivot=first;
    i=first;
    j=last;
    while(i<j)
    {
        while(a[i]<=a[pivot] && i<last)
            i++;
        while(a[j]>a[pivot])
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    return j;
}
void qks(int a[],int first,int last)
{
    int j;
    if(first<last)
    {
        j=prt(a,first,last);
        qks(a,first,j-1);
        qks(a,j+1,last);
    }
}
int main()
{
int i,j,n,a[100];
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
qks(a,0,n-1);
for(i=0;i<n;i++)
    printf("%d ",a[i]);

return 0;
}
