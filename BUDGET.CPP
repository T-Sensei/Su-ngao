#include <bits/stdc++.h>
#define ll long long
#define TASK "INP"
using namespace std;
const int N=1e2+5,NN=8*N;
int n,i,j,m;
ll p,s[N],c[N],a[N],f[N];
bool check(ll x)
{
	bool res=0;
	for (i=1;i<=n;i++)
	{
		f[i]=x+1;
	}
	for (j=1;j<=m;j++)
	{
		res=0;
		for (i=1;i<=n;i++)
		{
			if (f[i]>=c[j]+a[i]-1)
			{
				f[i]-=a[i];
				res=1;
				break;
			}
		}
		if (!res)	return 0;
	}
	return 1;
}
int main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>p;
    for (i=1;i<=n;i++)
    {
    	cin>>s[i];
    }

    for (i=1;i<=m;i++)
    {
    	cin>>c[i];
    }
    sort (c+1,c+m+1,greater<ll>());
    for (i=1;i<=n;i++)
    {
    	a[i]=p/s[i]+(p%s[i]!=0);
    }
    sort (a+1,a+n+1);
    ll l=0,r=1e14,mid;
    while (l+1<r)
    {
    	mid=(l+r)/2;
    	if (check(mid))	r=mid;
    	else l=mid;
    }
    if (check(r))	cout<<r;
    else cout<<l;

}



