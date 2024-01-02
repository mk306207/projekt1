#include "paragon_faktura.h"
paragon_faktura::paragon_faktura() {
	imie_nazwisko = " ";
	zawod = " ";
	przedmioty.emplace(" ", 0.00);
}
paragon_faktura::paragon_faktura(std::string in, std::string z, std::map<std::string, float> p) {
	this -> imie_nazwisko = in;
	this -> zawod = z;
	this -> przedmioty = p;
}
void paragon_faktura::odczytaj_paragon(std::string plik) {
	std::ifstream plikk(plik);
	if (plikk.is_open()) {
		std::string in;
		std::string z;
		std::map<std::string, float> p;
		std::getline(plikk, in);
		std::getline(plikk, z);
		std::string przedmiot;
		float cena;
		while (plikk >> przedmiot >> cena) {
			p[przedmiot] = cena;
		}
		*this = paragon_faktura(in, z, p);
		plikk.close();
	}
	else
		std::cout << "Nie udalo sie znalezc twojego pliku. Sprawdz czy dobrze go nazwales." << std::endl;
}
void paragon_faktura::stworz_fakture() {

}
paragon_faktura::~paragon_faktura() {}
void paragon_faktura::odczyt(){
	std::cout << "Imie i nazwisko: " << imie_nazwisko << std::endl;
	std::cout << "Zawod: " << zawod << std::endl;
	std::cout << "Przedmioty:" << std::endl;
	for (const auto& pair : przedmioty) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
}
std::string paragon_faktura::oddaj_imie() {
	return imie_nazwisko;
}
std::string paragon_faktura::oddaj_zawod() {
	return zawod;
}
std::map<std::string, float> paragon_faktura::oddaj_przedmioty() {
	return przedmioty;
}