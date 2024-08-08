#include <bits/stdc++.h>
#define ll long long
#define TASK "INP"
using namespace std;
const int N=500+5,NN=4*N;
const ll M=1e9+7;
int n,p,c,i,j,a[N];
ll f[N][N];
double b[N];
int d[N];
struct bg 
{
    int id; ll ts;
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
    for (i=1;i<=p;i++)
    {
        f[x][i]=1e9;
        d[i]=0;
    }
    priority_queue<bg,vector<bg>,cmp> h;
    f[x][x]=0;
    h.push({x,f[x][x]});
    while (!h.empty())
    {
        int u=h.top().id;
        h.pop();
        if (d[u]==1)    continue;
        d[u]=1;
        for (i=0;i<v[u].size();i++)
        {
            int kk=v[u][i].id;
            ll ts=v[u][i].ts;
            if (f[x][kk]>f[x][u]+ts and d[kk]==0)
            {
                f[x][kk]=f[x][u]+ts;
                h.push({kk,f[x][kk]});
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
    cin>>p>>n>>c;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=c;i++)
    {
        int t,b,c;
        cin>>t>>b>>c;
        v[t].push_back({b,c});
        v[b].push_back({t,c});
    }
    for (j=1;j<=p;j++)
    {
            dijkstra(j);
        for (int z=1;z<=n;z++)
        {
            b[j]+=f[j][a[z]];
        }
        b[j]=(double)(b[j])/n;
        // cout<<j<<" "<<b[j]<<"\n";
    }
    double res=1e9;
    for (i=1;i<=p;i++)
    {
        
            res=min(res,b[i]);
        
    }
    for (i=1;i<=p;i++)
    {
        
            if (b[i]==res)  
            {
                cout<<i;
                return 0;
            }
        
    }


}