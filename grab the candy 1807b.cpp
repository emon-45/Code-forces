#include <bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin>>test;
    while(test--){
        long long  num,k;
        cin>>num>>k;
        long long  p,q;
        cin>>p>>q;
        vector<long long > arr(num);
        for(int i=0;i<num;i++){
            cin>>arr[i];
        }

        long long  ans=0;
        long long  val;
        long long rem=k;
        for(int i=0;i<num;i++){
            if(i==0 or val<arr[i] or rem<1){
                ans++;
                rem=k;
                val=arr[i]+p+q;
            }
            rem--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
