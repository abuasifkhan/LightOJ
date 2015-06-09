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
#define ll unsigned long long
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

string num;
int base, k;

int retdig(int i){
    int a;
    if(num[i]=='A')a=10;
    if(num[i]=='B')a=11;
    if(num[i]=='C')a=12;
    if(num[i]=='D')a=13;
    if(num[i]=='E')a=14;
    if(num[i]=='F')a=15;
    if(num[i]>='0' and num[i]<='9')a=num[i]-'0';
    return a;
}
ll dp[(1<<16)+10][22];
int save[22];

ll rec(ll mask, int K){
    bool flag=1;
    for(int i=0;i<base;i++){
        if(save[i] and !Check(mask,i)){
            flag=false;break;
        }
    }
    if(flag and K==0)return 1;
    if(flag and K!=0)return 0;

    if(dp[mask][K]!=-1)return dp[mask][K];
    ll &ret = dp[mask][K];ret=0;

    for(int i=0;i<base;i++){
        if(save[i] and !Check(mask,i)){
            ret += rec(Set(mask,i), (K*base+i)%k );
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
        read(base);read(k);cin>>num;
        CLEAR(save,0);
        for(int i=0;i<num.size();i++)save[retdig(i)]++;
        CLEAR(dp,-1);
        cout<<rec(0ll,0)<<endl;
    }
    return 0;
}





