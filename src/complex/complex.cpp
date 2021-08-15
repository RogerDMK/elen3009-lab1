#include <iostream>
#include <complex>
#include <cmath>
//Exercise 3.3
using namespace std;
using complx = complex<float>;

void printRealAns(auto &a,auto &b,auto &disc)
{
    auto ans1 = ((-1*b)+sqrt(disc))/(2*a); //Qaudratic formula (first root)
    auto ans2 = ((-1*b)-sqrt(disc))/(2*a); //Qaudratic formula (second root)
    cout<<"x = " <<ans1<<" or "<<" x = "<<ans2<<endl<<endl;
}

void printComplexAns(auto &a,auto &b,auto &disc)
{
    auto ans = complx{(-1*b)/(2*a),(-1*disc)/(2*a)}; //Gives the complex answer after simplification

    cout <<"x = "<< ans.real()<<" + "<<ans.imag()<<"j"<<" or x = " <<ans.real()<<" - "<<ans.imag()<<"j"<<endl<<endl;
}

int main()
{
    auto a=0.0f,b=0.0f,c=0.0f,disc=0.0f;
    auto key=' ';

    while(key!='q')
    {
        cout << "Enter a,b and c"<<endl;
        cin >>a>>b>>c;
        cout <<endl;

        disc = pow(b,2)-4*a*c; //Calculates the discriminant

        if(disc>0)
        {
           printRealAns(a,b,disc); //Prints the real answer if discriminant is positive
        }

        else if(disc<0)
        {
           printComplexAns(a,b,disc); //Prints the complex answer if discriminant is negative
        }

        cout<<"Do you wish to do another calculation? Press q to quit or an other key to continue"<<endl;
        cin>>key;
        cout<<endl;

    }

return 0;
}

