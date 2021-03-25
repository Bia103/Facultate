# -*- coding: utf-8 -*-
"""
Created on Sun Dec 20 16:29:30 2020

@author: Bianca
"""

# Exercitiul 1

import numpy as np
from sympy import *


n=6


def f(A, b, x):
    return 1/2 * np.dot(np.resize(A@x, n),np.resize(x, n)) - np.dot(np.resize(b, n),np.resize(x, n))

def grad(f):
    g = []
    for i in range(n):
        g.append(f.diff(Symbol('x'+str(i+1))))
    return g




def critSylv(A, e):

    n=A.shape[0]   
    det=np.zeros(n)
    for i in range(n):
        mat = A[:(i+1),:(i+1)]
        det[i] = np.linalg.det(mat)
    poz=True
    for i in range(n):
        if det[i]<=e:
            poz=False
    return poz




def GradConjugat(A,b,e):
    # x - x    
    # xi = xi
    #
    #
    x = np.random.randint(10, size=(n,1))

    xi = []
    for i in range(n):
        xi.append(Symbol('x' + str(i + 1)))
    fx = f(A,b,xi)
    g = grad(fx)
    lam = lambdify([tuple(xi)], g, "numpy")
    va = lam(x)

    v=[]
    for i in range(n):
        v.append(va[i][0])
    v=np.array(v)

    d = b - A@x

    it = 0
    ok = 1
    while ok == 1:

        alfa = -1 * np.dot(np.resize(v, n), np.resize(d, n)) / np.dot(np.resize(v, n), np.resize(A@v, n))
        x = x - np.resize(alfa * v,(n, 1))
        d = b - A@x
        beta = np.dot(np.resize(d, n), np.resize(A@v, n)) / np.dot(np.resize(v, n), np.resize(A@v, n))
        v = -1 * d + np.resize(beta*v,(n,1))
        array = lam(x)
        nm = 0
        for i in range(n):
            nm += array[i][0] ** 2
        nm = np.sqrt(nm)
        if nm < e or it == n:
            ok = 0
        it += 1
    return x



b = np.zeros((n, 1), float)
for i in range(n):
    b[i] = (i + 1)**4

e = 10 ** -7
A = np.zeros((n, n))



for i in range(n):
    A[0][i] = 4 ** (n-i)
    A[i][0] = A[0][i]

for i in range(1,n):
    for j in range(i,n):
        A[i][j] = A[i-1][j-1]
        A[j][i] = A[i][j]



poz = critSylv(A, e)
if poz:
    print("pozitiv definita")
else:
    print("pozititv definita")

x = GradConjugat(A, b, 10 ** -10)

