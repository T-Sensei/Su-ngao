
#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=2*1e5+5,NN=8*N;
const int M=1e9+7;
struct bg {int x,y;};
struct bg2{int x,y,w;};
bool cmp(bg u,bg v){return u.x<v.x;}
bg e[N];int n,m,i,j,q;
bg a[N];
ll f[N];
int dd[N]={0},r1,r2,c[N];
vector <bg> vx,vy;
vector <bg2> v;
bool cmp2(bg2 u,bg2 v)
{
    return u.w<v.w;
}
vector <int> ka;
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
int main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    //----------sub1---------
    for (i=1;i<=n;i++)  f[i]=-1;

    // for (i=1;i<=n;i++)  for (j=i+1;j<=n;j++)   
    //     v.push_back({i,j,min(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y))});
    // sort (v.begin(),v.end(),cmp2);
    // ll sum=0,sl=0;
    // for (i=0;i<v.size();i++)
    // {
    //     r1=goc(v[i].x);
    //     r2=goc(v[i].y);
    //     if (r1!=r2)
    //     {
    //         sum+=v[i].w;
    //         HN(r1,r2);
    //         sl++;
    //         if (sl==n-1)    
    //         {
    //             cout<<sum;
    //             return 0;
    //         }
    //     }
    // }

    //------------sub2--------

    for (i=1;i<=n;i++)
    {
        vx.push_back({a[i].x,i});
        vy.push_back({a[i].y,i});
    }
    sort(vx.begin(),vx.end(),cmp);
    sort (vy.begin(),vy.end(),cmp);
    for (i=1;i<n;i++)
    {
        v.push_back({vx[i-1].y,vx[i].y,vx[i].x-vx[i-1].x});
        v.push_back({vy[i-1].y,vy[i].y,vy[i].x-vy[i-1].x});
    }
    sort (v.begin(),v.end(),cmp2);
    ll sl=0,sum=0;
    for (i=0;i<=n;i++)
    {
        r1=goc(v[i].x);
        r2=goc(v[i].y);
        if (r1!=r2)
        {
            HN(r1,r2);
            sum+=v[i].w;
            sl++;
            if (sl==n-1)
            {
                break;
            }
        }
    }
    cout<<sum;
    

}