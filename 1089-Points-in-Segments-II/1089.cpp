//! Bismillahi-Rahamanirahim.
///

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
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d:\n", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 170010
ll NegMod (ll a, ll b) { return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b; }
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

int points[mx],n,q, idx;
int freq[mx];
pii upd[mx];
int Qr[mx];

int main() {
	#ifdef LOCAL
    open
    double st=clock(),en;
    #endif // LOCAL

    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(n);read(q);
        idx=1;
        for(int i=0;i<n;i++){
            read(upd[i].first);read(upd[i].second);
            points[idx++]=upd[i].first;
            points[idx++]=upd[i].second;
        }
        for(int i=0;i<q;i++){
            read(Qr[i]);
            points[idx++]=Qr[i];
        }
        sort(points+1,points+idx);
        int t=1;
        for(int i=2;i<idx;i++){
            if(points[i]!=points[t]){
                points[++t]=points[i];
            }
        }t++;
        idx=t;
        fill(freq,freq+t,0);
//        for(int i=1;i<idx;i++)cout<<points[i]<<" ";cout<<endl;
        for(int i=0;i<n;i++){
            int l=upd[i].first;
            int r=upd[i].second;
            l = lower_bound(points+1,points+idx,l)-points;
            r = lower_bound(points+1,points+idx,r)-points;
            freq[l]++;
            freq[r+1]--;
//            cout<<l<<" "<<r<<endl;
        }
        for(int i=0;i<=idx;i++)freq[i]+=freq[i-1];
        for(int i=0;i<q;i++){
            int t=Qr[i];
            t=lower_bound(points+1,points+idx,t)-points;
            printf("%d\n",freq[t]);
        }
    }

    #ifdef LOCAL
    en=clock();
    cout<<"Time: ";
    cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}





