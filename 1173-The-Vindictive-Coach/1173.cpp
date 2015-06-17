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
#define ll unsigned long long
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
int N, m;
ll dp[55][55][3];

ll rec(int small, int big, bool isSmall){
    ll &ret=dp[small][big][isSmall];
    if(ret!=-1)return ret;
    if(small==0 and big==1 )
        return ret=isSmall;
    if(small==1 and big==0)
        return ret=isSmall^1;
    ret=0;
    if(isSmall){    //f
        for(int i=1;i<=big;i++)
            ret+=rec(small+i-1, big-i,0);
    }
    else{   //g
        for(int i=1;i<=small;i++)
            ret+=rec(small-i,big+i-1,1);
    }
    return ret;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    rec(50,50,0);
    rec(50,50,1);
    CLEAR(dp,-1);
    FOR(C, 1, test) {
        out(C);
        read(N);read(m);
        ll ans;
        if(m==1){
            if(N>3)
            ans=rec(0,N-3,1);
            else ans=1;
        }
        else{
            ans=rec(m-1,N-m,0);
        }
        printf("%llu\n",ans);
    }
    return 0;
}





