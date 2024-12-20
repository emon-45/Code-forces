#include<bits/stdc++.h>
const int MOD=1e9+7;
typedef long long int ll;

using namespace std;


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n,i,pos=-1;
       cin>>n;
       ll ar[n+2];
       for(i=1;i<=n;i++)
        cin>>ar[i];
       for(i=1;i<=n;i++)
       {
          if(ar[i]==1){
            pos=i;
            break;
          }
       }
       if(pos==-1){
        for(i=1;i<=n+1;i++)
            cout<<i<<" ";
        cout<<endl;
       }
       else {
        for(i=1;i<pos;i++)
            cout<<i<<" ";
        cout<<n+1<<" ";
        for(i=pos;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
       }
    }
    return 0;
}
