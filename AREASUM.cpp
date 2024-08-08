#include <bits/stdc++.h>
#define ll long long
#define int long long 
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e5+5,NN=5*1e5+5;
const ll M=1e9+7;
int n,i,j,m;
ll x[N],y[N],r1,r2;
void sub()
{
    r1=0;r2=0;
    for (i=2;i<=n;i++)
    {
        r1=(r1+(abs(x[i]-x[i-1])*((n-i+1)*(i-1)%M))%M)%M;
    }
    for (i=2;i<=m;i++)
    {
        r2=(r2+(abs(y[i]-y[i-1])*((m-i+1)*(i-1)%M))%M)%M;   
    }
    ll s=(r1*r2)%M;
    cout<<s;


}
signed main()
{

    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for (i=1;i<=m;i++)
    {
        cin>>y[i];
    }
    sort (x+1,x+n+1);
    sort (y+1,y+m+1);
    sub();
    
}