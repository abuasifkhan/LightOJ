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
#define mod 100000007
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

ll modPow(ll a, ll p, ll M = mod){
    if(!p)return 1ll;
    ll ret = modPow(a,p/2,M);
    ret = (ret*ret)%mod;
    if(p%2)ret = (ret*a)%mod;
    return ret;
}

ll discrete_log(ll a, ll b, ll m = mod){
    map<ll, ll>mp;
    ll sq = sqrt(m)+1;
    ll aa=1;
    // a^1, a^2, ... , a^(sq-1)
    for(int i=0;i<=sq;i++){
        if(!mp.count(aa)) mp[aa] = i;
        aa = (aa*a)%m;
    }

    // b, b*a^-k, b*a^-2k, b*a^-3k... b*a^-(sq-1)k

    // if a^n = b*a^-mk mod M
    // then a^(n+mk) = b mod M.
    ll gamma = b;
    ll coef = modPow(a, m-2);
    coef = modPow(coef, sq);
    for(int i=0;i<=sq;i++){
        if(mp.count(gamma)){
            return i*sq + mp[gamma];
        }
        gamma = (gamma*coef)%m;
    }
    return -1;
}

int main() {
#ifdef DEBUG
    freopen("C:/Users/abu.chowdhury/Desktop/programming/input.in","r",stdin);
//    freopen("C:/Users/abu.chowdhury/Desktop/programming/output.out","w",stdout);
#endif

    int test;
    read(test);
    for(int C=1; C<=test; C++) {
        printf("Case %d: ", C);
        int a, b;
        read(a); read(b);
        cout<<discrete_log(a,b)<<endl;
    }

    return 0;
}










