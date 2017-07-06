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
#include <bits/stdc++.h>

using namespace std;
struct node {
    int word;
    struct node * child[26];
    int count;
};
//create a function to initialize values of node. One can't node declare and initialize a struct at the same time.

struct node *newnode()
{
    struct node *newnode = new struct node;
    newnode->word = 0;
    newnode->count = 0;
    for(int i = 0; i < 26; i++)
    {
        newnode->child[i] = NULL;
    }
    return newnode;
}
struct node * root = NULL;
void addWord(struct node * root, string s)
{
    int i;
    int ch;
    struct node *temp = root;
    for(int i = 0; i <s.size() ; i++)
    {
        ch = s[i]-'a';
        if(temp->child[ch] == NULL){
            temp->child[ch] = newnode();
            
        }
        temp->count = temp->count + 1;
        temp = temp->child[ch];
    }
    temp->count = temp->count + 1;
    temp->word = 1;
}
int findword(struct node * root, string s)
{
    int i;
    int ch;
    struct node * temp = root;
    for(i = 0; i < s.size() ; i++)
    {
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL)
        {
            return 0;
        }
        temp = temp->child[ch];
       
            
    }
   
    return temp->count;
    
    
}
int main(){
    int n;
    root = newnode();
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add"){
            
            addWord(root, contact);
        }
        if(op == "find"){
            cout << findword(root,contact) <<endl;
        }
    }
    return 0;
}
