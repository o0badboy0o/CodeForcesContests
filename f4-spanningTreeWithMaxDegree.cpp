//max degree overall vertices in a spanning tree to be maximised ante....take any vertex with max degree and do a bfs from it...
//ante utilize each edge of the max_deg_ele in the spanning tree

/*
    YES PAIN YES GAIN
*/

#include<bits/stdc++.h>
using namespace std;
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

const int N=2e5+5;
const int M=3e5;
const int mod=1e9+7;

vi graph[N];
int degree[N];
bool vis[N];

void bfs(int idx)
{
    queue<int> q;
    q.push(idx);
    vis[idx]=true;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();


        for(int v : graph[u])
        {
            if(!vis[v]) 
            {
                vis[v]=true;
                q.push(v);
                cout<<u<<" "<<v<<"\n";
            }
        }
    }
}

void solve()
{
    int n,m,a,b;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
        degree[a]++;
        degree[b]++;
    }

    int max_deg_ele=1;
    for(int i=2;i<=n;i++)
    {
        if(degree[i]>degree[max_deg_ele]) max_deg_ele=i;
    }

    bfs(max_deg_ele);
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