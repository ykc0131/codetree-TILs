#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n;
vector<long long> vec;
void init(){
    cin >> n;
    vec.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
}

bool customeCmp(long long a, long long b){
    long long cmp1 = a*pow(10,to_string(b).size()) + b;
    long long cmp2 = b*pow(10,to_string(a).size()) + a;

    return cmp1 > cmp2;
}

void solve(){
    sort(vec.begin(), vec.end(), customeCmp);

    string result = "";
    for(auto v : vec){
        result += to_string(v);
    }

    cout << result << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}