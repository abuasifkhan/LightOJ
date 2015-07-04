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
#define out(C) printf("Case %d:", C);
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
#define mx 110

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

int Left[mx], Right[mx], seen[mx];
//vector<int>adj[mx];
//vector<int>tmp[mx];

vector<int>arr;
vector<int>tmp,tmp1;
int n;

bool kuhn(int u){
    for(int i=u+1;i<n;i++){
        int v = i;
        if(seen[v] or arr[i]%arr[u])continue;
        seen[v]=1;
        if(Right[v]==-1 or kuhn(Right[v])){
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}

int bipertiteMatching(){
    CLEAR(Left,-1);
    CLEAR(Right,-1);
    int cnt=0;
    for(int i=0;i<n;i++){
        CLEAR(seen,0);
        if(kuhn(i))cnt++;
    }
    return cnt;
}

map<int,bool>mp;

int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL
    int test;
    read(test);
    FOR(C, 1, test) {
        read(n);arr.clear();mp.clear();
        for(int i=0;i<n;i++){
            int a;read(a);
            if(!mp[a]){
                mp[a]=1;
                arr.pb(a);
            }
        }
        sort(arr.begin(),arr.end());
//        unique(arr.begin(),arr.end());
        n=arr.size();
//        for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
        int bm=bipertiteMatching();
        int mbm = max(bm,n-bm);
        out(C);
//        cout<<bm<<" "<<mbm<<endl;
        int made=0, st=0;
        vector<int>ans;
        while(made<mbm and st<n){
            made++;
            tmp=arr;
            tmp1.clear();
            for(int i=st+1;i<n;i++){
                if(arr[i]%arr[st]){
                    tmp1.pb(arr[i]);
//                    cout<<arr[i]<<" ";
                }
            }
//            cout<<endl;
            n=tmp1.size();
            arr=tmp1;
            int B = bipertiteMatching();
            int tb=max(B,n-B);
//            cout<<st<<" "<<tmp[st]<<" "<<B<<" "<<n-B<<" "<<made<<endl;
            if(tb+made==mbm){
                ans.pb(tmp[st]);
                cout<<" "<<tmp[st];
                st=0;
            }
            else{
                made--;
                st++;
                arr=tmp;
                n=arr.size();
            }
        }
        puts("");
    }
    return 0;
}





