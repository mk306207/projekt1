#include "element_listy.h"

template<typename szablon>
element_listy<szablon>::element_listy(szablon wartosc_elem) {
	this->wartosc_elem = wartosc_elem;
	nastepny_elem = nullptr;
}