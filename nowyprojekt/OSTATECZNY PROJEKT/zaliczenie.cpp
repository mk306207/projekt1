#include "funkcjezal.cpp"
#include "funkcjezal.h"
int main(int argc, char* argv[]){
std::string output;
przelacznik(output,argc,argv);
std::string stolik=output;
std::vector<std::string>kategorie; 
std::vector<produkt> dania;
std::vector<int>przedzial;
std::vector<produkt>zamowienie;
czyt("baza.txt",dania,kategorie);
char x;
sort(kategorie);
while(x!='0'){
    kate(kategorie);
    produkt p;
    std::cin >> x;
    int z=int(x)-48;
    if(z>0&&z<=kategorie.size()){
        while (true){
        if(z > 0 && z <= dania.size()){
            std::string y = kategorie[z-1];
            std::cout<<"====="<<y<<" ====="<<std::endl;
            std::cout<<"Wybierz produkt: "<<std::endl;
            for(auto a : dania){
                if(y==a.kategoria){
                    std::cout<<a.id<<" "<<a.nazwa<<" "<<a.cena<<std::endl;
                    przedzial.push_back(a.id);
                    }
                }
            std::cout<<"0 Powrot"<<std::endl;
            int w;
            std::cin>>w;
            if(w>=przedzial[0]&&w<=przedzial[przedzial.size()-1]){
                for(auto a : dania){
                    if(w==a.id){
                        produkt g={a.id,a.nazwa,a.kategoria,a.cena};
                        zamowienie.push_back(g);
                        std::cout<<a.nazwa<<" Dodano"<<std::endl;
                    }
                }
                std::cout<<"Czy chcesz wybrac cos innego z tej kategori napisz T jesli tak, jesli nie wpisz cokolwiek"<<std::endl;
                char w2;
                std::cin>>w2;
                if(w2=='t'||w2=='T'){
                }
                else{
                    przedzial.clear();
                    break;
                }
            }
            else if(w==0){
                std::cout<<"Wybierz kategorie (tylko jedna cyfra): "<<std::endl;
                przedzial.clear();
                break;
            }
            else{
                std::cout<<"niepoprawny wybor"<<std::endl;//niepoprawny wybor w menu kategorii
                przedzial.clear();
            }
        }
        else{
            std::cout<<"Zly wybor"<<std::endl;
        }
    }
    }
    else if(x=='0'){
        break;
    }
    else if(x=='r'||x=='R'){
        std::cout<<"Wyczyszczono zamowienie"<<std::endl;
        zamowienie.clear();
    }
    else
        std::cout<<"Niepoprawny wybor"<<std::endl;//niepoprawny wybor w menu glownym
    }
    std::cout<<"Zapisano do pliku"<<std::endl;
    float cenao=0.0;
    std::string chas=czas();
    std::string paragon;
    paragon=zapis(zamowienie,cenao,stolik,chas);
    wyswietl_plik(paragon, output);
}