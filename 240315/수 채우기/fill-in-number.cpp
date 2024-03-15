#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
void init(){
    cin >> n;
}

void solve(){
    int result = n/2+1, cnt = n/5;
    bool right = false;

    for(int i=0; i<cnt+1; i++){
        if((n-5*i)%2==0){
            result = min(result, i + (n-5*i)/2);
            right = true;
        }
    }
    if(right)
        cout << result << "\n";
    else
        cout << -1 << "\n";
}

int main() {
    init();
    solve();
    return 0;
}