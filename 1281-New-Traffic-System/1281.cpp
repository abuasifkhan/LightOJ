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
#define piii pair<int,pii>
#define fs first
#define sc second
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
#define mx 10000+10

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

int n, m, k, d;
vector<piii>g[mx];
int dist[mx][12];

void dijkstra(){
    set<piii>heap;
    heap.insert(piii(0, pii(0,0)));
    dist[0][0]=0;
    while(!heap.empty()){
        piii data = *heap.begin(); heap.erase(data);
        int u=data.sc.fs;
        int D=data.sc.sc;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].fs;
            int w=g[u][i].sc.fs;
            int t=g[u][i].sc.sc;
            if(dist[v][D+t]>dist[u][D]+w){
                if(dist[v][D+t]!=inf)
                    heap.erase(piii(dist[v][D+t], pii(v,D+t)));
                dist[v][D+t]=dist[u][D]+w;
                heap.insert(piii(dist[v][D+t], pii(v,D+t)));
            }
        }
    }
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
        read(n);read(m);read(k);read(d);
        for(int i=0;i<=n;i++){
            g[i].clear();
            for(int j=0;j<=d;j++)dist[i][j]=inf;
        }
        int u,v,w;
        while(m--){
            read(u);read(v);read(w);
            g[u].pb(piii(v, pii(w,0)));
        }
        while(k--){
            read(u);read(v);read(w);
            g[u].pb(piii(v, pii(w,1)));
        }
        printf("Case %d: ", C);
        dijkstra();
        int Mn=inf;
        for(int i=0;i<=d;i++){
            Mn=min(Mn, dist[n-1][i]);
        }
        if(Mn==inf)puts("Impossible");
        else printf("%d\n",Mn);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




