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

int node,edge;
vector <int> adjlist[mx];
int dfs_num[mx], dfs_low[mx], rootChildren, dfsRoot, dfs_parent[mx], dfsNumberCounter=0, c = 0;
//bool articulation_vertex[mx];
map<pii,bool>bridges;

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
            if ( dfs_low[v] > dfs_num[u] ){
                bridges[pii(u,v)]=1;
            }
        }
        else if ( v != dfs_parent[u] )
            dfs_low[u] = min (dfs_low[u], dfs_num[v]);
    }
}

void RESET ()
{
//    CLEAR (articulation_vertex, false);
    for (int i=0; i<mx; i++)
        adjlist[i].clear();
    dfsNumberCounter=0;
    CLEAR (dfs_num, 0);
    CLEAR (dfs_parent, 0);
    CLEAR (dfs_low, 0);
    rootChildren = 0;
}

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by Rank heuristics
class UnionFind {                                              // OOP style
private:
    vi p, Rank, setSize;                       // remember: vi is vector<int>
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        Rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // Rank is used to keep the tree short
            if (Rank[x] > Rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else                   {
                p[x] = y;
                setSize[y] += setSize[x];
                if (Rank[x] == Rank[y]) Rank[y]++;
            }
        }
    }
    int numDisjointSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
};

int cnt[mx];

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
        printf("Case %d: ", C);
        read(node);read(edge);
        RESET(); bridges.clear();CLEAR(cnt,0);

        while(edge--){
            int u,v;
            read(u);read(v);
//            cout<<u<<" "<<v<<endl;
            adjlist[u].pb(v);
            adjlist[v].pb(u);
        }
        dfsRoot=0, rootChildren=0;
        articulationPointAndBridges(0);

        UnionFind ds(node);

        for(int i=0;i<node;i++){
            for(int j=0;j<adjlist[i].size();j++){
                int v=adjlist[i][j];
                if(bridges.count(pii(i,v))==0 and
                   bridges.count(pii(v,i))==0 ){
                    ds.unionSet(i,v);
                }
            }
        }

        for(map<pii,bool>::iterator it=bridges.begin();it!=bridges.end();it++){
            int u=it->first.first;
            int v=it->first.second;
            u=ds.findSet(u);
            v=ds.findSet(v);
            cnt[u]++;
            cnt[v]++;
        }
        int ans=0;

        for(int i=0;i<node;i++)
            ans+=(cnt[i]==1);
        printf("%d\n",(ans+1)/2);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
