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
#define lson(n) n*2
#define rson(n) lson(n)+1
#define Mid(a,b) (a+b)/2
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

int indx[mx*3];

void build(int node, int l, int r){
    if(l==r){
        indx[node]=1;
        return;
    }
    indx[node]=0;
    build(lson(node), l, (l+r)/2);
    build(rson(node),(l+r)/2+1,r);
    indx[node]=indx[lson(node)]+indx[rson(node)];
}

int del(int node, int l, int r, int val){
    if(l==r){
        indx[node]=0;
        return l;
    }
    indx[node]--;
    if(indx[lson(node)]>=val)
        return del(lson(node),l,(l+r)/2,val);
    else
        return del(rson(node),(l+r)/2+1,r,val-indx[lson(node)]);
}
int arr[mx];
int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        int n;read(n);
        for(int i=1;i<=n;i++)read(arr[i]);
        build(1,1,n);
        int ans;
        for(int i=n;i>=1;i--){
            ans=del(1,1,n,i-arr[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}






