#include <iostream>
#define MAXN 91

using namespace std;

int n;
long long arr[MAXN] = {0,};

void init(){
    cin >> n;
}

void solve(){
    arr[1] = 1;
    for(int i=2; i<n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n] << "\n";
}

int main() {
    init();
    solve();
    return 0;
}

//1
// 1

//1
// 10

//2
// 101
// 100

//3
// 1010
// 1001
// 1000

//5
// 10101
// 10100
// 10010
// 10001
// 10000

//8
// 101010
// 101001
// 101000
// 100101
// 100100
// 100010
// 100001
// 100000

//13
// 1010101
// 1010100
// 1010010
// 1010001
// 1010000
// 1001010
// 1001001
// 1001000
// 1000101
// 1000100
// 1000010
// 1000001
// 1000000