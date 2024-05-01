#include<iostream>
#include<map>
using namespace std;

struct CityRecord{
    string Name;
    long Population;
    
};

int main(){
    map<string,CityRecord> CityMap;
    
    CityMap["Delhi"] = CityRecord{"Delhi",1000000};
    CityMap["London"] = CityRecord{"London",800000};
    CityMap["Dusseldorf"] = CityRecord{"Dusseldorf",700000};
    CityMap["Berlin"] = CityRecord{"Berlin",600000};

    CityRecord berlindata = CityMap["Berlin"];
    
    cout<<berlindata.Population<<endl;
    return 0;
}