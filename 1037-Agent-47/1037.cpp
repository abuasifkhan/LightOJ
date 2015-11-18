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
#define mx 20

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

int life[mx];
int gun[mx][mx];
ll dp[(1<<16)+20];
int n;

ll rec(int mask){
    if(mask==(1<<n)-1)
        return 0;

    ll &ret=dp[mask];
    if(ret!=-1)return ret;
    ret=inf;
    for(int i=0;i<n;i++){
        if(Check(mask,i))continue;
        ret=min(ret,rec(Set(mask,i))+life[i]);
        for(int j=0;j<n;j++){
            int k = gun[j][i];
            if(Check(mask,j)==0 or k==0)continue;
            ret=min(ret,(life[i]+k-1)/k+rec(Set(mask,i)));
        }
    }
    return ret;
}

int main() {
    #ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    for(int C=1;C<=test;C++) {
        printf("Case %d: ", C);
        read(n);
        CLEAR(dp,-1);
        for(int i=0;i<n;i++)read(life[i]);
        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<n;j++){
                gun[i][j]=s[j]-'0';
//                cout<<gun[i][j];
            }
//            cout<<endl;
        }
        ll ans = rec(0);
        printf("%lld\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}
