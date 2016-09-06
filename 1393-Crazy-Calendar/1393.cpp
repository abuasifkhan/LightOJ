/** ========================================**
 ** Bismillahi-Rahamanirahim.               **
 ** @Author: A Asif Khan Chowdhury          **
 ** ========================================**/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <strings.h>
#include <cmath>
#include <cstdio>
#include <set>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

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
#define inf (1ll<<28)
#define ll long long
#define ull unsigned ll
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while((~c&&c<'0')||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
//int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
int X[]= {-1, 0, 1, 0};   //x 4 direction
int Y[]= { 0, 1, 0, -1};  //y 4 direction

int r,c;

int main() {
#ifdef DEBUG
    freopen("/Users/abuasifkhan/Desktop/Programming/ProblemSolving/ProblemSolving/a.in", "r", stdin);
    //    freopen("/Users/abuasifkhan/Desktop/Programming/ProblemSolving/ProblemSolving/b.out", "w", stdout);
#endif
    
    int test;
    read(test);
    for(int C=1; C<=test; C++) {
        printf("Case %d: ", C);
        read(r);read(c);
        int x=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                int a;
                read(a);
//                if(i==r and j==c)continue;
                int dist = (r-i)+(c-j);
                
//                cout<<i<<" "<<j<<" "<<dist<<endl;
                if(dist%2==1) x^=a;
            }
        }
        if(x==0)puts("lose");
        else puts("win");
    }
    
    return 0;
}


