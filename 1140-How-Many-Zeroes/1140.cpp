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

ll from, to;
ll ten[19];

ll calcZero(ll n){
    ll ans=0;
    string num;
    stringstream ss; ss<<n;ss>>num;
    int k=0;
    ll tmp=n;
    while(n){
        int a=n%10;
        k++;
        ll t=0;
        if(k==1 or a) t=ten[k-1]*(n/10);
        else t=ten[k-1]*(n/10 -1)+tmp+1-ten[k]*(n/10);
        ans+=t;
        n/=10;
    }
    return ans;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    ten[0]=1;
    for(int i=1;i<=18;i++)ten[i]=ten[i-1]*10;

    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        cin>>from>>to;
        ll ans=calcZero(to);
        if(!from)ans++;
        else{
            ans-=calcZero(from-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}





