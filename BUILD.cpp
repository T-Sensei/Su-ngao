#include <bits/stdc++.h>
#define ll long long
#define TASK "INP"
using namespace std;
const int N=1e4+5,NN=4*1e6;
int n,m,i,j,u,r;
short k;
int a[10];
ll f[10][N];int dd[N];
int d[N];
struct bg
{
    int id;
    ll ts;
};
vector <bg> v[N];
struct cmp
{
    bool operator()(bg u,bg v)
    {
        return u.ts>v.ts;
    }
};
void dijkstra(int x)  
{
    for (j=1;j<=n;j++)
    {
        f[d[x]][j]=1e14;
        dd[j]=0;
    }
    priority_queue <bg,vector<bg>,cmp> h;
    f[d[x]][x]=0;
    h.push({x,f[d[x]][x]});
    while (!h.empty())
    {
        u=h.top().id;
        h.pop();
        if (dd[u]==1)   continue;
        dd[u]=1;
        for (j=0;j<v[u].size();j++)
        {
            r=v[u][j].id;
            ll z=v[u][j].ts;
            if (f[d[x]][r]>f[d[x]][u]+z and dd[r]==0)
            {
                f[d[x]][r]=f[d[x]][u]+z;
                h.push({r,f[d[x]][r]});
            }
        }
    }


}
int main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for (i=1;i<=n;i++)  d[i]=0;
    for (i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+k+1);
    for (i=1;i<=k;i++)
    {
        d[a[i]]=i;
    }
    for (i=1;i<=m;i++)
    {
        int a1,a2;ll a3;
        cin>>a1>>a2>>a3;
        v[a1].push_back({a2,a3});
        v[a2].push_back({a1,a3});
    }
    for (i=1;i<=k;i++)
    {
        dijkstra(a[i]);
    }
    ll ans=2e9;
    for (j=1;j<=n;j++)
    {
        if (d[j]==0)
        {
            sort (a+1,a+k+1);
            ll res=f[d[a[1]]][j];
                for (i=2;i<=k;i++)
                {
                   res+=f[d[a[i-1]]][a[i]];
                }
                res+=f[d[a[k]]][j];
                ans=min(res,ans);
                
            while (next_permutation(a+1,a+k+1))
            {
                ll res=f[d[a[1]]][j];
                for (i=2;i<=k;i++)
                {
                   res+=f[d[a[i-1]]][a[i]];
                }
                res+=f[d[a[k]]][j];
                ans=min(res,ans);
            }
        }
    }
    cout<<ans;





}