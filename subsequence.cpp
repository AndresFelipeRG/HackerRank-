#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string subsequenceAgain(string s, int k) {
    // Complete this function
    unordered_map <char, int> sol;
    for(int i = 0; i < s.size(); i++){
        if(sol.find(s.at(i)) == sol.end()){
        sol.insert(make_pair<char, int> ((char)s.at(i), 1));
        }
        else{
            sol[s.at(i)] = sol[s.at(i)] + 1;
        }
    }
    
    for(int i = 0; i < s.size(); i++){
        if(sol[s.at(i)] < k){
            sol.erase(s.at(i));
        }
    }
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(sol.find(s.at(i))!= sol.end()){
            res = res + s[i];
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    string result = subsequenceAgain(s, k);
    cout << result << endl;
    return 0;
}
