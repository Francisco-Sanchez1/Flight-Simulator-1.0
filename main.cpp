#include <iostream>

char start_plane(){
    char plane_start;
    std::cout << "Welcome to flight simulator 1.0" << '\n';
    std::cout << "Start up plane? (Y/N)" << '\n';
    std::cin >> plane_start;

    return plane_start;

}

class Plane{
    public:
        void get_speed();
        double set_speed(double s);
        
        void get_heading();
        double set_heading(double h);

        void get_altitude();
        double set_altitude(double a);

        Plane(double s, double h, double a) :speed{s}, heading{h}, altitude{a}{}


    private: // Plane state
        double speed;
        double heading;
        double altitude;
};

//Altitude Methods

void Plane::get_altitude(){
    std::cout << altitude << '\n';

}
double Plane::set_altitude(double a){
    altitude = a;
    return altitude;

}


//Heading Methods
void Plane::get_heading(){
    std::cout << heading << '\n';

}
double Plane::set_heading(double h){
    heading = h;
    return h;

}

//Speed Methods

void Plane::get_speed(){
    std::cout << speed << '\n';

}

double Plane::set_speed(double s){
        speed = s;
        return speed;
}


int main(){
    char plane_start;
    double speed;
    double heading;
    double altitude;


    //Welcome message
    plane_start = start_plane();
    
    if (plane_start == 'N'){
       return 0;
    }

    std::cout << "Please enter Speed: " << '\n';
    std::cin >> speed;

    std::cout << "Please enter heading direction: " << '\n';
    std::cin >> heading;

    std::cout << "Please enter altitude: " << '\n';
    std::cin >> altitude;
    
    
    Plane p1(speed, heading, altitude);

    std::cout << '\n' << '\n';

    p1.get_speed();
    p1.set_speed(4343);
    p1.get_speed();

    p1.get_altitude();
    p1.set_altitude(999);
    p1.get_altitude();

    p1.get_heading();
    p1.set_heading(34.54545);
    p1.get_heading();
    
}