# -*- coding: utf-8 -*-
"""
Created on Wed Jan 20 12:46:37 2021

@author: Bianca
"""
import numpy as np

# Exercitiul 2
def integrare(f, x, metoda):

    y = f(x)

    h = x[1] - x[0]
    
    if metoda == 'dreptunghi':
        I = 2 * h * np.sum(y[::2])
    elif metoda == 'trapez':
        I = h/2 * (y[0] + 2 * np.sum(y[1:-2]) + y[-1])
    elif metoda == 'simpson':
        I = h/3 * (y[0] + 4 * np.sum(y[1:-1:2]) + 2 * np.sum(y[2:-1:2]) + y[-1])
    else:
        raise Exception('Metodă necunoscută')

    return I

def f(x):
    return 9*x**2 - 2*x +5

met = 'simpson'
a = Symbol('a')
b = Symbol('b')
t = Symbol('t')

x = []

x.append(a)
for i in range(1,n):
    x.append(a + h * i )
x.append(b)

I1 = integrare(f,x,met)
I2 = integrate(f, (x, a, b))

print("Diferenta dreptunghi")
print(abs(integrare(f,x,met) - integrate(f, (x, a, b))))

print("Diferenta trapez")
print(abs(integrare(f,x,met) - integrate(f, (x, a, b))))

print("Diferenta simpson")
print(abs(integrare(f,x,met) - integrate(f, (x, a, b))))
