#include<stdio.h>
#include<stdlib.h>

void mrg(int a[],int mn,int mid,int mx)
{
    int i,k,t[100],j,m;
    j=mn;
    m=mid+1;
    for(i=mn;j<=mid && m<=mx;i++)
    {
        if(a[j]<=a[m])
            t[i]=a[j++];
        else
            t[i]=a[m++];
    }
    if(j>mid)
        for(k=m;k<=mx;k++)
            t[i++]=a[k];
    else
        for(k=j;k<=mid;k++)
            t[i++]=a[k];
    for(i=mn;i<=mx;i++)
        a[i]=t[i];
}

void prt(int a[],int mn,int mx)
{
    int mid;
    if(mn<mx)
    {
        mid=(mx+mn)/2;
        prt(a,mn,mid);
        prt(a,mid+1,mx);
        mrg(a,mn,mid,mx);
    }
}

int main()
{
    int n,a[100],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    prt(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
