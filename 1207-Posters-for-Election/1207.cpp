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
#define out(C) printf("Case %d: ", C);
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
#define rs(n) (ls(n)|1)
#define MID(a,b) ((a+b)>>1)

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

int lazy[mx*6],tree[mx*6];

void pushDown(int node){
    if(lazy[node]==0)return;
    tree[node]=tree[ls(node)]=tree[rs(node)]=
    lazy[ls(node)]=lazy[rs(node)]=lazy[node];
    lazy[node]=0;
}

void update(int node, int l, int r, int x, int y,int val){
    if(l==x and r==y){
        lazy[node]=val;
        tree[node]=val;
        return;
    }
    pushDown(node);
    int mid=MID(l,r);
    if(mid>=y)
        update(ls(node),l,mid,x,y,val);
    else if(mid<x)
        update(rs(node),mid+1,r,x,y,val);
    else{
        update(ls(node),l,mid,x,mid,val);
        update(rs(node),mid+1,r,mid+1,y,val);
    }
}

int query(int node, int l, int r, int x){
    if(l==r and l==x){
        return tree[node];
    }
    pushDown(node);
    int mid=MID(l,r);
    if(mid>=x)
        return query(ls(node),l,mid,x);
    else if(mid<x)
        return query(rs(node),mid+1,r,x);
}
set<int>myset;

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        CLEAR(tree,0);CLEAR(lazy,0);
        out(C);
        int n;read(n);
        for(int i=1;i<=n;i++){
            int a,b;read(a);read(b);
            update(1,1,2*n,a,b,i);
        }
        myset.clear();
        for(int i=1;i<=2*n;i++){
            int a=query(1,1,2*n,i);
            if(a)
            myset.insert(a);
        }
        printf("%d\n",myset.size());
    }
    return 0;
}





