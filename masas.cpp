#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<long long int> sol(int n, int a, int b){
    long long int res = 0;
    
    vector<long long int> ans;
    ans.push_back(0);
    for(int i = 0; i < n-1; i++){
        vector<long long int> ans2;
        unordered_map<long long int, long long int> an;
        for(int j = 0; j < ans.size(); j++){
            if(an.find(ans[j]+a) == an.end()){
            ans2.push_back(ans[j]+a);
            an[ans[j]+a] = 1;
            }
            if(an.find(ans[j]+b) == an.end()){
            ans2.push_back(ans[j]+b);
            an[ans[j]+b] = 1;
            }
            
        }
        ans = ans2;
    }
    
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t = 0;
    int n = 0;
    int a = 0;
    int b = 0;
    
    cin >>t;
    for(int i = 0; i < t; i++){
        cin >>n;
        cin >>a;
        cin >>b;
        vector<long long int> ans = sol(n, a,b);
        sort(ans.begin(), ans.end());
        for(int elements: ans){
            cout<< elements <<" ";
        }
        cout << endl;
        
    }
    return 0;
}

