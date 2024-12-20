#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(int test){
	int n, m;
	cin>>n>>m;
	string s[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	}
	if (m % 2)
	{
		cout<<"YES"<<endl;
		for (int i = 0; i < m + 1; ++i)
		{
			if (i % 2)
			{
				cout<<2<<" ";
			}
			else{
				cout<<1<<" ";
			}
		}
		cout<<endl;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int idxa = -1, idxb = -1;
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			if (s[i][j] == 'a')
			{
				idxa = j;
			}
			else{
				idxb = j;
			}
			if (s[i][j] == s[j][i])
			{
				cout<<"YES"<<endl;
				for (int k = 0; k < m + 1; ++k)
				{
					if (k % 2)
					{
						cout<<j + 1<<" ";
					}
					else{
						cout<<i + 1<<" ";
					}
				}
				cout<<endl;
				return;
			}
		}
		if (idxa != -1 and idxb != -1)
		{
			idxa++;
			idxb++;
			cout<<"YES"<<endl;
			if ((m / 2) % 2)
			{
				for (int k = 0; k < m / 2; ++k)
				{
					if (k % 2)
					{
						cout<<i + 1<<" ";
					}
					else{
						cout<<idxa<<" ";
					}
				}
				cout<<i + 1<<" ";
				for (int k = 0; k < m / 2; ++k)
				{
					if (k % 2)
					{
						cout<<i + 1<<" ";
					}
					else{
						cout<<idxb<<" ";
					}
				}
			}
			else{
				for (int k = 0; k < m / 2; ++k)
				{
					if (k % 2 == 0)
					{
						cout<<i + 1<<" ";
					}
					else{
						cout<<idxa<<" ";
					}
				}
				cout<<i + 1<<" ";
				for (int k = 0; k < m / 2; ++k)
				{
					if (k % 2)
					{
						cout<<i + 1<<" ";
					}
					else{
						cout<<idxb<<" ";
					}
				}
			}
			cout<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

int main(){
	cout<<setprecision(20);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t=1,k;
	cin>>t;
	k = t;
	while(t--){
		solve(k - t);
	}
	return 0;
}Nn
