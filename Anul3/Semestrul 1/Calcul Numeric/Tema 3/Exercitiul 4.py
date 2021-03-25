# -*- coding: utf-8 -*-
"""
Created on Sat Dec 19 15:59:33 2020

@author: Bianca
"""
# Furculesteanu Bianca Grupa 341
# Exercitiul 3
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

a = -4
b = 3
c = -3
d = 4


def f(x, y):
    return 7/2 * (x ** 2) + 2 * x * y + 3 * x + 7/2 * (y ** 2) - 3 * y
A = np.array([[3, 2], [2, 3]])
b = np.array([1, 3])


(Nx, Ny) = (20, 20)
x = np.linspace(a, b, Nx)
y = np.linspace(c, d, Ny)
[X, Y] = np.meshgrid(x, y)
Z = f(X, Y)

fig = plt.figure(1)
axes = plt.axes(projection='3d')
surf = axes.plot_surface(X, Y, Z, cmap = plt.cm.jet)
fig.colorbar(surf)
plt.show()