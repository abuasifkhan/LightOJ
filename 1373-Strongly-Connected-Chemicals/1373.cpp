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
#define mx 120

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

int r, c;
vector<int>g[mx];
char grid[mx][mx];
int Left[mx], Right[mx], Match[mx];
bool seen[mx];

bool kuhn(int u){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(Right[v]!=1 or seen[v])continue;
        seen[v]=1;
        if(Match[v]==-1 or kuhn(Match[v])){
            Match[v]=u;
            return 1;
        }
    }
    return 0;
}

int matching(){
    int cnt=0;
    CLEAR(Match,-1);
    for(int i=0;i<r;i++){
        if(Left[i]!=1)continue;
        CLEAR(seen,0);
        cnt+=kuhn(i);
    }
    return cnt;
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
        read(r);read(c);
        for(int i=0;i<mx;i++)g[i].clear();

        for(int i=0;i<r;i++){
            scanf("%s", grid[i]);
            for(int j=0;j<c;j++){
                if(grid[i][j]=='0')g[i].pb(j);
            }
        }

        printf("Case %d: ", C);
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='0')continue;
                CLEAR(Left,-1); CLEAR(Right,-1);
                int ca=0,cb=0;
                for(int k=0;k<c;k++){
                    if(grid[i][k]=='0')continue;
                    Right[k]=1;
                    ca++;
                }
                for(int k=0;k<r;k++){
                    if(grid[k][j]=='0')continue;
                    Left[k]=1;
                    cb++;
                }
                ans=max(ans, ca+cb-matching());
            }
        }
        printf("%d\n",ans);
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}




