//! Bismillahi-Rahamanirahim.
/// http://lightoj.com/volume_showproblem.php?problem=1044

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

string str;

bool isPal[1010][1010];
int dp[1010][1010];

int dpRec(int l, int r){
    if(isPal[l][r])return 1;
    int &ret=dp[l][r];
    if(ret!=-1)return ret;
    ret=(r-l+1);
    for(int i=l;i<r;i++)
        if(isPal[l][i])
            ret=min(ret,1+dpRec(i+1,r));
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
        cin>>str;
        int n=str.size();
        CLEAR(isPal,0);
        for(int i=0;i<n;i++)isPal[i][i]=1;
        for(int i=0;i+1<n;i++)isPal[i][i+1]=(str[i]==str[i+1]);

        for(int dist=3;dist<=n;dist++){
            for(int i=0;i+dist<=n;i++){
                int j=i+dist-1;
                isPal[i][j]=((isPal[i+1][j-1]) and (str[i]==str[j]));
            }
        }
        CLEAR(dp,-1);
        int ans=dpRec(0,str.size()-1);
        printf("%d\n",ans);
    }
    return 0;
}





