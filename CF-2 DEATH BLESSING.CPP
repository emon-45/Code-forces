
#include<bits/stdc++.h>
using namespace std;
int main(){

int test;
cin>>test;
while(test--){
        int num;
        cin>>num;
        vector<long long int> a(num),b(num);
        for(int i=0;i<num;i++){
            cin>>a[i];
        }
        for(int i=0;i<num;i++){
            cin>>b[i];
        }


        long long int  ans=0;

       for(int i=0;i<num;i++){
            if(i==num-1){
                ans+=a[i];
                break;
            }
            if(a[i]+(a[i+1]+b[i])<=a[i+1]+(a[i]+b[i+1])){
                ans+=a[i];
                a[i+1]+=b[i];
            }
            else{
                ans+=a[i+1];
                a[i]+=b[i+1];
                swap(a[i+1],a[i]);
                swap(b[i+1],b[i]);
            }
        }


        cout<<ans<<endl;
    }
    return 0;
}
