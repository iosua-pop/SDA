#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>

using namespace std;

MDO::MDO(Relatie r) {
	/* de adaugat */
	capacitate = 100;
	noduri = new Nod[capacitate];
	for (int i = 0; i < capacitate; i++) noduri[i].ocupat = false;
	radacina = -1;
	primLiber = 0;
	relatie = r;
	dimensiune = 0;
}

int MDO::creeazaNod(const TCheie& c, const TValoare& v) {
	if (primLiber == -1) redimensionare();
	int poz = primLiber;
	noduri[poz].cheie = c;
	noduri[poz].valori = { v };
	noduri[poz].stanga = -1;
	noduri[poz].dreapta = -1;
	noduri[poz].ocupat = true;
	actualizeazaPrimLiber();
	return poz;
}

void MDO::actualizeazaPrimLiber() {
	while (primLiber < capacitate && noduri[primLiber].ocupat)
		primLiber++;
	if (primLiber == capacitate)
		primLiber = -1;
}

void MDO::redimensionare() {
	int nouaCap = capacitate * 2;
	Nod* noduriNoi = new Nod[nouaCap];

	for (int i = 0; i < capacitate; i++)
		noduriNoi[i] = noduri[i];
	for (int i = capacitate; i < nouaCap; i++)
		noduriNoi[i].ocupat = false;

	delete[] noduri;
	noduri = noduriNoi;
	primLiber = capacitate;
	capacitate = nouaCap;
}



void MDO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	if (radacina == -1) {
		radacina = creeazaNod(c, v);
		dimensiune++;
		return;
	}

	int curent = radacina;
	int parinte = -1;

	while (curent != -1) {
		parinte = curent;
		if (noduri[curent].cheie == c) {
			noduri[curent].valori.push_back(v);
			dimensiune++;
			return;
		}
		else if (relatie(c, noduri[curent].cheie)) {
			curent = noduri[curent].stanga;
		}
		else {
			curent = noduri[curent].dreapta;
		}
	}

	int pozNou = creeazaNod(c, v);
	if (relatie(c, noduri[parinte].cheie))
		noduri[parinte].stanga = pozNou;
	else
		noduri[parinte].dreapta = pozNou;
	dimensiune++;
}

vector<TValoare> MDO::cauta(TCheie c) const {
	/* de adaugat */
	int curent = radacina;
	while (curent != -1) {
		if (noduri[curent].cheie == c) return noduri[curent].valori;
		else if (relatie(c, noduri[curent].cheie)) curent = noduri[curent].stanga;
		else curent = noduri[curent].dreapta;
	}
	return {};
	/*return vector<TValoare>();*/
}

bool MDO::sterge(TCheie c, TValoare v) {
	/* de adaugat */
	int curent = radacina;
	int parinte = -1;
	while (curent != -1 && noduri[curent].cheie != c) {
		parinte = curent;
		if (relatie(c, noduri[curent].cheie)) curent = noduri[curent].stanga;
		else curent = noduri[curent].dreapta;
	}
	if (curent == -1) return false;

	auto& valori = noduri[curent].valori;
	for (auto it = valori.begin(); it != valori.end(); ++it) {
		if (*it == v) {
			valori.erase(it);
			dimensiune--;
			return true;
		}
	}
	return false;
}

int MDO::dim() const {
	/* de adaugat */
	return dimensiune;
	/*return 0;*/
}

bool MDO::vid() const {
	/* de adaugat */
	return dimensiune == 0;
	/*return true;*/
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	/* de adaugat */
	delete[] noduri;
}
