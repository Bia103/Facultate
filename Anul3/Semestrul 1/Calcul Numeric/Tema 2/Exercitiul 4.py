# -*- coding: utf-8 -*-
"""
Created on Fri Nov 20 17:39:24 2020

@author: Bianca
"""
import numpy as np
import math

def metSubDesc(A, b, tol):
    """

    Parameters
    ----------
    A : matrice pătratică, superior triunghiulară, cu toate elementele de pe diagonala principală nenule.
    b : vectorul termenilor liberi.
    tol : toleranță = valoare numerică foarte mică în raport cu care vom compara numerele apropiate de 0.

    Returns
    -------
    x = Soluția Sistemului.

    """
    
    # Verificăm dacă matricea este pătratică
    m, n = np.shape(A)
    if m!= n:
        print("Matricea nu este pătratică. Introduceți altă matrice.")
        x = None
        return x
    
    # Verificăm dacă matricea este superior triunghiulară
    for i in range(m):
       for j in range(i):
           if abs(A[i][j]) > tol:
               print("Matricea nu este superior triunghiulară.")
               x = None
               return x
    
    # Verificam dacă toate elementele de pe diagonala principală sunt nenule => Si. este compatibil ddeterminat (adică am soluție unică)
    for i in range(n):
        if A[i][i] == 0:
            print("Sistemul nu este compatibil determinat.")
            x = None
            return x
    
    x = np.zeros((n, 1))
    x[n - 1] = b[n - 1] / A[n - 1][n - 1]
    
    k = n - 2
    while k >= 0:
        s = 0
        for j in range(k + 1, n):
            s += x[j] * A[k][j]
            
        x[k] = (1 / A[k][k]) * (b[k] - s)
        k -= 1
    
    return x



def metSubAsc(A, b, tol):
    """

    Parameters
    ----------
    A : matrice inferior triunghiulară.
    b : vectorul termenilor liberi.
    tol : toleranța.

    Returns
    -------
    soluția.

    """
    
    # Verificăm dacă matricea este pătratică
    m, n = np.shape(A)
    if m!= n:
        print("Matricea nu este pătratică. Introduceți altă matrice.")
        x = None
        return x
    
    # Verificăm dacă matricea este superior triunghiulară
    for i in range(m):
       for j in range(i):
           if abs(A[j][i]) > tol:
               print("Matricea nu este inferior triunghiulară.")
               x = None
               return x
    
    # Verificam dacă toate elementele de pe diagonala principală sunt nenule => Si. este compatibil ddeterminat (adică am soluție unică)
    for i in range(n):
        if abs(A[i][i]) <= tol:
            print("Sistemul nu este compatibil determinat.")
            x = None
            return x
    
    x = np.zeros((m, 1))
    x[0] = b[0] / A[0][0]
    
    for k in range(1, n):
        
        sum = 0
        for j in range(k):
            sum += A[k][j] * x[j]
        
        x[k] = (1 / A[k][k]) * (b[k] - sum)
    
    return x



def Cholesky(A, b):
    if A[0][0] <= 0:
        print("A nu este pozitiv definita")
        return 0
    
    L = np.zeros((n,n))
    L[0][0] = math.sqrt(A[0][0])
    
    for i in range(1,n):
        L[i][0] = A[i][0] / L[0][0]
    print(L)
    for k in range(1,n):
        su = 0
        
        for s in range (k):
            su = su + L[k][s] * L[k][s]
            
        al = A[k][k] - su
        
        if al <=0:
            print("A nu este pozitiv definita")
            return 0            
        
        L[k][k] = math.sqrt(al)
        
        for i in range(k + 1, n):
            su = 0
            for s in range(k):
                su = su + L[i][s] * L[k][s]
            L[i][k] = (1 / L[k][k]) * su
        
    return L
                

def minor_element(A,i):
    sub_A = A
    for j in range(n,i,-1):
        sub_A = np.delete(sub_A,j-1,0)     
        sub_A = np.delete(sub_A,j-1,1) 
    print(sub_A)
    M_ij = np.linalg.det(sub_A)
    return M_ij

n = 6
b = np.zeros((n, 1))
A = np.zeros((n,n))
a = 4
# 1
for i in range(n):
    b[i] = i ** 4

for i in range(n):
    A[0][i] = a ** (n-i)
    A[i][0] = A[0][i]

for i in range(1,n):
    for j in range(i,n):
        A[i][j] = A[i-1][j-1]
        A[j][i] = A[i][j]
print(A)
print(b)
# 2
ok = 1
if A[0][0] !=0 :

    for i in range(1,n):
        if minor_element(A,i):
            continue
        else:
            ok = 0
            break
else:
    ok = 0

if ok == 0:
    print("Nu indeplineste criteriul lui Sylvester")
else:
    print("Indeplineste criteriul lui Sylvester")

L = Cholesky(A,b)

y = metSubAsc(L, b, 10 ** -16);

x = metSubDesc(L.transpose(), y, 10 ** -16);

print(x)

print(L)
