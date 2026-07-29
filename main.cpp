#include <iostream>

char start_plane(){
    char plane_start;
    std::cout << "Welcome to flight simulator 1.0" << '\n';
    std::cout << "Start up plane? (Y/N)" << '\n';
    std::cin >> plane_start;

    return plane_start;

}

void error(std::string s){
    throw std::runtime_error{s};
}

class Plane{
    public:
        double get_speed();
        double set_speed(double s);
        double speed_controller(char input);
        
        double get_heading();
        double set_heading(double h);

        double get_altitude();
        double set_altitude(double a);

        Plane(double s, double h, double a) :speed{s}, heading{h}, altitude{a}{}


    private: // Plane state
        double speed;
        double heading;
        double altitude;
};

//Altitude Methods

double Plane::get_altitude(){
    return altitude;

}
double Plane::set_altitude(double a){
    altitude = a;
    return altitude;

}


//Heading Methods
double Plane::get_heading(){
    return heading;

}
double Plane::set_heading(double h){
    heading = h;
    return h;

}

//Speed Methods

double Plane::get_speed(){
    return speed;
}

double Plane::set_speed(double s){
        speed = s;
        return speed;
}

double Plane::speed_controller(char i){
    if (i == 'w' || i == 'W'){
        return 1;
    }
    else if (i == 's' || 'S')
        return -1;
    else{
        error("Not a valid input");
    }
}


int main(){
// need to organize this into seperate functions
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
    

    for(char c; std::cin >> c;){
        switch (c)
        {
            case 'w':{
                double new_speed = 0;
                new_speed = p1.get_speed() + (p1.speed_controller(c));
                p1.set_speed(new_speed);
                break;
            }
            case 's':{
                double new_speed = 0;
                new_speed = p1.get_speed() + (p1.speed_controller(c));
                p1.set_speed(new_speed);
                break;
            }
            default:
                break;
        }
    }

    std::cout << "SPEED: " << p1.get_speed() << '\n';

    
    
}