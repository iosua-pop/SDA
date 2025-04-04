#pragma once;
#include <iostream>

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

struct Nod {
	TElem nr;
	Nod* prev;
	Nod* next;
};

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	Nod* cap = NULL;
public:

	//complexitate theta(1)
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	//complexitatea theta(m)
	//cel mai bun caz Omega(1), inserare la inceput
	//cel mai rau caz O(n), inserare la final
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	//complexitatea theta(m+1), elementul de sters fiind al m-lea nod in LDI
	//cel mai bun caz Omega(1), elementul se afla la incetut
	//cel mai rau caz O(n) il gaseste sau nu 
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	//complexitatea theta(m) , elemenutul cautat fiind al m-lea nod in LDI
	//cel mai bun caz Omega(1) il gaseste ca si prim nod
	//caz rau caz O(n) il gaseste sau nu 
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	//complexitatea theta(n)
	//cel mai bun/rau caz O(n) il gaseste sau nu 
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	//complexitatea theta(n)
	//cel mai bun/rau caz O(n) il gaseste sau nu 
	int dim() const;

	//verifica daca colectia e vida;
	//complexitate theta(1)
	bool vida() const;

	//returneaza un iterator pe colectie
	//complexitate theta(1)
	IteratorColectie iterator() const;

	//cerinta live
	//verifica cate elemente sunt unice
	//complexitatea theta(n)
	//cel mai bun/rau caz O(n) (parcurge toate nodurile)
	int returnUnic() const;

	// destructorul colectiei
	//complexitate theta(1)
	~Colectie();


};

