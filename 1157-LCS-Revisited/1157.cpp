//! Bismillahi-Rahamanirahim.
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
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1<<28)
#define ll long long
#define mod 1000007
#define debug cout<<"ok"<<endl;
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
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

char a[1010],b[1010];
int dp[1010][1010],lcs[1010][1010];

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    for(int C=1;C<=test;C++) {
        scanf("%s %s",a,b);
        int al=strlen(a), bl=strlen(b);
        printf("Case %d: ", C);
        for(int i=0;i<=al;i++)for(int j=0;j<=bl;j++)dp[i][j]=0,lcs[i][j]=0;

        for(int i=al;i>=0;i--){
            for(int j=bl;j>=0;j--){
                if(i==al or j==bl){
                    dp[i][j]=1; // lcs of len 0, so 1.
                    lcs[i][j]=0;// no lcs.
                }
                else if(a[i]==b[j]){
                    lcs[i][j]=1+lcs[i+1][j+1];  // normal lcs formula
                    dp[i][j]=dp[i+1][j+1];      // diagonal intersection, so no change.
                }
                else{
                    lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]); // normal lcs formula
                    if(lcs[i][j]==lcs[i+1][j])  // ans can be from left side in the table.
                        dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
                    if(lcs[i][j]==lcs[i][j+1])  // ans can be from right side in the table.
                        dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
                    if(lcs[i][j]==lcs[i+1][j+1])    // diagonal count, which is over count.
                        dp[i][j]=(dp[i][j]-dp[i+1][j+1])%mod;
                    if(dp[i][j]<0)dp[i][j]+=mod;
                }
            }

        }
        printf("%d\n",dp[0][0]);
//        for(int i=0;i<al;i++){
//            for(int j=0;j<bl;j++){
//                cout<<lcs[i][j]<<" ";
//            }cout<<endl;
//        }
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




