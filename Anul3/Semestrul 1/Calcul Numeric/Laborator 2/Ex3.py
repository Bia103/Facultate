import metode_numerice_ecuatii_algebrice as mnea
import sympy as sym
import matplotlib.pyplot as plt
import numpy as np


'''
Ecercitiul 3
'''

def f(x):
    return x ** 3 - 7 * x ** 2 + 14 * x - 6

# Definim variabila simbolica x
x = sym.symbols("x")

def exercitiul3():
    """
        Implementarea metodei Newton-Rapson

    Returns
    -------
    None.
    """

    # Definim expresia simbolica
    f_expr = f(x)
    df_expr = sym.diff(f_expr, x)
    df = sym.lambdify(x, df_expr)
    print(f'Expresia f_expr: {f_expr} \n Derivata calculata: {df_expr} \n Valoarea derivatei in 2 : {df(2)}')

    # Construim functia pe [0, 4]
    a = 0
    b = 4
    n_noduri = 100
    x_grafic = np.linspace(a, b, n_noduri)
    y_grafic = f(x_grafic)
    plt.plot(x_grafic, y_grafic, linewidth = 3)
    plt.grid()
    plt.axvline(0, color = 'black')
    plt.axhline(0, color = 'black')
    # plt.show()

    # Definim x0, punctul de pornire
    # Alegem x0 a. i. f(x0) * f''(x0) > 0 si f(x0) < 0 la stanga
    x0 = np.array([0.3, 2.5, 4])
    
    sols = np.zeros(x0.shape)
    iteratii = np.zeros(sols.shape)
    eps = 10 ** (-6)
    for i in range(len(x0)):
        sols[i], iteratii[i] = mnea.metoda_newton_raphson(f, df, x0[i], eps = eps)

    plt.plot(sols, f(sols), 'o', markerfacecolor = 'red', markersize = 10)
    plt.show()

exercitiul3()



































