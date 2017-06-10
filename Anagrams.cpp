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

int number_needed(string a, string b) {
   vector<int> s_a(27);
   vector<int> s_b(27);
   for(int i = 0; i < a.length(); i++){
       s_a.at(int(a.at(i)-'a')) = s_a.at(int(a.at(i)-'a')) + 1;
   }
   for(int i = 0; i < b.length(); i++){
       s_b.at(int(b.at(i)-'a')) = s_b.at(int(b.at(i)-'a')) + 1;
       
   }
   int deletions = 0;
   int count_a = 0;
   int count_b = 0;
   for(int i = 0; i < 27; i++){
       count_a = s_a.at(i);
       count_b = s_b.at(i);
       deletions = deletions + abs(count_a-count_b);
   }
   return deletions;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
