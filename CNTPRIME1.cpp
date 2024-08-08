#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e5+5;
const int M=1e7+5;
int d[M]={0};
int n,i,j;
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
signed main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);;
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int l,r;
    cin>>l>>r;
    sang();
    for (i=l;i<=r;i++)
    {
        cnt+=abs(d[i]-1);
    }
    cout<<cnt;
}
