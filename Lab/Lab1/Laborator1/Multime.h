#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorMultime;

class Multime {
	friend class IteratorMultime;

private:
	/* aici e reprezentarea */
	int nr;
	int cap;
	TElem* elems;

public:
	//constructorul implicit

	//complexitate constanta O(1)
	Multime();

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)

	//complexitate O(n)
	//cel mai bun caz theta(1) - cauta elementul si il gaseste si nu se mai adauga, sau se adauga dar nu trebuie sa se redimensioneze vectorul
	//cel mai rau caz O(n)+O(2*n)+1=theta(n) - cauta elementul nu il gaseste dar cand sa-l adauge nu mai este loc si trebuie redimensionat vectorul
	bool adauga(TElem e);
	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters

	//complexitate theta(n)
	//cel mai bun caz theta(n) nu se gaseste in lista
	//cel mai rau caz theta(n)+theta(m)=theta(n) se gaseste si trebuie sa mute m elemente mai la stanga
	bool sterge(TElem e);

	//verifica daca un element se afla in multime

	//complexitatea theta(n)
	//cel mai bun/rau caz O(n) il gaseste sau nu 
	bool cauta(TElem elem) const;


	//intoarce numarul de elemente din multime;

	//complexitate theta(1)
	int dim() const;

	//verifica daca multimea e vida;

	//complexitate theta(1)
	bool vida() const;

	//returneaza un iterator pe multime

	//complexitate theta(1)
	IteratorMultime iterator() const;

	//complexitate theta(n)
	//cel mai bun caz theta(n)
	//cel mai rau caz theta(n)+1 = O(n) - calculeaza minim si maxim
	int diferentaMaxMin() const;


	// destructorul multimii

	//complexitate theta(1)
	~Multime();
};




