#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN -100000001

using namespace std;

int n;
vector<int> input;
void init(){
    cin >> n;
    input.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
}

void solve(){
    int result=MAXN, value=0;
    for(int i=0; i<n; i++){
        if(value+input[i]>=0)
            value = max(value+input[i], input[i]);
        else
            value = input[i];
        result = max(result, value);
    }
    cout << result << "\n";
}

int main() {
    init();
    solve();
    return 0;
}

//반례1
// 3
// 1 -1 8
// 답 : 8

//반례2 
// 4
// -2 -1 3 6
// 답 : 9