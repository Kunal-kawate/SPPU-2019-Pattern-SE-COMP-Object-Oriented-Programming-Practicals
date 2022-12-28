/*
Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. and other.
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete.
*/

#include <iostream>
using namespace std;
class student{
    private:
        string* contactAddress=new string();
        int* telephoneNo= new int();
        string dlno;
    
    public:
        student(){
            *contactAddress="-----------";
            *telephoneNo=000000;
            dlno="0000-0000-000";
        }
        ~student(){
            delete contactAddress;
            delete telephoneNo;
        }
        void getStudentInfo(void){
            cout<<"Enter student contact address: ";
            cin.get();
            getline(cin,*contactAddress);
            cout<<"Enter student telephone No. : ";
            cin>>*telephoneNo;
            cout<<"Enter student driving licence No. : ";
            cin.get();
            cin>>dlno;
        }

        void displayStudentInfo(void){
            cout<<"Contact address: "<<*contactAddress<<endl;
            cout<<"Tele-phone No.: "<<*telephoneNo<<endl;
            cout<<"Driving Licence No.: "<<dlno<<endl;
        }
};

class studentDataBase{
    private:
        string* name=new string();
        string rollno;
        string sclass;
        char *division=new char();
        string dob;
        string bg;
        static int count;
        friend class student;

    public:
        studentDataBase(){
            *name="unknown";
            rollno="00";
            sclass='X';
            *division='x';
            dob="DD/MM/YY";
            bg="+X";
        }
        ~studentDataBase(){
            delete name;
            delete division;
        }

        void getDataBase(student* obj){
            cout<<"\nEnter Student name: ";
            getline(cin,*name);
            cout<<"Enter Student Roll No. : ";
            cin>>rollno;
            cout<<"Enter Student class: ";
            cin.get();
            getline(cin,sclass);
            cout<<"Enter Student division: ";
            cin>>*division;
            cout<<"Enter Student Data of Birth: ";
            cin.get();
            getline(cin,dob);
            cout<<"Enter Student Blood Group: ";
            cin>>bg;
            count++;
            obj->getStudentInfo();
        }

        void displayStudentDataBase(student* obj){
            cout<<"\nName: "<<*name<<endl;
            cout<<"Division: "<<*division<<endl;
            cout<<"Date of Birth: "<<dob<<endl;
            cout<<"Blood Group: "<<bg<<endl;
            obj->displayStudentInfo();
        }

        inline void displayCount(void){
            cout<<"Total number of students : "<<count<<endl;
        }


};

int studentDataBase::count;

int main(){
    char choice;
    studentDataBase* obj1[100];
    student* obj2[100];
    int n=0;
    do{
        obj1[n]=new studentDataBase;
        obj2[n]=new student;
        obj1[n]->getDataBase(obj2[n]);
        n++;

        cout<<"\nDo you want enter another student info(y/n): ";
        cin>>choice;
        cin.get();
    }while(choice=='y'||choice=='Y');

    cout<<"\n-------------------Students Information---------------------"<<endl;
    for(int j=0;j<n;j++){
        obj1[j]->displayStudentDataBase(obj2[j]);
        cout<<"\n-------------------------------------------------------------\n"<<endl;
    }
    studentDataBase o1;
    o1.displayCount();
    cout<<"\n-------------------------------------------------------------\n"<<endl;
    
    for(int i=0;i<n;i++){
        delete obj1[i];
        delete obj2[i];
    }
    cout<<"\nThank You for using this program.......\n"<<endl;
    return 0;
}
