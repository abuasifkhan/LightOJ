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
#define out(C) printf("Case %d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 1000000007
#define mx 100010
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)

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

struct NODE{
    NODE*next[12];
    int endpoint;
    NODE(){
        for(int i=0;i<12;i++)
            next[i]=NULL;
        endpoint=0;
    }
    ~NODE(){
        for(int i=0;i<10;i++)
            if(next[i])
                delete(next[i]);
    }
}*root;
char str[10010][15];
int n;
void build(){
    delete(root);
    root=new NODE();
    for(int i=1;i<=n;i++){
        NODE * ptr=root;
        for(int j=0;str[i][j];j++){
            int a=str[i][j]-'0';
            if(ptr->next[a]==NULL)
                ptr->next[a]=new NODE();
            ptr=ptr->next[a];
        }
        ptr->endpoint++;
    }
}

bool check(){
    for(int i=1;i<=n;i++){
        NODE *ptr = root;
        for(int j=0;str[i][j];j++){
            if(ptr->endpoint)return 0;
            int a = str[i][j]-'0';
            ptr=ptr->next[a];
        }
        if(ptr->endpoint>1)return 0;
    }
    return 1;
}

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        read(n);
        for(int i=1;i<=n;i++){
            scanf("%s", str[i]);
        }
        build();
        if(check())puts("YES");
        else puts("NO");
    }
    return 0;
}





