#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            stack_newest_on_top.push(x);
            
        }

        void pop() {
            if( stack_newest_on_top.size() >=1 || stack_oldest_on_top.size() >=1 ){
               
                
                if(stack_oldest_on_top.size() == 0){///update
                while(stack_newest_on_top.size() >= 1 ){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
                    if(stack_oldest_on_top.size()>0){
                    stack_oldest_on_top.pop();
                    }
                }
                else{
                    stack_oldest_on_top.pop();
                }
                 
                
            }
        }

        int front() {
            int num = 0;
            if(stack_oldest_on_top.size()>0){
            int num = stack_oldest_on_top.top();
           // cout << stack_oldest_on_top.size();
            return num;
            }
            if(stack_oldest_on_top.size() == 0 && stack_newest_on_top.size() >0){
                 while(stack_newest_on_top.size() >= 1 ){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
                return stack_oldest_on_top.top();
            }
            
            return num;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
//33
//33
//33
