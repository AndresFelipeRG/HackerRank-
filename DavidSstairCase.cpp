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

long long num_ways(long long n, long long * arr){
    if(arr[n]!= -1){
        return arr[n];
    }
    if(n == 0){
        arr[0] = 1;
        return 1;}
    if(n == 1){
        arr[1] = 1;
        return 1;
    }
    if(n == 2){
        arr[2] = num_ways(n-1, arr) + num_ways(n-2, arr);
        return arr[2];
    }
    arr[n-1] = num_ways(n-1, arr);
    arr[n-2] = num_ways(n-2, arr) ;
    arr[n-3] = num_ways(n-3, arr);
    arr[n] = arr[n-1] + arr[n-2] + arr[n-3];
    return arr[n];
}
int main(){
    int s;
    cin >> s;
    long long arr[37];
    for(int i = 0; i < 37; i++){
        arr[i] = -1;
    }
    for(int a0 = 0; a0 < s; a0++){
        long long n;
        cin >> n;
        cout<< num_ways(n, arr)<<endl;
    }
    
    return 0;
}
