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
int n;
ll dp[35][2][2][110];

ll tightVal(int n1, int idx){
    ll ret=1;
    for(int i=idx-1;i>=0;i--)
        ret*=(1<<(Check(n1,i)) );
    return ret;
}

ll gen(int idx, bool tight, bool last, int count){
    if(idx<0){
        return count;
    }
    ll &ret=dp[idx][tight][last][count];
    if(ret!=-1)return ret;
    ret=0;
    if(last==1){
        if(tight){
            if(Check(n,idx)){
                ret+=gen(idx-1,1,1, count+1);
                ret+=gen(idx-1,0,0,count);
            }
            else{
                ret+=gen(idx-1,1,0,count);
            }
        }
        else{
            ret+=gen(idx-1, 0, 1,count+1);
            ret+=gen(idx-1,0,0,count);
        }
    }
    else{
        if(tight){
            if(Check(n,idx)){
                ret+=gen(idx-1,0,0,count);
                ret+=gen(idx-1,1,1,count);
            }
            else{
                ret+=gen(idx-1,1,0,count);
            }
        }
        else{
            ret+=gen(idx-1,tight,1,count);
            ret+=gen(idx-1,tight,0,count);
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
    FOR(C, 1, test) {
        out(C);
        read(n);
        int idx=31;
        for(idx=31;idx>=0;idx--) if(Check(n,idx))break;
        CLEAR(dp,-1);
        ll ans=gen(idx,1,0, 0);
        printf("%lld\n",ans);
    }
    return 0;
}





