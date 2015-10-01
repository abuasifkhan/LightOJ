//! Bismillahi-Rahamanirahim.
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
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1<<28)
#define ll long long
#define mod 1000000007
#define gc getchar
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 500+10
#define fs first
#define sc second

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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
// int X[]= {-1, 0, 1, 0};   //x 4 direction
// int Y[]= { 0, 1, 0, -1};  //y 4 direction

int shop[20];
vector<pii>g[mx];
int dist[20][20];
int d[mx];
int dp[20][(1<<18)+10];
int n,m,s, strt, nd;

void dijkstra(int st, int ith){
    set<pii>heap;
    heap.insert(pii(0,st));
    for(int i=0;i<=n;i++)d[i]=inf;
    d[st]=0;
    while(!heap.empty()){
        pii data=*heap.begin(); heap.erase(data);
        int u=data.sc;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].fs; int w=g[u][i].sc+d[u];
            if(w<d[v]){
                if(d[v]!=inf) heap.erase(pii(d[v],v));
                d[v]=w;
                heap.insert(pii(d[v],v));
            }
        }
    }
    for(int i=0;i<=nd;i++)
        dist[ith][i]=d[shop[i]];
}

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL
    // Can you solve it by brute force?
    // LDC
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)
    int test;
    read(test);
    for(int C=1;C<=test;C++) {

        read(n);read(m);read(s);
        for(int i=0;i<=s;i++)for(int j=0;j<=s;j++)dist[i][j]=inf;
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=0;i<s;i++)read(shop[i]);
        strt=s, nd=strt+1;
        shop[strt]=0, shop[nd]=n-1;

        while(m--){
            int u,v,w;
            read(u);read(v);read(w);
            g[u].pb(pii(v,w));
        }
        for(int i=0;i<=nd;i++) dijkstra(shop[i], i);
        printf("Case %d: ", C);
        if(dist[strt][nd]==inf){
            puts("Impossible");continue;
        }

        for(int i=0;i<s;i++){
            for(int j=0;j<(1<<s);j++)dp[i][j]=inf;
            dp[i][(1<<i)]=dist[strt][i];
        }

//        for(int i=0;i<s;i++){
//            for(int j=0;j<(1<<s);j++)cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }

        int cnt=0, ans=dist[strt][nd];
        for(int mask=0;mask<(1<<s);mask++){
            for(int u=0;u<s;u++)if(dp[u][mask]!=inf){
//                cout<<mask<<" "<<u<<" "<<dp[u][mask]<<endl;
                for(int v=0;v<s;v++){
                    if(shop[u]!=shop[v] and dist[u][v]!=inf){
                        int nxt=Set(mask,v);
                        dp[v][nxt]=min(dp[v][nxt], dp[u][mask]+dist[u][v]);
                    }
                }

                int x=__builtin_popcount(mask);
                if(dist[u][nd]!=inf and x>=cnt){
                    if(cnt==x) ans=min(ans, dp[u][mask]+dist[u][nd]);
                    else ans=dp[u][mask]+dist[u][nd];
                    cnt=x;
                }
            }
        }
        printf("%d %d\n",cnt,ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




