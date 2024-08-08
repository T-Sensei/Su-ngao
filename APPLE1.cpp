#include <bits/stdc++.h>
#define ll long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=100;
int n,i,j;
int xa,ya,xb,yb,xc,yc;
double S,Sp;
int x,y;
double xet(int xb,int yb,int xc,int yc,int xm,int ym)
{
    double S1=abs((xb-xm)*(yc-ym)-(xc-xm)*(yb-ym));
    return S1/2;
}
int main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);;
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    S=abs((xb-xa)*(yc-ya)-(xc-xa)*(yb-ya));
    S=S/2;;
    cout<<fixed<<setprecision(1)<<S<<"\n";
    cin>>n;
    int cnt=0;
    for (i=1;i<=n;i++)
    {
        cin>>x>>y;
        Sp=xet(xa,ya,xb,yb,x,y)+xet(xb,yb,xc,yc,x,y)+xet(xc,yc,xa,ya,x,y);
        if (Sp==S)  
        {
            cout<<x<<" "<<y<<"\n";
            cnt++;
        }
    }
    cout<<cnt;
}
