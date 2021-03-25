# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import numpy as np
def gaussFp(A, b, tol):
    """
    param A: matricea asoc sistemului, patratica
    param b: vectorul term liberi
    param tol: val cu care compatam nr nrnule
    return x: solutia sistemului
    """
    m, n = np.shape(A)
    if m!= n:
        print("Matricea nu este patratica")
        x = None
        return x
    A_extins = np.concatenate((A,b), axis = 1)
    for k in range(n-1):
        p = None
        for j in range(k, n):
            if abs(A[j][k]) > tol:
                p = j
                break
        if(p == None):
            print("Sistemul nu admite solutie unica")
            x = None
        if(p != k):
            A_extins[[p, k]] = A_extins[[k, p]]
        
        for j in range(k+1, n):
            A_extins[j] = A_extins[j] - (A_extins[j][k]/A_extins[k][k]) * A_extins[k]
    if abs(A_extins[n-1][n-1]) <=tol:
        print("Sistemul nu admite solutie unica")
        x = None
        return x
    x = metSubsDesc(A_extins[:, 0:n],A_extins[:,n], tol)
    return x