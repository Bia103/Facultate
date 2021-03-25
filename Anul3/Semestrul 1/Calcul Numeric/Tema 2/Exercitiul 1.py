# -*- coding: utf-8 -*-
"""
Created on Fri Nov 20 15:11:39 2020

@author: Bianca
"""
import numpy as np

def LR(A):
    L = np.zeros((n,n))
    R = np.zeros((n,n))
    
    for i in range(n):
        L[i][i] = 1
    
    R[0][0] = A[0][0]
    
    for i in range(0, n-1):
        L[i + 1][i] = A[i + 1][i] / R[i][i]
        R[i][i + 1] = A[i][i + 1]
        R[i + 1][i + 1] = A[i+1][i+1] - L[i + 1][i] * R[i][i + 1]
    return L,R

def detY(L,b):
    y = np.zeros((n,1))
    y[0][0] = b[0][0]
    for i in range(1,n):
        y[i][0] = b[i][0] - L[i][i - 1] * y[i - 1][0]
    return y

def detX(R,b):
    x = np.zeros((n,1))
    x[n-1][0] = y[n - 1][0] / R[n - 1][n - 1]
    
    for i in range(n - 2, -1, -1):
        x[i][0] = (y[i][0] - R[i][i + 1] * x[i + 1][0] ) / R[i][i]
    return x

c = -3
d = 9
f = -8

n = 15

A = np.zeros((n,n))

A[0][0] = d
A[0][1] = f

A[1][0] = c
A[1][1] = d
A[1][2] = f

for i in range(2,n):
    for j in range(n):
        A[i][j] = A[i - 1][j - 1]

b = np.zeros((n, 1))

for i in range(1, n - 1):
    b[i] = 1
b[0] = 2
b[n - 1] = 2


L,R = LR(A)
print(L@R)
y = detY(L,b)
print(L@y)
print(y)
x = detX(R,b)
print(R@x)