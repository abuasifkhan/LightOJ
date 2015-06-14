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
#define mx 1000010

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
//r[1] = 1;
//for(int i = 2; i < m; ++i)
//    r[i] = (m - (m/i) * r[m%i] % m) % m;

ll fact[mx];

void precal(){
    fact[0]=1;
    for(int i=1;i<mx;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
//    modInv[1]=1;
//    for(int i=2;i<mx;i++)
//        modInv[i]=(mod - (mod/i)*modInv[mod%i] %mod )%mod;

}
ll inv(ll a, ll p=mod-2){
    if(!p)return 1;
    if(p%2)return (a*inv(a,p-1) )%mod;
    ll t = inv(a,p/2);
    return (t*t)%mod;
}
ll nCr(int n, int r){
    ll ret=fact[n];
    ret = (ret*inv(fact[r]) )%mod;
    ret = (ret*inv(fact[n-r]) )%mod;
    return ret;
}
int arr[1010];
int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    precal();
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        int N;read(N);
        ll ans=1;
        ll sum=0;
        for(int i=1;i<=N;i++){
            read(arr[i]);

        }
        sum=arr[1];
        for(int i=2;i<=N;i++){
            sum+=arr[i];
            ans= (ans*nCr(sum-1, arr[i]-1) )%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}





