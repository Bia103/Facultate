# -*- coding: utf-8 -*-
"""
Created on Mon Oct 26 12:00:10 2020

@author: Bianca
"""

import numpy as np
import matplotlib.pyplot as plt

def f(x):
    y=x**3-10*x**2+5
    return y

def MetSecantei(f, x0, x1, tol):
    k = 1
    x2 = 0
    while abs(x1 - x0) / abs(x0) >= tol:
        
        x2 = (x0 * f(x1) - x1 * f(x0))  / (f(x1) - f(x0))
        k = k + 1
        x0 = x1
        x1 = x2
    return x1

def MetPozFalse(f, a, b, tol):
    k = 0
    a0 = a
    b0 = b
    x0 = (a0 * f(b0) - b0 * f(a0)) / (f(b0) - f(a0))

    k = k + 1
    if f(x0) == 0:
        x1 = x0
        return x0
    elif (f(a0) * f(x0)) < 0:
        b0 = x0
        x1 = (a0*f(b0) - b0 * f(a0)) / (f(b0) - f(a0))
    else:
        a0 = x0
        x1 = (a0*f(b0) - b0 * f(a0)) / (f(b0) - f(a0))
        
    while abs(x1 - x0) / abs(x0) >= tol:
        x0 = x1
        if f(x0) == 0:
            x1 = x0
            return x0
        elif (f(a0) * f(x0)) < 0:
            b0 = x0
            x1 = (a0*f(b0) - b0 * f(a0)) / (f(b0) - f(a0))
        else:
            a0 = x0
            x1 = (a0*f(b0) - b0 * f(a0)) / (f(b0) - f(a0))
    return x1

(a,b)=(-1,1)
x_grafic=np.linspace(-1,1,100)
y_grafic= f(x_grafic)
plt.plot(x_grafic,y_grafic, "-", color="blue", linewidth=3)
plt.axvline(0, color='black')
plt.axhline(0, color='black')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Exercitiul 1')
plt.grid(True)

interval1 = MetSecantei(f,-0.75,-0.50,10**(-5))
interval2 = MetSecantei(f,0.75,0.50,10**(-5))
print(interval1)
print(interval2)
interval3 = MetPozFalse(f,-0.75,-0.50,10**(-5))
interval4 = MetPozFalse(f,0.75,0.50,10**(-5))
print(interval3)
print(interval4)
plt.plot([interval1, interval2], [0,0], 'ro')
plt.plot([interval3, interval4], [0,0], 'g^')
plt.show()