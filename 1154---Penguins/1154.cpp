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
#define inf 999999999
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define mx 310

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

vector<int>adj[mx];
int w[mx][mx];
int wt[mx][mx];
vector<int>sinklist;
bool col[mx];
int par[mx];
int totflow,flow;
int n;double D;

struct pnt{
    int x, y, n, m;
}p[mx];

double dist(int a, int b){
    return  (double)(p[a].x-p[b].x)*(p[a].x-p[b].x) +
                 (p[a].y-p[b].y)*(p[a].y-p[b].y);
}

void updategraph(int source, int sink) //flow is never infinity here
{
    int prev,next;
    next=sink;
    flow=inf;
    //printf("fsd");
    while(par[next]>-1)
    {
        //print2(next,par[next]);
        prev=par[next];
        flow=min(flow,w[prev][next]);
        next=prev;
    }
    //printf("fds");
    next=sink;
    while(par[next]>-1)
    {
        prev=par[next];
        w[prev][next]-=flow;
        w[next][prev]+=flow;
        next=prev;
    }
}


bool augment_path(int source,int sink) // return true if there is positive flow
{
    queue<int>q;
    q.push(source);
    CLEAR(par,-1);
    CLEAR(col,false);
    col[source]=true;
    int prev,next;
    bool cnt=true;
    while(q.size()&&cnt)
    {
        int i;
        prev=q.front();
        q.pop();
        //print1(prev);
        for(i=0;i<adj[prev].size();i++)
        {
            next=adj[prev][i];
            //print1(next);
            if(!col[next]&&w[prev][next]>0)
            {
                col[next]=true;
                par[next]=prev;
                if(next==sink) continue;
                q.push(next);
            }
        }
    }

    return par[sink]!=-1;
}

void maxflow(int source,int sink)
{
    totflow=0;
    sinklist=adj[sink];
    while(augment_path(source,sink))
    {
        for(int i=0;i<sinklist.size();i++)
        {
            int u = sinklist[i];
            if(!col[u] || w[u][sink]<=0) continue;
            par[sink]=u;
            updategraph(source,sink);
            totflow+=flow;
        }
    }
    return;
}

void makeedge(int a, int b, int c){
    adj[a].pb(b);
    adj[b].pb(a);
    wt[a][b]+=c;
//    wt[b][a]+=0;
}

void inp(){
    cin>>n>>D;
    D*=D;
    int tot=0;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y>>p[i].n>>p[i].m;
        tot+=p[i].n;
    }
//    int N=2*n;
    for(int i=1;i<=n;i++){
        makeedge(0,i,p[i].n);
        makeedge(i,i+n,p[i].m);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i==j)continue;
        if(dist(i,j)<D)
            makeedge(n+i,j,inf);
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        for(int i=0;i<=2*n+5;i++)for(int j=0;j<=2*n+5;j++)
            w[i][j]=wt[i][j];

        maxflow(0,i);
//        cout<<i<<" "<<tot<<" "<<totflow<<endl;
        if(totflow==tot)
            ans.pb(i-1);
    }
    if(!ans.size())printf(" -1\n");
    else{
        for(int i=0;i<ans.size();i++)
            cout<<" "<<ans[i];cout<<endl;
    }
}
int main() {
	#ifdef LOCAL
    open
    #endif // LOCAL

    int test;
    read(test);
    FOR(C, 1, test) {
        out(C);
        CLEAR(w,0);CLEAR(wt,0);
        for(int i=0;i<mx;i++)adj[i].clear();
        inp();
    }
    return 0;
}





