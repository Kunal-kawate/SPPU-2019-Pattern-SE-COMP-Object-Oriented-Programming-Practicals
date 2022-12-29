/*
Write a program in C++ to use map associative container. The keys will be the names of
states, and the values will be the populations of the states. When the program runs, the
user is prompted to type the name of a state. The program then looks in the map, using
the state name as an index, and returns the population of the state.
*/

#include <iostream>
#include <map>
using namespace std;
int main(){
    int condition=true;
    int choice;
    string stateName;
    map<string , int> populationMap;

    populationMap["maharshtra"]= 98;
    populationMap["Uttar Pradesh"]= 10;
    populationMap["Bihar"]= 20;
    populationMap["West Bengal"]= 15;
    populationMap["Madhya Pradesh"]= 88.63;
    populationMap["Tamil Nadu"]= 60.0;
    populationMap["Rajasthan"]= 55.2;
    populationMap["Andhra Pradesh"]= 69.0;
    populationMap["Odisha"]= 34.1;
    populationMap["Kerala"]= 45.8;
    populationMap["Telangana"]= 25.0;
    populationMap["Assam"]= 12;
    populationMap["Jharkhand"]= 9.8;
    populationMap["Karnataka"]= 68;

    map<string ,int>:: iterator iter;
    cout<<"\n---------------------------------State Names--------------------------------\n"<<endl;
    for(iter=populationMap.begin();iter!=populationMap.end();iter++){
        cout<<(*iter).first<<endl;
    }
    // cout<<"\n------------------------------------------------------------------------------\n"<<endl;
    while(condition){
        cout<<"\n----------------MENU----------------\n1)See Population\n2)Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cin.ignore();
                cout<<"\nEnter that state name you want to know population: ";
                getline(cin,stateName);
                cout<<"\nState: "<<stateName<<" Population: "<<populationMap.find(stateName)->second<<" Million"<<endl;
                break;
            case 2:
                condition=false;
                cout<<"\nThank You for using this program.....\n"<<endl;
                break;
            default:
                cout<<"\nPlease Enter Valid Choice!!"<<endl;
        }
    }
    return 0;
}
