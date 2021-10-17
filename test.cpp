#include <iostream>
#include <cstring>
class Bicycle
{
    public:
        Bicycle(int initialSpeed);
        ~Bicycle();
        int getSpeed();
        void setSpeed(int speed);
        void pedal();
        void brake();
        
    private:
        int speed;
};

// constructor for the object
Bicycle::Bicycle(int initialSpeed)
{
    setSpeed(initialSpeed);
}

// destructor for the object
Bicycle::~Bicycle()
    {
    // do nothing
    }
    
// get the trike's speed
int Bicycle::getSpeed()
{
    return speed;
}

// set the trike's speed
void Bicycle::setSpeed(int newSpeed)
{
    if (newSpeed >= 0)
    {
        speed = newSpeed;
    }
}

// pedal the trike
void Bicycle::pedal()
{
    setSpeed(speed + 1);
    std::cout << "\nPedaling; bicycle speed " << getSpeed() << " mph\n";
}

// apply the brake on the trike
void Bicycle::brake()
{
    setSpeed(speed - 1);
    std::cout << "\nBraking; bicycle speed " << getSpeed() << " mph\n";
}

auto add(int x, int y){

    return(x+y);
}

auto *cat_str(const char *c1, const char *c2){
    char *ptr = NULL;

    ptr = (char *) malloc(strlen(c1)+strlen(c2)+1);
    strncpy(ptr, c1, strlen(c1) );
    strncpy(ptr+ strlen(c2), c2, strlen(c2) );
    ptr[strlen(c1)+strlen(c2)] = 0;
    return ptr;
}

int main()
{
    char *ptr=NULL;
    int nums[5] = {1,2,3,4,5};
    auto s=100;
    ptr = cat_str("Hello", "World");
    for ( int n: nums ){
        s = add(s, n);
        std::cout << s << ' ';
    }
    std::cout << ptr << s << "\n";
    free(ptr);
    
    Bicycle bike(5);

    bike.pedal();
    bike.pedal();
    bike.brake();
    bike.brake();
    bike.brake();
    return 0;
}
