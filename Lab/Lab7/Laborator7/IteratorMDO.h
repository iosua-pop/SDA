#pragma once

#include "MDO.h"


class IteratorMDO {
	friend class MDO;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMDO(const MDO& dictionar);

	//contine o referinta catre containerul pe care il itereaza
	const MDO& dict;
	/* aici e reprezentarea  specifica a iteratorului */

	std::vector<int> stiva;  // stivã de indici pentru parcurgere in-order
	int nodCurent;           // indexul nodului curent
	int indexValoare;        // indexul valorii curente din vectorul de valori al nodului
	void inordineStanga(int nod);

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	//complexitate Tetha(h) unde h = înãl?imea arborelui
	//in arbore balansat : O(log m)
	//in arbore degenerat(listã) : O(m)
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//complexitate
	//Dacã mai are valori pe aceea?i cheie: O(1)
	//Altfel, urcã înapoi pe stivã, apoi coboarã în subarbore drept : O(h)
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	//complexitate: Tetha(1)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//complexitate: Tetha(1)
	TElem element() const;
};

