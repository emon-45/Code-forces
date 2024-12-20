#include<bits/stdc++.h>
using namespace std;
#define ll long long int
using namespace std;


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int numf = 0, numb = 0, num_ = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '-')
                num_++;
            else if (s[i] == '>')
                numf++;
            else
                numb++;
        if (numb == 0 || numf == 0)
            cout << n << endl;
        else
        {
            int ans = 0;
            if (s[0] == '-' || s[n - 1] == '-')
                ans++;
            for (int i = 1; i < n; i++)
                if (s[i - 1] == '-' || s[i] == '-')
                    ans++;
            cout << ans << endl;
        }
    }
    return 0;
}

