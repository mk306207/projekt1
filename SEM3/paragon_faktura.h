#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <map>
class paragon_faktura
{
private:
	std::string imie_nazwisko;
	std::string zawod;
	std::map<std::string, float> przedmioty;
public:
	paragon_faktura();
	paragon_faktura(std::string in, std::string z, std::map<std::string, float> p);
	void odczytaj_paragon(std::string plik);
	void stworz_fakture();
	~paragon_faktura();
	void odczyt();
	std::string oddaj_imie();
	std::string oddaj_zawod();
	std::map<std::string, float> oddaj_przedmioty();
};

