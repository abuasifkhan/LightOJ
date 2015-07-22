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
#define mx 100010
#define fs first
#define sc second

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
pii p[20];
int r,c,g;
int dp[20][1<<17];

int dist(pii a, pii b){
    return max(abs(a.fs-b.fs), abs(a.sc-b.sc));
}

int rec(int idx, int mask){
    if(mask==(1<<g)-1){
        return dist(p[idx],p[15]);
    }
    int &mm=dp[idx][mask];
    if(mm!=-1)return mm;
    mm = (1<<20);

    for(int i=0;i<g;i++){
        if(!Check(mask,i)){
            mm = min(mm, rec(i,Set(mask,i))+dist(p[i],p[idx]));
        }
    }
//    cout<<idx<<" "<<mask<<" "<<mm<<endl;
    return mm;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(r);read(c);
        char str[30];
        g=0;
        for(int i=0;i<r;i++){
            scanf("%s",str);
            for(int j=0;j<c;j++){
                if(str[j]=='g'){
                    p[g++]=pii(i,j);
                }
                else if(str[j]=='x'){
                    p[15]=pii(i,j);
                }
            }
        }
//        cout<<dist(p[15],p[2])<<endl;
//        for(int i=0;i<g;i++)cout<<p[i].fs<<" "<<p[i].sc<<endl;
//        CLEAR(dp,-1);
        for(int i=0;i<17;i++){
            for(int j=0;j<=(1<<g);j++)
                dp[i][j]=-1;
        }
//        cout<<g<<endl;
        int ans = rec(15,0);
        printf("%d\n",ans);
    }
    return 0;
}





