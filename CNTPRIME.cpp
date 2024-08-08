#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e5+5;
const int M=1e7+5;
short d[M]={0};
ll n,i,j,l,r;
int cnt=0;
void sang()
{
    d[0]=1;
    d[1]=1;
    for (i=1;i*i<=M;i++)
    {
        if (d[i]==0)
        for (j=i*i;j<=M;j+=i)
        {
            d[j]=1;
        }
    }
}
void sangd(ll l,ll r)
{

    for (i=2;i*i<=r;i++)
    {
        // if (d[i]==0)
        for (j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
        {
            d[j-l]=1;
        }
    }
    if (1>=l)   d[1-l]=1;
    for (i=l;i<=r;i++)
    {
        if (!d[i-l])  cnt++;
    }
    cout<<cnt;
}
signed main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);;
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // ll l,r;
    cin>>l>>r;

    // sang(l,r);
    if (r<=5*1e6)
    {
        sang();
        for (i=l;i<=r;i++)
        {
            cnt+=abs(d[i]-1);
        }
        cout<<cnt;
    }
    else sangd(l,r);
}
