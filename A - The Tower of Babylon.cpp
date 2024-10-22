// Problem Name : A - The Tower of Babylon
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
vector<pair<pair<int,int>,int>>v;
int dp[200];


int solve(int x, int y,int pos){
    if(v[pos].first.first>=x || v[pos].first.second>=y) return 0;
    if(dp[pos]!=-1) return dp[pos];
    int ans = 0;
    for(int i=0;i<v.size();i++){
        ans = max(ans,solve(v[pos].first.first,v[pos].first.second,i));
    }
    return dp[pos] = v[pos].second+ans;
}

int32_t main() {
    fastIO;
    for(int test = 1 ; test; test++){
        int n; cin >> n;
        if(n==0) break;
        init(dp,-1);
        for(int i=0;i<n;i++){
            int x,y,z; cin >> x >> y >> z;
            v.push_back({{x,y},z});
            v.push_back({{y,x},z});
            v.push_back({{x,z},y});
            v.push_back({{z,x},y});
            v.push_back({{z,y},x});
            v.push_back({{y,z},x});
        }
        int ans = 0;
        for(int i=0;i<v.size();i++){
            ans = max(ans,solve(INT_MAX,INT_MAX,i));
        }
        testcase(test)<<"maximum height = " << ans << endl;
        v.clear();
    }
    return 0;
} 
