#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e6+5;
int n,i,j;
struct bg
{
    ll gt;
    int vt;
};
bg a[N];
bool cmp(bg x,bg y)
{
    return x.gt<y.gt;
}
set <ll> s;
set <ll>::iterator it,it1,it2;
ll ma=0,c=0;
int main()
{
    if (fopen("inp.inp","r"))
    {
        freopen("inp.inp","r",stdin);
        freopen("out.out","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i].gt;
        a[i].vt=i;
    }
    sort (a+1,a+n+1,cmp);
    s.insert(a[1].vt);
    s.insert(a[2].vt);
    c=2;
    for (i=3;i<=n;i++)
    {
        s.insert(a[i].vt);
        c++;
        it=s.find(a[i].vt);
        if (it==s.begin() or it==s.end())
        {
            c--;
            ma=max(ma,c);
            continue;
        }
        it--;
        it1=it;
        it++;
        it++;
        it2=it;
        it--;
        if (*it==*it1+1 and *it2-1==*it)
        {
            c--;
            ma=max(c,ma);
        }
    
        else ma=max(c,ma);
    }
    cout<<c;


}
