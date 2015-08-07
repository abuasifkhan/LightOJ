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
int arr[mx];
int tree[mx];
int prev[mx];
int output[mx];

struct dat{
    int fs, sc, idx;
}inp[mx];

bool comp(dat a, dat b){
    if(a.sc==b.sc)return a.fs<b.fs;
    return a.sc<b.sc;
}

void update(int idx, int val){
    while(idx<=n){
        tree[idx]+=val;
        idx += (idx & -idx);
    }
}

int query(int idx){
    int ret=0;
    while(idx){
        ret+=tree[idx];
        idx -= (idx & -idx);
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
        CLEAR(tree,0);
        CLEAR(prev,0);

        read(n);read(q);
        for(int i=1;i<=n;i++)read(arr[i]);
        for(int i=0;i<q;i++){
            read(inp[i].fs);
            read(inp[i].sc);
            inp[i].idx=i;
        }
        sort(inp,inp+q,comp);

        int indx=0;

        for(int i=1;i<=n;i++){
            int t=arr[i];
            if(prev[t]){
                update(prev[t],-1);
            }
            update(i,1);
            prev[t]=i;
            while(inp[indx].sc==i){
                int ans= query(inp[indx].sc)-query(inp[indx].fs-1);
//                cout<<i<<" "<<ans<<endl;
                output[inp[indx].idx]=ans;
                indx++;
            }
        }
        for(int i=0;i<q;i++)
            printf("%d\n",output[i]);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





