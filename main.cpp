#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

#define e 2.7182818284
#define gravity 9.80665 // m/s^2


int main()
{


    // VARIABLES

    double g = 1; // not used at this time
    int x; // not used at this time
    double dens, h, t, v1, y, velocity, acceleration, m, d, f, airdens; // Variables for mass calculation
    int  x1, y1, l; // Variables for positional data
    float k, p; // Variables for air




    // INTRO

    std::cout << "Welcome to this gravity calculator, made by Hannah, Gabriel and Christian!" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "This calculator will give you all the values from your desired fall" << std::endl;
    std::cout << "Gravity is set to 9.80665 m/s^2 " << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Please note that this calculator does not represent the presence of buoyancy, \ntherefore should the density of the cube always be bigger than density of the air" << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    std::cout << "=============================================================================================" << std::endl;
    std::cout << "Please type the length of one of the sides of your cube in cm:" << std::endl;
    std::cin >> d;
    std::cout << " " << std::endl;
    std::cout << d << " cm" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Thank you, now please type your desired density of the cube in g/cm^3 (use . )" << std::endl;
    std::cin >> dens;
    std::cout << " " << std::endl;
    std::cout << dens << " g/cm^3" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Now type your desired density of the air in g/cm^3 (use . )    (Air at 15C is 0.001225)" << std::endl;
    std::cin >> airdens;
    std::cout << " " << std::endl;
    std::cout << airdens << " g/cm^3" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Thank you, please add the height of the fall in meters:" << std::endl;
    std::cin >> h;
    std::cout << " " << std::endl;
    std::cout << h << " m" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "=============================================================================================" << std::endl;





    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;



        // Calculation of p, density of air
        p = airdens * 1000;

        // Calculation of cube mass:
        m = pow(d, 3) * dens / 1000;


        // Calculation of air resistance coefficient, kg/m
        k = p * pow(d/100, 2) * 2.1 / 2;


        /*
        // Falling force
        f = m * gravity

        // Calculation of time
        t = sqrt(2 * h / gravity);


        // Calculation of end velocity
        v1 = sqrt(2 * gravity * h);


        // Falling force
        f = m * gravity

*/

            // Calculates the time
            t = sqrt(m / (gravity * k)) * acosh(pow(e, h*k / m));

            // Calculates the end velocity
            v1 = sqrt((m*gravity)/k)*tanh(t/(sqrt(m/(gravity * k))));


    std::cout << "Air resistance coefficient: " << k << std::endl;
    std::cout << "Volume of cube: " << d*d << " cm^3" << std::endl;
    std::cout << "Mass of cube: " << m << " kg" << std::endl;
    std::cout << "Time of fall: " << t << " seconds " << std::endl;
    std::cout << "End velocity: " << v1 << " m/s" << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Enter 1 to play or 2 to exit" << std::endl;
    std::cin >> l;



    if (l == 1)
    {


    // Creates the window for the program
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Window");


    //Starts a clock which is used for frame rate limitation
    sf::Clock clock;

    // Sets the framerate limitation to 60fps
    window.setFramerateLimit(60);







                // T E X T U R E S

                // Cube
                sf::Texture t_ball;
                if (!t_ball.loadFromFile("assets/green.png"))
                {
                    std::cout << "error loading green.png..." << std::endl;
                }


                // Ground
                sf::Texture t_ground;
                if (!t_ground.loadFromFile("assets/yellow.jpg"))
                {
                    std::cout << "error loading yellow..jpg..." << std::endl;
                }





                // S P R I T E S

                // Cube
                sf::Sprite s_ball;
                s_ball.setTexture(t_ball);


                // Ground
                sf::Sprite ground;
                ground.setTexture(t_ground);



    //turning meters into pixels, 1 meter is 100 pixels
    h = h * 100;

    // SETTING SPRITE TEXTURES

    //Loads texture to cube
    s_ball.setTextureRect(sf::IntRect(725, 475, d, d));

    //Loads texture to ground
    ground.setTextureRect(sf::IntRect(10, 10, 1500, 50));

    // Calculates the position of the cube
    x1 = 1500/2 - d/2; // X Coordinate is in the middle
    y = 1000 - h - 50; // Y coordinates is based on the dimensions of the cube


    // Places the cube in the world
    s_ball.setPosition(sf::Vector2f(x1, y));

    // Places the Ground in the world
    ground.setPosition(sf::Vector2f(0, 950));





    velocity = 0; // Start movement is 0
    acceleration = gravity / (t * 60); //Earth's acceleration, divided by 10 because 10pix = 1 meter


    while (window.isOpen())
    {



        if (s_ball.getPosition().y > 950 - d) //If the cube position is below the ground it stops
        {
            y = y + 0; //Here it stops the y motion
        }

        else
   {


        //This calculates the new values for the cube
        velocity += acceleration;
        y += velocity;
   }

        //This moves the cube to the new position
        s_ball.setPosition(x1, y);





        sf::Event event;
        while (window.pollEvent(event))
        {




            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(ground);
        window.draw(s_ball);
        window.display();
    }
    }
    return 0;
}

