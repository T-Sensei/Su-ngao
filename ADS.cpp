
#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e4+5,NN=8*N;
const int M=1e9+7;
struct bg {int x,y;};
bg e[N];int n,m,i,j,q;
ll f[N];
int dd[N],r1,r2;
int goc(int x)
{
    while (f[x]>0)  x=f[x];
    return x;
}
void HN(int r1,int r2)
{
    int t=f[r1]+f[r2];
    if (abs(f[r1])>abs(f[r2]))
    {
        f[r1]=t;
        f[r2]=r1;
    }
    else 
    {
        f[r2]=t;
        f[r1]=r2;
    }
}
void CK()
{
    for (i=1;i<=n;i++)
    {
        f[i]=-1;
    }
    for(i=1;i<=m;i++)
    {
        r1=goc(e[i].x);
        r2=goc(e[i].y);
        if (r1!=r2) HN(r1,r2);
    }
}
void CK2()
{
    for (i=1;i<=n;i++)  f[i]=-1;
    for (i=1;i<=m;i++)  
    {
        r1=goc(e[i].x);
        r2=goc(e[i].y);
        if(r1!=r2)  HN(r1,r2);
    }
    for (i=1;i<=n;i++)  cout<<f[i]<<" ";
    ll cnt=0;
    for (i=1;i<=n;i++)
    {
        if (f[i]<0) cnt++;
    }
    cout<<m-n+cnt;
}
int main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>e[i].x>>e[i].y;
    }
    CK2();
}