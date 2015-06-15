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
#define mod 100000007
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

ll powers[200010],idx;
ll fact[2*mx], cat[mx];
ll modPow(ll n, ll p=mod-2){
    if(p==0)return 1ll;
    if(p%2)return (n*modPow(n,p-1))%mod;
    ll ret=modPow(n,p/2);
    return (ret*ret)%mod;
}

void prec(){
    idx=0;
//    powers[idx++]=0;
    for(ll i=2;i<100005;i++){
        ll t=i*i;
        while(t<=10000000001ll){
            powers[idx++]=t;
            t=t*i;
//            _sleep(100);
        }
    }
    sort(powers,powers+idx);
    int id=0;
    for(int i=1;i<idx;i++)if(powers[id]!=powers[i])powers[++id]=powers[i];
    idx=id+1;
    powers[idx++]=10001000010;

    fact[0]=1;
    for(int i=1;i<mx;i++)
        fact[i]=(i*fact[i-1])%mod;
    cat[0]=cat[1]=1;
    for(int i=2;i<mx;i++){
        cat[i]=(fact[i*2]*modPow((fact[i+1]*fact[i])%mod) )%mod;
    }
}

ll catalan(ll n){
    return cat[n];
}

ll solve(ll a, ll b){
    int l=lower_bound(powers,powers+idx,a)-powers;
    int r=lower_bound(powers,powers+idx,b)-powers;
    if(powers[r]>b)r--;

    int n=(r-l+1);
    if(!n)return 0;
    return catalan((ll)n);
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    prec();
//    for(int i=0;i<20;i++)cout<<powers[i]<<" ";cout<<endl;
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        ll a, b;
        read(a);read(b);
        printf("%lld\n",solve(a,b));
    }
    return 0;
}





