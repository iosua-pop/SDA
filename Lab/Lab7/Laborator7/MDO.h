#pragma once

#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

struct Nod {
	TCheie cheie;
	vector<TValoare> valori;
	int stanga;
	int dreapta;
	bool ocupat;
};

class MDO {
	friend class IteratorMDO;
private:
	/* aici e reprezentarea */
	Nod* noduri;        // tabloul care ?ine nodurile
	int capacitate;     // capacitatea vectorului de noduri
	int radacina;       // indexul rãdãcinii
	int primLiber;      // indexul primei pozi?ii libere
	Relatie relatie;

	int creeazaNod(const TCheie& c, const TValoare& v);
	void redimensionare();
	void actualizeazaPrimLiber();
	int dimensiune;
public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	//complexitate
	//Caz favorabil (cheie este rãdãcina): O(log m)
	//Caz nefavorabil(cheie la capãt) : O(m)
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	//complexitate
	//Caz favorabil: O(log m)
	//Caz nefavorabil : O(m)
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	//complexitate: Tetha(log m + k)
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	//complexitate: Tetha(1)
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	//complexitate: Tetha(1)
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	//complexitate: Tetha(1)
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();

};
