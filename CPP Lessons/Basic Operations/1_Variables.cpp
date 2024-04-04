#include <iostream>


namespace first{
    int x = 1;
}

int main(){
    int x ; // decleration
    x = 5; // assignment

    int y = 7; // decleration and assignments

    std :: cout << x << std::endl;
    std :: cout << x + y<< std::endl;
    std :: cout << y << std::endl;  
    
    int num;
    double fiyat ;
    char grade;
    bool power;
    std::string name;

    /* ---------------------------------------------------- */

    //the contant keyword pecifies that a variable's value is constant
    // tells the compiler to prevent anything from modifying it.
    //(read only)

    const double PI = 3.14159; // const variable names has to be uppercase
    double radius = 10;
    double circumference = 2 * PI * radius;

    std::cout<< circumference<<"cm \n"; 
    /*-----------------------------------------------------------*/
    /*
        Namespaces = provides a solution for preventing name conflicts in 
        large projects. Each entity needs a unique name.
        A namespace allows for identically named entities as long as the
        namespaces are different
    */
   std:: cout<< x <<" = local x variable\n";
   std:: cout<< first::x <<" = namespace x variable \n";

    using namespace first; // gotta be used on top of the function
    std:: cout<< x <<" namespace variable but different usage \n";

    using namespace std; // this type of usage saves us time because we are no longer need to type std everytime we declare string or just printing stuff.
    cout<<x ;
    using std::cout; // only applies to cout we still have to use it for strings etc.

    //32:15 de kaldim



    return 0; 
}
