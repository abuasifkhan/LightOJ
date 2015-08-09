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
#define out(C) printf("Case %d:\n", C);
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
#define mx 100010
ll NegMod (ll a, ll b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }
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

int grid[510][510];
int r,q;
int st[1700][1700];

void update (int tree[], int node, int l, int r, int x, int val){
//    cout<<node<<" "<<l<<" "<<r<<" "<<x<<" "<<val<<endl;
    if(l>x or r<x)return;
    if(l==x and r==x){
        tree[node]=val;
        return;
    }
    int m=MID(l,r);
    update(tree, node*2, l, m, x, val);
    update(tree, node*2+1, m+1, r, x, val);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int query(int tree[], int node, int l, int r, int x, int y){
    if(l>=x and r<=y)
        return tree[node];
    int m = MID(l,r);
    int ret=-1;
    if(m>=x)
        ret=query(tree,node*2, l, m, x, y);
    if(m<y)
        ret=max(ret, query(tree,node*2+1,m+1,r,x,y));
    return ret;
}

int main() {
	#ifdef LOCAL
    open
    double stc=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(r);read(q);
        for(int i=1;i<=r;i++){
            fill(st[i],st[i]+(r*3), -1);
            for(int j=1;j<=r;j++){
                read(grid[i][j]);
                update(st[i],1,1,r,j,grid[i][j]);
            }
        }
//        cout<<"ok"<<endl;
        while(q--){
            int x1,y1,y;
            read(x1);read(y1);read(y);
            int x2=x1+y-1,y2=y1+y-1;
            int ans=-1;
            for(int i=x1; i<=x2;i++){
                ans = max(ans, query(st[i],1,1,r,y1,y2));
            }
            printf("%d\n",ans);
        }
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-stc)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





