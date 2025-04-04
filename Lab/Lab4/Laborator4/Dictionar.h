#pragma once


#define NULL_TVALOARE -1
typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

struct Nod {
	TElem elem;
	Nod* next;
};

class Dictionar {
	friend class IteratorDictionar;

private:
	/* aici e reprezentarea */
	Nod* cap;
public:

	//complexitate theta(1)
	// constructorul implicit al dictionarului
	Dictionar();

	// adauga o pereche (cheie, valoare) in dictionar	
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	//complexitatea theta(m)
	//cel mai bun caz Omega(1), inserare la inceput
	//cel mai rau caz O(n), inserare la final
	TValoare adauga(TCheie c, TValoare v);

	//complexitatea theta(m) , elemenutul cautat fiind al m-lea nod in LSI
	//cel mai bun caz Omega(1) il gaseste ca si prim nod
	//caz rau caz O(n) il gaseste pe ultima pozitie sau nu
	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;

	//complexitatea theta(m) , elemenutul cautat fiind al m-lea nod in LSI
	//cel mai bun caz Omega(1) il gaseste ca si prim nod
	//caz rau caz O(n) il gaseste pe ultima pozitie sau nu
	//cauta o cheie si returneaza true daca il gaaseste, respectiv false daca nu gaseste cheia
	bool find(TCheie c) const;

	//complexitatea theta(m+1), elementul de sters fiind al m-lea nod in LDI
	//cel mai bun caz Omega(1), elementul se afla la incetut
	//cel mai rau caz O(n) il gaseste sau nu
	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//complexitatea theta(n)
	//cel mai bun/rau caz O(n) il gaseste sau nu 
	//returneaza numarul de perechi (cheie, valoare) din dictionar 
	int dim() const;

	//complexitate theta(1)
	//verifica daca dictionarul e vid 
	bool vid() const;

	//complexitate theta(1)
	// se returneaza iterator pe dictionar
	IteratorDictionar iterator() const;

	/*
	TAD Dictionar

	// returneaza diferenta dintre cheia maxima si cheia minima (presupunem chei intregi)

	// Daca dictionarul este vid, se returneaza  -1
	*/


	/*
	daca dictionar = vid atunci return -1
	altfel
		(Nod*) actual <- dictionar.cap.next
		minim,maxim <- actual.elem
		cat timp actual.next =/= null executa
			actual = actual.next
			daca actual.elem.first > maxim.first atunci
				maxim = actual.elem
			daca actual.elem.first < minim.first atunci
				minim = actuaal.elem
		return maxim.second - minim.second
	*/


	//complexitatea theta(n)
	//cel mai bun/rau caz O(n)
	int diferentaCheieMaxMin() const;

	//complexitate theta(1)
	// destructorul dictionarului	
	~Dictionar();

};


