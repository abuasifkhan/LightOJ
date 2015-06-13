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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};
pii points[20];
int n;

int line[18][18], dp[(1<<17)+5];

bool isInLine(pii p1, pii p2, pii p3){
    int x1,x2,y1,y2,x,y;
    x1=p1.fs, x2=p2.fs, x=p3.fs;
    y1=p1.sc, y2=p2.sc, y=p3.sc;

    return (bool) ((y-y1)*(x1-x2)==(x-x1)*(y1-y2) );
}

void gen(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                line[i][j]|=(1<<i);
                line[i][j]|=(1<<j);

                if(!Check(line[i][j],k) and isInLine(points[i], points[j], points[k])){
                    line[i][j]|=(1<<k);
                }
            }
        }
    }
}

int rec(int mask){
    if(mask==(1<<n)-1)return 0;
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    int c=0;for(int i=0;i<n;i++) c+=!Check(mask,i);
    if(c<=2)return 1;

    ret=(1<<30);
    for(int i=0;i<n;i++){
        if(Check(mask,i)) continue;

        for(int j=0;j<n;j++){
            if(Check(mask,j))continue;
            int tmp=mask;
            tmp|=line[i][j];
            ret = min(ret, 1+rec(tmp));
        }
        break;
    }
    return ret;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;read(test);
    for(int C=1;C<=test;C++){
        read(n);
        out(C);
        CLEAR(line,0);
        for(int i=0;i<n;i++){
            read(points[i].fs);read(points[i].sc);
        }
        CLEAR(dp,-1);
        gen();
        int ans=rec(0);
        printf("%d\n",ans);
    }
    return 0;
}





