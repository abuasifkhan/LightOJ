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
#define mx 105

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

int grid[mx][mx];
int dp[mx][mx][mx]; //[row][path1_col][path2_col]. path1 left path, path2 right path.
int r, c;
void solve(){
    CLEAR(dp,0);
    dp[0][0][0]=grid[0][0];
    for(int k=1;k<c;k++)
        dp[0][0][k]=dp[0][0][k-1]+grid[0][k];

    for(int i=1;i<r;i++){
        // column fixed just pushing down
        for(int j=0;j<c;j++)
            for(int k=j+1;k<c;k++)
            dp[i][j][k]=dp[i-1][j][k]+grid[i][j]+grid[i][k];
        // path1 is going left; path2 cannot cross it.
        for(int j=1;j<c;j++)
            for(int k=j+1;k<c;k++)
            dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k]+grid[i][j]);
        // path2 is going right, path1 cannot cross it.
        for(int j=0;j<c;j++)
            for(int k=j+1;k<c;k++)
            dp[i][j][k]=max(dp[i][j][k], dp[i][j][k-1]+grid[i][k]);
    }
    CLEAR(grid,0);
}
int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            scanf("%d",&grid[i][j]);
        solve();
        printf("%d\n",dp[r-1][c-2][c-1]);
    }
    return 0;
}





