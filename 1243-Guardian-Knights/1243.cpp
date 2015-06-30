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
#define inf 10000ll
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
//int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
 int X[]= {-1, 0, 1, 0};   //x 4 direction
 int Y[]= { 0, 1, 0, -1};  //y 4 direction

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
//        cout<<from<<" "<<to<<" "<<cap<<" "<<cost<<endl;
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
    pair<ll,ll> GetMaxFlow(int s, int t){
        ll totflow=0, totcost=0;
        while(ll amt=Dijkstra(s,t)){
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
        }

        return make_pair(totflow,totcost);
    }
};
int N, k,m;
char grid[50][50];
int vertex[50][50];
int knights[30];

void bfs(int sx, int sy, MinCostMaxFlow& flow){
    bool vis[50][50];CLEAR(vis,0);
    int dist[50][50];CLEAR(dist,0);
//    MinCostMaxFlow flow(N);

    queue<pii>Q;
    Q.push(pii(sx,sy));
    vis[sx][sy]=1;
    dist[sx][sy]=0;
    while(!Q.empty()){
        int ux=Q.front().first;
        int uy=Q.front().second;
        Q.pop();

        for(int i=0;i<4;i++){
            int vx=ux+X[i];
            int vy=uy+Y[i];
            if(vx<0 or vx>=N or vy<0 or vy>=N or grid[vx][vy]=='#')
                continue;
            if(vis[vx][vy])continue;
            vis[vx][vy]=true;
            dist[vx][vy]=dist[ux][uy]+1;
            Q.push(pii(vx,vy));
            if(grid[vx][vy]=='m'){
                flow.AddEdge(vertex[sx][sy],vertex[vx][vy],1,dist[vx][vy]);
            }
        }
    }
//    return flow;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        CLEAR(vertex,0);
        read(N);read(k);read(m);
        for(int i=0;i<N;i++){
            scanf("%s",grid[i]);
        }
        for(int i=0;i<k;i++){
            read(knights[i]);
        }
        int mill=k;
        MinCostMaxFlow flow(k+m+10);
        int source=k+m+1, sink=k+m+2;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='m'){
                    vertex[i][j]=mill++;
                    flow.AddEdge(vertex[i][j],sink,1,0);
                }
                else if(grid[i][j]>='A' and grid[i][j]<='Z'){
                    vertex[i][j]=(int)grid[i][j]-'A';
                    flow.AddEdge(source,vertex[i][j],(ll)knights[vertex[i][j]],0ll);
//                    cout<<grid[i][j]<<endl;
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]>='A' and grid[i][j]<='Z')
                    bfs(i,j,flow);
            }
        }
        pair<ll,ll> f = flow.GetMaxFlow(source,sink);
        printf("%lld\n",f.second);
    }
    return 0;
}





