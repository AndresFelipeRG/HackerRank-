#include <bits/stdc++.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>
using namespace std;

long long int buyMaximumProducts(int n, long long int k, vector <int> a) {
    // Complete this function
    if(n == 0 || k == 0){
        return 0;
    }
    vector<pair<int, int>> pairs;
    for(int i = 0; i < a.size(); i++){
        pairs.push_back(make_pair(a[i], i +1));
    }
    sort(pairs.begin(), pairs.end());
    long long int res = 0;
    long long int rem = k;
    for(int i = 0; i < pairs.size(); i++){
        long long int money = pairs[i].first;
        long long int days  = pairs[i].second;
        long long int temp = min(days, 1LL*rem/money);
        res += temp;
        rem-=(temp*money);
    }
    
    
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long long int k;
    cin >> k;
    long long int result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
