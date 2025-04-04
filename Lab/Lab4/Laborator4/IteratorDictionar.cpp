#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>

using namespace std;

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d) {
	/* de adaugat */
	this->actual = d.cap->next;
	this->cap = d.cap;
}


void IteratorDictionar::prim() {
	/* de adaugat */
	this->actual = this->cap->next;
}

void IteratorDictionar::urmator() {
	/* de adaugat */
	this->actual = this->actual->next;
	if (!valid())
		throw std::exception("Nu este valid");

}


TElem IteratorDictionar::element() const {
	/* de adaugat */
	if (!valid())
		throw new exception("Nu este valid");
	return this->actual->elem;
	return pair <TCheie, TValoare>(-1, -1);
}


bool IteratorDictionar::valid() const {
	/* de adaugat */
	if (this->actual == NULL)
		return false;
	else
		return true;
}

