//! Bismillahi-Rahamanirahim.
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
#define pii pair <int, int>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1<<28)
#define ll long long
#define mod 1000000007
#define debug cout<<"ok"<<endl;
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
// int X[]= {-1, 0, 1, 0};   //x 4 direction
// int Y[]= { 0, 1, 0, -1};  //y 4 direction

double dp[510][510];

double rec(int red, int blue){
//    cout<<red<<" "<<blue<<endl;
    if(red==0 and blue>=1)return 1;
    if(blue==0 and red>=1)return 0;
    double &ret=dp[red][blue];
    if(ret!=-1)return ret;
    ret=0.00;
    double sum = red+blue;
    // blue blue
    if(blue>=2) ret+= 1.0*blue/sum*rec(red,blue-2);
    // red blue
    ret+=1.0*red/sum*rec(red-1,blue-1);
    return ret;
}

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    for(int i=0;i<510;i++)for(int j=0;j<510;j++)dp[i][j]=-1;
    for(int C=1;C<=test;C++) {
        printf("Case %d: ", C);
        int red,blue;
        read(red);read(blue);
        double ans = rec(red,blue);
        printf("%.10lf\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




