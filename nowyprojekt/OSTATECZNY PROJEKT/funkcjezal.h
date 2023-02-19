#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include <chrono>
#include <ctime>
#include <cstring>
#ifndef funkcjezal_h_
#define funkcjezal_h_
struct produkt {
int id;
std::string nazwa, kategoria;
float cena;

};
void czyt(std::string baza,std::vector<produkt>&wektor,std::vector<std::string>&kategorie/*,std::map<int,std::string>&map*/);
void sort(std::vector<std::string>&kategorie);
void kate(std::vector<std::string>&kategorie);
std::string zapis(std::vector<produkt>&zamowienie,float &cenao,std::string &stolik,std::string &chas);
std::string czas();
void przelacznik(std::string&output,int argc, char*argv[]);
void wyswietl_plik(std::string nazwa_pliku,std::string przelacznik);
#endif