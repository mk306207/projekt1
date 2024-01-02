#pragma once
#include <string>
#include<iostream>
#include "element_listy.h"
#include "paragon_faktura.h"
template<typename szablon>

class lista
{
public:
	int licznik = 0;
	std::shared_ptr<element_listy<szablon>> poczatek_listy;
	lista();
	void odczytaj_plik(std::string plik);
	void dodaj_element(szablon wartosc);
	void wyswietl_kontener();
	int przelicz_gwiazdy();
	void pokaz();
};