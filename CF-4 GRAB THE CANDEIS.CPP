#include <bits/stdc++.h>
using namespace std;


int main(){

    int test;
    cin>>test;
    while(test--){
    int num;
    cin>>num;
        vector<int> a(num);
        for(int i=0;i<num;i++){
            cin>>a[i];
        }

        int even=0,odd=0;
        for(int i=0;i<num;i++){
        if(a[i]%2==0){
              even+=a[i];
            }
            else{
             odd+=a[i];
            }
        }
        if(even>odd){
        cout<<"YES"<<endl;
        }
        else{
        cout<<"NO"<<endl;
        }
    }
    return 0;
}
