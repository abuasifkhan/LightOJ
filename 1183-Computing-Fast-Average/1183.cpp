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

int n, q;
ll tree[3*mx],lazy[3*mx];

void pushDown(int node, int l, int r){
    if(lazy[node]<0)return;
    int m=MID(l,r);

    lazy[node*2]=lazy[node];
    lazy[node*2+1]=lazy[node];
    tree[node*2] = lazy[node]*(m-l+1);
    tree[node*2+1] = lazy[node]*(r-(m+1)+1);
    lazy[node]=-1;
}

void update(int node, int l, int r, int x, int y, int val){
    if(l>=x and r<=y){
        tree[node] = (r-l+1)*val;
        lazy[node] = val;
        if(lazy[node]<val)lazy[node]++;
        return;
    }
    pushDown(node, l, r);
    int m = MID(l,r);
    if(m>=x)
        update(node*2,l,m,x,y,val);
    if(m<y)
        update(node*2+1, m+1,r,x,y,val);
    tree[node] = tree[node*2]+tree[node*2+1];
}

ll query(int node, int l, int r, int x, int y){
    if(l>=x and r<=y){
        return tree[node];
    }
    pushDown(node,l,r);
    int m=MID(l,r);
    ll ret=0;
    if(m>=x)
        ret=query(node*2,l,m,x,y);
    if(m<y)
        ret+=query(node*2+1, m+1, r, x, y);
    return ret;
}

int main() {
	#ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    FOR(C, 1, test) {
        CLEAR(tree,0);CLEAR(lazy,-1);

        out(C);
        read(n);read(q);
        while(q--){
            int choice;read(choice);choice--;
            if(choice){
                int l,r;read(l);read(r);
                l++,r++;
                ll ans = query(1,1,n,l,r);
                ll hor=(r-l+1);
                ll gc=__gcd(ans,hor);
                hor/=gc, ans/=gc;
                if(hor==1)
                    printf("%lld\n",ans);
                else printf("%lld/%lld\n",ans,hor);
            }
            else{
                ll l, r, val;read(l);read(r);read(val);
                l++,r++;
                update(1,1,n,l,r,val);
            }
        }
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
