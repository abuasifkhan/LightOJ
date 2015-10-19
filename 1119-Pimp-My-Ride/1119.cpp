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
#define gc getchar
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
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

int n;
int g[20][20];
int dp[(1<<14)+10];

int rec(int mask){
    if(mask==(1<<n)-1)
        return 0;
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    ret=inf;
    for(int i=0;i<n;i++){
        if(Check(mask,i))continue;
        int total=g[i][i];
        for(int j=0;j<n;j++){
            if(i==j or Check(mask,j)==0)continue;
            total+=g[i][j];
        }
        ret=min(ret, total+rec(Set(mask,i)));
    }
    return ret;
}

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL
    // Can you solve it by brute force?
    // LDC
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)
    int test;
    read(test);
    for(int C=1;C<=test;C++) {
        read(n);
        for(int j=0;j<(1<<n)+1;j++)dp[j]=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)read(g[i][j]);
        }
        printf("Case %d: ", C);
        int ans = rec(0);
        printf("%d\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




