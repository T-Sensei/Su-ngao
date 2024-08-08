#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e3+5;
int n,m,i,j,q,x,y,u,v;
char c;
int a[N][N],f[N][N]={0},g[N][N];
int main()
{
    if (fopen("inp.inp","r"))
    {
        freopen("inp.inp","r",stdin);
        freopen("out.out","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n>>q;
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            cin>>c;
            if (c=='*') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    for (i=1;i<m;i++)
    {
        for (j=1;j<n;j++)
        {
            g[i][j]=a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
        }
    }
    for (i=1;i<m;i++)
    {
        for (j=1;j<n;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+(g[i][j]%2==1);
        }
    }
    while (q--)
    {
        cin>>x>>y>>u>>v;
        u--;
        v--;
        int cnt=f[u][v]-f[x-1][v]-f[u][y-1]+f[x-1][y-1];
        if (cnt==0) cout<<"YES\n";
        else cout<<"NO\n";
    }

}
