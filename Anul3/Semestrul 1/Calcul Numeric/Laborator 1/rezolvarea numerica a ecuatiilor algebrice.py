import numpy as np
import metodeNumericePentruEcuatiiAlgebrice as mn
import matplotlib.pyplot as plt
'''
ex1
Sa se identifice intervalele pe care functia f determina o solutie unica
f(x)=x^3-7*x^2+14*x-6
Interval de studiu: (a,b)=(0,4)
'''
def f(x):
    y=x**3-7*x**2+14*x-6
    return y

(a,b)=(0,4)
interval=mn.construieste_intervale(f,a,b,10)
x_grafic=np.linspace(0,4,100)
y_grafic= f(x_grafic)
plt.plot(x_grafic,y_grafic, "-", color="blue", linewidth=3)
plt.axvline(0, color='black')
plt.axhline(0, color='black')
plt.xlabel('x')
plt.ylabel('y')
plt.title('ex1')
plt.grid(True)
for i in range(np.shape(interval)[1]):
    plt.plot(interval[:,i], np.zeros((2,1)), color='red', linewidth=10)




print(interval)

'''
ex2
Pentru datele de la ex1 sa se afle toate radacinile conform metodeo bisectiei
'''
r=np.zeros(np.shape(interval)[1])
for i in range(np.shape(interval)[1]):
    r[i],N= mn.bisectie(f, interval[0,i], interval[1,i], 10**-3)
    print("Metoda bisectiei")
    print("x^3-7*x^2+14*x-6")
    print("Intervalul [{:.3f}, {:.3f}]".format(interval[0,i], interval[1,i]))
    print("Solutia numerica x*={:.3f}".format(r[i]))
    print("---------------------------------------------")
plt.plot(r,f(r), "o-", color="green", linewidth=3, markersize=10)
plt.show()