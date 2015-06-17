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
#define mod 10056
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
ll st[mx][mx];
ll fact[mx];
ll dp[mx];

void precal(){
    st[1][1]=1;
    for(int i=2;i<mx;i++){
        for(int k=1;k<=i;k++){
            st[i][k] = (st[i-1][k-1]+(k*st[i-1][k])%mod)%mod;
        }
    }
    fact[0]=1;
    for(int i=1;i<mx;i++)fact[i]=(i*fact[i-1])%mod;
    CLEAR(dp,0);

    for(int i=1;i<=1000;i++){
        for(int j=1; j<=i; j++){
            dp[i]+=(st[i][j]*fact[j])%mod;
            dp[i]%=mod;
        }
    }
};

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    precal();
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        int a;read(a);
        printf("%lld\n",dp[a]);
    }
    return 0;
}





