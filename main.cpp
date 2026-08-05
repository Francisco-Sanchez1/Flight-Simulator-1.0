#include <iostream>
#include <SFML/Graphics.hpp>



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
        double heading_controller(char input);
        double heading_converter(double hc);

        double get_altitude();
        double set_altitude(double a);
        double altitude_controller(char input);

        Plane(double s, double a, double h) :speed{s}, altitude{a}, heading{h}{}


    private: // Plane state
        double speed;
        double heading;
        double altitude;
};

//Altitude Methods

double Plane::get_altitude(){
    if (altitude <= 0){
        error("Bro you crashed the $10B Plane");
    }
    return altitude;

}
double Plane::set_altitude(double a){
    altitude = a;
    
    return altitude;

}
double Plane::altitude_controller(char i){
    if (i == 'q' || i == 'Q'){
        return 1;
    }
    else if (i == 'e' || 'E')
        return -1;
    else{
        return 0;
    }
}


//Heading Methods
double Plane::get_heading(){
    return heading;

}
double Plane::set_heading(double h){
    heading = h;
    return h;

}
double Plane::heading_controller(char i){
    if (i == 'd' || i == 'D'){
        return 1;
    }
    else if (i == 'a' || 'A'){
        return -1;
    }
    else
    {
        return 0;
    }
    
}

double Plane::heading_converter(double hc){
    
    if(hc < 0){
        return (360 + (hc));
    }
    else if(hc >= 360){
        return ((hc) - 360);
    }
    else{
        return hc;
    }

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
        return 0;
    }
}

void display_cockpit(Plane &p){
    std::cout << "SPEED: " << p.get_speed() << '\n';
    std::cout << "ALTITUDE: " << p.get_altitude() << '\n';
    std::cout << "HEADING: " << p.get_heading() << '\n';
}


void external_window() {
    {
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Cockpit Simulator 1.0");
    
    
    sf::Font font;
    if (!font.openFromFile("/System/Library/Fonts/Helvetica.ttc")){
        std::cerr << "Failed to load font \n";
    }


    //Speed text
    sf::Text speed_text(font);
    speed_text.setString("Speed: ");
    speed_text.setCharacterSize(30);
    speed_text.setStyle(sf::Text::Bold);
    speed_text.setFillColor(sf::Color::Red);
    speed_text.setPosition({10.f,0});

    //Altitude text
    sf::Text altitude_text(font);
    altitude_text.setString("Altitude: ");
    altitude_text.setCharacterSize(30);
    altitude_text.setStyle(sf::Text::Bold);
    altitude_text.setFillColor(sf::Color::Blue);
    altitude_text.setPosition({10.f,50.f});


    //Heading text
    sf::Text heading_text(font);
    heading_text.setString("Heading: ");
    heading_text.setCharacterSize(30);
    heading_text.setStyle(sf::Text::Bold);
    heading_text.setFillColor(sf::Color::White);
    heading_text.setPosition({10.f,100.f});

    
    
    Plane p1(0,1,0); //speed, alt, heading
    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if(const auto* KeyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if(KeyPressed->scancode == sf::Keyboard::Scancode::W){ //speed
                    double new_speed = p1.get_speed() + (p1.speed_controller('W'));
                    p1.set_speed(new_speed);
                    std::cout << "W was pressed Speed is: " << p1.get_speed() << std::endl;
                    std::string speed_value = "Speed: " + std::to_string(p1.get_speed()); 
                    speed_text.setString(speed_value);
                    
                }
                else if(KeyPressed->scancode == sf::Keyboard::Scancode::S){//Speed
                    double new_speed = p1.get_speed() + (p1.speed_controller('S'));
                    p1.set_speed(new_speed);
                    std::cout << "S was pressed Speed is: " << p1.get_speed() << std::endl;
                    std::string speed_final_output = "Speed: " + std::to_string(p1.get_speed()); 
                    speed_text.setString(speed_final_output);
                    
                }
                else if(KeyPressed->scancode == sf::Keyboard::Scancode::Q){//Altitude
                    double new_altitude = p1.get_altitude() + (p1.altitude_controller('Q'));
                    p1.set_altitude(new_altitude);
                    std::cout << "Q was pressed Speed is: " << p1.get_altitude() << std::endl;
                    std::string altitude_final_output = "Altitude: " + std::to_string(p1.get_altitude()); 
                    altitude_text.setString(altitude_final_output);
                    
                }
                else if(KeyPressed->scancode == sf::Keyboard::Scancode::E){//Altitude
                    double new_altitude = p1.get_altitude() + (p1.altitude_controller('E'));
                    p1.set_altitude(new_altitude);
                    std::cout << "E was pressed Speed is: " << p1.get_altitude() << std::endl;
                    std::string altitude_final_output = "Altitude: " + std::to_string(p1.get_altitude()); 
                    altitude_text.setString(altitude_final_output);
                    
                }
                else if(KeyPressed->scancode == sf::Keyboard::Scancode::A){//Altitude
                    double new_heading = p1.get_heading() + (p1.heading_controller('A'));
                    p1.set_heading(p1.heading_converter(new_heading));
                    std::cout << "A was pressed Speed is: " << p1.get_heading() << std::endl;
                    std::string heading_final_output = "Heading: " + std::to_string(p1.get_heading()); 
                    heading_text.setString(heading_final_output);
                    
                }
                else if(KeyPressed->scancode == sf::Keyboard::Scancode::D){//Altitude
                    double new_heading = p1.get_heading() + (p1.heading_controller('D'));
                    p1.set_heading(p1.heading_converter(new_heading));
                    std::cout << "D was pressed Speed is: " << p1.get_heading() << std::endl;
                    std::string heading_final_output = "Heading: " + std::to_string(p1.get_heading()); 
                    heading_text.setString(heading_final_output);
                    
                }
                else{
                    std::cout <<"Not valid input";
                }
                
            }
            
        }

        window.clear();
        window.draw(speed_text);
        window.draw(altitude_text);
        window.draw(heading_text);
        window.display();
    }
}
    
}

void input_handling_speed_heading_altitude(Plane &p1){
    for(char c; std::cin >> c;){
        switch (c)
        {
            case 'w':{//speed
                double new_speed = p1.get_speed() + (p1.speed_controller(c));
                p1.set_speed(new_speed);
        
                break;
            }
            case 's':{
                double new_speed = p1.get_speed() + (p1.speed_controller(c));
                p1.set_speed(new_speed);
                break;
            }
            case 'q':{//altitude
                double new_altitude = p1.get_altitude() + (p1.altitude_controller(c));
                p1.set_altitude(new_altitude);
                break;
            }
            case 'e':{
                double new_altitude = p1.get_altitude() + (p1.altitude_controller(c));
                p1.set_altitude(new_altitude);
                break;
            }
            case 'a':{//heading
                double new_heading = p1.get_heading() + (p1.heading_controller(c));
                p1.set_heading(p1.heading_converter(new_heading));
                break;
            }
            case 'd':{
                double new_heading = p1.get_heading() + (p1.heading_controller(c));
                p1.set_heading(p1.heading_converter(new_heading));
                break;
            }
            default:
                std::cout << c <<": is not a valid input" << '\n';
                break;
        }
    }

}

void run_plane(){
    

    double speed = 0;
    double heading = 0;
    double altitude = 1;

    std::cout << "Please enter Speed: " << '\n';
    std::cin >> speed;

    std::cout << "Please enter heading direction: " << '\n';
    std::cin >> heading;

    std::cout << "Please enter altitude: " << '\n';
    std::cin >> altitude;
        
    Plane p1(speed, heading, altitude);

    input_handling_speed_heading_altitude(p1); //handle 

    //external_window(p1);
    display_cockpit(p1);
}

void run_application(){
    char plane_start = 'N';
    
    //Welcome message
    plane_start = start_plane();

    while(plane_start =='N'){
        std::cout << "You have not started plane" << std::endl;
        plane_start = start_plane();

    }

    run_plane();
    
}


int main(){
    
    try{
        external_window();
        // Create the main window
    
    }
    catch (std::exception& e){
        std::cerr <<  "Error: " << e.what() << '\n';
        return 1;
    }

    
    
}