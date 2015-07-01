//! Bismillahi-Rahamanirahim.

// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
//
// Running time:
//     O(|V|^2 |E|)
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).

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
#define inf 2000000000ll
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
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index):
        from(from),to(to),cap(cap),flow(flow),index(index) {}
};

struct Dinic {
    int N;
    vector< vector<Edge> >G;
    vector<Edge * >dad;
    vector<int>Q;

    Dinic(int N):N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to ,int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from==to)G[from].back().index++;
        G[to].push_back(Edge(to,from, 0,0, G[from].size()-1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(),dad.end(),(Edge *)NULL);
        dad[s] = &G[0][0]-1;

        int head=0, tail=0;
        Q[tail++]=s;
        while(head<tail) {
            int x = Q[head++];
            for(int i=0; i<G[x].size(); i++) {
                Edge &e = G[x][i];
                if(!dad[e.to] and e.cap-e.flow>0) {
                    dad[e.to]=&G[x][i];
                    Q[tail++]=e.to;
                }
            }
        }
        if(!dad[t])return 0;

        long long totflow=0;
        for(int i=0; i<G[t].size(); i++) {
            Edge *start=&G[G[t][i].to][G[t][i].index];
            int amt=inf;
            for(Edge*e = start; amt&&e!=dad[s]; e=dad[e->from]) {
                if(!e) {
                    amt=0;
                    break;
                }
                amt=min(amt, e->cap - e->flow);
            }
            if(amt==0)continue;
            for(Edge *e=start; amt && e!=dad[s]; e=dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow-=amt;
            }
            totflow+=amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow=0;
        while(long long flow=BlockingFlow(s,t))
            totflow+=flow;
        return totflow;
    }
};

char grid[30][30];
int mark[30][30];
int g,h,n;
vector<pii>G[60];
int source, sink;

bool isValid(int x, int y) {
    if(x<0 or x>=n or y<0 or y>=n or grid[x][y]=='#')return 0;
    return true;
}

void bfs(int sx, int sy) {
    bool vis[30][30];
    int dist[30][30];
    CLEAR(vis,0);
    vis[sx][sy]=1;
    dist[sx][sy]=0;
    queue<pii>Q;
    Q.push(pii(sx,sy));
    while(!Q.empty()) {
        int ux=Q.front().first;
        int uy=Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++) {
            int vx=ux+X[i];
            int vy=uy+Y[i];
            if(!isValid(vx,vy))continue;
            if(vis[vx][vy])continue;
            vis[vx][vy]=1;
            dist[vx][vy]=dist[ux][uy]+1;
            Q.push(pii(vx,vy));
            if(grid[vx][vy]=='H') {
                G[mark[sx][sy]].pb(pii(mark[vx][vy],dist[vx][vy]));
//                cout<<vx<<" "<<vy<<" "<<dist[vx][vy]<<endl;
            }
        }
    }
}

void makeGraph(int m, Dinic & flow) {
    for(int j=0; j<g; j++) {
        for(int k=0; k<G[j].size(); k++) {
            int v=G[j][k].first;
            int w=G[j][k].second*2+2;
            if(w<=m) {
                flow.AddEdge(j,v,1);
            }
        }
    }

    for(int j=0; j<g; j++) {
        flow.AddEdge(source, j, 1);
    }
    for(int j=g; j<h; j++) {
        flow.AddEdge(j,sink,1);
    }
}

int main() {
#ifdef LOCAL
    open
#endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        read(n);
        for(int i=0; i<60; i++)G[i].clear();
        for(int i=0; i<n; i++) {
            scanf("%s",grid[i]);
        }
        g=0, h=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='G')
                    mark[i][j]=g++;
            }
        }
        h=g;
        int human=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='H')
                    mark[i][j]=h++, human++;
            }
        }
        source=h, sink=h+1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='G') {
//                    cout<<i<<" "<<j<<endl;
                    bfs(i,j);
                }
            }
        }
        int lo=1, hi=1000000, mid, ans=-1;
        while(lo<=hi) {
            Dinic flow(h+5);
            int mid = (lo+hi)/2;
            makeGraph(mid,flow);
            int f = flow.GetMaxFlow(source,sink);
            if(f==human){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        out(C);
        if(ans==-1)puts("Vuter Dol Kupokat");
        else
        printf("%d\n",ans);
    }
    return 0;
}





