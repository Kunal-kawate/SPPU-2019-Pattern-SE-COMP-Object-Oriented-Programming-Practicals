/*
Imagine a publishing company which does marketing for book and audio cassette
versions. Create a class publication that stores the title (a string) and price (type float) of
a publication.
From this class derive two classes: book, which adds a page count (type int), and tape,
which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data
and displays the data members. If an exception is caught, replace all the data member
values with zero values.
*/

#include <iostream>
using namespace std;

class publication{
    private:
        string title;
        float price;
    
    public:
        publication(){
            title="-";
            price=0.0;
        }

        void setHeading(void){
            cin.ignore();
            cout<<"\nEnter the Title: ";
            getline(cin,title);
            cout<<"Enter the Price: ";
            cin>>price;
        }

        void displayHeading(void){
            cout<<"\nTitle: "<<title<<endl;
            cout<<"Price: "<<price<<endl;
        }
};

class book: public publication{
    private:
        int pagecount;
    public:
        book(){
            pagecount=0;
        }

        void setBookInfo(void){
            publication::setHeading();
            cout<<"Enter the page count: ";
            cin>>pagecount;
        }

        void displayBookInfo(void){
            publication::displayHeading();
            try{
                if(pagecount<0){
                    throw pagecount;
                }
                else{
                    cout<<"Pages are: "<<pagecount<<endl;
                }
            }catch(int pagecount){
                cout<<"Pages are: (ERROR) Invalid Count!!!"<<endl;
            }
        }
};

class tape: public publication{
    private:
        float playingTime;
    public:
        tape(){
            playingTime=0.0;
        }

        void setTapeInfo(void){
            publication::setHeading();
            cout<<"Enter the play time of tape: ";
            cin>>playingTime;
        }

        void displayTapeInfo(void){
            publication::displayHeading();
            try{
                if(playingTime<0){
                    throw playingTime;
                }
                else{
                    cout<<"Playing Time: "<<playingTime<<endl;
                }
            }catch(float playingTime){
                cout<<"Playing Time: (ERROR) Invalid Playing Time!!!"<<endl;
            }
        }

};
int main(){
    book obj1[10];
    tape obj2[10];

    int bookcount=0;
    int tapecount=0;

    bool condition=true;
    int choice;

    while(condition){
        cout<<"\n--------------------MENU---------------------\n1)Add Book\n2)Add Tape\n3)Display Books\n4)Display Tapes\n5)Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                obj1[bookcount].setBookInfo();
                bookcount++;
                break;
            case 2:
                obj2[tapecount].setTapeInfo();
                tapecount++;
                break;
            case 3:
                cout<<"\n--------------------Books----------------------"<<endl;
                for(int i=0;i<bookcount;i++){
                    obj1[i].displayBookInfo();
                }
                break;
            case 4:
                for(int j=0;j<tapecount;j++){
                    obj2[j].displayTapeInfo();
                }
                break;
            case 5:
                condition=false;
                cout<<"\nThank You for using this program....\n"<<endl;
                break;
            default:
                cout<<"\nPlease Enter valid Choice!!!"<<endl;
        }
    }
    return 0;
}
