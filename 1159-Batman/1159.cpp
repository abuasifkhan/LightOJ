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

int dp[55][55][55];
string a,b,c;

int rec(int al, int bl, int cl){
    if(al==a.length() and bl==b.length() and cl==c.length()){
        return 0;
    }
    int &ret=dp[al][bl][cl];
    if(ret!=-1)return ret;
    ret=0;
    if(al<a.length() and bl<b.length() and cl<c.length()){
        if(a[al]==b[bl] and b[bl]==c[cl])
            ret=1+rec(al+1,bl+1,cl+1);
    }
    if(bl<b.length()) ret=max(ret,rec(al,bl+1,cl));
    if(cl<c.length()) ret=max(ret,rec(al,bl,cl+1));
    if(bl<b.length() and cl<c.length()) ret=max(ret,rec(al,bl+1,cl+1));

    if(al<a.length()) ret=max(ret,rec(al+1,bl,cl));
    if(cl<c.length()) ret=max(ret,rec(al,bl,cl+1));
    if(al<a.length() and cl<c.length()) ret=max(ret,rec(al+1,bl,cl+1));

    if(al<a.length()) ret=max(ret,rec(al+1,bl,cl));
    if(bl<b.length()) ret=max(ret,rec(al,bl+1,cl));
    if(al<a.length() and bl<b.length()) ret=max(ret,rec(al+1,bl+1,cl));
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
        cin>>a>>b>>c;
        CLEAR(dp,-1);
        int ans = rec(0,0,0);
        printf("%d\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




