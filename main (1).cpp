#include <iostream>
#include <iomanip>
#include <string>

struct studentas{//aprasom ka naudosim
  std::string Vardas, Pavarde;
  int nd[10]={0};//sveikas skaicius
  int egzaminas;
  float galutinis;//skaicius per kableli
};

void print(studentas);

int main(){
  std::cout <<"Iveskite studentu skaiciu"<< std::endl;
  int n;//studentu skaicius
  std::cin>>n;
  studentas grupe[n];//studentas-naudojamas duomenu tipas kuri patys apsirasem, tokio tipo turesim grupe su n nariu
  float suma=0;//reikalinga apskaiciuoti vidurki
  for (int i=0; i<n; i++)//for funkcija skirta duomenu apie studentus surinkimui
   {
    std::cout<<"Iveskite "<<i+1<<"-jo studento vardas:\n";
    std::cin>>grupe[i].Vardas;
    std::cout<<"Iveskite "<<i+1<<"-jo studento pavarde:\n";
    std::cin>>grupe[i].Pavarde;
    suma=0;
    for (int j=0; j<10; j++)//for funkcija skirta kiekvieno studento visu pazymiu surinkimui
    {
      std::cout<<"Iveskite pazymi uz "<<j+1<<" namu darba:\n";
      std::cin>>grupe[i].nd[j];//pirmos gr 1-10 pazymai, antros ir t.t.
      suma=suma+grupe[i].nd[j];//iskart skaiciuojame is pazymiu suma, suma + atitinkamas pazimys
    }
    std::cout<<"iveskite "<<i+1<<"-jo studento egzamino pazymi:\n";
    std::cin>>grupe[i].egzaminas;
    grupe[i].galutinis=0.4*suma/10+0.6*grupe[i].egzaminas;
  }
  
  std::cout<<std::setw(15)<<"Vardas"<<std::setw(15)<<"Pavarde"<<std::setw(20)<<"Galutinis pazymys\n"<<"-----------------------------------------------------\n";//atspausdiname antraste

  for (auto &g:grupe)//foras skirtas duomenu isvedimui, automatiskai kintamajam priskiriama po viena elementa, kuris patalpintas masyve grupe; &-adresas (kad kiekviena kart nereiktu perrasinet kintamojo) i atitinkama elementa
  {
    
    print(g);
  }
};

void print(studentas g){

  

  

  std::cout<<std::setw(15)<<g.Vardas<<std::setw(15)<<g.Pavarde<<std::setw(15)<<std::setprecision(2)<<g.galutinis<<std::endl;//isvedame ats, setw reiskia tarpus tarp zodziu, endl uzbaigia viska.
  

}