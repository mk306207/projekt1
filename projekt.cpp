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
void kategorie(std::string(kategoria));
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
    std::string ids, cenas;
        while(std::getline(inFile, line))
        {
            std::stringstream ss(line);//wybieranie liczb ze stringa
            getline(ss, ids, ';'); //ss>>id; // zmienna ss do id
            id = stoi(ids);//zmiana stringa do int
            getline(ss, nazwa, ';');//czytam linie dopoki nie natrafie na ;
            getline(ss, kategoria, ';');
            getline(ss,cenas,';');  // zmienna ss do ceny
            cena = stof(cenas);//zmiana z string na float
            getline(ss, opis);
            Food f = {id, nazwa, kategoria, cena, opis};
            menu[kategoria].push_back(f);
        }
    inFile.close();
}
