#include "lista.h"
#include "element_listy.h"
#include <fstream>
template<typename szablon>
lista<szablon>::lista() {
	poczatek_listy = nullptr;
}
template<typename szablon>
void lista<szablon>::odczytaj_plik(std::string plik) {
	std::ifstream plikk(plik);
	if (plikk.is_open()) {
		std::string linia;
		while (std::getline(plikk, linia)) {
			for (auto& gwiazdka : linia) {
				if (gwiazdka % 42 == 0) {
					dodaj_element(gwiazdka);
					licznik++;
				}
				else
					std::cout << "Zle elementu pliku tekstowego! Powinien zawierac jedynie '*'!" << std::endl;
			}
		}
	}
	else
		std::cout << "Nie udalo sie otworzyc pliku tekstowego!";
}

template<typename szablon>
void lista<szablon>::dodaj_element(szablon wartosc) {
	std::shared_ptr<element_listy<szablon>> nowy_element = std::make_shared<element_listy<szablon>>(wartosc);
	if (poczatek_listy == nullptr) {
		poczatek_listy = nowy_element;
	}
	else {
		std::shared_ptr<element_listy<szablon>> biezacy_elem_listy = poczatek_listy;
		while (biezacy_elem_listy->nastepny_elem) {
			biezacy_elem_listy = biezacy_elem_listy->nastepny_elem;
		}
		biezacy_elem_listy->nastepny_elem = nowy_element;
	}
}

template<typename szablon>
int lista<szablon>::przelicz_gwiazdy() {
	return licznik;
}

template<typename szablon>
void lista<szablon>::wyswietl_kontener() {
	std::shared_ptr<element_listy<szablon>> biezacy_elem_listy = poczatek_listy;
	while (biezacy_elem_listy->nastepny_elem) {
		std::cout << biezacy_elem_listy->wartosc_elem << " ";
		biezacy_elem_listy = biezacy_elem_listy->nastepny_elem;
	}
	std::cout << biezacy_elem_listy->wartosc_elem << std::endl << "Liczba gwiazdek wynosi : " << przelicz_gwiazdy() << std::endl << "koniec programu" << std::endl;

}

template<typename szablon>
void lista<szablon>::pokaz() {
	std::shared_ptr<element_listy<szablon>> biezacy_elem_listy = poczatek_listy;
	while (biezacy_elem_listy != nullptr) {
		std::cout << biezacy_elem_listy->wartosc_elem << " ";
		biezacy_elem_listy = biezacy_elem_listy->nastepny_elem;
	}
	std::cout << std::endl;
}
