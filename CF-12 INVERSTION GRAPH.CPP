#include<bits/stdc++.h>
using  namespace  std;

typedef long long int ll;


bool prime(int n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}


int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int ar[n+3];
       for(int i=1;i<=n;i++)cin>>ar[i];
       int ans = 1;
       int val = ar[1];
       int cnt = 1;
       for(int i=2;i<=n;i++)
       {
           if(ar[i]>val)
           {
               if(cnt==val){

                  ans++;
               }
               val = ar[i];
           }

           cnt++;
       }
       cout<<ans<<endl;
    }
}


