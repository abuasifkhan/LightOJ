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
#define ll unsigned long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 1000100
//ll NegMod (ll a, ll b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }
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

int phi[3*mx];
ll s[3*mx];
void eulerPhi(int sz){
    for(int i=1;i<=sz;i+=2) phi[i]=i;
    for(int i=2;i<=sz;i+=2) phi[i]=i/2;
    for(int i=3;i<=sz;i+=2){
        if(phi[i]==i){
            phi[i]--;
            for(int j=i+i;j<=sz;j+=i)
                phi[j]-= phi[j]/i;
        }
    }
}

void preproc(int sz=3000010){
    eulerPhi(sz);
    
    s[1]=1;
    for(int i=2;i<=sz;i++){
        for(int j=i;j<=sz;j+=i){
            s[j] += (ll)phi[i]*(ll)i;
        }
    }
    for(int i=1;i<=sz;i++){
        s[i] = (s[i])/2 * i;
    }
    for(int i=1;i<=sz;i++)
        s[i]+=s[i-1];
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
        int n;
        read(n);
        out(C);
        printf("%llu\n", s[n]);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





