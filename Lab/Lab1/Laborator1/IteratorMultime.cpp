#include "IteratorMultime.h"
#include "Multime.h"



IteratorMultime::IteratorMultime(const Multime& m) : multime(m) {
	/* de adaugat */
	this->actual = multime.elems;
}

//pointer = recipient pentru adresa

void IteratorMultime::prim() {
	/* de adaugat */
	this->actual = &multime.elems[0];
}


void IteratorMultime::urmator() {
	/* de adaugat */
	this->actual = this->actual + 1;
	//sizeof(TElem);
}


TElem IteratorMultime::element() const {
	/* de adaugat */
	if (valid())
		return *this->actual;

	return NULL_TELEM;
}

bool IteratorMultime::valid() const {
	if (*this->actual != NULL_TELEM)
		return true;
	return false;
}
