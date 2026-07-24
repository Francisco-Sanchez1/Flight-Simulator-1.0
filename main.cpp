#include <iostream>

class Plane{
    public:
        double speed;
        double heading;
        double altitude;
        Plane(double s, double h, double a) :speed{s}, heading{h}, altitude{a}{}
};

int main(){
    char plane_start;
    double speed;
    double heading;
    double altitude;


    //Welcome message
    std::cout << "Welcome to flight simulator 1.0" << '\n';
    std::cout << "Start up plane? (Y/N)" << '\n';
    std::cin >> plane_start;

    std::cout << "Please enter Speed: " << '\n';
    std::cin >> speed;

    std::cout << "Please enter heading direction: " << '\n';
    std::cin >> heading;

    std::cout << "Please enter altitude: " << '\n';
    std::cin >> altitude;


    if (plane_start == 'N'){
       return 0;

    }
    Plane p1 {speed, heading, altitude};

    std::cout << "Speed: " << p1.speed << '\n';
    std::cout << "Heading: " <<p1.heading << '\n';
    std::cout << "Altitude: " << p1.altitude << '\n';

    //initalize a plane
    



    std::cout << "Speed: " << p1.speed << '\n' << "Heading: " 
    << p1.heading << '\n' <<"Altitude: " << p1.altitude;
}