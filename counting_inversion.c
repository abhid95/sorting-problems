#include<iostream>
using namespace std;
int n;
int divide(int a[],int p,int r);
int fix(int a[],int p,int q,int r);
int main()
{
int i,a[250],count;
cin>>n;
for(i=0;i<n;i++)
{
	cin>>a[i];
}
count=divide(a,0,n-1);
for(i=0;i<n;i++)
cout<<a[i]<<endl;
cout<<" number of inversions"<<count<<endl;
return 0;
}
int divide(int a[],int p,int r)
{
int m,count=0;
if(p<r)
{
	m=(p+r)/2;	
    count=divide(a,p,m);
	count=count+divide(a,m+1,r);
	count=count+fix(a,p,m,r);
}
return count;
}
int fix(int a[],int p,int q,int r)
{
int i,j,m,b[250],o,count=0;
for(i=p,m=q+1,o=p;i<=q&&m<=r;)
{
	if(a[i]<=a[m])
	{
		b[o++]=a[i++];

	}
	else
	{
		b[o++]=a[m++];
		count+=1+q-i;
		
	}
	
}
for(;i<=q;i++)
b[o++]=a[i];
for(;m<=r;m++)
b[o++]=a[m];
label:
for(i=p;i<=r;i++)
a[i]=b[i];
return count;
}
