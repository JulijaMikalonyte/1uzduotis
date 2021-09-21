#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

struct studentas{//aprasom ka naudosim
  std::string Vardas, Pavarde;
  std::vector<float> nd;//skaiciavimui su mediana
  float galutinis;//skaicius per kableli, skaiciuojama pagal vidurki
  float medgalutinis;
  float egzaminas;
};

void print(studentas);
double mediana(std::vector<float> &vec);

int main(){
  std::cout <<"Iveskite studentu skaiciu"<< std::endl;
  int n;
  std::cin>>n;

  std::vector<studentas> grupe;//skaiciavimui su mediana
  studentas tempas;  // pakeist zodi tempas-----------------------------------------------
  grupe.reserve(n);

  float suma=0, laik, vid, med;//reikalinga apskaiciuoti vidurki
  
  for (int i=0; i<n; i++)
  {
    std::cout<<"Iveskite "<<i+1<<"-jo studento varda:\n";
    std::cin>>tempas.Vardas;

    std::cout<<"Iveskite "<<i+1<<"-jo studento pavarde:\n";
    std::cin>>tempas.Pavarde;

    std::cout<<"Iveskite studento gautus pazymius uz namu darbus, suvedus visus pazymius ivekite bruksni:\n";

    suma=0;

    while(std::cin>>laik)
    {
      tempas.nd.push_back(laik);
      suma=suma+laik;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout<<"Iveskite "<<i+1<<"-jo studento egzamino pazymi:\n";
    std::cin>>tempas.egzaminas;

    vid=std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0.0)/tempas.nd.size();

    med=mediana(tempas.nd);
    tempas.medgalutinis=med;

    tempas.galutinis=0.4*vid+0.6*tempas.egzaminas;
    grupe.push_back(tempas);
    tempas.nd.clear();
  }
  std::cout<<"Jei norite, kad studentu galutiniai pazymiai butu suskaiciuoti pagal vidurki, iveskite 1, jei pagal mediana iveskite 2:"<<std::endl;
  int pasirinkimas;
  std::cin>>pasirinkimas;


  std::cout<<std::setw(15)<<"Vardas"<<std::setw(15)<<"Pavarde"<<std::setw(20)<<"Galutinis pazymys\n"<<"-----------------------------------------------------\n";//atspausdiname antraste

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
    std::cout<<std::setw(15)<<g.Vardas<<std::setw(15)<<g.Pavarde<<std::setw(15)<<std::setprecision(2)<<g.galutinis<<std::endl;//isvedame ats, setw reiskia tarpus tarp zodziu, endl uzbaigia viska.
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