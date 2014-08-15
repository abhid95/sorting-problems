#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void heap(int a[],int n)
{
    int i,child,par,j;
    for(i=0;i<n;i++)
    {
        child=i;
        do
        {
            par=(child-1)/2;
            if(a[par]<a[child])
                swap(&a[par],&a[child]);
            child=par;
        }while(child!=0);
    }
    for(i=0;i<n;i++)
        printf(" %d\n",a[i]);
    for(j=n-1;j>=0;j--)
    {
        swap(&a[0],&a[j]);//sorting process starts taking place from the end
        par=0;            //max element is sent to the end-i position in each outer loop
        do
        {
            child=2*par+1;
            if(a[child]<a[child+1] && child<j-1)//be care
                child++;                        //rearranging only children of that parent in increasing order
            if(a[par]<a[child] && child<j)
                swap(&a[par],&a[child]);
            par=child;
            for(i=0;i<n;i++)
                printf("%d ",a[i]);
            printf("\n");
        }while(child<j);
        for(i=0;i<n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
}
int main()
{
    int i,a[100],n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    heap(a,n);
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
return 0;
}
