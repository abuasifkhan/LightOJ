//! Bismillahi-Rahamanirahim.

// Implementation of min cost max flow algorithm using adjacency
// matrix (Edmonds and Karp 1972).  This implementation keeps track of
// forward and reverse edges separately (so you can set cap[i][j] !=
// cap[j][i]).  For a regular max flow, set all edge costs to 0.
//
// Running time, O(|V|^2) cost per augmentation
//     max flow:           O(|V|^3) augmentations
//     min cost max flow:  O(|V|^4 * MAX_EDGE_COST) augmentations
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - (maximum flow value, minimum cost value)
//     - To obtain the actual flow, look at positive values only.


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
//#define pi 3.141592653589793
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
#define inf 10000000ll
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 100010

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

typedef vector<int>VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<pii>VPII;

struct MinCostMaxFlow{
    int N;
    VVL cap, flow, cost;
    VI found;
    VL dist, pi, width;
    VPII dad;
    MinCostMaxFlow(int N):
        N(N), cap(N, VL(N)), flow(N,VL(N)), cost(N,VL(N)),
        found(N), dist(N),pi(N),width(N),dad(N){}

    void AddEdge(int from, int to, ll cap, ll cost){
        this->cap[from][to]=cap;
        this->cost[from][to]=cost;
    }

    void Relax(int s, int k, ll cap, ll cost, int dir){
        ll val = dist[s]+pi[s]-pi[k]+cost;
        if(cap and val<dist[k]){
            dist[k]=val;
            dad[k]=make_pair(s,dir);
            width[k]=min(cap,width[s]);
        }
    }

    ll Dijkstra(int s, int t){
        fill(found.begin(),found.end(),false);
        fill(dist.begin(),dist.end(),inf);
        fill(width.begin(),width.end(),0);
        dist[s]=0;
        width[s]=inf;

        while(s!=-1){
            int best=-1;
            found[s]=true;
            for(int k=0;k<N;k++){
                if(found[k])continue;
                Relax(s,k,cap[s][k]-flow[s][k],cost[s][k],1);
                Relax(s,k,flow[k][s],-cost[k][s],-1);
                if(best==-1 or dist[k]<dist[best])best=k;
            }
            s=best;
        }

        for(int k=0;k<N;k++)
            pi[k]=min(pi[k]+dist[k],inf);
        return width[t];
    }
    pair<ll,ll> GetMaxFlow(int s, int t, ll P){
        ll totflow=0, totcost=0;
        while(ll amt=Dijkstra(s,t)){
            amt = min(amt,P);
            P-=amt;
            totflow+=amt;
            for(int x=t;x!=s; x=dad[x].first){
                if(dad[x].second==1){
                    flow[dad[x].first][x]+=amt;
                    totcost+=amt*cost[dad[x].first][x];
                } else {
                    flow[x][ dad[x].first ]-=amt;
                    totcost -= amt*cost[x][dad[x].first ];
                }
            }
            if(!P)break;
        }

        return make_pair(P,totcost);
    }
};
int N, M, P;

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        read(N);read(M);read(P);
        MinCostMaxFlow flow(N+5);
        for(int i=1;i<=M;i++){
            int u,v,w,c;
            read(u);read(v);read(w);read(c);
            flow.AddEdge(u,v,w,c);
            flow.AddEdge(v,u,w,c);
        }
        int source = 1, sink=N;
        pair<ll,ll> ans = flow.GetMaxFlow(source,sink,P);
        out(C);
        if(!ans.first)
            cout<<ans.second<<endl;
        else printf("impossible\n");
    }
    return 0;
}





