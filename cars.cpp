#include "cars.hpp"

const float SPAWN_DELAY = 1.0f;
const int MAX_CARS_PER_INTERVAL = 1;
const float MIN_SPEED = 200.0f;
const float MAX_SPEED = 250.0f;

void spawnCars(std::vector<Car>& cars, float dt) {
    static float elapsedTime = 0.0f;
    elapsedTime += dt;

    if (elapsedTime >= SPAWN_DELAY) {
        int numCars = rand() % (MAX_CARS_PER_INTERVAL + 1);
        for (int i = 0; i < numCars; ++i) {
            Car car;
            car.speed = static_cast<float>((rand() % static_cast<int>((MAX_SPEED - MIN_SPEED) * 100)) + (MIN_SPEED * 100)) / 100;
            car.direction = static_cast<Direction>(rand() % 4);  // Randomize direction

            switch (car.direction) {
                case LEFT:
                    car.shape.setSize(sf::Vector2f(80, 60));  // Horizontal car shape
                    car.shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                    car.shape.setPosition(1030, 420);  // Start from right, move left
                    break;

                case RIGHT:
                    car.shape.setSize(sf::Vector2f(80, 60));  // Horizontal car shape
                    car.shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                    car.shape.setPosition(-30, 520);  // Start from left, move right
                    break;

                case UP:
                    car.shape.setSize(sf::Vector2f(60, 80));  // Vertical car shape
                    car.shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                    car.shape.setPosition(500, 1030);  // Start from bottom, move up
                    break;

                case DOWN:
                    car.shape.setSize(sf::Vector2f(60, 80));  // Vertical car shape
                    car.shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                    car.shape.setPosition(400, -80);  // Start from top, move down
                    break;
            }

            cars.push_back(car);
        }
        elapsedTime = 0.0f;
    }
}

// Helper function to check if two cars are colliding
bool checkCollision(const Car& car1, const Car& car2) {
    return car1.shape.getGlobalBounds().intersects(car2.shape.getGlobalBounds());
}

void updateCars(std::vector<Car>& cars, float dt) {
    // Update car positions
    for (auto& car : cars) {
        if (car.speed > 0) {  // Only move the car if it's still moving
            switch (car.direction) {
                case LEFT:
                    car.shape.move(-car.speed * dt, 0);  // Move left
                    break;
                case RIGHT:
                    car.shape.move(car.speed * dt, 0);  // Move right
                    break;
                case UP:
                    car.shape.move(0, -car.speed * dt);  // Move up
                    break;
                case DOWN:
                    car.shape.move(0, car.speed * dt);  // Move down
                    break;
            }
        }
    }

    // Check for collisions and stop cars if a collision occurs
    for (size_t i = 0; i < cars.size(); ++i) {
        for (size_t j = i + 1; j < cars.size(); ++j) {
            if (checkCollision(cars[i], cars[j])) {
                cars[i].speed = 0;  // Stop the first car
                cars[j].speed = 0;  // Stop the second car
            }
        }
    }
}

void drawCars(sf::RenderWindow& window, const std::vector<Car>& cars) {
    for (const auto& car : cars) {
        window.draw(car.shape);
    }
}

