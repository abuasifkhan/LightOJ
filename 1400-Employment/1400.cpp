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
#define inf (1<<30)
#define ll long long
#define mod 1000000007
#define gc getchar
#define debug_array(a,n) for(int i=0;i<n;i++) cout<<a[i].in<<" "; cout<<endl;
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 210

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

void solve(int arr[][mx]){
    int status[mx];
    CLEAR(status,-1);
    queue<int>Q;
    for(int i=1;i<=n;i++) Q.push(i);
    while(!Q.empty()){
        int men=Q.front();
        Q.pop();
        for(int j=1;j<=n;j++){
            int company=arr[men][j];
            if(status[company]==-1){
                status[men]=company;
                status[company]=men;
                break;
            }
            int rank1, rank2;
            for(int k=1;k<=n;k++){
                if(arr[company][k]==status[company])rank1=k;
                if(arr[company][k]==men)rank2=k;
            }
            if(rank2<rank1){
                status[men]=company;
                int old=status[company];
                status[old]=-1;
                Q.push(old);
                status[company]=men;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("(%d %d)",i,status[i]);
        if(i!=n)printf(" ");
    }puts("");
}

int prefer[mx][mx];
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
        printf("Case %d: ", C);
        read(n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                read(prefer[i][j]);
        }
        for(int i=n+1;i<=2*n;i++){
            for(int j=1;j<=n;j++)read(prefer[i][j]);
        }
        solve(prefer);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




