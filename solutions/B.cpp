#include <bits/stdc++.h>
#define int                long long int
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define fastIO             ios::sync_with_stdio(false); cin.tie(NULL);
#define ull                unsigned long long int
#define all(v)             v.begin(),v.end()
#define print(v)           for(auto x : v) cout << x << " "; cout << endl;
#define init(arr, val)     memset(arr, val, sizeof(arr))
#define testcase(x)        cout << "Case " << x << ": "
using namespace std;

const int N = 1e3+10;
double dp[N][N],dist[N][N];
int x[N],y[N];
int n;

double path_cal(int a , int b){
    double distance = hypot(abs(x[a]-x[b]),abs(y[a]-y[b]));
    return distance;
}

double solve(int a, int b){
    if(a==n-1){
        return dp[a][b]=dp[b][a]= dist[b][n-1];
    }
    if(dp[a][b]!= -1.0) return dp[a][b];
    double ans1 = solve(a+1,b) + dist[a][a+1];
    double ans2 = solve(a+1,a) + dist[b][a+1];
    double ans = min(ans1,ans2);
    return dp[a][b] = ans;
}

int32_t main()
{
    cout << fixed << setprecision(2);
    while(cin >> n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1.0;
            }
        }
        
        for(int i=0;i<n;i++) cin >> x[i] >> y[i];

        //Calculate all pair path
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dist[i][j] = dist[j][i] = path_cal(i,j);
             }
        }

        double ans = solve(0,0);
        cout << ans << endl;
    }
}
