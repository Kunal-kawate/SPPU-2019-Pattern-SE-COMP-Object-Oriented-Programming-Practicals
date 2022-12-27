/*
Write a C++ program that creates an output file, writes information to it, closes the file
andopen it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;
class Employee{
    private:
        string name;
        string id;
        float salary;
    
    public:
        void setInfo(void){
            cin.ignore();
            cout<<"Enter the name of Employee: ";
            getline(cin,name);
            cin.ignore();
            cout<<"Enter the ID of Employee: ";
            cin>>id;
            cout<<"Enter the Salary of Employee: ";
            cin>>salary;
        }

        void saveInfo(void){
            fstream myFile;
            myFile.open("myText.txt",ios::app);
            myFile<<"\nEmployee Name: "<<name<<endl;
            myFile<<"Employee ID: "<<id<<endl;
            myFile<<"Employee salary: "<<salary<<endl;
            myFile.close();
        }

        void getInfo(void){
            string data;
            fstream myFile;
            myFile.open("myText.txt");
            cout<<"\nEmployee Data: "<<endl;
            while(myFile){
                getline(myFile,data);
                cout<<data<<endl;
            }
        }
};

int main(){
    ofstream myFile("myText.txt"); // to clear previous data.
    myFile.close();                //

    Employee obj;
    int n;
    cout<<"\nEnter the numbers of Employee: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nEmployee No. "<<i+1<<" : "<<endl;
        obj.setInfo();
        obj.saveInfo();
    }
    obj.getInfo();
    return 0;
}
