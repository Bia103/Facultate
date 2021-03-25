import metodeNumericePentruEcuatiiLiniare as sel
import numpy as np

A = np.array([[1,2,3], [4,5,6]])
b = np.array([[1], [4], [5]])
tol = 10 ** -16

x = sel.metSubsDesc(A, b, tol)
print(x)

A = np.array([[1,2,3], [4,5,6], [3,9,8]])
x = sel.metSubsDesc(A, b, tol)
print(x)

A = np.array([[1,2,3], [0,0,6], [0,0,8]])
x = sel.metSubsDesc(A, b, tol)
print(x)

A = np.array([[1,2,3], [0,5,6], [0,0,8]])
x = sel.metSubsDesc(A, b, tol)
print(x)

#Verificare:
print(A@x)
print(np.dot(A, x))
print(b)

# Ex 3, b

A = np.array([[0,1,1], [2,1,5], [4,2,1]])
b = np.array([[3], [5], [1]])

x = sel.gaussPp(A, b, tol)
print(x)

print(A@x-b)

#if A@x - b == np.array([[0], [0], [0]]):
#	print("Solutie calculata corect")
	
A = np.array([[0,1,-2], [1,-1,1], [1,0,-1]])
b = np.array([[4], [6], [2]])

x = sel.gaussPp(A, b, tol)
print(x)
print(np.linalg.det(A))

#Ex 3, c

eps = 10 ** -20
tol1 = 10 ** -30
tol2 = 10 ** -16

A = np.array([[eps, 1], [1,1]])
b = np.array([[1], [2]])

x = sel.gaussFp(A, b, tol1)
print(x)

x = sel.gaussFp(A, b, tol2)
print(x)