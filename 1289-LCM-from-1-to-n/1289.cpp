//! Bismillahi-Rahamanirahim.
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/


/**................ Headers ................**/
#include <bits/stdc++.h>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1ll<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1ll<<j))
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
#define mod (1ll<<32)
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 100000010

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

int prime[6000000],psz;
//bitset<100000010>p;
ll mask[mx/64 + 10];
void sieve(ll sz=mx-1){
    psz=0;
    CLEAR(mask,0);
    prime[psz++]=2;

    for(ll i=3;i<=sz;i+=2){
        if(!Check(mask[i/64], (i%64))){
            for(ll j=i*i;j<=sz;j+=2*i)
                mask[j/64]=Set(mask[j/64], (j%64));
        }
    }
    for(ll i=3;i<=sz;i+=2){
        if(!Check(mask[i/64], (i%64)))
            prime[psz++]=i;
    }
}

unsigned cumPrime[6000000];
unsigned func(int n){
    int sq=sqrt(n);
    unsigned ret=1;
    for(int i=0;prime[i]<=sq;i++){
        int t=n/prime[i];

        while(t/prime[i]){
            t/=prime[i];
            ret*=prime[i];
        }
    }
    return ret;
}

int main() {
	#ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL
    sieve();
    cumPrime[0]=2;
    for(int i=1;i<psz;i++)
        cumPrime[i]=cumPrime[i-1]*prime[i];

    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        int n;
        read(n);
        int idx=upper_bound(prime,prime+psz,n)-prime;
//        cout<<n<<" "<<idx<<endl;
        unsigned ans = func(n);
        ans*=cumPrime[idx-1];
        printf("%u\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





