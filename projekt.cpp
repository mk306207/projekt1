#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

struct Food {
    int id;
    std::string nazwa;
    std::string kategoria;
    float cena;
    std::string opis;
};
//struktura
int main() {
    std::ifstream inFile;
    inFile.open("baza.txt");
    std::string line;
    std::map<std::string, std::vector<Food>> menu;
    std::vector<Food> zamowienie;
    int id;
    std::string nazwa, kategoria;
    float cena;
    std::string opis;
        while(std::getline(inFile, line))
        {
            std::stringstream ss(line);//wybieranie liczb ze stringa
            ss >> id; // zmienna ss do id
            getline(ss, nazwa, ';');//czytam linie dopoki nie natrafie na ;
            getline(ss, kategoria, ';');
            ss >> cena;  // zmienna ss do ceny
            getline(ss, opis);
            Food f = {id, nazwa, kategoria, cena, opis};
            menu[kategoria].push_back(f);
        }
    inFile.close();
}