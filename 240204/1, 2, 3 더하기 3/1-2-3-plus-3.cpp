#include <iostream>
#define NUM 1000000007

using namespace std;

int n;

void init(){
    cin >> n;
}

void solve(){
    int ans = 0;
    int dp[n+1] = {0,1,2,4};
    for(int i=4; i<=n; i++){
        dp[i] = ((dp[i-1] + dp[i-2])%NUM + dp[i-3])%NUM;
        //dp[i] %= NUM;
    }
    cout << dp[n]%NUM << "\n";
}

int main() {
    init();
    solve();
    return 0;
}