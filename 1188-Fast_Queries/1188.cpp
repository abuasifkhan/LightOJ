//!
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
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case %d:\n", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define mx 100010
#define gc getchar

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
int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}

struct qry{
    int l, r, idx;
}Q[mx];

int n, q;
int arr[mx];
int tree[mx];

void update(int idx, int val){
    while(idx<mx){
        tree[idx]+=val;
        idx+= (idx & -idx);
    }
}

int query(int idx){
    int ret=0;
    while(idx){
        ret+=tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

bool comp(qry a, qry b){
    return a.r<b.r;
}
int prev[mx];
int ans[mx];

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(n);read(q);
        CLEAR(tree,0);CLEAR(Q,0);CLEAR(prev,-1);CLEAR(ans,0);

        for(int i=1;i<=n;i++)read(arr[i]);

        for (int i=0;i<q;i++){
            read(Q[i].l);read(Q[i].r);
            Q[i].idx=i;
        }
        sort(Q,Q+q,comp);
        int idx=0;
        for(int i=0;i<q;i++){
            while(idx<Q[i].r){
                int val = arr[++idx];
                if(prev[val]!=-1)
                    update(prev[val], -1);
                prev[val]=idx;
                update(idx,1);
            }
            ans[Q[i].idx] += query(Q[i].r)-query(Q[i].l-1);
        }
        for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    }
    return 0;
}





