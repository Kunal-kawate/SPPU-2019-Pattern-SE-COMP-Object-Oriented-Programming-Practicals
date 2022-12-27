/*
Write a function template selection Sort. Write a program that inputs, sorts and outputs
an integer array and a float array.
*/

#include <iostream>
using namespace std;
# define SIZE 50
template<class T>

void selectionSort(T x[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(x[i]>x[j]){
                T temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
}

int main(){
    int A[SIZE],n1,n2;
    float B[SIZE];
    bool condition=true;
    while(condition){
        int choice;
        cout<<"\n-----------------MENU----------------\n1)Add Integers.\n2)Add Float\n3)Sort Integers.\n4)Sort Float\n5)Display Integers.\n6)Display Float\n7)Exit"<<endl;
        cout<<"Enter your choice(form 1 to 7): ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter the total number of int elements: ";
                cin>>n1;
                for(int i=0;i<n1;i++){
                    cin>>A[i];
                }
                break;
            case 2:
                cout<<"\nEnter the total number of float elements: ";
                cin>>n2;
                for(int j=0;j<n2;j++){
                    cin>>B[j];
                }
                break;
            case 3:
                selectionSort(A,n1);
                cout<<"\nSort operation is Done!!!"<<endl;
                break;
            case 4:
                selectionSort(B,n2);
                cout<<"\nSort operation is Done!!!"<<endl;
                break;
            case 5:
                cout<<"\nInt elements are:"<<endl;
                for(int p=0;p<n1;p++){
                    cout<<" "<<A[p];
                }
                cout<<endl;
                break;
            case 6:
                cout<<"\nFloat elements are:"<<endl;
                for(int q=0;q<n1;q++){
                    cout<<" "<<B[q];
                }
                cout<<endl;
                break;
            case 7:
                condition=false;
                cout<<"\nThank you for using this program.......\n"<<endl;
                break;
            default:
                cout<<"\nPlaese Enter the Valid Choice!!!!"<<endl;
        }
    }
    return 0;
}
