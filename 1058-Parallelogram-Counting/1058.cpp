//! Bismillahi-Rahamanirahim.
///

/** ========================================**
 ** @Author: A Asif Khan Chowdhury
 ** @Category:
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
#define pii pair <ll, ll>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d: ", C);
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
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};
int n;
pii arr[1010];
vector<pii>segments;
bool comp(pii a, pii b){
    if(a.fs==b.fs)return a.sc<b.sc;
    return a.fs<b.fs;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        segments.clear();
        read(n);
        for(int i=0;i<n;i++){
            read(arr[i].fs);read(arr[i].sc);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                segments.pb(pii(arr[i].fs+arr[j].fs, arr[i].sc+arr[j].sc));
            }
        }
        sort(segments.begin(), segments.end(),comp);
        ll ans=0;
        pii tmp=segments[0];
        int cnt=1;
        for(int i=1;i<segments.size();i++){
//            cout<<tmp.fs<<" "<<tmp.sc<<" "<<segments[i].fs<<" "<<segments[i].sc<<endl;
            if(tmp!=segments[i]){
//                cout<<"yes"<<endl;
                ans+=cnt*(cnt-1)/2;
                cnt=1;
                tmp=segments[i];
            }
            else cnt++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}





