#include <bits/stdc++.h>
using namespace std;
int compare(const void *a,const void *b)
{
 
    return (*(int*)a-*(int*)b);
}
int main()
{
    int t,n,f,i,ar[100000];
cin>>t;
while(t--)
{
f=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
 
 
 
 
    }
qsort(ar,n,sizeof(int),compare);
for(i=0;i<n-1;i++)
{
 
    if(ar[i+1]-ar[i]>1)
    {
 
 
        f=1;
        break;
    }
    if(ar[i+1]-ar[i]==0)
    {
 
        f=2;
        break;
    }
}
 
if(f==1)
{
 
    if(i==0)
        cout<<ar[0]<<"\n";
    else if(i==n-2)
        cout<<ar[n-1]<<"\n";
    else
        cout<<ar[i]<<"\n";
}
 
else if(f==2)
    cout<<ar[i]<<"\n";
 
 
}
 
}
 