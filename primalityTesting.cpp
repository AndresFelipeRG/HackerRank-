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

void is_prime(int n){
    if(n <=1){
        cout << "Not prime"<<endl;
        return;
        
    }
    if( n<=3){
        cout << "Prime" << endl;
        return;
    }
    if(n%2 == 0 || n% 3 == 0){
        cout << "Not prime" << endl;
        return;
    }
    for(int i = 5; i*i <= n; i = i + 6){
        if(n% i == 0 || (n%(i+2) == 0)){
            cout << "Not prime" <<endl;
            return;
        }
    }
    cout << "Prime" << endl;
}
int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        is_prime(n);
    }
    return 0;
    
}
