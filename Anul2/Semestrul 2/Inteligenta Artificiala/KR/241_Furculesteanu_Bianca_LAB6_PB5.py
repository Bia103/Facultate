
#Furculesteanu Bianca 241
import time
from copy import deepcopy

class Nod:

    def __init__(self, info, h):
        self.info = info
        self.h = h

    def __str__(self):
        sir = ''
        for idx, vas in enumerate(self.info):
            sir += str(idx) + ': ' + str(vas) + '\n'
        sir.replace('[', '')
        return f"vase:\n{sir}\n"

    def __repr__(self):
        return f"({self.info}, h={self.h})"

class Problema:
    def __init__(self, h, combinatii=None, stare_initiala=None):
        self.h = h

        self.combinatii = combinatii

        if h == 1:
          self.nod_start = Nod(stare_initiala, self.euristica())
        else:
          self.nod_start = Nod(stare_initiala, self.euristica_inadmisibila())

    def euristica(self):
      # indepartam toate duplicatele din scop (culorile la care trebuie sa ajungem) si daca nu gasim vreuna printre culorile pe care le avem in aceasta stare, atunci crestem cu 1 deoarece va trebui sa mai facem cel putin o combinatie pana sa ajungem la rezultatul dorit


      e = 0

      culori_din_vase = []
      scop = []
      for i in stare_initiala:          # adaugam toate culorile din starea curenta intr-un vector
        culori_din_vase.append(i[2])
        
      for i in nod_scop:                # delectam toate culorile scop fara duplicate, deoarece alfel s-ar putea ca h sa creasca prea mult
        if i[1] not in scop:
          scop.append(i[1])

      for culoare in scop:              # daca culoarea scop nu se afla printre culorile noastre, va trebui sa mai facem cel putin o combinatie pana sa ajungem la starea_finala
          if culoare not in culori_din_vase:
            e = e + 1
      return e

    def euristica_inadmisibila(self):  
        # la fel ca cea de mai sus, dar faptul ca nu eliminam duplicate va creste estimarea prea mult
        e = 0
        culori_din_vase = []
        scop = []
        for i in stare_initiala:
          culori_din_vase.append(i[2])

        for i in nod_scop:
            if i[1] not in culori_din_vase:
                e = e + 1
        return e
""" Sfarsit definire problema """

""" Clase folosite in algoritmul A* """


class NodParcurgere:
    """O clasa care cuprinde informatiile asociate unui nod din listele open/closed
        Cuprinde o referinta catre nodul in sine (din graf)
        dar are ca proprietati si valorile specifice algoritmului A* (f si g).
        Se presupune ca h este proprietate a nodului din graf
    """

    problema = None  # atribut al clasei

    def __init__(self, nod_graf, parinte=None, g=0, f=None):
        self.nod_graf = nod_graf  # obiect de tip Nod
        self.parinte = parinte  # obiect de tip NodParcurgere
        self.g = g  # costul drumului de la radacina pana la nodul curent
        if f is None:
            self.f = self.g + self.nod_graf.h
        else:
            self.f = f

    def drum_arbore(self):
        """
            Functie care calculeaza drumul asociat unui nod din arborele de cautare.
            Functia merge din parinte in parinte pana ajunge la radacina
        """
        nod_c = self
        drum = [nod_c]
        while nod_c.parinte is not None:
            drum = [nod_c.parinte] + drum
            nod_c = nod_c.parinte
        return drum

    def contine_in_drum(self, nod):
        """
            Functie care verifica daca nodul "nod" se afla in drumul dintre radacina si nodul curent (self).
            Verificarea se face mergand din parinte in parinte pana la radacina
            Se coampara doar informtiile nodurilor (proprietatea info)
            Returnati True sau False.
            "nod" este obiect de tip Nod (are atributul "nod.info")
            "self" este obiect de tip NodParcurgere (are "self.nod_graf.info")
        """
        if in_lista(self.drum_arbore(), nod):
            return True
        else:
            return False

    def calcul_culoare(self, culoare1, culoare2):
        for comb in self.problema.combinatii:
          if culoare1 == comb[0] and culoare2 == comb[1]:
            return comb[2]
          if culoare1 == comb[1] and culoare2 == comb[0]:
            return comb[2]
        if culoare1 == '':
          return culoare2
        return "nedefinit"

    # se modifica in functie de problema
    def expandeaza(self):
        """Pentru nodul curent (self) parinte, trebuie sa gasiti toti succesorii (fiii)
        si sa returnati o lista e tupluri (nod_fiu, cost_muchie_tata_fiu),
        sau lista vida, daca nu exista niciunul.
        (Fiecare tuplu contine un obiect de tip Nod si un numar.)
        Luam toate combinatiile de perechi de vase si amestecam intre ele culorile
        si adaugam configuratia noua in lista rez[] cu costul 1
        """
        vase_rezultate = []                                 # vasele rezultate in urma expandarii

        vase = self.nod_graf.info                           # vasele curente

        for a in range(len(vase)):                          # parcurgem vas cu vas
            for b in range(len(vase)):
                copie_vas = deepcopy(vase)                  # copiam cu deep copy ca schimbarile sa nu se reflecte in vas
               
                i = copie_vas[a]                            # retinem cate un vas
                j = copie_vas[b]
                # print("i:", i)
                if i != j and i[0] > i[1] and j[1] > 0:     # daca vasele sunt diferite si mai putem turna in i
                    spatiu_ramas = i[0] - i[1]              # spatiul ramas pentru turnarea lichidului de alta culoare
                    if spatiu_ramas < j[1]:
                      i[1] = i[1] + spatiu_ramas
                      j[1] = j[1] - spatiu_ramas
                    else:
                      i[1] = i[1] + j[1]
                      j[1] = 0
                    culoare = self.calcul_culoare(i[2],j[2])  # calculul noii culori
                    i[2] = culoare
                    if j[1] == 0:
                        j[2] = ''
                vase_rezultate.append((Nod(copie_vas, self.problema.h), 1))
                
        return vase_rezultate

    # se modifica in functie de problema
    def test_scop(self):
        perechi = []
        vase = self.nod_graf.info
        for v in vase:
          perechi.append((v[1], v[2])) 

        return set(nod_scop).issubset(set(perechi))

    def __str__(self):

        if self.nod_graf == self.problema.nod_start:
            return f"{self.nod_graf}"

        sir = ''
        vase = [0, 0]
        nod_curent = self.nod_graf.info
        parinte = self.parinte 
        if self.parinte:      
            for i, vas in enumerate(self.parinte.nod_graf.info):  #comparam copilul cu parintele si daca exista modificari inseamna ca din acele vase s-au extres culorile/ s-au adaugat culorile
                if vas != nod_curent[i]:
                    if vas[1] < nod_curent[i][1]:
                        vase[1] = [nod_curent[i][1]-vas[1], i]
                    if vas[1] > nod_curent[i][1]:
                        vase[0] = [vas[1] - nod_curent[i][1], i, vas[2]]
        # print(vase)
        sir += f"Din vasul {vase[0][1]} s-au turnat {vase[0][0]} litri de apa de culoare {vase[0][2]} in vasul {vase[1][1]}."
        return f"{sir}\n{self.nod_graf}"


""" Algoritmul A* """


def str_info_noduri(l):
    """
        o functie folosita strict in afisari - poate fi modificata in functie de problema
    """
    sir = ""
    for x in l:
        sir += str(x) + "  "
   # sir += "]"
    return sir


def afis_succesori_cost(l):
    """
        o functie folosita strict in afisari - poate fi modificata in functie de problema
    """
    sir = ""
    for (x, cost) in l:
        sir += "\nnod: " + str(x) + ", cost arc:" + str(cost)

    return sir


def in_lista(l, nod):
    """
    lista "l" contine obiecte de tip NodParcurgere
    "nod" este de tip Nod
    """
    for i in range(len(l)):
        if l[i].nod_graf.info == nod.info:
            return l[i]
    return None


def a_star():
    rad_arbore = NodParcurgere(NodParcurgere.problema.nod_start)
    open = [rad_arbore]  
    closed = []  #

    while open:
        # sorteaza dupa f lista open

        open.sort(key=lambda nod: nod.f)

        nod_curent = open.pop(0)
        closed.append(nod_curent)

        if nod_curent.test_scop():
            open.append(nod_curent)
            break
        else:
            succesori = nod_curent.expandeaza()

            for succesor in succesori:
                if nod_curent.contine_in_drum(succesor[0]) is False:

                    is_in_open = in_lista(open, succesor[0])
                    is_in_closed = in_lista(closed, succesor[0])

                    if is_in_open is None and is_in_closed is None:
                        succ_de_parcurs = NodParcurgere(succesor[0], nod_curent, nod_curent.g + succesor[1])
                        open.append(succ_de_parcurs)
                    else:
                        if is_in_open and is_in_open.f > nod_curent.f + succesor[1]:
                            is_in_open.parinte = nod_curent
                            is_in_open.g = nod_curent.g + succesor[1]
                            is_in_open.f = is_in_open.g + succesor[0].h
                        if is_in_closed and is_in_closed.f > nod_curent.f + succesor[1]:
                            is_in_closed.parinte = nod_curent
                            is_in_closed.g = nod_curent.g + succesor[1]
                            is_in_closed.f = is_in_closed.g + succesor[0].h
                            open.append(is_in_closed)
                            closed.remove(is_in_closed)

    
    if (len(open) == 0):
        print("Lista open e vida, nu avem drum de la nodul start la nodul scop", file=fout)
    else:
        print("Drum de cost minim:\n " + str_info_noduri(nod_curent.drum_arbore()), file=fout)


combinatii = []

fout = None

if __name__ == "__main__":

    ind = int(input("Alegeti fisierul (1, 2, 3, 4): "))           # alegerea fisierului de input(1 - cel cu 3-5 iteratii, 2 cel cu solutia starea initiala, 3 - fara solutii, 4 cu multi pasi)
    ind = ind - 1                                                 # deoarece vectorii sunt indexati de la 0 trebuie sa scadem cu 1 indexul fisierului
    ok = 0                                                        # un contor care o sa ne spuna in ce faza a citirii suntem(citirea combinatiilo, citirea vaselor si a culorilor din ele, oaia)
    f = ["input1.txt", "input2.txt", "input3.txt", "input4.txt"]  # lista cu fisierele de input

    # output-ul pt cele 3 euristici in functie de input
    output1 = ["output1-1.txt", "output2-1.txt", "output3-1.txt", "output4-1.txt"] 
    output2 = ["output1-2.txt", "output2-2.txt", "output3-2.txt", "output4-2.txt"]
    output3 = ["output1-3.txt", "output2-3.txt", "output3-3.txt", "output4-3.txt"]

    inputf = f[ind]                                               # fisierul ales
    cont = 0 
    stare_initiala = []                                           # se memoreaza starea initiala
    stare_finala = []                                             # se memoreaza starea la care ar trebui sa ajungem in unele dintre vase

    with open(inputf, 'r') as fis:                                # citim din fisier
      for linie in fis:                                           # pentru fiecare linie din fisier
        linie = linie.split()                                     # impartim linia in cuvinte
        if linie[0] == "stare_initiala":                          # am terminat cu combinatiile de culori si incepem sa citim starea initiala
          ok = 1
        if linie[0] == "stare_finala":                            # marcheaza locul de unde incepem sa citim starea finala
          ok = 2
        if ok == 0:                                               # stocam in combinatii cele 2 culori care se combina in a 3-a culoare considerata compusa
          combinatii.append([linie[0],linie[1],linie[2]])
        if ok == 1 and linie[0] != "stare_initiala":              # memoram fiecare linie din starea initala
          i = 0
          ok1 = 0
          if len(linie) == 2:
            stare_initiala.append([int(linie[0]),int(linie[1]),''])
          else:
            stare_initiala.append([int(linie[0]),int(linie[1]),linie[2]])
        if ok == 2 and linie[0] != "stare_finala":                # memoram starea finala
          stare_finala.append((int(linie[0]), linie[1]))
        
    nod_scop = stare_finala
    print(stare_finala)
    print(stare_initiala)
    print(combinatii)


    fout = open(output1[ind], 'w')                                # facem un fisier in care scriem

    problema = Problema(combinatii=combinatii, stare_initiala=stare_initiala, h=1)  # initiam problema
    NodParcurgere.problema = problema
    before = int(round(time.time() * 1000))                       # timpul de dinainte de a incepe a_star
    a_star()                                                        
    after = int(round(time.time() * 1000))                        # timpul pana cand se executa algoritmul a_star
    print("Timp : " + str((after - before)/1000) + " secunde.", file=fout) # scriem in fisier timpul in care se executa a_star

    fout = open(output2[ind], 'w')

    problema = Problema(combinatii=combinatii, stare_initiala=stare_initiala, h=2)
    NodParcurgere.problema = problema
    before = int(round(time.time() * 1000))
    a_star()
    after = int(round(time.time() * 1000))
    print("Timp : " + str((after - before)/1000) + " secunde.", file=fout)

    fout = open(output3[ind], 'w')

    problema = Problema(combinatii=combinatii, stare_initiala=stare_initiala, h=1)
    NodParcurgere.problema = problema
    before = int(round(time.time() * 1000))
    a_star()
    after = int(round(time.time() * 1000))
    print("Timp : " + str((after - before)/1000) + " secunde.", file=fout)


    fout.close()
