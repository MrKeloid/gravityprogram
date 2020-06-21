#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>

#define gravity 9.8


int main()
{

    double g = 1;
    int x = 0;
    double dens, h, t, v1;
    int d, x1, y1;


    std::cout << "Welcome to this gravity calculator, please type the length of one of the sides of your cube in cm:" << std::endl;
    std::cin >> d;
    std::cout << "\n";
    std::cout << "Thank you, now please type your desired density in g/cm^3 (use . )" << std::endl;
    std::cin >> dens;
    std::cout << "Thank you, please add the height of the fall in meters:" << std::endl;
    std::cin >> h;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;



    t = sqrt(2 * h / gravity);

    v1 = sqrt(2 * gravity * h);

    std::cout << "Time: " << t << std::endl;
    std::cout << "Velocity: " << v1 << std::endl;


    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Window");

    sf::Clock clock;
    window.setFramerateLimit(60);

    // T E X T U R E S

    sf::Texture t_ball;
    if (!t_ball.loadFromFile("assets/green.png"))
    {
        std::cout << "error loading green.png..." << std::endl;
    }



    // S P R I T E S
    sf::Sprite s_ball;
    s_ball.setTexture(t_ball);

    s_ball.setTextureRect(sf::IntRect(725, 475, d, d));
    x1 = 1500/2 - d/2;
    y1 = 1000/2 + d/2;
    s_ball.setPosition(sf::Vector2f(x1, 100 + d/2));

    while (window.isOpen())
    {

       //GRAVITATION FUNTION
       if (x == 0){
                g = g + 16.366;
            }

            s_ball.move(sf::Vector2f(0, g));



        sf::Event event;
        while (window.pollEvent(event))
        {




            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(s_ball);
        window.display();
    }

    return 0;
}
