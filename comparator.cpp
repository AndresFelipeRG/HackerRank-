#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

struct Player {
    string name;
    int score;
}; 

vector <Player> quickSortScore(vector<Player> players){
    if(players.size() <= 1){
        return players;    
    }
    vector<Player> left;
    vector <Player> right;
    vector<Player> middle;
    int pivot_score = players.at(0).score;
    for(vector<Player>::iterator it = players.begin(); it != players.end(); it++){
        if(it->score > pivot_score){
            right.push_back(*it);
            continue;
            
        }
        if(it->score < pivot_score){
            left.push_back(*it);
            continue;
        }
        else{
            middle.push_back(*it);
            continue;
        }
    }
    left = quickSortScore(left);
    right = quickSortScore(right);
    right.insert(right.end(),middle.begin(),middle.end());
    right.insert(right.end(),left.begin(),left.end());
    return right;
    
}
vector<Player> quickSortString(vector<Player> players){
    if(players.size()<= 1){
        return players;
    }
    vector<Player> left;
    vector<Player> right;
    vector<Player> middle;
    string pivot = players.at(0).name;
    for(vector<Player>::iterator it = players.begin(); it != players.end(); it++){
        if(it->name.compare(pivot)> 0){
            right.push_back(*it);
            continue;
        }
        if(it->name.compare(pivot) < 0){
            left.push_back(*it);
            continue;
        }
        else{
            
            middle.push_back(*it);
            continue;
        }
        
    }
    left = quickSortString(left);
    right = quickSortString(right);
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
    
      
}
vector<Player> comparator(vector<Player> players) {
      if(players.size()== 1){
          return players;
      }
      vector<tuple<string, int>> players2;
      
      players = quickSortScore(players);
      vector<Player>::iterator it = players.begin();
      vector<Player> output;
      vector<Player> interm;
      bool new_sequence = true;
      int current_score = players.at(0).score;
      while(it != players.end()){
          if(it->score == current_score){
              interm.push_back(*it);
              it++;
              continue;
          }
          else{
              current_score = it->score;
              interm = quickSortString(interm);
              output.insert(output.end(), interm.begin(), interm.end());
              
              interm.clear();
              interm.push_back(*it);
              it++;
              continue;
          }
      }
      interm = quickSortString(interm);
      output.insert(output.end(), interm.begin(), interm.end());
      
      return output;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
