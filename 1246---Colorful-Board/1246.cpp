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
#define mx 300

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

ll ncr[mx][mx];
ll dp[mx][55];
int n, m, k;

void precal(){
    for(int i=0;i<mx;i++){
        ncr[i][0]=ncr[i][i]=1;
        for(int j=1;j<i;j++){
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
//            cout<<ncr[i][j]<<" ";
        }
//        cout<<endl;
    }
}

ll rec(int square, int color){
    if(color>square or square<=0 or color<=0)return 0;
    if(color==1 )return 1;

    ll &ret=dp[square][color];
    if(ret!=-1)return ret;
    ret=0;
    for(int pick=1;pick<=square;pick++){
        ll t=(ncr[square][pick]*rec(square-pick, color-1))%mod;
        ret=(ret+t)%mod;
    }
    return ret;
}

ll solve(){
    ll ret=0;
    int a=n*m/2;
    int b=n*m-a;
    for(int color=1;color<=k; color++){
        for(int rest=1;color+rest<=k; rest++){
            ll t=ncr[k][color];
            t = (t*ncr[k-color][rest])%mod;
            t=(t * rec(a,color))%mod;
            t=(t*rec(b,rest))%mod;
            ret = (ret+t)%mod;
//            cout<<color<<" "<<rest<<" "<<ncr[k][color]<<" "<<ncr[k-color][rest]<<endl;
//            cout<<color<<" "<<rest<<" "<<t<<" "<<ret<<endl;
        }
    }
    return ret;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    precal();
    CLEAR(dp,-1);

    FOR(C, 1, test) {
        out(C);
        read(n);read(m);read(k);
        m++,n++;
        if(n==1 and m==1)printf("%d\n", k);
        else
        printf("%lld\n",solve());
    }
    return 0;
}





1246 - Colorful Board
