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

int n, d;
int Max[3*mx], Min[3*mx];

void build(int node, int l, int r){
    if(l>r)return;
    if(l==r){
        int a; read(a);
        Max[node]=Min[node]=a;
        return;
    }
    build(node*2, l,MID(l,r));
    build(node*2+1, MID(l,r)+1, r);
    Max[node]=max(Max[node*2],Max[node*2+1]);
    Min[node]=min(Min[node*2], Min[node*2+1]);
}

pii query(int node, int l, int r, int x, int y){
    if(l>=x and r<=y){
        return pii(Max[node], Min[node]);
    }
    int m=MID(l,r);
    pii ret=pii(-1,100000001),tmp;

    if(m>=x){
        tmp = query(node*2,l,m,x,y);
        ret=tmp;
    }
    if(m<y){
        tmp = query(node*2+1, m+1, r, x, y);
        ret.first = max(ret.first,tmp.first);
        ret.second= min(ret.second, tmp.second);
    }

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
        out(C);
        read(n);read(d);
        fill(Max,Max+(3*n),-1);
        fill(Min,Min+(3*n), 100000001);
        build(1,1,n);
        int diff=0;
        for(int i=1;i<=n;i++){
            if(i+d-1>n)break;
            int r=i+d-1;
            pii t = query(1,1,n,i,r);
            diff = max(diff, t.first-t.second);
        }
        printf("%d\n",diff);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





