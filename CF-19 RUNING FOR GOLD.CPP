#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main(void)
{

    int T, n;
    cin>>T;
    while (T--)
    {
        cin >> n;
        int a[n][5];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cin>>a[i][j];
            }
        }
        if (n == 1)
        {
            cout<<"1\n";
            continue;
        }

        int res = -1, max = 0;
        for (int i = 1; i < n; ++i)
        {
            int num = 0;
            for (int j = 0; j < 5; ++j)
            {
                if (a[i][j] < a[max][j])
                {
                    num++;
                }
            }
            if (num >= 3)
            {
                max = i;
            }
        }
        int i;
        for (i = 0; i < n; ++i)
        {
            int num = 0;
            if (i != max)
            {
                for (int j = 0; j < 5; ++j)
                {
                    if (a[i][j] < a[max][j])
                    {
                        num++;
                    }
                }
                if (num >= 3)
                {
                    res = -1;
                    break;
                }
            }
        }
        if (i == n)
        {
            res = max + 1;
        }
     cout<<res;
    }

    return 0;
}
