#include <iostream>
#include <SFML/Graphics.hpp>



/*char start_plane(){
    char plane_start;
    std::cout << "Welcome to flight simulator 1.0" << '\n';
    std::cout << "Start up plane? (Y/N)" << '\n';
    std::cin >> plane_start;

    return plane_start;

}
*/

class Plane{
    public:
        double get_speed();
        double set_speed(double s);
        double speed_controller(char input);

        void set_accelerate(bool value);
        void set_decelerate(bool value);

        void turn_left(bool value);
        void turn_right(bool value);

        void ascend(bool value);
        void descend(bool value);
        void update(float dt);

        
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

        //new state
        bool accelerating = false;
        bool decelerate = false;
        bool t_left = false;
        bool t_right = false;
        bool ascending = false;
        bool descending = false;
};

void error(std::string s){
    throw std::runtime_error{s};
}

//Speed Methods
double Plane::get_speed(){
    return speed;
}

void Plane::set_accelerate(bool value){
    accelerating = value;

}
void Plane::set_decelerate(bool value){
    decelerate = value;

}

//Altitude Methods
double Plane::get_altitude(){
    if (altitude <= 0){
        error("Bro you crashed the $10B Plane");
    }
    return altitude;

}

void Plane::ascend(bool value){
    ascending = value;
}

void Plane::descend(bool value){
    descending = value;
}


//Heading Methods
double Plane::get_heading(){
    return heading;

}
void Plane::turn_left(bool value){
    t_left = value;

}
void Plane::turn_right(bool value){
    t_right = value;

}
//Update method

void Plane::update(float dt){
    if(accelerating){
        speed += 10 * dt;
    }
    if(decelerate){
        speed -= 10 * dt;
    }
    if(t_left){
        if(heading < 0)
            heading += (10 * dt) + 360;
        else if(heading >360)
            heading += (10 * dt) - 360;
        else
            heading -= 10 * dt;
    }
    if(t_right){
        if(heading < 0)
            heading += (10 * dt) + 360;
        else if(heading >360)
            heading += (10 * dt) - 360;
        else
            heading += 10 * dt;
    }
    if(ascending){
        altitude += 10 * dt;
    }
    if(descending){
        altitude -= 10 * dt;
    }

}



void run_plane() {
    {
    sf::RenderWindow window(sf::VideoMode({500, 500}), "Flight Simulator 1.0");
    
    
    sf::Font font;
    if (!font.openFromFile("/System/Library/Fonts/Helvetica.ttc")){
        std::cerr << "Failed to load font \n";
    }
    Plane p1(0,1,0);
    //Speed text
    sf::Text speed_text(font);
    std::string speed_value = "Speed: " + std::to_string(static_cast<int>(p1.get_speed()));
    speed_text.setString(speed_value);
    speed_text.setCharacterSize(20);
    speed_text.setStyle(sf::Text::Bold);
    speed_text.setFillColor(sf::Color::Red);
    speed_text.setPosition({10.f,0});

    //Altitude text
    sf::Text altitude_text(font);
    altitude_text.setString("Altitude: ");
    altitude_text.setCharacterSize(20);
    altitude_text.setStyle(sf::Text::Bold);
    altitude_text.setFillColor(sf::Color::Blue);
    altitude_text.setPosition({10.f,50.f});


    //Heading text
    sf::Text heading_text(font);
    heading_text.setString("Heading: ");
    heading_text.setCharacterSize(20);
    heading_text.setStyle(sf::Text::Bold);
    heading_text.setFillColor(sf::Color::White);
    heading_text.setPosition({10.f,100.f});

    //vertex array: screen line in middle 
    sf::VertexArray line(sf::PrimitiveType::Lines, 2);
    line[0].position = sf::Vector2f(0.f, 250.f);
    line[1].position = sf::Vector2f(500.f, 250.f);

    //vertex array: screen line in middle 
    sf::VertexArray line_divider(sf::PrimitiveType::Lines, 2);
    line_divider[0].position = sf::Vector2f(250.f, 250.f);
    line_divider[1].position = sf::Vector2f(250.f, 500.f);

    //Spawn in plane sprite
    sf::Texture plane_texture("/Users/fs/Desktop/Programs/Flight-Simulator-1.0/assests/plane.png");
    plane_texture.setSmooth(true);
    sf::Sprite plane_sprite(plane_texture);
    

    sf::Vector2<float> plane_size_bounds = plane_sprite.getLocalBounds().getCenter(); // 
    
    plane_sprite.setOrigin({plane_size_bounds.x, plane_size_bounds.y});
    plane_sprite.setPosition({125.f,375.f});
    
    
     //construct plane speed, alt, heading
    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        
        while (const std::optional event = window.pollEvent())
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){//Heading
                    window.close();
            
                }
            
        }
        //input
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ //speed
            
            p1.set_accelerate(true);                   
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            p1.set_decelerate(true);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            p1.turn_left(true);
            plane_sprite.setRotation(sf::degrees(p1.get_heading()));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            p1.turn_right(true);
            plane_sprite.setRotation(sf::degrees(p1.get_heading()));

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
            p1.ascend(true);

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)){
            p1.descend(true);

        }
        else{
            std::cout <<"Not valid input" << std::endl;
            p1.set_accelerate(false);
            p1.set_decelerate(false);
            p1.turn_left(false);
            p1.turn_right(false);
            p1.ascend(false);
            p1.descend(false);
            
        }
        //update state
        p1.update(dt);

        //update text
        speed_text.setString(std::to_string(static_cast<int>(p1.get_speed())));
        altitude_text.setString(std::to_string(static_cast<int>(p1.get_altitude())));
        heading_text.setString(std::to_string(static_cast<int>(p1.get_heading())));

        //draw
        window.clear();
        window.draw(speed_text);
        window.draw(altitude_text);
        window.draw(heading_text);
        window.draw(line);
        window.draw(line_divider);
        window.draw(plane_sprite);
        window.display();
        
    }
}
    
}
/* old code - console
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
*/


int main(){
    
    try{
        run_plane();    
    }
    catch (std::exception& e){
        std::cerr <<  "Error: " << e.what() << '\n';
        return 1;
    }

    
    
}