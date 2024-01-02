#pragma once
#include <iostream>
template<typename szablon>

class element_listy
{
public:
	szablon wartosc_elem;
	std::shared_ptr<element_listy<szablon>> nastepny_elem;
	element_listy(szablon wartosc_elem);
};
