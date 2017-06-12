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

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    
    map<Node *,int> my;
    Node * iterator = head;
    
    if(head!= NULL){
        iterator->data = head->data;
    iterator->next = head->next;
    while(iterator->next!= NULL){
        if(my.find(iterator) != my.end()){
        my[iterator]++;
        }
        else{
             my[iterator] = 1;
        }
        
        int value = my[iterator];
       
        if(value >1){
            return true;
        }
        iterator = iterator->next;
    }
    }
    
    return false;
    // Complete this function
    // Do not write the main method
}

