#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void ins(int a[],int loc,int ele)
{
    int par;
    while(loc>0)
    {
        par=(loc-1)/2;
        if(ele>a[par])
        {
            a[loc]=ele;
            return;
        }
        a[loc]=a[par];
        loc=par;
    }
    a[0]=ele;
}

void disp(int a[],int n)
{
    int i;
    if(n==0)
        printf("no nodes\n");
    for(i=0;i<n;i++)
        printf("  %d\n",a[i]);
}

void del(int a[],int n,int ele)
{
    int i,par,left,right;
    for(i=0;i<n;i++)
        if(a[i]==ele)
            break;
    if(ele!=a[i])
    {
        printf("%d not found\n",ele);
        return;
    }
    a[i]=a[n-1];//put last element in place of element to be deleted
    n=n-1;      //decrement n here as well as in main function;
    par=(i-1)/2;
    if(a[i]<a[par])
    {
        ins(a,i,a[i]);//no need of sending n
        return;
    }
    left=2*i+1;
    right=2*i+2;
    while(right<n)
    {
        if(a[i]<=a[left] && a[i]<=a[right])
            return;
        if(a[right]>=a[left])
        {
            swap(&a[i],&a[left]);
            i=left;
        }
        else
        {
            swap(&a[i],&a[right]);
            i=right;
        }
        left=2*i+1;
        right=2*i+2;
    }
    if(left==n-1 && a[i])
        swap(&a[i],&a[left]);//still not clear why this is done
}

int main()
{
    int a[100],i,j,k,n=0,choice,ele;
    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter ele\n");
                    scanf("%d",&ele);
                    ins(a,n,ele);
                    n=n+1;
                    break;
            case 2:printf("enter ele\n");
                    scanf("%d",&ele);
                    del(a,n,ele);
                    n=n-1;
                    break;
            case 3:disp(a,n);
                    break;
            case 4:return 0;
        }
    }
return 0;
}
