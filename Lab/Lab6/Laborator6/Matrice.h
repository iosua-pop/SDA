#pragma once
#include <cmath>
typedef int TElem;


#define NULL_TELEMENT 0

struct Nod {
	int linie;
	int coloana;
	TElem valoare;
	Nod* urm;
};

class Matrice {

private:
	/* aici e reprezentarea */
	Nod** tabela;       // tabela de dispersie (vector de pointeri la Nod)
	int m;              // numãr de linii
	int n;              // numãr de coloane
	int capacitate;     // dimensiunea TD
	int dimensiune;     // câte elemente avem în total

	int hash(int linie, int coloana) const {
		return abs((linie * 101 + coloana) % capacitate);
	}

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0

	// complexitate: Capacitatea este constanta, Tetha(1) în utilizare normala.
	Matrice(int nrLinii, int nrColoane);


	//destructor
	// complexitate: O(n) – trebuie sã elibereze toate n noduri
	~Matrice() {
		for (int i = 0; i < capacitate; i++) {
			Nod* p = tabela[i];
			while (p != nullptr) {
				Nod* q = p->urm;
				delete p;
				p = q;
			}
		}
		delete[] tabela;
	}

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	//complexitate:
	//Caz favorabil: Tetha(1) – elementul este primul în lista din TD
	//Caz nefavorabil: O(n) – ultimul din lista de coliziuni TD 
	TElem element(int i, int j) const;


	// returnare numar linii
	//complexitate: Tetha(1) 
	int nrLinii() const;

	// returnare numar coloane
	//complexitate: Tetha(1) 
	int nrColoane() const;

	 
	// modificare element de pe o linie si o coloana si returnarea vechii valori se arunca
	// exceptie daca(i, j) nu e o pozitie valida in Matrice
	//complexitate:
	//Caz favorabil: Tetha(1) – elementul este primul în lista din TD
	//Caz nefavorabil: O(n) – ultimul din lista de coliziuni TD 
	TElem modifica(int i, int j, TElem);

};







