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
int total;
int arr[95][10];
void nqueen(int cnt, int row, int leftRow, int rightRow, int made[10]) {
    if(row==(1<<8)-1) {
        for(int i=0; i<8; i++)
            arr[total][i]=made[i];
        total++;
        return;
    }
    int blocked = row|leftRow|rightRow;
    for(int i=0; i<8; i++) {
        if(!Check(blocked,i)) {
            made[cnt]=i;
            nqueen(cnt+1, Set(row,i), Set(leftRow,i)<<1, Set(rightRow,i)>>1, made);
        }
    }
}

char grid[10][10];
int dp[1<<8+10];
pii pos[10];

int Place(int r1,int c1, int r2, int c2) {
    if(r1==r2 and c1==c2)return 0;
    if(r1==r2 or c1==c2) return 1;
    if(abs(r1-r2)==abs(c1-c2))return 1;
    return 2;
}

int rec(const int* v, int mask) {
    if(mask==(1<<8)-1) {
        return 0;
    }
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    ret=inf;
    int col=__builtin_popcount(mask);
    for(int i=0;i<8;i++){
        if(Check(mask,i))continue;
        int dist=Place(i,v[i],pos[col].fs, pos[col].sc);
        ret=min(ret, dist+rec(v,Set(mask,i)));
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
    total=0;
    int sdlkafj[9];
    nqueen(0,0,0,0,sdlkafj);
//    for(int i=0;i<92;i++){
//        cout<<i<<": ";
//        for(int j=0;j<8;j++)cout<<arr[i][j]+1<<" ";cout<<endl;
//    }
    int test;
    read(test);
    for(int C=1; C<=test; C++) {
        printf("Case %d: ", C);
        int p=0;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                cin>>grid[i][j];
                if(grid[i][j]=='q')pos[p++]=pii(i,j);
            }
        }
        int Mn=inf;
        for(int i=0; i<92; i++) {
            CLEAR(dp,-1);
            Mn=min(Mn,rec(arr[i],0));
        }
        printf("%d\n",Mn);
    }

#ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
#endif // LOCAL
    return 0;
}




