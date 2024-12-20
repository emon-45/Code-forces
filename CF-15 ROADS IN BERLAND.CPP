#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 300;
ll dist[N+1][N+1];

ll update(int n , int a , int b , int w){
	dist[a][b] = dist[b][a] = min(dist[a][b] , w*1LL);

	ll sum = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j] = min(dist[i][j] , dist[i][a] + w + dist[b][j]);
			dist[i][j] = min(dist[i][j] , dist[i][b] + w + dist[a][j]);

			sum += dist[i][j];
		}
	}

	return sum;
}

int main(){
	int n , k;
	int a , b , w;

	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>dist[i][j];
	}

	cin>>k;
	while(k--){
		cin>>a>>b>>w;
		cout<<update(n , a , b , w)/2<<" ";
	}
}
