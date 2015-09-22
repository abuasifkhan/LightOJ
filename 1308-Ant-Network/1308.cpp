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
#define ll unsigned long long
#define mod 1000000007
#define gc getchar
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 10010

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
bool vis[mx];
vector <int> adjlist[mx];
int dfs_num[mx], dfs_low[mx], rootChildren, dfsRoot, dfs_parent[mx], dfsNumberCounter=0, c = 0;
bool articulation_vertex[mx];

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
        }
        else if ( v != dfs_parent[u] )
            dfs_low[u] = min (dfs_low[u], dfs_num[v]);
    }
}

void RESET () {
    CLEAR (articulation_vertex, false);
    for (int i=0; i<mx; i++)
        adjlist[i].clear();
    dfsNumberCounter=0;
    CLEAR (dfs_num, 0);
    CLEAR (dfs_parent, 0);
    CLEAR (dfs_low, 0);
    rootChildren = 0;
}

int srrnd, key[mx];

void dfs(int u) {
    vis[u]=1;
    rootChildren++;
    for(int i=0; i<adjlist[u].size(); i++) {
        int v=adjlist[u][i];
        if(articulation_vertex[v]){
            if(key[v]!=dfsRoot)srrnd++;
            key[v]=dfsRoot;continue;
        }
        if(!vis[v]) {
            dfs(v);
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
    for(int C=1; C<=test; C++) {
        printf("Case %d: ", C);
        RESET();CLEAR(key,-1);

        int edge;
        read(node);
        read(edge);
        while(edge--) {
            int u,v;
            read(u);
            read(v);
            adjlist[u].pb(v);
            adjlist[v].pb(u);
        }
        for(int i=0; i<node; i++) {
            if(!dfs_num[i]) {
                dfsRoot=i, rootChildren=0;
                articulationPointAndBridges(i);
                articulation_vertex[dfsRoot]=(rootChildren>1);
            }
        }

        int cnt=0;
        ll ans=1;
        CLEAR(vis,0);
        for(int i=0; i<node; i++) {
            if(!articulation_vertex[i] and !vis[i]) {
                srrnd=0;
                dfsRoot=i,rootChildren=0;
                dfs(i);
                if(srrnd==1){
                    cnt++;
                    ans*=rootChildren;
                }
//                cout<<i<<" "<<rootChildren<<" "<<cnt<<" "<<srrnd<<endl;
            }
        }

        if(cnt<=1)printf("%d %llu\n", 2, node*(node-1)/2ll);
        else
            printf("%d %llu\n",cnt,ans);
    }

#ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
#endif // LOCAL
    return 0;
}
