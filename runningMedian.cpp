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

#define MAX_HEAP_SIZE 100000
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
using namespace std;
 

 
//// Utility functions
 
// This function exchanges a and b.
inline void exch(int &a, int &b)
{
    int temp =a ;
    a = b;
    b = temp;
}
 
// Greater and Smaller are used as comparators
//can't be named greater because when getting the address of the function-&greater, it referes to a reserved function greater.
bool Greater(int a , int b){
    return a>b;
}
 
bool Smaller(int a, int b){
    return a < b;
}
float average(int a, int b){
    return float(a+b)/2.0;
}
 
// Signum function
// = 0  if a == b  - heaps are balanced
// = -1 if a < b   - left contains less elements than right
// = 1  if a > b   - left contains more elements than right
inline int signum(int a , int b){
    if (a == b)
        return 0;
    return a < b ? -1 : 1;
}

class Heap
{
public:
    // Initializes heap array and comparator required
    // in heapification
    Heap(int * b, bool (*c)(int, int)): A(b), comp(c)
    {
        heapSize = -1;
    }
    virtual ~Heap()
    {
        if(A)
        {
            delete[]A;
        }
    }
 
    //
    virtual bool insert(int e) = 0;
    virtual int gettop() = 0;
    virtual int extracttop() = 0;
    virtual int getcount() = 0;
 
protected:
    int left(int i )
    {
        return 2*i + 1;
    }
    
    int right(int i){
        return 2*(i+1);
    }
    int parent(int i){
        
        if( i <= 0){
            return -1;
        }
        return (i-1)/2;
    }
    //array of heap
    
    int * A;
    //comparator
    bool (*comp)(int, int);
    
    //heapSize
    
    int heapSize;
    //return the top element of the heap
    int top(){
        int max = -1;
        if(heapSize>=0){
            max = A[0];
        }
        return max;
    }
   
    //Returns the number of elements in the heap
    int count(){
        return heapSize +1;
    }
    void heapify(int i)
    {
        int p = parent(i);
        if(p >= 0 && comp(A[i], A[p])){
            exch(A[i], A[p]);
            heapify(p);
        }
    }
    void heapifydown(int i){
        int index = i;
        
        int lchild = left(index);
        if(lchild < count()){
            int minimum = lchild;
            int rchild = right(index);
            if(rchild < count()){
                if(comp(A[rchild],A[lchild])){
                    minimum = rchild;
                }
            }
            if(comp( A[minimum], A[index])){
                exch(A[index], A[minimum]);
            }
            heapifydown(minimum);
               }
     }
    // Deletes root of heap
    int deleteTop(){
        int del = -1;
        if(heapSize > -1){
            del = A[0];
            exch(A[0], A[heapSize]);
            heapSize--;
            heapifydown(0);
        }
        return del;
    }
    bool insertHelper(int key){
        bool ret = false;
        if(heapSize < MAX_HEAP_SIZE){
            ret = true;
            heapSize++;
            A[heapSize] = key;
            heapify(heapSize);
        }
        return ret;
    }
 
   
};
class MaxHeap: public Heap
{
private:
 
public:
    MaxHeap(): Heap(new int[MAX_HEAP_SIZE], &Greater){}
    ~MaxHeap(){}
    
    
 
    // Wrapper to return root of Max Heap
    int gettop()
    {
        return top();
    }
    
    // Wrapper to delete and return root of Max Heap
    int extracttop()
    {
        return deleteTop();
    }  
    
    // Wrapper to return # elements of Max Heap
    int getcount()
    {
        return count();
    }
 
    // Wrapper to insert into Max Heap
    bool insert(int key)
    {
        return insertHelper(key);
    }
   
};
class MinHeap: public Heap
{
private:
 
public:
     
     MinHeap(): Heap(new int[MAX_HEAP_SIZE], &Smaller){}
     
    ~MinHeap(){}
 
 
    // Wrapper to return root of Min Heap
    int gettop()
    {
        return top();
    }
    
    // Wrapper to delete and return root of Min Heap
    int extracttop(){
        return deleteTop();
    }
    // Wrapper to return # elements of Min Heap
    int getcount(){
        return count();
    }
    // Wrapper to insert into Min Heap
    bool insert(int key)
    {
        return insertHelper(key);
    }
    
};

float getMedian(int e, float &m, Heap &l, Heap &r){
    int sig = signum(l.getcount(), r.getcount());//verify if the heaps are balanced.
    switch(sig)
    {
        case 1: //The heap in the left has more elements than the heap in the right.
            if(e < m){
                r.insert(l.extracttop()); //we remove the top element from the left and move it to the right
                l.insert(e); // insert element to the left
            }
            else
            {
                r.insert(e);   //the element can be inserted into the right heap since it has few elements and it's greater than the median.
            }
            m = average(l.gettop(), r.gettop()); //both heaps contain the same number of elements now, so we take the average.
            break;
       case 0: //both heaps contain the same number of elements.
            if(e < m)
            {
                l.insert(e); //insert new elements and he leaft heap contains 1 more elements than the right heap
                m = l.gettop();//the median now becomes the top of the left heap since it contains 1 more elements than the right heap, and its top elements is the greater among the elements in the left heap. 
            }
            else
            {
                r.insert(e);
                m = r.gettop();
            }
            break;
        case -1: //the right heap contains more elements than the left heap
            if(e<m){
                l.insert(e); //insert into the left heap since it has less elements
            }
            else
            {
                l.insert(r.extracttop()); // move the top element to the left heap since it contains 1 more element than the left heap.
                r.insert(e); //insert elements into the right heap, both heaps now constain the same number of elements
            }
            m = average(l.gettop(), r.gettop());
            break;
    }
    return m;
}

    
   
 
int main(){
    Heap * right = new MinHeap();
    Heap * left = new MaxHeap();
    float median = -1.0;
    int sizev =0;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    sizev = a.size();
    for(int b = 0; b < sizev; b++){
        median = getMedian(a[b], median, *left, *right);
        printf("%.1lf\n",median);
    }
    delete left;//deallocate memory
    delete right;//deallocate memory
    return 0;
}
