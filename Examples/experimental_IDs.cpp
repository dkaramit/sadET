#include<iostream>
#include<cmath>
#include<functional>

#include<sadET.hpp>
#include<experimental/new_variable.hpp>


using std::cout;
using std::endl;
using sadET::evaluate;
using sadET::derivative;


int main(){
    auto x=sadET::new_variable<double>();
    auto y=sadET::new_variable<double>();

    cout<<x.getID()<<endl;
    cout<<y.getID()<<endl;


    return 0;
}