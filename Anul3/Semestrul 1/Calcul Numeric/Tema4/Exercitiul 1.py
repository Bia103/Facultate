# -*- coding: utf-8 -*-
"""
Created on Wed Jan 20 14:07:23 2021

@author: Bianca
"""
from sympy import *

n = 3
x = []
a = Symbol('a')
b = Symbol('b')
t = Symbol('t')
f = Function('f')
h = (b - a) /n
x.append(a)
for i in range(1,n):
    x.append(a + h * i )
x.append(b)

w = []
for k in range(0,n + 1):
    p = 1
    for i in range(0,n + 1):
        if i != k :
            p = p * ((t - i - 1)/(k - i))
    w.append(h * integrate(p, (t, 1, n + 1)) )


l = 0
for i in range(0,n + 1):
    l = l + w[i] * f(x[i])
print(l)         

# cuadratura sumate
    
I = 0
for i in range(n):
    c = l.subs(a,x[i])
    I += c.subs(b,x[i+1])

print(I)
    

