#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int n;
vector<string> sv;

void init(){
    cin >> n; 
    sv.clear();
    sv.resize(n,"");
    for(int i=0; i<n; i++){
        cin >> sv[i];
    }
}

void solve(){
    int result = 0;
    for(int i=0; i<sv.size(); i++){
        string s = sv[i];

        stack<char> st;
        for(int j=0; j<s.size(); j++){
            char c = s[j];
            if(st.empty()){
                st.push(c);
                continue;
            }

            if(st.top() == c)
                st.pop();
            else
                st.push(c);
        }

        if(st.empty())
            result++;
    }   
    cout << result << "\n";
}

int main() {
    init();
    solve();
    return 0;
}