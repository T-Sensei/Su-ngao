//I'm still the same person with the same name. But with a different mindset and a new game!
//----------------------------------------------------
// When you are serious about your dreams:
/* Be ready to be alone
            to be laughed
            to lose friends
            to face the world
            to fail
            to be depressed
        and disrespected!
                            */

//=================================

#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=500+5,NN=1e5+5;
int n,i,u,v,j,r,k;
int a[N][N],f[N][N];
int x,y;
signed main() 
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>r>>k;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    // for (i=1;i<=n;i++)  for (j=1;j<=n;j++)  f[i][j]=0;
    ll sum=0;
    while (k--)
    {
        cin>>x>>y;
        for (u=x;u<=min(n,x+r-1);u++)
        {
            for (v=y;v<=min(n,y+r-1);v++)
            {
                f[u][v]++;
                sum+=a[u][v];
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (f[i][j]>0)  sum-=(f[i][j]-1)*a[i][j];
        }
    }
    cout<<sum;


}//I'm still the same person with the same name. But with a different mindset and a new game!
//----------------------------------------------------
// When you are serious about your dreams:
/* Be ready to be alone
            to be laughed
            to lose friends
            to face the world
            to fail
            to be depressed
        and disrespected!
                            */

//=================================

#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=500+5,NN=1e5+5;
int n,i,u,v,j,r,k;
int a[N][N],f[N][N];
int x,y;
signed main() 
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>r>>k;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    // for (i=1;i<=n;i++)  for (j=1;j<=n;j++)  f[i][j]=0;
    ll sum=0;
    while (k--)
    {
        cin>>x>>y;
        for (u=x;u<=min(n,x+r-1);u++)
        {
            for (v=y;v<=min(n,y+r-1);v++)
            {
                f[u][v]++;
                sum+=a[u][v];
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (f[i][j]>0)  sum-=(f[i][j]-1)*a[i][j];
        }
    }
    cout<<sum;


}
