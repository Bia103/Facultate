import numpy as np
import calcul_num as sel
import time

tol = 10**-10
A = np.array([[0.,1.,2.],[1.,0.,1.],[3.,2.,1.]])
b = np.array([[8.],[4.],[10.]])
L,U,w = sel.factLU(A,b,tol)
print(L)
print(U)
print(w)
print("-----------------")
b_nou = np.copy(b)
for i in range(np.shape(b)[0]):
    b_nou[i] = b[w[i]]
print(b)
print(b_nou)
y = sel.metSubsAsc(L,b_nou,tol)
x = sel.metSubsDesc(U,y,tol)
print(x)
#print(L@U)
#print(A)

#EX2
n = 100
A = np.random.rand(n,n)*10
b = np.zeros((n,1))
for i in range(n):
    sum = 0
    for j in range(n):
        sum += A[i][j]
    b[i] = sum

L,U,w = sel.factLU(A,b,tol)
b_nou = np.copy(b)
for i in range(np.shape(b)[0]):
    b_nou[i] = b[w[i]]
y = sel.metSubsAsc(L,b_nou,tol)
x = sel.metSubsDesc(U,y,tol)
print(x)
#c
x_old = np.copy(x)
tic = time.time()
L,U,w = sel.factLU(A,b,tol)
b_nou = np.zeros((n,1))

for k in range(0,100):
    
    b_nou = x_old[:] + 2
    for i in range(np.shape(b)[0]):
        b_nou[i] = b[w[i]]
        
    y = sel.metSubsAsc(L,b_nou,tol)
    x_new = sel.metSubsDesc(U,y,tol)
    
    x_old = x_new[:]

toc = time.time() - tic
print("Sol la ultima iteratie\n",x_old)
print("In timp de", toc)

tic = time.time()
x_old = x
for k in range(0,100):
    x_new = sel.gaussPP(A,x_old + 2,tol)
    x_old = x_new[:]
toc = time.time() - tic
print("Sol la ultima iteratie\n",x_old)
print("In timp de", toc)