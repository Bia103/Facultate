import numpy as np

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
	
	
def gaussFp(A, b, tol):
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
		p = None
		for j in range(k, n):
			if abs(A[j][k]) > tol:
				p = j
				break
		
		if (p == None):
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
				
	