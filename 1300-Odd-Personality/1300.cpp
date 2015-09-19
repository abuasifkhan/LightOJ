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
#define inf (1<<30)
#define ll long long
#define mod 1000000007
#define gc getchar
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 30010

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

int node;
vector <int> adjlist[mx];
int dfs_num[mx], dfs_low[mx], rootChildren, dfsRoot, dfs_parent[mx], dfsNumberCounter=0, c = 0;
bool articulation_vertex[mx];
map<pii,bool>isBridge;

void articulationPointAndBridges(int u)
{
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
    for (int i=0; i<adjlist[u].size(); i++)
    {
        int v = adjlist[u][i];
        if (dfs_num[v] == 0){
            dfs_parent[v] = u;
            if (u == dfsRoot)   rootChildren++;

            articulationPointAndBridges( v);
            dfs_low[u] = min (dfs_low[u], dfs_low[v]) ;

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;
            if ( dfs_low[v] > dfs_num[u] ){
                isBridge[pii(u,v)]=1;
                isBridge[pii(v,u)]=1;
//                cout<<u<<" "<<v<<endl;
            }
        }
        else if ( v != dfs_parent[u] )
            dfs_low[u] = min (dfs_low[u], dfs_num[v]);
    }
}

void RESET ()
{
    CLEAR (articulation_vertex, false);
    for (int i=0; i<mx; i++)
    adjlist[i].clear();
    dfsNumberCounter=0;
    CLEAR (dfs_num, 0);
    CLEAR (dfs_parent, 0);
    CLEAR (dfs_low, 0);
    rootChildren = 0;
    isBridge.clear();
}

bool visOdd[mx], visEven[mx];

int bfs(int st){
    queue<int>Q;
    Q.push(st);
    visEven[st]=1;
    bool odd_cycle=0;
    int cnt=0;

    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        cnt++;
//        cout<<u<<": ";
        for(int i=0;i<adjlist[u].size();i++){
            int v=adjlist[u][i];
//            cout<<u<<" "<<v<<endl;
            if(isBridge.count(pii(u,v)))continue;
//            cout<<v<<" ";
            if(!visEven[v] and !visOdd[v])Q.push(v);
            if(visEven[u] and visEven[v]) odd_cycle=1;

            if(visEven[u])visOdd[v]=1;
            if(visOdd[u])visEven[v]=1;
        }
//        cout<<endl;
    }
    return (odd_cycle?cnt:0);
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
    for(int C=1; C<=test; C++) {
        printf("Case %d: ", C);
        RESET(); int edge;
        read(node);read(edge);
        while(edge--){
            int u,v;read(u);read(v);
            adjlist[u].pb(v);
            adjlist[v].pb(u);
        }
        for(int i=0;i<node;i++){
            if(!dfs_num[i]){
                dfsRoot=i,rootChildren=0;
                articulationPointAndBridges(i);
            }
        }
        int ans=0;
        CLEAR(visOdd,0);CLEAR(visEven,0);
        for(int i=0;i<node;i++){
            if(!visOdd[i] and !visEven[i]){
                ans+=bfs(i);
            }
        }
        printf("%d\n",ans);
    }

#ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
#endif // LOCAL
    return 0;
}





