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
long long merge(vector<int> & arr, vector<int> & temp,int left, int mid, int right){
    int i, j,k;
    i = left;
    k = left;
    j = mid;
    long long inversions = 0;
    
    while(i <= mid-1 && j <= right){
        if(arr.at(i) > arr.at(j)){
            temp[k++] = arr[j++];
            inversions = inversions + (mid-i);
        }
        else{
            temp[k++] = arr[i++];
        }
    }
    while(i<= mid-1){
        temp[k++] = arr[i++];
    }
    while(j<= right){
        temp[k++] = arr[j++];
    }
    for(int i = left; i <= right; i++){
        arr[i] = temp[i];
        
    }
    return inversions;
      
    
}
long long mergesort (vector<int> & arr, vector<int> & temp, int left, int right){
    long long inversions = 0;
    if(right > left){
    int middle = (left + right)/2;
    
    inversions = mergesort(arr, temp, left, middle);
    inversions += mergesort(arr, temp, middle +1, right);
    inversions += merge(arr,temp,  left, middle +1, right);
    }
    return inversions;
}

long long count_inversions(vector<int> a) {
    vector<int> temp(a.size());
    bool condition = true;
    for(int i = 0; i < a.size()-1; i++){
        if(a.at(i) > a.at(i+1)){
            condition = false;
            break;
        }
    }
    if(condition){return 0;}
    long long inversions = mergesort(a,temp, 0, a.size()-1 );
    return inversions;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
