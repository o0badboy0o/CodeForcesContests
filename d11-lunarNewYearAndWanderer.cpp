//lex order of undirected graph ante...bfs lo queue badlul set...and know where to print

/*
    YES PAIN YES GAIN
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T> using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

const int N=1e5;
const int M=3e5;
const int mod=1e9+7;

vi graph[N];
int vis[N];

void bfs()
{
    set<int> q;
    q.insert(1);
    vis[1]=true;

    while(!q.empty())
    {
        int u=*q.begin();
        q.erase(q.begin());
        cout<<u<<" ";

        for(int v : graph[u])
        {
            if(!vis[v])
            {
                q.insert(v);
                vis[v]=true;
            }
        }
    }
}

void solve()
{
    int n,m,a,b;
    
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bfs();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}