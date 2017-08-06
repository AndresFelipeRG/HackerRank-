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
#define pb push_back
using namespace std;
stack<vector<int>> neighbors(int i, int j, int n, int m, vector<vector<int>> grid){ 
       stack<vector<int>> nbrs;
       if(i-1>= 0 && j-1 >= 0){
           if(grid[i-1][j-1] == 1){
           vector<int> pair;
           pair.pb(i-1);
           pair.pb(j-1);
           nbrs.push(pair);
           }
       }
      if(i-1>= 0){
          if(grid[i-1][j] == 1){
           vector<int> pair;
           pair.pb(i-1);
           pair.pb(j);
           nbrs.push(pair);}
       }
     if(i-1>= 0 && j+1 <= m-1){
           if(grid[i-1][j+1] == 1){
           vector<int> pair;
           pair.pb(i-1);
           pair.pb(j+1);
           nbrs.push(pair);
           }
       }
    if(i>= 0 && j-1 >=0){
           if(grid[i][j-1] == 1){
           vector<int> pair;
           pair.pb(i);
           pair.pb(j-1);
           nbrs.push(pair);}
       }
     if(i>= 0 && j+1 <=m-1){
           if(grid[i][j+1] == 1){
           vector<int> pair;
           pair.pb(i);
           pair.pb(j+1);
           nbrs.push(pair);}
       }
     if(i+1 <=n-1 && j-1 >=0){
           if(grid[i+1][j-1] == 1){
           vector<int> pair;
           pair.pb(i+1);
           pair.pb(j-1);
           nbrs.push(pair);
           }
       }
     if(i +1 <= n-1 && j>=0){
           if(grid[i+1][j] == 1){
           vector<int> pair;
           pair.pb(i+1);
           pair.pb(j);
           nbrs.push(pair);}
       }
     if(i +1 <= n-1 && j+1 <=m-1){
           if(grid[i+1][j+1] == 1){
           vector<int> pair;
           pair.pb(i+1);
           pair.pb(j+1);
           nbrs.push(pair);
           }
       }
    return nbrs;
}
int get_biggest_region(vector< vector<int> > grid, int n, int m, stack<vector<int>> ones) {
    vector<vector<int>> visited(n, vector<int>(m));
    stack<vector<int>> unvisited = ones;
    vector<int> sizes;
    
    while(unvisited.size() > 0){
        vector<int> v = unvisited.top();
        unvisited.pop();
        if(visited[v[0]][v[1]] == 1){
            continue;
        }
        visited[v[0]][v[1]] = 1;
        stack<vector<int>> ns = neighbors(v[0], v[1], n, m, grid);//fix this
        
        vector<int> cur;
        if(ns.size()>0){cur = ns.top();//fix this
        ns.pop();}
        int count = 1;
        while(ns.size() > 0 && cur.size()> 0){
            if(visited[cur[0]][cur[1]] == 0){
                count = count +1;
                stack<vector<int>> k = neighbors(cur[0], cur[1], n, m, grid);
                while(k.size() > 0){
                    ns.push(k.top());
                    k.pop();
                }
                visited[cur[0]][cur[1]] = 1;
            }
           
            cur = ns.top();
            ns.pop();
            
            
        }
        sizes.pb(count);
       
    }
    sort(sizes.begin(), sizes.end());
    if(sizes.size() == 0){return 0;}
    return sizes[sizes.size()-1];
}
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    stack<vector<int>> ones;
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
          if(grid[grid_i][grid_j] == 1){
              vector<int> pair;
              pair.pb(grid_i);
              pair.pb(grid_j);
              ones.push(pair);
          }
          
       }
    }
    cout << get_biggest_region(grid,n,m, ones) << endl;
    return 0;
}

