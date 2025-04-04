#include "Matrice.h"

#include <exception>

using namespace std;


Matrice::Matrice(int m, int n) {
	/* de adaugat */
	if (m <= 0 || n <= 0)
		throw std::exception();

	this->m = m;
	this->n = n;
	this->capacitate = 10007;
	this->dimensiune = 0;
	this->tabela = new Nod * [capacitate];
	for (int i = 0; i < capacitate; i++)
		tabela[i] = nullptr;
}



int Matrice::nrLinii() const {
	/* de adaugat */
	return m;
}


int Matrice::nrColoane() const {
	/* de adaugat */
	return n;
}


TElem Matrice::element(int i, int j) const {
	/* de adaugat */
	if (i < 0 || i >= m || j < 0 || j >= n)
		throw std::exception();

	int poz = hash(i, j);
	Nod* p = tabela[poz];
	while (p != nullptr) {
		if (p->linie == i && p->coloana == j)
			return p->valoare;
		p = p->urm;
	}
	return NULL_TELEMENT;
}



TElem Matrice::modifica(int i, int j, TElem e) {
	/* de adaugat */
	if (i < 0 || i >= m || j < 0 || j >= n)
		throw std::exception();

	int poz = hash(i, j);
	Nod* p = tabela[poz];
	Nod* anterior = nullptr;

	while (p != nullptr) {
		if (p->linie == i && p->coloana == j) {
			TElem vecheaValoare = p->valoare;
			if (e == NULL_TELEMENT) {
				if (anterior == nullptr)
					tabela[poz] = p->urm;
				else
					anterior->urm = p->urm;
				delete p;
				dimensiune--;
			}
			else {
				p->valoare = e;
			}
			return vecheaValoare;
		}
		anterior = p;
		p = p->urm;
	}

	// Daca nu am gasit si e diferit de 0, il adaugam
	if (e != NULL_TELEMENT) {
		Nod* nou = new Nod{ i, j, e, tabela[poz] };
		tabela[poz] = nou;
		dimensiune++;
	}

	return NULL_TELEMENT;
}

