# HackerRank-
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
