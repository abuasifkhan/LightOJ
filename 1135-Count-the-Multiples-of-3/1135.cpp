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

int n,q;
struct NODE{
    int count[5];
    int lazy,v;
    NODE(){
        for(int i=0;i<5;i++)count[i]=0;
        lazy=v=0;
    }
    void merge(NODE l, NODE r){
        for(int i=0;i<3;i++)count[i]=l.count[i]+r.count[i];
    }
    void RotateOnce(){
        int tmp=count[2];
        count[2]=count[1];
        count[1]=count[0];
        count[0]=tmp;
    }

}tree[3*mx];

void pushDown(int idx){
    if(tree[idx].lazy==0)return;
    tree[idx].lazy%=3;
    tree[idx*2].lazy+=tree[idx].lazy;
    tree[idx*2+1].lazy += tree[idx].lazy;

    for(int i=0;i<tree[idx].lazy;i++){
        tree[idx*2].RotateOnce();
        tree[idx*2+1].RotateOnce();
    }
    tree[idx].lazy=0;
}
bool f;
void build(int idx,int l, int r){
    if(l>r)return;
    if(l==r){
        tree[idx].count[0]=1;
        return;
    }
    build(idx*2,l,(l+r)/2);
    build(idx*2+1,(l+r)/2+1,r);
    tree[idx].merge(tree[idx*2],tree[idx*2+1]);
}
void update(int idx, int l, int r, int x, int y, int val){
    if(l>=x and r<=y){
        tree[idx].RotateOnce();
        tree[idx].lazy++;
        return;
    }
    pushDown(idx);
    int mid=(l+r)/2;
    if(mid>=x) update(idx*2,l,(l+r)/2,x,y,val);
    if(mid<y) update(idx*2+1,(l+r)/2+1,r,x,y,val);
    tree[idx].merge(tree[idx*2],tree[idx*2+1]);
}

int query(int idx, int l, int r, int x, int y){
    if(l>=x and r<=y){
        return tree[idx].count[0];
    }
    pushDown(idx);
    int mid=(l+r)/2;
    int ret=0;
    if(mid>=x)
        ret+=query(idx*2,l,mid,x,y);
    if(mid<y)
        ret+=query(idx*2+1,mid+1,r,x,y);
    return ret;
}
int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        CLEAR(tree,0);
        read(n);read(q);
        build(1,1,n);
        while(q--){
            int t,l,r;read(t);read(l);read(r);
            l++,r++;
            if(t==0){
                update(1,1,n,l,r,1);
            }
            else{
                int ans = query(1,1,n,l,r);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}





