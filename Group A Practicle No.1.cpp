
/*
Implement a class Complex which represents the Complex Number data type. Implement
the following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to
print and read Complex Numbers.
*/

#include <iostream>
using namespace std;

class complex{
    private:
        int real;
        int img;
    public:
        complex(void){
            real=0;
            img=0;
        }
        complex(int x,int y){
            real=x;
            img=y;
        }

        complex operator +(complex obj3){
            complex temp;
            temp.real=real+obj3.real;
            temp.img=img+obj3.img;
            return temp;
        }

        complex operator *(complex obj3){
            complex temp;
            temp.real=real*obj3.real-img*obj3.img;
            temp.img=real*obj3.img+img*obj3.real;
            return temp;
        }

        void display(void){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
};

int main(){
    int p,q,r,s;
    cout<<"\nEnter your First complex number(a+ib):"<<endl;
    cin>>p>>q;
    cout<<"\nEnter your second complex number(a+ib): "<<endl;
    cin>>r>>s;

    complex obj1(p,q),obj2(r,s),obj3;

    obj3=obj1+obj2;
    cout<<"\nThe Addition is: "<<endl;
    obj3.display();

    obj3=obj1*obj2;
    cout<<"\nThe Multiplication is: "<<endl;
    obj3.display();
    return 0;
}
