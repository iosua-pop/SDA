#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Multime::Multime() {
	// initializam parametrii
	/* de adaugat */
	this->nr = 0;
	this->cap = 1;
	this->elems = new TElem[1];
	this->elems[0] = NULL_TELEM;
}

bool Multime::adauga(TElem elem) {
	/* de adaugat */
	bool ok = cauta(elem);

	//elementele sunt unice intr o multime
	if (ok != true) {

		//nu mai avem spatiu
		if (this->dim() == this->cap - 1)
		{
			int nCap = this->cap * 2;
			TElem* nElem = new TElem[nCap];
			for (int i = 0; i < cap; i++)
				nElem[i] = this->elems[i];
			for (int i = this->cap; i < nCap; i++)
				nElem[i] = NULL_TELEM;
			delete[] this->elems;
			this->elems = nElem;
			this->cap = nCap;
		}
		this->elems[this->nr] = elem;
		this->nr++;
		return true;
	}
	//exista deja
	return false;
}


bool Multime::sterge(TElem elem) {
	/* de adaugat */
	bool ok = cauta(elem);

	//elementul nu exista in multime
	if (ok == true) {
		for (int i = 0; i < this->dim(); i++)
		{
			if (this->elems[i] == elem)
			{
				for (int j = i; j < this->dim() - 1; j++)
				{
					this->elems[j] = this->elems[j + 1];
				}
				this->elems[this->nr - 1] = NULL_TELEM;
				this->nr--;

				return true;
			}
		}
	}

	//daca nu exista
	return false;
}


bool Multime::cauta(TElem elem) const {
	/* de adaugat */
	for (int i = 0; i < this->dim(); i++)
	{
		if (this->elems[i] == elem)
			return true;
	}
	//nu exista
	return false;
}


int Multime::dim() const {
	/* de adaugat */
	return this->nr;

	return 0;
}

bool Multime::vida() const {
	/* de adaugat */
	if (this->nr == 0)
		return true;

	return false;
}
/*
* dim() este numarul de elemente din vector
* elems[i] elementul din vector de pe pozitia i
*

minim<- infinit
maxim<- -infinit
daca dim() = 0 ,atunci(vectorul e nul)
	returneaza -1
for i<-0, dim(), executa
	daca minim > elems[i], atunci
		minim = elems[i]
	daca maxim < elems[i], atunci
		maxim = elems[i]

returneaza maxim-minim
*/

int Multime::diferentaMaxMin() const {
	int minim = INFINITY, maxim = -INFINITY;

	if (this->dim() == 0)
		return -1;

	for (int i = 0; i < this->dim(); i++)
	{
		if (this->elems[i] > maxim)
			maxim = this->elems[i];
		if (this->elems[i] < minim)
			minim = this->elems[i];
	}
	return maxim - minim;
}


Multime::~Multime() {
	/* de adaugat */

	delete[] elems;
}



IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

