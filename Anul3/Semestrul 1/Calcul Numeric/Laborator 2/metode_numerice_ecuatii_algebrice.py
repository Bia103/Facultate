import numpy as np

def cauta_intervale(f, a, b, n):
    """
    Parameters
    ----------
    f : functia asociata ecuatiei f(x) = 0
    a : capatul din stanga intervalului
    b : capatul din dreapta intervalului
    n : numarul de subintervale in care impartim intervalul global (a, b)

    Returns : matricea 'intervale' cu 2 linii, prima ne va da capatul din stanga al intervalului curent,
                                            iar a doua linie ne va da capatul din dreapta al intervalului curent
                                            si cu numar de coloane = numarul de radacini
    """
    
    x = np.linspace(a, b, n + 1)
    for i in range(len(x)):
        if f(x[i]) == 0:
            print('Schimbati numarul de intervale')
            exit(0)

    matrice = np.zeros((2, 1000))
    z = 0
    for i in range(n):
        if f(x[i]) * f(x[i + 1]) < 0:
            matrice[0][z] = x[i]
            matrice[1][z] = x[i + 1]
            z += 1
    intervale = matrice[:, :z]
    return intervale


def metoda_bisectiei(f, xmin, xmax, eps):
    """
    Parameters
    ----------
    f : functia asociata ecuatiei f(x) = 0
    xmin : capatul din stanga intervalului
    xmax : capatul din dreapta intervalului
    eps : toleranta, eroarea
    """

    c = (xmin + xmax) / 2
    N = int(np.log2((xmax - xmin) / eps))
    for i in range(N):
        if f(c) == 0:
            break
        elif f(xmin) * f(c) < 0:
            xmax = c
        elif f(xmin) * f(c) > 0:
            xmin = c
        c = (xmin + xmax) / 2
    return c, N

def metoda_bisectiei2(f, xmin, xmax, eps):
    """
    Parameters
    ----------
    f : functia asociata ecuatiei f(x) = 0
    xmin : capatul din stanga intervalului
    xmax : capatul din dreapta intervalului
    eps : toleranta, eroarea
    Returns : solutia aproximativa si numarul de iteratii
    """
    k = 1
    x_old = (xmin + xmax) / 2
    while True:
        if f(x_old) == 0:
            x_new = x_old
            break
        elif f(xmin) * f(x_old) < 0:
            xmax = x_old
        elif f(xmin) * f(x_old) > 0:
            xmin = x_old
        x_new = (xmin + xmax) / 2
        k += 1
        if abs(x_new - x_old) / abs(x_old) < eps:
            break
        x_old = x_new

    return x_new, k


def metoda_newton_raphson(f, df, x0, eps):
    """
    Parameters
    ----------
    f : functia pentru care cautam solutia f(x) = 0
    df : derivarea functiei
    x0 : valoare de pornire
    eps : toleranta impusa
    Returns : solutia, xk,
              N numarul de iteratii
    """

    # Deci verificam dinainte sa apelam functia aceasta
    x_old = x0
    N = 1
    while True:
        # Calculam noua iteratie
        x_new = x_old - (f(x_old) / df(x_old))
        N += 1
        if abs(x_new - x_old) / abs(x_old) < eps:
            break
        x_old = x_new

    return x_new, N










