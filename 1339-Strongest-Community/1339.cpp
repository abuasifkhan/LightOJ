//!
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
#define out(C) printf("Case %d:\n", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define mx 100010
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fi first
#define se second

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
int arr[mx];
int n,c,q;
struct NODE{
    pii le,ri;
    ll maxVal;
    NODE(){
        le.fi=le.se=ri.fi=ri.se=maxVal=0;
    }
    void clr(){
        le=ri=pii(0,0);
        maxVal=0;
    }
    void init(int val){
        le=ri=pii(val,1);
        maxVal=1;
    }
    void merge(NODE a, NODE b){
        maxVal=max(a.maxVal,b.maxVal);
        if(a.ri.fi==b.le.fi)
            maxVal = max(maxVal, (ll)a.ri.se+b.le.se);
        le=a.le;
        if(le.fi==b.le.fi)
            le.se+=b.le.se;
        ri=b.ri;
        if(ri.fi==a.ri.fi)
            ri.se+=a.ri.se;
    }
}tree[mx*3], qt[mx*3];

void build(int node, int l, int r){
    if(l==r){
        tree[node].init(arr[l]);
        return;
    }
    build(ls(node),l,MID(l,r));
    build(rs(node),MID(l,r)+1,r);
    tree[node].merge(tree[ls(node)], tree[rs(node)]);
}
int ans;

void query(int node, int l, int r, int x, int y){
    if(l>y or l>r or r<x){
        qt[node].clr();
        return;
    }
    if(l>=x and r<=y){
        qt[node]=tree[node];
        return;
    }
    query(ls(node),l,MID(l,r),x,y);
    query(rs(node),MID(l,r)+1, r, x, y);
    qt[node].merge(qt[ls(node)], qt[rs(node)]);
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        CLEAR(tree,0);CLEAR(qt,0);
        read(n);read(c);read(q);
        for(int i=1;i<=n;i++)read(arr[i]);
        build(1,1,n);
        for(int i=1;i<=q;i++){
            int a, b;read(a);read(b);
            query(1,1,n,a,b);
            printf("%lld\n",qt[1].maxVal);
        }
    }
    return 0;
}





