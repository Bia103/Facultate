# -*- coding: utf-8 -*-
"""
Created on Fri Jan 29 12:57:52 2021

@author: Furculesteanu Bianca 341
"""
import numpy as np
import math
# Problema 1
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
           if abs(A[i][j] > tol):
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

def QR(A, b):
    
    Q = np.zeros((n, n))
    R = np.zeros((n, n))
    sum_pat = 0
    for i in range(n):
        sum_pat = sum_pat + A[i][0] * A[i][0]   # facem suna cu ajutorul careia vom determina R[0][0] - adica r[1][1]
    
    R[0][0] = math.sqrt(sum_pat)                # determinam elementul de pe pozitia 0 0
    '''
        Calculam prima colaoana a matricei Q si prima linie a matricei R
    '''
    for i in range(n):
        Q[i][0] = A[i][0] / R[0][0]
    
    for j in range(1,n):
        sum_r1 = 0;
        for s in range(n):
            sum_r1 = sum_r1 + Q[s][0] * A[s][j]
        R[0][j] = sum_r1
    '''
        Pentru k = 2 , n completeaza coloana k a matricei Q si linia k a matricei R
    '''
    for k in range(1,n):
        sum_a = 0
        sum_r2 = 0
        
        for i in range(n):
            sum_a = sum_a + A[i][k] * A[i][k]
        for s in range(k-1):
            sum_r2 = sum_r2 + R[s][k] * R[s][k]
        
        R[k][k] = math.sqrt(sum_a - sum_r2)
        
        for i in range(n):
            sum_qr = 0
            for s in range(k - 1):
                sum_qr = sum_qr + Q[i][s] * R[s][k]
            Q[i][k] = (1 / R[k][k]) * (A[i][k] - sum_qr)
        
        for j in range(k + 1 , n):
            sum_qa = 0
            for s in range(n):
                sum_qa = sum_qa + Q[s][k] * R[s][j]
    QT = Q.T #matricea Q transpusa
    res = QT @ b  # se determina Q * b
    tol = 10 ** (-16)
    x = metSubDesc(R, res, tol) # cu ajutorul metodei substitutiei descendente se afla solutia x
    return x, R, Q

n = 3

A = np.zeros((n, n))
b = np.zeros((n, 1), float)
for i in range(n):
    for j in range(n):
        if i != j :
            A[i][j] = 1
b[0] = 1
b[1] = 2
b[2] = 5
x , R , Q = QR(A, b)
print(x)
print(A@x)


# Problema 2
import numpy as np
import sympy as sym

def f(x):
    y = x**3 + 7*x**2 + 12*x 
    return y

"""
    Metoda Newton-Raphson
"""       
def NewtonRap(f, df, x0, eps):
    """
    Parameters
    ----------
    f : functia pt care cautam solutia f(x) = 0.
    df : derivata functiei.
    x0 : valoare de pornire.
    eps : epsilon / toleranta.

    Returns
    -------
    solutia (xk), nr de iteratii (N).
    """
    
    x_old = x0
    N = 1
    while True:
        #Calculăm noua iteratie
        x_new = x_old - (f(x_old) / df(x_old))
        N += 1
        if(abs(x_new - x_old) / abs(x_old) < eps):
            break
        x_old = x_new
    
    return x_new, N   


(a, b) = (-1, 5) # f (a) * f (b) < 0.
# Definim x0 = vector cu valoarea de pornire pt fiecare radacina 
# Aleg x0 a.î. f(x0) * f''(x0) > 0
# f(x0) < 0 --> la stanga (pt prima radacina)
x = sym.symbols('X')           # var simbolica
f_expr = f(x)                  # expresia simbolica
df_expr = sym.diff(f_expr, x)
df = sym.lambdify(x, df_expr)  # functie acum
x0 = np.array([0.3, 2.5, 4])
sols = np.zeros(x0.shape)
iteratii = np.zeros(sols.shape)
eps = 10 ** (-3)
for i in range(len(x0)):
    sols[i], iteratii[i] = NewtonRap(f, df, x0[i], eps)