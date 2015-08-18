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
#define mod 100000007
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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
// int X[]= {-1, 0, 1, 0};   //x 4 direction
// int Y[]= { 0, 1, 0, -1};  //y 4 direction

ll dp[5][16000]; // [idx][made]
/*
    Calculation: dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+....+dp[i-1][j-k]
                 dp[i][j-1]=dp[i-1][j-2]+dp[i-1][j-3]+....+dp[i-1][j-k-1]
        So we can get:
                 dp[i][j]-dp[i][j-1]=dp[i-1][j-1] - dp[i-1][j-k-1]
               =>dp[i][j] = dp[i][j-1]+dp[i-1][j-1] - dp[i-1][j-k-1]

        base case: dp[0][0]=1;
        Use space optimization dp.
*/
int n, k, s;

int main() {
	#ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(n);read(k);read(s);
        for(int i=0;i<3;i++)
            for(int j=0;j<=s;j++)dp[i][j]=0;

        dp[1][0]=1;
        int i=0;
        for(int _=0;_<n;_++, i^=1){
            dp[i][0]=0;
            for(int j=1;j<=s;j++){
                dp[i][j]=dp[i^1][j-1]+dp[i][j-1];
                dp[i][j]%=mod;
                if(j-k-1>=0){
                    dp[i][j]-=dp[i^1][j-k-1];
                    dp[i][j]+=mod;
                    dp[i][j]%=mod;
                }
            }
//            for(int _=1;_<=s;_++){
//                printf("%lld ",dp[i][_]);
//            }cout<<endl;
        }
        ll ans=dp[i^1][s];
        printf("%lld\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





