//! Bismillahi-Rahamanirahim.
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
 ** @Category:
/** ========================================**/


/**................ Headers ................**/
#include <bits/stdc++.h>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf (1ll<<25)
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 2010

//Fast Reader
template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};

vector<int>adj[mx];
int w[mx][mx];
vector<int>sinklist;
bool col[mx];
int par[mx];
ll totflow,flow;
int n,e;

void updategraph(int source, int sink){
    int prev,next;
    next=sink;
    flow=inf;
    while(par[next]>-1){
        prev=par[next];
        flow=min(flow, (ll)w[prev][next]);
        next=prev;
    }
    next=sink;
    while(par[next]>-1){
        prev=par[next];
        w[prev][next]-=flow;
        w[next][prev]+=flow;
        next=prev;
    }
}

bool augment_path(int source, int sink){
    queue<int>q;
    q.push(source);
    CLEAR(par,-1);
    CLEAR(col,0);
    col[source]=true;
    int prev,next;
    bool cnt=true;
    while(q.size() and cnt){
        int i;
        prev=q.front();
        q.pop();
        for(i=0;i<adj[prev].size();i++){
            next=adj[prev][i];
            if(!col[next] and w[prev][next]>0){
                col[next]=true;
                par[next]=prev;
                if(next==sink)continue;
                q.push(next);
            }
        }
    }
    return par[sink]!=-1;
}

void maxflow(int source, int sink){
    totflow=0;
    sinklist=adj[sink];
    while(augment_path(source,sink)){
        for(int i=0;i<sinklist.size();i++){
            int u=sinklist[i];
            if(!col[u] or w[u][sink]<=0)continue;
            par[sink]=u;
            updategraph(source,sink);
            totflow+=flow;
        }
    }
}

void makeedge(int a, int b, int c){
    adj[a].pb(b);
    adj[b].pb(a);
    w[a][b]+=c;
    w[b][a]+=0;
}

void inp(){
    read(n);read(e);
    CLEAR(w,0);
    for(int i=0;i<=2*n+5;i++)adj[i].clear();
    makeedge(1, 1+n, inf);
    makeedge(n, n+n, inf);
    for(int i=2;i<=n-1;i++){
        ll t;read(t);
        makeedge(i,i+n,t);
    }
    for(int i=1;i<=e;i++){
        int a,b;ll c;read(a);read(b);read(c);
        makeedge(a+n,b,c);
        makeedge(b+n,a,c);
    }
    int source=1, sink=n+n;
    maxflow(source,sink);
    printf("%lld\n",totflow);
}
int main() {
    #ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        inp();
    }
    return 0;
}





