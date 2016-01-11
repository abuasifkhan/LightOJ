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

int dp[12][100][110][3];
int K;
int a,b;
string A, B;
int p[15];
int rec(string t, int idx, int md,int sum, bool isTight){
//    cout<<idx<<" "<<md<<" "<<sum<<" "<<isTight<<endl;
    if(idx==t.length()){
        return (md%K==0 and sum%K==0);
    }
    int &ret=dp[idx][md][sum][isTight];
    if(ret!=-1)return ret;
    ret=0;
    if(isTight){
        int n=t[idx]-'0';
        ret+=rec(t,idx+1,(md+n)%K,(sum*10+n)%K,1);
        for(int i=0;i<n;i++)
            ret+=rec(t,idx+1,(md+i)%K, (sum*10+i)%K, 0 );
    }
    else{
        for(int i=0;i<10;i++)
            ret+=rec(t,idx+1,(md+i)%K, (sum*10+i)%K, 0);
    }
    return ret;
}

string toStr(int n){
    stringstream ss;
    ss<<n;
    string ret;
    ss>>ret;
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
        read(a);read(b);
        a--;
        A=toStr(a);
        B=toStr(b);
        read(K);
        printf("Case %d: ", C);
        if(K>99){
            printf("0\n");
            continue;
        }
        p[0]=1;

        CLEAR(dp,-1);
        a = rec(A,0,0,0,1);
        CLEAR(dp,-1);
        b = rec(B,0,0,0,1);
        printf("%d\n",b-a);
    }


    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




