#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pie_value 3.14159265358979323846

int main() {


	ll t;
	cin >> t;

	while (t--) {

		ll n;
		cin >> n;

		string arr[n + 1];
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}

		ll a[n + 1][n + 1];
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				a[i + 1][j + 1] = arr[i][j] - '0';
			}
		}



		ll vis[n + 1][n + 1];
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				if (i == n || j == n) {
					if (a[i][j] == 1)
						vis[i][j] = 1;
					else
						vis[i][j] = 0;
				}
			}
		}

		for (ll i = n - 1 ; i >= 1; i--) {
			for (ll j = n - 1 ; j >= 1; j--) {

				if (a[i][j] == 0)
					vis[i][j] = 0;
				else {
					ll row_flag = 0, col_flag = 0;


					for (ll row = i + 1 ; row <= n; row++) {
						if (vis[row][j] == 1 ) {
							row_flag = 0;
							break;
						}
						else {
							row_flag = 1;
							break;
						}
					}

					for (ll col = j + 1 ; col <= n; col++) {
						if (vis[i][col] == 1) {
							col_flag = 0;
							break;
						}
						else {
							col_flag = 1;
							break;
						}
					}

					if (row_flag == 1 && col_flag == 1)
						vis[i][j] = 0;
					else
						vis[i][j] = 1;
				}
			}
		}

		ll flag = 0;
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {

				if (vis[i][j] != a[i][j])
					flag = 1;
			}

		}

		if (flag == 1) {
			cout << "NO" << "\n";
		} else {
			cout << "YES" << "\n";
		}

	}


	return 0;
}

