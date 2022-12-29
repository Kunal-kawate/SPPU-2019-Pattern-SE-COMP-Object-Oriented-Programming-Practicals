/*
Write C++ program using STL for sorting and searching with user defined records such as
person record(Name, DOB, Telephone number), Item record (Item code, name,
cost,quantity) using vector container
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class student
{
private:
    string name;
    string dob;
    int telephoneNo;

public:
    void setData(void)
    {
        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter Date of Birth: ";
        cin >> dob;
        cout << "Enter Telephone No. : ";
        cin.get();
        cin >> telephoneNo;
    }

    void displayData(void)
    {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Telephone No. : " << telephoneNo << endl;
    }
};

int main()
{
    bool condition = true;
    int choice, n, rollno = 0, element;

    vector<int> v;
    vector<int>:: iterator it;

    student *obj[100];

    while (condition)
    {
        cout << "\n---------------------MENU---------------------\n1)Add Data\n2)Display Data\n3)Insert Data\n4)Find\n5)Delete Data\n6)Sort Data\n7)Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Number of students: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter Roll No. : ";
                cin >> rollno;
                cin.get();
                v.push_back(rollno);
                obj[rollno] = new student;
                obj[rollno]->setData();
            }
            break;
        case 2:
            cout << "\n-------------------------Data-------------------------" << endl;
            for (int j = 0; j < v.size(); j++)
            {
                element = v[j];
                cout << "\nRoll No. : " << element << endl;
                obj[element]->displayData();
            }
            break;
        case 3:
            it=v.end();
            cout << "\nEnter Roll No. : ";
            cin >> rollno;
            cin.get();
            v.insert(it,rollno);
            obj[rollno] = new student;
            obj[rollno]->setData();
            break;

        case 4:
            cout << "\nEnter Roll No. : ";
            cin >> rollno;
            if(binary_search(v.begin(),v.end(),rollno)){
                obj[rollno]->displayData();
            }else{
                cout<<"\nNot Found!!!\n"<<endl;
            }
            break;
        
        case 5:
            cout << "\nEnter Roll No. : ";
            cin >> rollno;
            if(binary_search(v.begin(),v.end(),rollno)){
                for(int k=0;k<v.size();k++){
                    if(rollno==v[k]){
                        int temp;
                        temp=v[0];
                        v[0]=v[k];
                        v[k]=temp;
                        v.erase(v.begin());
                        sort(v.begin(),v.end());
                        break; 
                    }
                }
            }else{
                cout<<"\nNot Found!!!\n"<<endl;
            }
            break;
  
        case 6:
            sort(v.begin(),v.end());
            cout<<"\nSorting Operation is Done.......\n"<<endl;
            break;

        case 7:
            condition = false;
            cout << "\nThank You for using this program...\n"<< endl;
            break;
        default:
            cout << "\nPlaese enter valid choice!!\n"<< endl;
        }
    }
    return 0;
}

