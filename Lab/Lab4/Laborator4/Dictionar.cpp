#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

Dictionar::Dictionar() {
	/* de adaugat */
	this->cap = (Nod*)malloc(sizeof(Nod));
	if (this->cap == NULL)
		std::cout << "Nu se poate creea";
	else
	{
		cap->elem = std::make_pair(NULL_TVALOARE, NULL_TVALOARE);
		cap->next = NULL;
	}
}

Dictionar::~Dictionar() {
	/* de adaugat */
	if (this->cap != NULL)
	{
		free(this->cap);
	}
}

TValoare Dictionar::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	if (vid() == true)
	{
		Nod* new_nod = (Nod*)malloc(sizeof(Nod));
		this->cap->next = new_nod;
		new_nod->next = NULL;
		new_nod->elem = std::make_pair(c, v);
		return NULL_TVALOARE;
	}
	else
	{
		if (find(c) != false) // daca exista cheia
		{
			TValoare veche;
			Nod* element_curent = this->cap->next;
			while (element_curent->elem.first != c)
				element_curent = element_curent->next;
			veche = element_curent->elem.second;
			element_curent->elem.second = v;
			return veche;
		}
		else
		{
			Nod* new_nod = (Nod*)malloc(sizeof(Nod));
			Nod* element_curent = this->cap->next;
			//Nod* element_prec = this->cap;
			while (element_curent->next != NULL && element_curent->next->elem.first < c)
			{
				element_curent = element_curent->next;
				//element_prec = element_prec->next;
			}

			if (element_curent->next == NULL)
			{
				element_curent->next = new_nod;
				new_nod->next = NULL;
				new_nod->elem = std::make_pair(c, v);
			}
			else
			{
				new_nod->next = element_curent->next;
				element_curent->next = new_nod;
				new_nod->elem = std::make_pair(c, v);
			}
			return NULL_TVALOARE;
		}
	}
}

bool Dictionar::find(TCheie c) const {
	/* de adaugat */
	if (vid() == true)
		return false;
	else
	{
		Nod* element_curent = this->cap->next;
		while (element_curent != NULL)
		{
			if (element_curent->elem.first == c)
				return true;
			element_curent = element_curent->next;
		}
		return false;
	}
}

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const {
	/* de adaugat */
	if (vid() == true)
		return NULL_TVALOARE;
	else
	{
		Nod* element_curent = this->cap->next;
		while (element_curent != NULL)
		{
			if (element_curent->elem.first == c)
				return element_curent->elem.second;
			element_curent = element_curent->next;
		}
		return NULL_TVALOARE;
	}
}


TValoare Dictionar::sterge(TCheie c) {
	/* de adaugat */
	if (vid() == true)
		return NULL_TVALOARE;
	else
	{
		if (find(c) == false)
		{
			return NULL_TVALOARE;
		}
		else
		{
			TValoare sters = NULL_TVALOARE;
			Nod* elem_curent = this->cap->next;
			Nod* elem_predec = this->cap;
			while (elem_curent->elem.first != c)
			{
				elem_curent = elem_curent->next;
				elem_predec = elem_predec->next;
			}
			Nod* elem_urmator = elem_curent->next;
			sters = elem_curent->elem.second;
			free(elem_curent);

			elem_predec->next = elem_urmator;

			return sters;
		}
	}
	return NULL_TVALOARE;
}


int Dictionar::dim() const {
	/* de adaugat */
	int dim = 0;
	if (vid() == true)
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

bool Dictionar::vid() const {
	/* de adaugat */
	if (this->cap->next == NULL)
		return true;
	else
		return false;
}


int Dictionar::diferentaCheieMaxMin() const {
	TElem minim, maxim;
	if (vid())
		return NULL_TVALOARE;
	else
	{
		Nod* actual = this->cap->next;
		minim = maxim = actual->elem;
		while (actual->next != NULL)
		{
			actual = actual->next;
			if (actual->elem.first > maxim.first)
				maxim = actual->elem;
			if (actual->elem.first < minim.first)
				minim = actual->elem;
		}
		return maxim.second - minim.second;
	}
}


IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}


