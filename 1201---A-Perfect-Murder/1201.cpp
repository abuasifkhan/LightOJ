//! Bismillahi-Rahamanirahim.
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
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
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 1010

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

int n, e;
int dp[mx][5];
bool vis[mx];
vector<int>adj[mx];

void dfs(int u){
    vis[u]=true;
    dp[u][0]=0;
    dp[u][1]=1;
    for(int i=0;i<adj[u].size();i++){
        int v= adj[u][i];
        if(vis[v]==0){
            dfs(v);
            dp[u][0]+=max(dp[v][1],dp[v][0]);
            dp[u][1]+=dp[v][0];
        }
    }
}

int sol(){
    int M=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            M+=max(dp[i][0], dp[i][1]);
        }
    }
    return M;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        CLEAR(vis,0);CLEAR(dp,0);
        read(n);read(e);
        for(int i=0;i<=n;i++)adj[i].clear();
        for(int i=0;i<e;i++){
            int u,v;read(u);read(v);
            adj[u].pb(v);adj[v].pb(u);
        }
        printf("%d\n",sol());
    }
    return 0;
}





