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
#define inf 999999999
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 55
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
// int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
// int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction

int n;
vector<int>adj[mx];
int id[mx][mx];
int g, h;
vector<int>G[mx];
string grid[mx];
int dist[mx][mx];
int dt[mx][mx];

void RESET(){
    CLEAR(id,0);
//    CLEAR(grid,0);
    CLEAR(dist,0);
    CLEAR(dt,0);
}

void bfs(int stx, int sty){
    queue<pii>Q;
    CLEAR(dt,-1);
    Q.push(pii(stx,sty));
    dt[stx][sty]=0;
    while(!Q.empty()){
        pii cur=Q.front();
        Q.pop();
        int ux=cur.fs;
        int uy=cur.sc;
        if(grid[ux][uy]=='G'){
            dist[id[stx][sty]][id[ux][uy]]=dt[ux][uy];
        }
//        cout<<"k "<<ux<<" "<<uy<<endl;
        for(int i=0;i<4;i++){
            int vx=ux+X[i];
            int vy=uy+Y[i];
//            cout<<ux<<" "<<uy<<" "<<vx<<" "<<vy<<endl;
            if(vx>=n or vy>=n or vx<0 or vy<0)continue;
            if(grid[vx][vy]=='#')continue;
            if(dt[vx][vy]==-1){
                dt[vx][vy]=dt[ux][uy]+1;
                Q.push(make_pair(vx,vy));
            }
        }
    }
//    cout<<"ok"<<endl;
}
int Left[mx*mx], Right[mx*mx], seen[mx*mx];

bool kuhn(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(seen[v])continue;
        seen[v]=1;
        if(Right[v]==-1 or kuhn(Right[v])){
//            cout<<u<<" "<<v<<endl;
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}

int bipertite(){
    CLEAR(Left,-1);
    CLEAR(Right, -1);
    int cnt=0;
    for(int i=0;i<h;i++){
        if(Left[i]!=-1)continue;
        CLEAR(seen,0);
        if(kuhn(i))cnt++;
    }
//    cout<<cnt<<endl;
    return cnt;
}

void Build(int mid){
    for(int i=0;i<=h;i++){
        G[i].clear();
        for(int j=0;j<=g;j++){
            if(dist[i][j]<=mid)
                G[i].pb(j);
        }
    }
}

int main() {
    // #ifdef LOCAL
    open
    // #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        RESET();
        read(n);
        for(int i=0;i<n;i++){
            cin>>grid[i];
//            cout<<grid[i]<<endl;
        }
        g=h=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='H')
                    id[i][j]=h++;
                if(grid[i][j]=='G')
                    id[i][j]=g++;
            }
        }
//        cout<<g<<" "<<h<<endl;
        for(int i=0;i<=h;i++)
            for(int j=0;j<=g;j++) dist[i][j]=inf;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='H'){
                    bfs(i,j);
                }
            }
        }
        int lo=0, hi=inf/2,mid,best=-1;
        while(lo<=hi){
            mid=(lo+hi)/2;
            Build(mid);
//            cout<<mid<<" ";
            if(bipertite()==h){
//                cout<<mid<<" "<<h<<endl;
                best=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        if(best==-1){
            puts("Vuter Dol Kupokat");
        }
        else cout<<best*2+2<<endl;
    }
    return 0;
}





