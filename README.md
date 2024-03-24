# sadET
<img align="right" src="https://github.com/dkaramit/SAD_ET/blob/logo/sadETlogo-small.png">

![](https://img.shields.io/badge/language-C++-black.svg)  ![](https://tokei.rs/b1/github/dkaramit/SadET)
  
![](https://img.shields.io/github/repo-size/dkaramit/sadET?color=blue)


sadET is a C++ library for automatic differentiation using expression templates. It provides a simple (and sometimes efficient) way to compute derivatives of mathematical expressions.
The good thing about expresison templates is that the mathematical expressions and their derivatives are constructed at compile-time, while their numerical evaluation is occurres at 
run-time on demand (sort of lazy evaluation).


## Current Features

- Supports basic arithmetic operations: addition, subtraction, multiplication, division, and power
- Supports unary operations: negative, exponential, logarithm, and trigonometric functions (sin, cos)
- Allows the creation of variables and constants
- Provides functions to evaluate expressions and compute derivatives

## Usage

To use the sadET library, include the `sadET.hpp` header file in your C++ code:

```cpp
#include <sadET.hpp>
```

Use `Constant<numType,value>` to declare constants and `Variable<ID,numType>` to decalre variables. Example:
```cpp
sadET::Constant<long double, 0.4> c;
sadET::Variable<0, double> x;
sadET::Variable<1, double> y;
```
Due to the powerful type-deduction that C++ offers, you only need to declare types of your cponstants and variables, and the cpmpiler will figure it out. Consider this:
```c++
sadET::Constant<long double, 0.4> c;
sadET::Variable<0, double> x;
auto f = pow(x,c);
```
Here, `f` automatically is an instance of `sadET::Pow<sadET::Variable<0, double>, sadET::Constant<long double, 0.4>>`. However, all numerical operations will return `long double`, since it is their "biggest" common type.

You can simply use the `evaluate` function to get the value of an expression, and `derivative` to get its derivative. For example:

```cpp
#include<iostream>
#include<sadET.hpp>


using std::cout;
using std::map;

using sadET::IDType;
using sadET::Constant;
using sadET::Variable;

int main(){
    Constant<long double,0.4> c;
    Variable<0,double> x;
    Variable<1,double> y;

    map<IDType,long double> at= {{x.getID(),0.2},{y.getID(),0.8}} ;

    //note that c++ can figure out that evaluate and derivative belong to sadET!
    cout<<evaluate( derivative( sin(x) * cos(y) + pow( x, sin(y+c) ) ,  x,y ) , at )<<"\n";

    return 0;
}
```


For full examples, see the `Examples` directory. I hope to continue adding new features, so keep an eye on this repo.


# Work in progress... What I want to add in the near future:
- Sort variables wrt ids's in operators. This may help you simplify things. 
- Define Sum and Product for many variables (e.g. `Sum<expr, restExpr...>`) recursively, but with expressions ordered in some way.
- Simplification rules. This feels harder, due to the heuristic nature of the subject.

***If you know how to do these things, and like `sadET`, let me know, dkarami@yahoo.com.*** 