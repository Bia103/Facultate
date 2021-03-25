# -*- coding: utf-8 -*-
"""
Created on Wed Jan 20 16:28:49 2021

@author: Bianca
"""
from sympy import *
import numpy as np
import matplotlib.pyplot as plt

def metSubsDesc(A, b, tol):
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

def gaussPp(A, b, tol):
	"""
	param A: matricea asoc sistemului, patratica
	param b: vectorul term liberi
	param tol: val cu care comparam nr nenule
	return x: solutia sistemului
	"""
	
	m, n = np.shape(A)
	if m != n:
		print("Matricea nu este patratica. Introduceti o alta matrice.")
		x = None
		return x
		
	A_extins = np.concatenate((A, b), axis=1) #axis=0 l-ar pune pe b o noua linie, 1 il pune drept coloana
	for k in range(n-1):
		max = A_extins[k][k]
		p = k
		for j in range(k+1, n):
			if abs(A_extins[j][k]) > abs(max):
				max = A_extins[j][k]
				p = j
			
		if abs(max) <= tol:
			print("Sistemul nu admite solutie unica")
			x = None
			return x
			
		if (p != k):
			A_extins[[p, k]] = A_extins[[k, p]] #swap linia p cu linia k
			
		for j in range(k+1, n):
			A_extins[j] = A_extins[j] - (A_extins[j][k] / A_extins[k][k]) * A_extins[k]
		
	if abs(A_extins[n-1][n-1]) <= tol:
		print("Sistemul nu admite solutie unica")
		x = None
		return x
		
	x = metSubsDesc(A_extins[:, 0:n], A_extins[:, n], tol)
	return x


x = []

n = 20

for i in range (1,20):
    x.append(i)


y= 20*np.random.rand(1,20)

y.sort()

y1 = []
msg = 'sistem liniar'
# sistem liniar
if msg = 'sistem liniar':
    A = np.zeros((2, 2))
    w = np.zeros((2, 1), float)

    for i in range(19):
        A[0][0] = A[0][0] + x[i] * x[i]
        A[0][1] = A[0][1] + x[i]
        w[0][0] = x[i] * y[0][i] + w[0][0]
        w[1][0] = y[0][i] + w[1][0]
    
    
    A[1][0] = A[0][1]
    A[1][1] = n
    tol = 10 ** -16

    sol = gaussPp(A, w, tol)
    print(sol)
    
    a = sol[0]
    b = sol[1]
    
    o1 = a * x[0] + b
    o2 = a * x[n-2] + b
    
    for i in range (1,20):
        y1.append(y[0][i])
    
    plt.plot(x,y1,'o', color = 'red',markersize = 10)
    plt.plot([x[0],x[n-2]],[o1,o2],'-', color = 'blue')
    plt.show()
else:
    A = np.zeros((3, 3))
    w = np.zeros((3, 1), float)

    for i in range(19):
        A[0][0] = A[0][0] + x[i] ** 4
        A[0][1] = A[0][1] + x[i] ** 3
        A[0][2] = A[0][2] + x[i] ** 2
        A[1][0] = A[0][1]
        A[1][1] = A[0][2]
        A[1][2] = A[1][2] + a[i]
        A[2][0] = A[1][1]
        A[2][1] = A[1][2]
        w[0][0] = x[i] * x[i] * y[0][i] + w[0][0]
        w[0][0] = x[i] * y[0][i] + w[0][0]
        w[2][0] = y[0][i] + w[1][0]
    
    

    A[2][2] = n
    tol = 10 ** -16

    sol = gaussPp(A, w, tol)
    print(sol)
    
    a = sol[0]
    b = sol[1]
    c = sol[3]
    
    o1 = a * x[0] + b
    o2 = a * x[n-2] + b
    
    for i in range (1,20):
        y1.append(y[0][i])
    
    plt.plot(x,y1,'o', color = 'red',markersize = 10)
    plt.plot([x[0],x[n-2]],[o1,o2],'-', color = 'blue')
    plt.show()
    

    