# -*- coding: utf-8 -*-
"""
Created on Sun Nov  1 17:09:30 2020

@author: Bianca
"""
import numpy as np
import matplotlib.pyplot as plt
n = 15

def SubsDesc(A, b, tol):
	"""
	param A: matrice patratica, superior triunghiulara, cu toate elem pe diag principala nenule
	param b: vectorul term liberi
	param tol: val numerica ft mica in rap cu care vom compara numerele apropiate de 0
	return: sol sistem
	"""
	
	m, n = np.shape(A)
	if m != n:
		print("Matricea nu este patratica. Introduceti o alta matrice.")
		x = None
		return x
		
	#Verificam daca matricea este superior triunghiulara
	for i in range(m):
		for j in range(i):
			if abs(A[i][j]) > tol:
				print("Matricea nu este superior triunghiulara")
				x = None
				return x
	
	#Verificam daca elementele de pe diagonala principala sunt nule (sist comp det)
	for i in range(n):
		if A[i][i] == 0:
			print("Sistemul nu este compatibil determinat")
			x = None
			return x
	
	x = np.zeros((n,1))
	x[n-1] = 1 / A[n-1][n-1] * b[n-1]
	k = n-2
	while k >= 0:
		sum = 0
		for i in range(k+1, n):
			sum += A[k][i] * x[i]
		x[k] = 1 / A[k][k] * (b[k] - sum)
		k = k - 1
	return x

def GaussPivTot(A,b):
    a = np.zeros((n, n + 1))
    for i in range(n):
        for j in range(n + 1):
            if j == n:
                a[i][j] = b[i]
            else:
                a[i][j] = A[i][j]
    print(a)
    for k in range(0, n):
        max = 0
        for i in range(k, n):
            for j in range(k, n + 1):
                if abs(abs(a[i][j]) > max):
                    max = abs(a[i][j])
                    p = i
                    m1 = j
        if a[p][m1] == 0:
            print('Sistem incompatibil sau compatibil nedeterminat')
            return 0
        if p != k:
            a[[p, k]] = a[[k, p]]
        if m1 != k:
            a[:,[m1,k]] = a[:,[k,m1]]
            aux = m1
            m1 = k
            k = m1
        for l in range(k + 1, n):
            ml = a[l][k] / a[k][k]
            for j in range(n +1):
                a[l][j] = a[l][j] - m1 * a[k][j]
    if a[n - 1][n - 1] == 0:
        print('Sistem incompatibil sau compatibil nedeterminat')
        return 0
    for i in range(n):
        for j in range(n):  
            A[i][j] = a[i][j]
    for i in range(n):
        b[i] = a[i][n]
    y = SubsDesc(A, b, 10**(-15))
    return y
    
                    


A = np.zeros((15, 15))
c = -3
d = 9
f = -8


A[0][0] = d
A[0][1] = f

A[1][0] = c
A[1][1] = d
A[1][2] = f

for i in range(2,n):
    for j in range(n):
        A[i][j] = A[i - 1][j - 1]
        
b = np.zeros((n, 1))

for i in range(1,n-1):
    b[i] = 1
b[0] = 2
b[n-1] = 2

g = GaussPivTot(A,b)
print(g)