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
#define mx 10010
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

int n, m, st, ed, p;
int roadSt[mx], roadEd[mx];

void dijkstra(int *dist, int st, vector<pii>*g){
    set<pii>heap;
    for(int i=0;i<=n;i++)dist[i]=inf;

    heap.insert(pii(0,st));
    dist[st]=0;
    while(!heap.empty()){
        pii data=*heap.begin(); heap.erase(data);
        int u = data.sc;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].fs;
            int w=g[u][i].sc;
            if(dist[v]>dist[u]+w){
                if(dist[v]!=inf)heap.erase(pii(dist[v],v));
                dist[v]=dist[u]+w;
                heap.insert(pii(dist[v],v));
            }
        }
    }
}
vector<pii>g1[mx],g2[mx];

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
        read(n);read(m);read(st);read(ed);read(p);
        for(int i=0;i<=n;i++){
            g1[i].clear();g2[i].clear();
        }

        while(m--){
            int u,v,w;
            read(u);read(v);read(w);
            g1[u].pb(pii(v,w));
            g2[v].pb(pii(u,w));
        }

        dijkstra(roadSt,st,g1);
        dijkstra(roadEd,ed,g2);
        printf("Case %d: ", C);
        int M=-1;
        for(int u=1;u<=n;u++){
            for(int j=0;j<g1[u].size();j++){
                int v=g1[u][j].fs;
                int w=g1[u][j].sc;
                if(roadSt[u]+roadEd[v]+w<=p){
                    M=max(M,w);
                }
            }
        }
        printf("%d\n",M);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




