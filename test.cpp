
#include <iostream>

/*** class ***/
class Man
{
public:
    int age;
    Man();           // constructor
    Man(Man &p); // copy constructor
    ~Man();          // destructor
};

Man::Man()
{
    this->age = 50;
    std::cout << "  Man's Constructor()..." << this << "\n";
}

Man::Man(Man &p)
{
    this->age = 60;
    std::cout << "  Man's Copy Constructor() ..." << this << "\n";
}

Man::~Man()
{
    this->age = 0;
    std::cout << "  Man's Destructor() ..." << this << "\n";
}

/*** functions ***/
// passes by value
Man func_val(Man p)
{
    std::cout << "  func_val() returns an object copied from" << &p << ",age=" << p.age << "\n";
    return p;
}

// functionTwo, passes by reference
Man *func_ref(Man *p)
{
    std::cout << "  func_ref() returns a pointer " << p << ",age=" << p->age << "\n";
    return p;
}

int main()
{
    std::cout << "Making a jerry ..." << std::endl;
    Man jerry;
    std::cout << "jerry's age=" << jerry.age << "\n"; 
    std::cout << "Making a person ..." << std::endl;
    Man person;
    std::cout << "person's age=" << person.age << "\n"; 
    Man *man_ptr=nullptr;
    std::cout << "Calling func_val(jerry) ..." << std::endl;
    person = func_val(jerry);
    std::cout << "person's age=" << person.age << "\n"; 
    std::cout << "Calling func_ref(&jerry) ..." << std::endl;
    man_ptr = func_ref(&jerry);
    std::cout << "man_ptr's age=" << man_ptr->age << "\n"; 
    std::cout << "End\n";
    return 0;
}
