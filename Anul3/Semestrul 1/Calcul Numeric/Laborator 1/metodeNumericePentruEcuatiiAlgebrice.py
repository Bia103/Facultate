import numpy as np
def construieste_intervale(f,a,b,n):
    '''

    :param f: functia asociata ecuatiei f(x)=0
    :param a: capatul din stanga al intervalului
    :param b: capatul din dreapta al intervalului
    :param n: numarul de subintervale in care impartim intervalul global
    :return: matricea 'intervale' cu 2 linii, prima linie ne va da capatul din stanga, a doua capatul din dreapta al intervalului curent,
    si nr de coloane = nr de radacini
    '''
    x=np.linspace(a,b,n+1)
    for i in range (len(x)):
        if f(x[i]) == 0:
            print("Scimbati nr de intervale")
            exit(0)

    matrice = np.zeros((2, 1000))
    z=0
    for i in range(n):
        if f(x[i])*f(x[i+1])<0:
            matrice[0][z]=x[i]
            matrice[1][z]=x[i+1]
            z+=1
    matrice_finala=matrice[:, 0:z]
    return matrice_finala

def bisectie(f,xmin,xmax,eps):
    '''

    :param f: functia f(x)=0
    :param xmin: capatul interv
    :param xmax: capatul interv
    :param eps: toleranta/eroarea
    :return:
    '''
    c=(xmin+xmax)/2
    N=int(np.log2(xmax-xmin)/eps)
    for i in range(N):
        if c==0 :
            break
        elif f(xmin)*f(c)<0:
            xmax=c
        elif f(xmin)*f(c)>0:
            xmin=c
        c = (xmin + xmax) / 2
    return c,N




