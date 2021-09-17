#include <iostream>
#include <iomanip>
#include <string>

struct studentas{//aprasom ka naudosim
  std::string Vardas, Pavarde;
  int nd[10]={0};//sveikas skaicius
  int egzaminas;
  float galutinis;//skaicius per kableli
};

int main(){
  std::cout <<"Iveskite studentu skaiciu"<< std::endl;
  int n;//studentu skaicius
  std::cin>>n;
  studentas grupe[n];//studentas-naudojamas duomenu tipas kuri patys apsirasem, tokio tipo turesim grupe su n nariu
  for (int i=0; i<n; i++)//surenkam kiekvieno studento duomenis
  {
    std::cout<<"Iveskite "<<i+1<<"-jo studento varda:\n";
    std::cin>>grupe[i].Vardas;
    std::cout<<"Iveskite "<<i+1<<"-jo studento pavarde:\n";
    std::cin>>grupe[i].Pavarde;
    for (int j=0; j<10; j++)//surenkam kiekvieno studento pazymius
    {
      std::cout<<"Iveskite pazimi uz "<<j+1<<" namu darba:\n";
      std::cin>>grupe[i].nd[j];//pirmos gr 1-10 pazymai, antros ir t.t.
    }
    std::cout<<"iveskite "<<i+1<<"-jo studento egzamino pazymi:\n";
    std::cin>>grupe[i].egzaminas;

  }
};