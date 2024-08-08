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
#define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e5+5,NN=8*N;
const ll M=1e9+7;
int n,m,w,h,i,j;
vector <int> g;
ll a[N],b[N],sa[N],sb[N];
// ll HCN(int x,int y,int u,int v)
// {
//     return f[u][v]-f[x-1][v]-f[u][v-1]
// }
void sub4()
{
    sa[0]=0;
    for (i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
    sb[0]=0;
    for (i=1;i<=m;i++)  sb[i]=sb[i-1]+b[i];
    ll r1=-1e17,r2=-1e17;
    for (i=w;i<=n;i++)  
    {
        r1=max(r1,sa[i]-sa[i-w]);
    }
    for (i=h;i<=m;i++)
    {
        r2=max(r2,sb[i]-sb[i-h]);
    }
    cout<<(r1*h+r2*w);
}
signed main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>w>>h;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    // for (i=1;i<=n;i++)
    // {
    //     for (j=1;j<=n;j++)
    //     {
    //         c[i][j]=a[i]+b[j];
    //     }
    // }
    // for (i=1;i<=n;i++)
    // {
    //     for (j=1;j<=n;j++)
    //     {
    //         f[i][j]=c[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
    //     }
    // }
    sub4();



}