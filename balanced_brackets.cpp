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
char get_closing(char opening){
    char closing = ')';
    if(opening == '('){
        closing = ')';
    }
    if(opening == '['){
        closing = ']';
    }
    if(opening == '{'){
        closing =  '}';
    }
    return closing;
    
}
bool is_closing(char variable){
    if(variable == ')'){
        return true;
    }
    if(variable == ']'){
        return true;
    }
    if(variable == '}'){
       return true;
    }
    return false;
}
bool is_balanced(string expression) {
    if(expression.length() == 1){
        return false;
    }
    if(expression.at(0) == ')' || expression.at(0) == ']'  || expression.at(0) == '}'){
        return false;
    }
    int counter_left = 0;
    int counter_right = 0;
    int last_valid_position = 0;
    int i = 0;
    while(i < expression.length()){
        if(i == last_valid_position){
            if(is_closing(expression.at(i))){
                last_valid_position = last_valid_position + 1;
                counter_left = 0;
                counter_right = 0;
               
                i++;
                continue;
            }
          
            counter_left++;
            i++;
            continue;
        }
        if(i > last_valid_position && is_closing(expression.at(i))){
            counter_right++;
            if(counter_right == counter_left){
            if(get_closing(expression.at(last_valid_position))!= expression.at(i)){
               // cout <<expression.at(last_valid_position);
               // cout << get_closing(expression.at(last_valid_position));
               //  cout << expression.at(i);
               
                return false;
            }
            if(get_closing(expression.at(last_valid_position)) == expression.at(i)){
                //cout<<i;
                //cout << last_valid_position;
               // cout <<get_closing(expression.at(last_valid_position));
               //  cout << i;
              // cout <<expression.at(i);
              //  cout << last_valid_position;
              //  cout <<"found";
                i = last_valid_position + 1;
                last_valid_position = last_valid_position +1;
                
                counter_left = 0;
                counter_right = 0;
              
                continue;
            }
            return false;
            }
           
            i++;
            continue;
        }
        
        if(i > last_valid_position && !is_closing(expression.at(i))){
          
            counter_left++;
           
            i++;
            continue;
        }
    }
    if(counter_left> 0 || counter_right > 0){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
//{}{([{{{{}})]{)]()[[}(}{
//{(){{}}}{}{{({})}}{({(){}})}
