#include<stdio.h>
#include<stdlib.h>

int mrg(int a[],int mn,int mid,int mx)
{
    int i,k,t[100],j,m,cnt=0;
    j=mn;
    m=mid+1;
    for(i=mn;j<=mid && m<=mx;i++)
    {
        if(a[j]<=a[m])
            t[i]=a[j++];
        else
        {
            t[i]=a[m++];
            cnt+=mid-j+1;//remember this
        }
    }
    if(j>mid)
        for(k=m;k<=mx;k++)
            t[i++]=a[k];
    else
        for(k=j;k<=mid;k++)
            t[i++]=a[k];
    for(i=mn;i<=mx;i++)
        a[i]=t[i];
    return cnt;
}

int prt(int a[],int mn,int mx)
{
    int cnt=0;
    int mid;
    if(mn<mx)
    {
        mid=(mx+mn)/2;
        cnt=prt(a,mn,mid);
        cnt+=prt(a,mid+1,mx);
        cnt+=mrg(a,mn,mid,mx);
    }
    return cnt;
}

int main()
{
    int n,a[100],i,j,cnt;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    cnt=prt(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n%d",cnt);
    return 0;
}
