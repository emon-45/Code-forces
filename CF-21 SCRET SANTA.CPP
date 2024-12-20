#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        cin>>n;
        int alreadygifted[n+1]={0};

        int initialwanttoggift[n+1];

        int finallist[n+1];

        stack<int> notyetgifted;
        int ans=0;

        int giftedby[n+1]={0};

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;

            initialwanttoggift[i]=x;

            if(alreadygifted[x]==1)
            {
                finallist[i]=-1;
            }
            else
            {
                ans++;
                giftedby[x]=i;
                alreadygifted[x]=1;
                finallist[i]=x;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (alreadygifted[i] == 0)
            {
                notyetgifted.push(i);
            }
        }


        if(notyetgifted.size() == 1)
        {
            int z = notyetgifted.top();
            if(finallist[z]==-1)
            {
                finallist[z]=initialwanttoggift[z];
                finallist[giftedby[initialwanttoggift[z]]]=z;
            }
        }

        int last;
        for (int i = 1; i <= n ; i++)
        {
            if (finallist[i] != -1)
            {
                continue;
            }
            int z = notyetgifted.top();
            notyetgifted.pop();

            if (i == z)
            {
                if(!notyetgifted.empty())
                {
                    finallist[i] = notyetgifted.top();
                    notyetgifted.pop();
                    notyetgifted.push(z);
                    last =i;
                }
                else
                {
                    finallist[i]=z;
                    swap(finallist[i],finallist[last]);
                }
            }
            else
            {
                finallist[i] = z;
                last =i;
            }
        }

        cout<<ans<<"\n";
        for (int i = 1; i <= n; i++)
        {
            cout<<finallist[i]<<" ";
        }
        cout<<"\n";



    }

    return 0;
}
