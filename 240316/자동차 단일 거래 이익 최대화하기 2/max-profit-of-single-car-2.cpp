#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;
void init(){
    cin >> n;   
    vec.resize(n,0);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
}

void solve(){

    int minN = vec[0], result = 0;
    for(int i=1; i<n; i++){
        if(minN < vec[i])
            result = max(result, vec[i] - minN);
        else
            minN = min(minN, vec[i]);
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