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
#define mx 1000010
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

int tree[mx];

void update(int node, int l, int r,int pos, int val){
    if(pos>r or pos<l)return;
    if(pos>=l and pos<=r){
        tree[node]+=val;
        if(l==r)return;
    }
    update(node*2,l,(l+r)/2, pos,val);
    update(node*2+1,(l+r)/2+1, r, pos, val);
}

int query(int node, int l, int r, int idx){
    if(l>r)return 0;
    if(l==r)return l;
    int leftSum=tree[node*2];
    if(leftSum>=idx){
        return query(node*2,l,(l+r)/2,idx);
    }
    else return query(node*2+1,(l+r)/2+1, r, idx-leftSum);
}
int n, nq, q, nn, arr[mx];
int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(n);read(q);
        CLEAR(tree,0);
        nq=n+q; nn=n;
        for(int i=1;i<=n;i++){
            read(arr[i]);
            update(1,1,nq,i,1);
        }
        while(q--){
            char c[5];int v;
            scanf("%s %d", c, &v);
            if(c[0]=='c'){
                if(n<v){
                    printf("none\n");
                    continue;
                }
                n--;
                int idx = query(1,1,nq,v);
                printf("%d\n",arr[idx]);
                update(1,1,nq,idx,-1);
            }
            else{
                arr[++nn]=v;
                n++;
                update(1,1,nq,nn,1);
            }
        }
    }
    return 0;
}





