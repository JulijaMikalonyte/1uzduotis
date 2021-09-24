#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
#include <chrono>

struct studentas{
  std::string Vardas, Pavarde;
  std::vector<float> nd;
  float galutinis;//naudijamas vidurkiui apskaiciuot
  float medgalutinis;
  float egzaminas;
};

void print(studentas);//apibreziam ka naudojam, kad f-ja is anksto zinotu
double mediana(std::vector<float> &vec);//&- ne kopijuoja o tik naudojasi duomenimis, priskyrimas

int Random() //sugeneruoja random skaiciu nuo 1 iki 10
{
  srand(time(NULL));
  return rand() % 10 + 1;
}

int main(){
  std::cout<<"Jei norite, kad pazymiai uz namu darbus butu suvesti automatiskai iveskite 1, jei norite pazymius suvesti patys iveskite 2:\n";
  int a;
  std::cin>>a;

  std::cout <<"Iveskite studentu skaiciu"<< std::endl;
  int n;
  std::cin>>n;

  if(isdigit(n)!=true){
    std::cout<<"ivedimo klaida, bandykite dar karta\n";
    std::cin>>(a);
  }

  std::vector<studentas> grupe;
  studentas tempas;
  grupe.reserve(n);

  float suma=0, laik, vid, med;
  
  for (int i=0; i<n; i++)//info surinkimas
  {
    std::cout<<"Iveskite "<<i+1<<"-jo studento varda:\n";
    std::cin>>tempas.Vardas;

    std::cout<<"Iveskite "<<i+1<<"-jo studento pavarde:\n";
    std::cin>>tempas.Pavarde;

    if(a==1){//nd atsitiktiniai
      tempas.egzaminas = Random();
      int k=0;
      while(k<5){
        tempas.nd.push_back(Random());
        k=k+1;
      }
    }
    else{//nd suvesti ranka
      std::cout<<"Iveskite studento gautus pazymius uz namu darbus, suvedus visus pazymius ivekite bruksni:\n";

      suma=0;

      while(std::cin>>laik){
        tempas.nd.push_back(laik);
        suma=suma+laik;
      }
    
    std::cin.clear();//ignoruoja bloga ivesti
    std::cin.ignore(10000, '\n');//ignoruoja ivesties paskutini n-taji

    std::cout<<"Iveskite "<<i+1<<"-jo studento egzamino pazymi:\n";
    std::cin>>tempas.egzaminas;
    }
    vid=std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0.0)/tempas.nd.size();//acc-susumuoja nuo pirmo iki paskutinio vektoriaus elemento

    med=mediana(tempas.nd);
    tempas.medgalutinis=med;

    tempas.galutinis=0.4*vid+0.6*tempas.egzaminas;
    grupe.push_back(tempas);
    tempas.nd.clear();
  }
  std::cout<<"Jei norite, kad studentu galutiniai pazymiai butu suskaiciuoti pagal vidurki, iveskite 1, jei pagal mediana iveskite 2:"<<std::endl;
  int pasirinkimas;
  std::cin>>pasirinkimas;

  std::cout<<std::setw(15)<<"Vardas"<<std::setw(15)<<"Pavarde"<<std::setw(20)<<"Galutinis pazymys\n"<<"-----------------------------------------------------\n";

  if(pasirinkimas==1){
    for (const auto &g:grupe){
      print(g);}
  }
  else{
    for (const auto &g:grupe){
      std::cout<<std::setw(15)<<g.Vardas<<std::setw(15)<<g.Pavarde<<std::setw(15)<<std::setprecision(2)<<g.medgalutinis<<std::endl;
    }
  }
}

void print(studentas g){
    std::cout<<std::setw(15)<<g.Vardas<<std::setw(15)<<g.Pavarde<<std::setw(15)<<std::setprecision(2)<<g.galutinis<<std::endl;
}

double mediana(std::vector<float> &vec){
  typedef std::vector<float>::size_type vecSize;
  vecSize size=vec.size();
  if (size==0)
    throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
  sort(vec.begin(), vec.end());
  vecSize vid=size/2;
  return size%2==0?(vec[vid]+vec[vid-1])/2:vec[vid];
}