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
#define           TASK  "SALE"

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
void add (int &x, const int &y) {x+=y; if (x>=sm) x-=sm;}
void sub (int &x, const int &y) {x-=y; if (x<0) x+=sm;}

int xx[]={0,-1,-1,0,1,1,1,0,-1};
int yx[]={0,0,1,1,1,0,-1,-1,-1};

const db PI = acos(-1);
const ll inf = 1e18;
const int N = 10000+5 ,base=331;
bool mtt = 0 ;
int test = 1 ;  

//------Starting-------
int n,k;
vector <int> g[N];

void doc()
{
    cin>>n>>k;
    FOR(i,1,n-1)
    {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
}

//gọi f[u]=số nút trên cây nhánh u gốc root
int f[N];

void dfs(int u,int parent)
{
    f[u]=1;
    for(int v:g[u])
    {
        if (v==parent)  continue;
        dfs(v,u);
        f[u]+=f[v];
    }
}

int find(int u,int parent)
{
    for (int v:g[u])
    {
        if (v==parent)  continue;
        if (f[v]>n/2)   return find(v,u);

    }
    return u;
}

void sub1()
{
    dfs(1,0);
    int root=find(1,0);
    dfs(root,0);
    sort(f+1,f+n+1,greater <int>());

    ll res=0;
    FOR(i,k+2,n)    res+=f[i];
    cout<<res;
}


void sub2()
{
    
    

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
}