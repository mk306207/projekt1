#include <iostream>
#include "lista.h"
#include "lista.cpp"
#include "paragon_faktura.h"
int main()
{
    std::cout << "Program do faktur"<<std::endl;
    paragon_faktura temp;
    lista<std::string> abc;
    temp.odczytaj_paragon("p.txt");
    temp.odczyt();
    std::string a;
    a = temp.oddaj_imie();
    std::cout << a;
}
