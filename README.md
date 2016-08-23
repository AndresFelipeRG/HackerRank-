# HackerRank-Reference-Tips-Solutions
SimpleOne: use exponentiation by squaring and modular exponentiation.
https://en.wikipedia.org/wiki/Modular_exponentiation.

#Div mod:

(a + b) %n = (a%n + b %n) %n


(a*b)%n = (a%n * b %n)%n

#Next Square

n^2 = (n-1)^2 + (n-1) + n


#PRIME FACTORIZATION

For every unique  prime factor there are (a+1)(b+1)... possible factors. For a square number x^2: every factor less than x, there is a factor greater than x. Thus, there are (a+1)(b+1).../2 factors less than x - including 1.



#Samantha and portfolio management

Cauchy–Bunyakovsky–Schwarz inequality:
sum(x(i)y(i)^2 <= sum(x(i)^2)sum(y(i)^2)
x(i) = w(i)/sqrt(i) ; y(i) = sqrt(i)

variance = sum(w(i)^2/i)
sum(w(i)) = 1
1/sum(i)) <= sum(w(i)^2/i) 
Therefore variance min is when 1/sum(i)
Use lagrange multipliers.
let:
f(w_1,σ_i,⋯,w_n,σ_n)=∑w_i^2*σ^2
g(w_1,⋯,w_n) = 1 - ∑w_i 
let:
F = f + k*g
then on differentiating F w.r.t w_i we get
dF/dw_i = 2*σ_i^2*w_i - k = 0
(condition for minima , first order derivative should be zero)
solving this we get
w_i = k/2*σ_i^2
now ∑w_i = 1 --- (2)
substituting value of w_i in (2) we get k = 1 / (n*(n+1))


Any pair of integers, not both zero, can be reduced to a pair of coprime ones by dividing them by their GCD:

gcd{a,b}=d⟺ad,bd∈ℤ∧gcd{ad,bd}=1


#Matrix inversions

The naive solution is counting the number of elements greater than each element  in it's prefix submatrix . The complexity of this solution is  which does not pass the problem's constraints. 

The optimal solution is : Sort the elements of the matrix and store them in an array. Now , iterate over the elements in descending order. Assume the current element is at position . 

Now the number of inversions will be equal to the number of elements processed till now in the submatrix  because the elements marked in this submatrix are greater than the current element . This can be counted using a 2-D binary indexed tree in  . 

Thus the total complexity of the solution is : O(n^2log(n))

#Pair selection

The given problem can be modelled as a bipartite graph with N vertices on the left side and M vertices on the right side and there is and edge between vertex i on left and vertex j on right if . 
Now,choosing the K pairs can be thought of as choosing a matching in the bipartite graph having K edges such that for every edge connecting , one of the  or  is good, where the definition of good is given in the problem statement. 
Now we need to find a matching having largest number of edges satisfying the above properties.
Claim : The maximum matching in a bipartite graph would always satify the above properties. ** 
**Proof : Let us consider any maximum matching of the bipartite graph. If every pair  is good, then we are done. Suppose there exists a pair  in the matching such that both the  and  are not good. This means there exists a neighbour  of  which is not in the matching and there exists a neighbour  of  which is not in the matching. Hence, we can remove the edge  from the set of selected edges in the matching and add the edges  and  , and hence increase the size of the maximum matching by 1. This leads us to a contradiction. Hence, in a maximum matching no such pair would exist.
Now, we know that every maximum matching of the graph meets the conditions. Since any other matching that satisfies the conditions would have a size less equal the size of the maximum matching, hence the size of the maximum matching is the required answer.

#Guga travelling
Introduction
If you look at the problem constraints you will notice that while the graph can contain 2000 normal edges it can only contain 10 special edges.

I therefore approaced this by reducing the graph using the normal Dijkstra's algorithm and then augmenting Dijkstra's algorithm with bitmasks on the reduced graph to find the solution.

#Minimum tranformation cost
As we need to transform a given  to  so that  and  can be anagrams. Thus we can calculate the transformation cost by the analysis of frequency of each letters in both the strings.

Lets define the following two variables:
V1: Sum of all the frequencies of characters that are present in  but not required in .
V2: Sum of all the frequencies of characters that are required in  but not present in .

Now the Transformation Cost function can be defined as: V1(A) + V2(B) +Z(C-A-B). A = delete, B = insert.

A, B, C are the operations costs as defined in the problem. Z is the total no. of Replace Operations performed.
#Minimum connected component

Using DSU, after each operation we can have connected components.
Let's have a multiset of weights of connected components. Initially, it is weight of each node. When two connected component is mergered, both weights will be deleted form multiset and sum of them will be inserted. For example, if weights are  and , C++ code will be like:
mymultiset.erase(mymultiset.find(X));
mymultiset.erase(mymultiset.find(Y));
mymultiset.insert(X+Y);
after each operation you have to print minimum element in this multiset. (it's possible to use any binary tree instead multset).
