#include <iostream>
#include <cstring>
using namespace std;
struct Nod
{
    int numar;
    Nod* urmator;
};
void inserareFinal(Nod* &cap, int valoare)
{
    Nod *elem_final = new Nod;
    elem_final->numar = valoare;
    elem_final->urmator = NULL;
    if (cap == NULL)
        cap = elem_final;
    else
    {  Nod *nod_curent = cap;
        while (nod_curent->urmator != NULL)
            nod_curent = nod_curent->urmator;
        nod_curent->urmator = elem_final;
    }
}
void inserareInceput(Nod* &cap, int valoare)
{
    Nod *elem = new Nod;
    elem->numar = valoare;
    elem->urmator = cap;
    cap = elem;
}
void inserareElement(Nod* &cap, Nod* element_dat, int valoare)
{
    Nod *elem_creat = new Nod;
    elem_creat->numar = valoare;
    elem_creat->urmator = NULL;
    if (cap == NULL)
    {
        cap = elem_creat;
        return;
    }
    if (cap == element_dat)
    {
        elem_creat->urmator = cap;
        cap = elem_creat;
        return;
    }
    elem_creat->urmator = element_dat->urmator;
    element_dat->urmator = elem_creat;
}
void afisareLista(Nod* cap)
{
    while (cap != NULL)
    {
        cout << cap->numar << "\n";
        cap = cap->urmator;
    }
}
Nod* cautareValoare(Nod* cap, int valoare)
{
    while (cap != NULL && cap->numar != valoare)
        cap = cap->urmator;
    return cap;
}
Nod* cautarePozitie(Nod* cap, int pozitie)
{
    int i = 0;
    while (cap != NULL && i < pozitie)
    {
        cap = cap->urmator;
        i++;
    }
    if (i == pozitie)
        return cap;
    else
        return NULL;
}
void stergereElement(Nod* predecesor)
{
    Nod* elem = predecesor->urmator;

    predecesor->urmator = predecesor->urmator->urmator;

    delete elem;
}
void stergereElementValoare(Nod* &cap, int valoare)
{
    if(cap->numar == valoare)
    {
        Nod* victima = cap;
        cap = cap->urmator;
        delete victima;
        return;
    }
    Nod* elem = cap;
    while (elem->urmator != NULL && elem->urmator->numar != valoare)
        elem = elem->urmator;
    if (elem->urmator != NULL)
        stergereElement(elem);
}

void stergereElementPozitie(Nod* &cap, int pozitie)
{
    if (pozitie == 0)
    {
        Nod* elem = cap;
        cap = cap->urmator;
        delete elem;
    }
    else
    {
        Nod* predecesor = cautarePozitie(cap, pozitie-1);
        stergereElement(predecesor);
    }
}
void stergereToataLista(Nod* &cap, Nod *p)
{
   while ( cap!= NULL )
    { p = cap;
      cap = cap->urmator;
    free(p);
    }
     p=NULL;
}
int main()
{
    char optiune= 'a';
    Nod *cap;
    int valoare=1;
    while(optiune!=NULL)
    {
      switch (optiune)
  case 'a':
    inserareFinal(cap, valoare);
    }


    return 0;
}
