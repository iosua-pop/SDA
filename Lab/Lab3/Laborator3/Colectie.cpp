#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	/* de adaugat */
	return e1 <= e2;
	return false;
}

bool rel_egal(TElem e1, TElem e2) {
	/* de adaugat */
	return e1 == e2;
	return false;
}

Colectie::Colectie() {
	/* de adaugat */
	this->cap = (Nod*)malloc(sizeof(Nod));
	if (this->cap == NULL)
		std::cout << "Nu se poate creea";
	else
	{
		cap->prev = NULL;
		cap->next = NULL;
		cap->nr = -1;
	}
}

void Colectie::adauga(TElem e) {
	/* de adaugat */
	if (vida() == true)
	{
		Nod* new_nod = (Nod*)malloc(sizeof(Nod));
		new_nod->prev = this->cap;
		new_nod->next = NULL;
		new_nod->nr = e;

		this->cap->next = new_nod;
	}
	else
	{
		Nod* actual = this->cap->next;
		Nod* predec = this->cap;
		while (actual != NULL && rel(actual->nr, e))
		{
			actual = actual->next;
			predec = predec->next;
		}

		Nod* new_nod = (Nod*)malloc(sizeof(Nod));
		new_nod->prev = predec;
		new_nod->next = actual;
		new_nod->nr = e;

		if (actual != NULL)
			actual->prev = new_nod;

		predec->next = new_nod;
	}
}


bool Colectie::sterge(TElem e) {
	/* de adaugat */
	if (vida() == true)
		return false;
	else
	{
		if (cauta(e) == false)
		{
			return false;
		}
		else
		{
			Nod* elem_curent = this->cap->next;
			while (!rel_egal(elem_curent->nr, e))
				elem_curent = elem_curent->next;
			Nod* elem_urmator = elem_curent->next;
			Nod* elem_predec = elem_curent->prev;

			free(elem_curent);

			elem_predec->next = elem_urmator;

			if (elem_urmator != NULL)
				elem_urmator->prev = elem_predec;

			return true;
		}
	}
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	if (vida() == true)
		return false;
	else
	{
		Nod* element_curent = this->cap->next;
		while (element_curent != NULL)
		{
			if (element_curent->nr == elem)
				return true;
			element_curent = element_curent->next;
		}
		return false;
	}
}


int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	int nr_ap = 0;
	if (vida() == true)
		return nr_ap;
	else
	{
		Nod* element_curent = this->cap;
		while (element_curent->next != NULL)
		{
			element_curent = element_curent->next;
			if (element_curent->nr == elem)
				nr_ap++;
		}
		return nr_ap;
	}
	return 0;
}



int Colectie::dim() const {
	/* de adaugat */
	int dim = 0;
	if (vida() == true)
		return dim;
	else
	{
		Nod* element_curent = this->cap->next;
		while (element_curent != NULL)
		{
			element_curent = element_curent->next;
			dim++;
		}
		return dim;
	}
	return 0;
}


bool Colectie::vida() const {
	/* de adaugat */
	if (this->cap->next == NULL)
		return true;
	else
		return false;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

/*
Pseudocode
daca colectia = vida atunci return 0
altfel
	nr<-0
	(Nod*) element<-colectie.cap.next
	cat timp element != null efectueaza
		cat timp element.next != null and element.nr = element.next.nr efectueaza
			element = element.next
		nr<- nr + 1
		element = element.next
	return nr
*/

int Colectie::returnUnic() const {
	if (vida() == true)
		return 0;
	else {
		int nr = 0;
		Nod* element = this->cap->next;
		while (element != NULL) {
			while (element->next != NULL && element->nr == element->next->nr)
			{
				element = element->next;
			}
			nr++;
			element = element->next;
		}
		return nr;
	}
}

Colectie::~Colectie() {
	/* de adaugat */
	if (this->cap != NULL)
	{
		free(this->cap);
	}
}
