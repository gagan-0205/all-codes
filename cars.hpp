#ifndef CARS_HPP
#define CARS_HPP

#include <SFML/Graphics.hpp>
#include <vector>

enum Direction { LEFT, RIGHT, UP, DOWN };  // Enum to represent direction

struct Car {
    sf::RectangleShape shape;
    sf::Color color;
    float speed;
    Direction direction;  // Direction in which the car is moving
};

void spawnCars(std::vector<Car>& cars, float dt);
void updateCars(std::vector<Car>& cars, float dt);
void drawCars(sf::RenderWindow& window, const std::vector<Car>& cars);

#endif

