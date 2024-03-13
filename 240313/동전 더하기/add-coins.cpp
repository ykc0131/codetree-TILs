#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> input;

bool cmp(int a, int b){
    return a > b;
}

void init(){
    cin >> n >> k;
    input.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    sort(input.begin(), input.end(), cmp);
}

void solve(){
    int result = 0;
    for(int i=0; i<n; i++){
        result += k/input[i];
        k %= input[i];
    }
    cout << result << "\n";
}

int main() {
    init();
    solve();
    return 0;
}