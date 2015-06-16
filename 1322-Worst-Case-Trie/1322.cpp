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
#define pii pair <ll, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf 0x7fffffff
#define ll long long
#define mod 1000000
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 10000010

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

ll save[5];
pii inp[10010];
pii output[10010];
int test;
ll MAX;
void postCal(){
    save[0]=1;
    int ptr=0;
    ll len=log10(1.0);
    for(ll i=1;i<=MAX;i++){
        save[i%2] = (1ll+(i*save[(i-1)%2 ])%mod)%mod;
        while(ptr<test and i==inp[ptr].first){
            output[inp[ptr].second].first=save[i%2];
            output[inp[ptr].second].second=i;
            ptr++;
        }
        if(ptr>=test)return;
    }
}



int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    read(test);
    FOR(C, 0, test-1) {
        read(inp[C].first);
        MAX=max(MAX, inp[C].first);
        inp[C].second=C;
    }
    sort(inp,inp+test);
    postCal();
    for(int C=0;C<test;C++){
        out(C+1);
        if(output[C].second<=5){
            printf("%lld\n",output[C].first);
        }
        else{
            ll ans=output[C].first;
            ans%=10000;
            printf("%04lld\n",ans);
        }
    }
    return 0;
}





