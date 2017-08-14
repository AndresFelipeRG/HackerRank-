#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long make_change(vector<int> coins, int money, int maxi, vector<vector<vector<long long>>> * sol) {
    
    if(coins.size() == 0 ){return 0;}
    //cout << money <<","<<maxi<<endl;
    if((*sol)[maxi][money][1] == 1){return (*sol)[maxi][money][0];}
    if(money == 0){(*sol)[maxi][0][0] = 1; return 1;}
   
    long long ways = 0;
    int i = 0;
    while(i < coins.size() && coins[i] <= money && coins[i] <= maxi){
        
        
        
        ways = ways + make_change(coins, money-coins[i], coins[i], sol);
        
        
        i++;
    }
    
    (*sol)[maxi][money][0] = ways;
    (*sol)[maxi][money][1] = 1;
    
    return ways;
    
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    if(n != 0){
    sort(coins.begin(), coins.end());
    vector<long long> sec(2,-1);
    vector<vector<long long>> pair(n+1, sec);
    vector<vector<vector<long long>>> sol(n+1, pair);
    
    cout << make_change(coins, n,n, &sol) << endl;
   
    }
    else{
    cout << 0;
    }
    return 0;
}
