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
#define mx 510

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

int N, K;
vector<ll>primelist;
bitset<1000000>p;

void seive(int sz=4000){
    p.set();
    primelist.pb(0);
    p[1]=0;
    for(ll i=2;i<=sz;i++){
        if(p[i]){
            primelist.pb(i);
            for(ll j=i*i;j<=sz;j+=i){
                p[j]=0;
            }
        }
    }
}

ll modPow(ll n, ll p){
    if(!p)return 1;
    if(p%2)return (n*modPow(n,p-1))%mod;
    ll ret=modPow(n,p/2);
    return (ret*ret)%mod;
}

ll dp[mx][mx];
ll pwr[mx];

void preproc(){
    seive();

    dp[1][1]=1;
    for(int i=2;i<mx;i++){
        dp[1][i]=modPow(2,i)-modPow(2,i-1);
        dp[1][i]%=mod;
        if(dp[1][i]<0)dp[1][i]+=mod;
    }
    for(int i=2;i<mx;i++){
        int nowprime=primelist[i];
        pwr[0]=1;
        for(int j=1;j<mx;j++)
            pwr[j]=modPow(nowprime, j);
        for(int k=i;k<mx;k++){
            dp[i][k]=0;
            for(int j=1;j<k;j++){
                int l=k-j;
                ll t=(dp[i-1][j]*(pwr[l]-pwr[l-1]+mod)%mod)%mod;
                dp[i][k]+=t;
                dp[i][k]%=mod;
            }
        }
    }
}

int main() {
	#ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    preproc();

    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(K);read(N);
        printf("%lld\n",dp[N][K]);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





