#include "funkcjezal.h"


void czyt(std::string baza,std::vector<produkt>&wektor,std::vector<std::string>&kategorie/*,std::map<int,std::string>&map*/){
    std::ifstream plik;
    plik.open(baza);
    if(plik){
        std::string linia;
        while(std::getline(plik,linia)){
            produkt p;
            std::stringstream ss(linia);
            std::string f;
            getline(ss,f,';');
            p.id=stoi(f);
            getline(ss,f,';');
            p.nazwa=f;
            getline(ss,f,';');
            p.kategoria=f;
            kategorie.push_back(f);
            getline(ss,f,';');
            p.cena=stof(f);
            wektor.push_back(p);
            //map.insert(std::pair<int,std::string>(p.id,p.nazwa));
        }

    }
    else{
        std::cout<<"BLAD WCZYTANIA DANYCH";
    }
    plik.close();
}


void sort(std::vector<std::string>&kategorie){
    sort(kategorie.begin(),kategorie.end());//sortuje wektor
    auto end=unique(kategorie.begin(),kategorie.end());//zmienna end dostaje ile razy przerzucilismy duplikat kategorii na koniec wektora | funkcja unique znajduje duplikaty i przerzuca je na koniec wektora
    kategorie.erase(end,kategorie.end());//wymazujemy koniec wektora od zmiennej end az do samego konca| edit1:nie potrzebne dowiedzialem sie ze unique tez usuwa
    std::cout<<"Wybierz kategorie (tylko jedna cyfra): "<<std::endl;
}


void kate(std::vector<std::string>&kategorie){
        for (int i=0;i<=kategorie.size();i++){
        if(kategorie[i].empty()){//jezeli wektor od jakiegos inta jest pusty koniec petli
            continue;
        }
        else{
        std::cout<<i+1 << "."<<kategorie[i]<<std::endl;}
    }
    std::cout<<"0. Zloz zamowienie"<<std::endl;
    std::cout<<"R. Resetuj zamowienie"<<std::endl;
}


std::string zapis(std::vector<produkt>&zamowienie,float &cenao,std::string &stolik,std::string &chas){
    std::string paragon;
    paragon ="S"+stolik+"_"+chas+".txt";
    std::ofstream plik(paragon);
    if (plik){
        plik<<"Stolik nr "<<s<<std::endl;
        plik<<chas<<std::endl;
        for(auto a:zamowienie){
            plik<<a.nazwa<<"         "<<a.cena<<std::endl;
            cenao+=a.cena;
        }
        plik<<"=================================="<<std::endl;
        plik<<"Kwota do zaplaty:        "<<cenao<<std::endl;
    }
    else{
        std::cout<<"BLAD";

    }
    plik.close();
    return paragon;
}


// std::string stolik(){
//     srand(time(nullptr));
//     int st=rand()%15+1;
//     std::string s = std::to_string(st);
//     return s;
// }


std::string czas(){
    time_t tim = time(0);
    tm *gottime = localtime(&tim);
    std::string czas=std::to_string(gottime->tm_hour)+"_"+std::to_string(gottime->tm_min);
    return czas;
}


void przelacznik(std::string&output,int argc, char*argv[]){
    for(int i=0;argc>i;i++){
        if(strcmp(argv[i],"-s")==0){
            output=argv[i+1];
        }
    }
}


void wyswietl_plik(std::string nazwa_pliku,std::string przelacznik) {
    std::ifstream plik(nazwa_pliku);
    if(plik){
        std::string linia;
        while(std::getline(plik,linia)){
            std::cout<<linia<<std::endl;
        }
    }
    else{
        std::cout<<"BLAD"<<std::endl;
    }
    plik.close();
}