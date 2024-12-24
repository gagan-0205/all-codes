#include <SFML/Graphics.hpp>
#include "traffic_lights.hpp"
#include "cars.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Crossroads Simulation");

    // Roads and dividers
    sf::RectangleShape hor_road(sf::Vector2f(1000, 200));
    sf::RectangleShape hor_div(sf::Vector2f(1000, 10));
    hor_road.setFillColor(sf::Color(100, 100, 100));
    hor_div.setFillColor(sf::Color(200, 200, 200));
    hor_road.setPosition(0, 400);
    hor_div.setPosition(0, 500);

    sf::RectangleShape ver_road(sf::Vector2f(200, 1000));
    sf::RectangleShape ver_div(sf::Vector2f(10, 400));
    sf::RectangleShape ver_div2(sf::Vector2f(10, 400));
    ver_road.setFillColor(sf::Color(100, 100, 100));
    ver_div.setFillColor(sf::Color(200, 200, 200));
    ver_div2.setFillColor(sf::Color(200, 200, 200));
    ver_road.setPosition(400, 0);
    ver_div.setPosition(500, 0);
    ver_div2.setPosition(500, 600);

    std::vector<Car> cars;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(hor_road);
        window.draw(hor_div);
        window.draw(ver_road);
        window.draw(ver_div);
        window.draw(ver_div2);

        // Update cars
        spawnCars(cars, deltaTime);
        updateCars(cars, deltaTime);
        drawCars(window, cars);

        // Draw traffic lights
        drawTrafficLights1(window, 400, 400);
        drawTrafficLights2(window, 600, 540);
        drawTrafficLights3(window, 400, 600);
        drawTrafficLights4(window, 540, 400);

        window.display();
    }

    return 0;
}

