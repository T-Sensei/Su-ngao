#include<bits/stdc++.h>
using namespace std; 
#define             ll  long long
//#define             int long long
#define             db  double 
#define             fi  first
#define             se  second
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define        MASK(i)   (1ll<<(i))
#define       c_bit(i)  __builtin_popcountll(i)  //đếm số bit đang bật
#define       BIT(x,i)  ((x) & MASK(i))  //TRẠNG THÁI CỦA BIT THỨ I TRONG X
#define    set_on(x,i)  ((x) | MASK(i)) // bật bit thứ i trong x
#define   set_off(x,i)  ((x) & ~MASK(i)) //tắt bit thứ i trong x
#define             pb  push_back
#define           TASK  "COLORPATH"

template <class X, class Y>
    bool minimize (X &x, const Y &y)
    {
        if (x>y)
        {
            x=y;
            return 1;
        }
        else return 0;
    }
template <class X, class Y>
    bool maximize(X &x, const Y &y)
    {
        if (x<y)
        {
            x=y;
            return 1;
        }
        else return 0;
    }
template <class T>
    T Abs(const T &x)
    {
        return (x<0 ? -x : x);
    }

const int sm =1e9+7,sm2=1e9+7; 

ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void add (ll &x, const ll &y) {x+=y; if (x>=sm) x-=sm;}
void sub (ll &x, const ll &y) {x-=y; if (x<0) x+=sm;}

int xx[]={0,-1,-1,0,1,1,1,0,-1};
int yx[]={0,0,1,1,1,0,-1,-1,-1};

const db PI = acos(-1);
const ll inf = 1e18;
const int N = 100005 ,base=331;
bool mtt = 0 ;
int test = 1 ;  

//------Starting-------
int n,m,k;
int a[N];
vector <int> g[N];
int c[N][7];
pair <int,int> e[N];
//ll res=0;

void doc()
{
    cin>>n>>m>>k;
    FOR(i,1,n)  cin>>a[i];
    FOR(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

ll f[N][1<<5];

void sub1()
{
    ll TT=MASK(k)-1;
    FOR(i,1,n)
    {
        f[i][MASK(a[i]-1)]=1;
    }
    FOR(x,1,TT)
    {
        FOR(u,1,n)
        {
            for (int v:g[u])
            {
                if (BIT(x,a[v]-1)==0)
                {
                    int p = set_on (x,a[v]-1);
                    f[v][p]+=f[u][x];
                }
            }
        }
    }
    ll res=0;
    FOR(x,0,TT) FOR(u,1,n)
    {
        if (c_bit(x)>=2)    res+=f[u][x];   
    }
    cout<<res;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    else if (fopen("INP.INP","r"))
    {
        freopen("INP.INP","r",stdin);
        freopen("INP.OUT","w",stdout);
    }
    if(mtt) cin>>test;
    //solve();
    FOR(i,1,test)
    {
        doc();
        sub1();
    }
    //cout<<ma;
}