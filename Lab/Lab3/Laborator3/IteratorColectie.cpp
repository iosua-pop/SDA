#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	/* de adaugat */
	this->actual = c.cap->next;
	this->cap = c.cap;
}

TElem IteratorColectie::element() const {
	/* de adaugat */
	return this->actual->nr;
	return -1;
}

bool IteratorColectie::valid() const {
	/* de adaugat */
	if (this->actual == NULL) //|| this->actual == this->cap
		return false;
	else
		return true;
}

void IteratorColectie::urmator() {
	/* de adaugat */
	this->actual = this->actual->next;
}

void IteratorColectie::prim() {
	/* de adaugat */
	this->actual = this->cap->next;
}
