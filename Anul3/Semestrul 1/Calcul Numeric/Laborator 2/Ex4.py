import metode_numerice_ecuatii_algebrice as mnea
import sympy as sym
import matplotlib.pyplot as plt
import numpy as np

"""
Exercitiul 4
"""

def f(x):
    return x ** 3 - 7 * x ** 2 + 14 * x - 6

x = sym.symbols("x")

def Ex4():
    f_expr = f(x)
    df_expr = sym.diff(f_expr, x)
    df = sym.lambdify(x, df_expr)
    
    x_grafic2 = np.linspace(-1, 1.5, 100)
    y_grafic2 = f(x_grafic2)
    
    plt.plot(x_grafic2, y_grafic2, linewidth = 3)
    plt.grid()
    plt.axvline(0, color = 'black')
    plt.axhline(0, color = 'black')
    plt.show()
    x0 = -1
    eps = np.linspace(10 ** (-13), 10 ** (-3), 50)
    N_bisectie2 = np.zeros(eps.shape)
    N_NR = np.zeros(eps.shape)
    for i in range(len(eps)):
        sol_bis, N_bisectie2[i] = mnea.metoda_bisectiei2(f, -1, 1.5, eps[i])
        sol_NR, N_NR[i] = mnea.metoda_newton_raphson(f, df, x0, eps[i])
    plt.plot(eps, N_bisectie2, "b", linewidth = 2)
    plt.plot(eps, N_NR, "r", linewidth = 2)
    plt.grid()
    plt.axvline(0, color = 'black') # ax vertical line
    plt.axhline(0, color = 'black')
    plt.show()
    
Ex4()
