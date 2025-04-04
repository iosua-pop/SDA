#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d) {
	/* de adaugat */
	prim();
}

void IteratorMDO::inordineStanga(int nod) {
	while (nod != -1) {
		stiva.push_back(nod);
		nod = dict.noduri[nod].stanga;
	}
}

void IteratorMDO::prim() {
	/* de adaugat */
	stiva.clear();
	inordineStanga(dict.radacina);
	if (!stiva.empty()) {
		nodCurent = stiva.back(); stiva.pop_back();
		indexValoare = 0;
	}
	else {
		nodCurent = -1;
		indexValoare = -1;
	}
}

void IteratorMDO::urmator() {
	/* de adaugat */
	if (!valid())
		throw std::exception();

	indexValoare++;
	if (indexValoare >= dict.noduri[nodCurent].valori.size()) {
		if (!stiva.empty()) {
			inordineStanga(dict.noduri[nodCurent].dreapta);
		}
		else {
			inordineStanga(dict.noduri[nodCurent].dreapta);
		}

		if (!stiva.empty()) {
			nodCurent = stiva.back(); stiva.pop_back();
			indexValoare = 0;
		}
		else {
			nodCurent = -1;
			indexValoare = -1;
		}
	}
}

bool IteratorMDO::valid() const {
	/* de adaugat */
	return nodCurent != -1 && indexValoare < dict.noduri[nodCurent].valori.size();
	/*return false;*/
}

TElem IteratorMDO::element() const {
	/* de adaugat */
	if (!valid())
		throw std::exception();
	return { dict.noduri[nodCurent].cheie, dict.noduri[nodCurent].valori[indexValoare] };
	/*return pair <TCheie, TValoare>(-1, -1);*/
}


