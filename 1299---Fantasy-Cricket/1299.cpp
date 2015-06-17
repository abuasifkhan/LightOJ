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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};
char str[1002];
int n;
ll dp[1002][1002];

ll rec(int pos, int prevU){
    if(prevU<0)return 0;
    if(pos==n)return (prevU==0);
    ll &ret=dp[pos][prevU];
    if(ret!=-1)return ret;
    ret=0;
    if(str[pos]=='E')return ret=rec(pos+1,prevU);
    else if(str[pos]=='U'){
        ret=(prevU*rec(pos+1,prevU))%mod;
        ret+=rec(pos+1,prevU+1);ret%=mod;
    }
    else{
        ret=(prevU*rec(pos+1,prevU-1))%mod;
        ret+=rec(pos+1,prevU);ret%=mod;
        ret=(ret*prevU)%mod;
    }
    return ret;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        scanf("%s",str);
        n=strlen(str);
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
        printf("%lld\n",rec(0,0));
    }
    return 0;
}





