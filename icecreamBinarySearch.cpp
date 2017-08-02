#include <bits/stdc++.h>
using namespace std;

class IceCream {
    
    public: 
        int flavor; 
        int index;

        IceCream (int flavor2, int index2) {
            flavor = flavor2;
            index = index2;
       }
};
bool compare(IceCream a, IceCream b){return a.flavor < b.flavor;}
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
   int left = first;
   int right = last;
   int middle = (left+right)/2;
   if(left <= right){
       int flavor = arr[middle].flavor;
       int index = arr[middle].index;
       if(flavor == search){
           return index;
       }
       if(search > flavor){
           return binarySearch(middle+1, right, arr, search);
       }
       if(search < flavor){
           return binarySearch(left, middle-1, arr, search);
       }
       
   }
   return -1;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }

    }

}
