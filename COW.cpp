#include <bits/stdc++.h>
#define ll long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll,vector<ll>>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e5+5;
int n,i,j,c;
ll a[N];
bool check (ll x)
{
    int cnt=1,vt=a[1];
    for (i=2;i<=n;i++)
    {
        if (a[i]-vt>=x)
        {
            cnt++;
            vt=a[i];
        }
    }
    return cnt>=c;

}
int main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);;
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>c;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort (a+1,a+n+1);
    ll d=0,c=1e9,mid;
    while (d+1<c)
    {
        mid=(d+c)/2;
        if (check(mid)) d=mid;
        else c=mid;
    }
    // if (check(d))   cout<<d;
    // else cout<<c;
    cout<<d;
}
