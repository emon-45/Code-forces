#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int num=(n*(n-1))/2;
        if(k<2)
        cout<<"NO\n";
        else if(k==2)
        {
            if(n==1 && m==0)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
        else if(k==3)
        {
            if(num==m)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
        else
        {
            if(m>=(n-1) && m<=num)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
    }
    return 0;
}n
