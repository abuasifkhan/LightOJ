/** ========================================**
 ** Bismillahi-Rahamanirahim.
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/

#include <bits/stdc++.h>

using namespace std;

#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 110

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
//int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction

int next1[30][mx], next2[30][mx];
char A[mx],B[mx],str[mx];
int alen, blen, stlen;
int dp[mx][mx][mx],dp1[mx][mx][mx], dp2[mx][mx][mx];

void init(){
    CLEAR(dp,0);CLEAR(dp1,0);CLEAR(dp2,0);
}


int solve(){
    for(int i=0;i<=alen;i++)for(int j=0;j<=blen;j++)dp[i][j][0]=dp1[i][j][0]=dp2[i][j][0]=1;

    for(int k=1;k<=stlen;k++){
        for(int i=0;i<=alen;i++){
            for(int j=0;j<=blen;j++){
                if(i){
                    dp1[i][j][k] = dp1[i-1][j][k];
                    if(A[i]==str[k])
                        dp1[i][j][k] = (dp1[i][j][k]+dp[i-1][j][k-1])%mod;
                }
                if(j){
                    dp2[i][j][k] = dp2[i][j-1][k];
                    if(B[j]==str[k])
                        dp2[i][j][k] = (dp2[i][j][k]+dp[i][j-1][k-1])%mod;
                }

                dp[i][j][k]=(dp1[i][j][k]+dp2[i][j][k])%mod;
            }
        }
    }
    return dp[alen][blen][stlen];
}

int main() {
#ifdef LOCAL
    freopen("a.txt", "r", stdin);
#endif // LOCAL

    int test;
    read(test);
    for(int C=1; C<=test; C++) {
        scanf("%s%s%s",A+1,B+1,str+1);
        alen=strlen(A+1);
        blen=strlen(B+1);
        stlen=strlen(str+1);
        init();

        printf("Case %d: ", C);
//        ll ans = rec(1,1,1);
        ll ans = solve();
        printf("%d\n",ans);
    }

    return 0;
}


