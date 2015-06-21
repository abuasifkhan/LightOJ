//! Bismillahi-Rahamanirahim.
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
 ** @Category:
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
#define inf 0x7fffffff
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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};

map<string , int>mp;
int N, M;
int Left[mx],Right[mx],seen[mx];
vector<int>adj[100];

bool kuhn(int u){
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(seen[v])continue;
        seen[v]=1;
        if(Right[v]==-1 or kuhn(Right[v])){
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}

int bipertitematching(){
    CLEAR(Left,-1);
    CLEAR(Right,-1);
    int cnt=0;
    for(int i=1;i<=M;i++){
        CLEAR(seen,0);
        if(kuhn(i)) cnt++;
    }
    return cnt;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    mp["XXL"]= 1;
    mp["XL"]= 2;
    mp["L"]= 3;
    mp["M"]= 4;
    mp["S"]= 5;
    mp["XS"]= 6;
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(N);read(M);
        for(int i=0;i<=M;i++)adj[i].clear();

        for(int i=1;i<=M;i++){
            string a, b;cin>>a>>b;
            int u=mp[a],v=mp[b];
            for(int j=(u-1)*N+1; j<=u*N;j++ ){
                adj[i].pb(j);
            }
            for(int j=(v-1)*N+1; j<=v*N; j++)
                adj[i].pb(j);
        }
        int cnt=bipertitematching();
        if(cnt==M)puts("YES");
        else puts("NO");
    }
    return 0;
}





