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
#define inf (1<<30)
#define ll long long
#define mod 1000000007
#define gc getchar
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 110

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

int n, e, price[mx];
vector<pii>g[mx];
int cost[mx][mx];

int dijkstra(int st, int ed, int load){
    for(int i=0;i<n;i++)for(int j=0;j<=load;j++)cost[i][j]=inf;

    cost[st][0]=0;
    set<piii>heap;
    heap.insert(piii(0, pii(st,0)));

    while(!heap.empty()){
        piii data = *heap.begin();
        int u=data.sc.fs, w=data.sc.sc;
        heap.erase(data);
//        cout<<u<<" "<<w<<" "<<cost[u][w]<<endl;
        if(u==ed)break;

        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].fs;
            int c=g[u][i].sc;
//            cout<<u<<" "<<v<<" "<<w<<" "<<c<<endl;
            if(w>=c){
                int rest=w-c;
                if(cost[v][rest]<=cost[u][w])continue;
                if(cost[v][rest]!=inf)
                    heap.erase(piii(cost[v][rest], pii(v,rest)));
                cost[v][rest]=cost[u][w];
                heap.insert(piii(cost[v][rest], pii(v,rest)));
            }
        }
        if(w+1>load)continue;
        int c=cost[u][w]+price[u];
        if(c<cost[u][w+1]){
            if(cost[u][w+1]!=inf)
                heap.erase(piii(cost[u][w+1], pii(u,w+1)));
            cost[u][w+1]=c;
            heap.insert(piii(cost[u][w+1], pii(u,w+1)));
        }
    }
    int ret=inf;
    for(int i=0;i<=load;i++)ret=min(ret, cost[ed][i]);
    return ret;
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
        printf("Case %d:\n", C);
        read(n);read(e);
        for(int i=0;i<n;i++){
            g[i].clear();
            read(price[i]);
        }
        for(int i=0;i<e;i++){
            int u,v,w;read(u);read(v);read(w);
            g[u].pb(pii(v,w));
            g[v].pb(pii(u,w));
        }
        int q;read(q);
        while(q--){
            int st,ed,load;
            read(load);read(st);read(ed);
            int ans = dijkstra(st,ed,load);
            if(ans==inf)
                puts("impossible");
            else
                printf("%d\n",ans);
        }
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




