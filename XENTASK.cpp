#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,ans1,ans2,s11=0,s12=0,s21=0,s22=0,i,ans,n;
cin>>t;
while(t--)
{
    s11=0;s12=0;s21=0;s22=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ans;
        if(i%2==0)
            s11+=ans;
        else
            s21+=ans;
 
 
 
    }
 
    for(i=0;i<n;i++)
    {
        cin>>ans;
        if(i%2==0)
            s21+=ans;
        else
            s22+=ans;
 
 
 
    }
 
ans1=s11+s22;
ans2=s12+s21;
 
if(ans1<ans2)
    cout<<ans1<<"\n";
else
    cout<<ans2<<"\n";
 
 
 
 
}
 
}
 