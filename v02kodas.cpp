#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
#include <chrono>
#include <sstream>
#include <fstream>
#include <iterator>

struct studentas{
  std::string Vardas, Pavarde;
  std::vector<float> nd;
  std::vector<int> paz = { 0 };
  float galutinis;//naudijamas vidurkiui apskaiciuot
  float medgalutinis;
  float egzaminas;
};

void print(studentas);//apibreziam ka naudojam, kad f-ja is anksto zinotu
double mediana(std::vector<float> &vec);//&- ne kopijuoja o tik naudojasi duomenimis, priskyrimas
void Nuskaitymas(std::vector<studentas>& Eil, int* pazymiu_sk);//duomenu is failo nuskaitymas
void Spausdinimas(std::vector<studentas> Eil, int pazymiu_sk);//duomenu is failo spausdinimas


int Random() //sugeneruoja random skaiciu nuo 1 iki 10
{
  srand(time(NULL));
  return rand() % 10 + 1;
}

int main(){
  std::cout<<"Jei norite, kad pazymiai uz namu darbus butu suvesti automatiskai iveskite 1, jei norite pazymius suvesti patys iveskite 2, jei norite pazymius nuskaityti is failo iveskite 3:\n";
  int a;
  std::cin>>a;

  if(a==3){
    int pazymiu_sk;
    char temp;
    std::vector<studentas> Eil;
    Nuskaitymas(Eil, &pazymiu_sk);
    Spausdinimas(Eil, pazymiu_sk);
    system("pause");
    return 0;
  }
  
  std::cout <<"Iveskite studentu skaiciu"<< std::endl;
  int n;
  std::cin>>n;

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
    if(a==2){//nd suvesti ranka
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

    tempas.galutinis =0.4*vid+0.6*tempas.egzaminas;
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

float count_median(std::vector<int> pazymiai){ //funkcija suskaiciuoja mediana
  int counter = 0;
  for (int i = 0; i < 10; i++){
    if (pazymiai[i] != 0){
      counter++;
    }
    if (pazymiai[i] == -1){
      pazymiai[i] = 0;
      counter--;
      break;
    }
  }
  if (counter % 2 == 0){
    return float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
  else{
    return float(pazymiai[(counter / 2)]);
  }
}

void Spausdinimas(std::vector<studentas> Eil, int pazymiu_sk){ //atspausdina rezultatus
  std::ofstream output;
  output.open("rezultatai.txt");
  output << std::setw(20) << std::left << "Vardas"<< std::setw(20) << std::left << "Pavarde"<< std::setw(18) << std::left << "Galutinis(vid.)/"<< std::left << "Galutinis(med.)\n"<< "--------------------------------------------------------------------------\n";
  for (int i = 0; i < Eil.size(); i++){
    output << std::setw(20) << std::left << Eil[i].Vardas<< std::setw(20) << std::left << Eil[i].Pavarde<< std::setw(18) << std::left << Eil[i].galutinis<< count_median(Eil[i].paz)<< std::endl;
  }
  output << "\n\n";
}

unsigned int countWordsInString(std::string const& str){
  std::stringstream stream(str);
  return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void Nuskaitymas(std::vector<studentas>& Eil, int* pazymiu_sk)
{
  int student_counter = 0;
  int temp;
  std::ifstream fileRead;
  std::string buff;
  fileRead.open("kursiokai.txt");
  if (fileRead.is_open()){
    getline(fileRead >> std::ws, buff);
    *pazymiu_sk = countWordsInString(buff) - 3;
     while (true){
      Eil.resize(Eil.size() + 1);
      fileRead >> Eil.at(student_counter).Vardas;
      if (fileRead.eof()) { Eil.pop_back(); break; }
      fileRead >> Eil.at(student_counter).Pavarde;
      for (int i = 0; i < *pazymiu_sk; i++){
        fileRead >> temp;
        Eil.at(student_counter).paz.push_back(temp);
      }
      fileRead >> Eil.at(student_counter).egzaminas;
      Eil.at(student_counter).galutinis = Eil.at(student_counter).galutinis / *pazymiu_sk;
      Eil.at(student_counter).galutinis = Eil.at(student_counter).galutinis * 0.4 + 0.6 * Eil.at(student_counter).egzaminas;
      student_counter++;
    }
    fileRead.close();
    std::cout<<"\nApskaiciuoti studentu rezultatai pateikti atskirame rezultatai.txt faile\n\n";
  }
  else { std::cout << "\n nepavyko atidaryti failo \n\n"; }
};

