#include "CircleStrategy.h"

CircleStrategy::CircleStrategy()
    : PathStrategy(generatePointsOnCircle(std::rand() % 1449 - 699,
                                          std::rand() % 799 - 399, 150, 100,
                                          std::rand() % 359 + 241)) {}

std::vector<std::vector<float>> CircleStrategy::generatePointsOnCircle(
    float centerX, float centerZ, double radius, int numPoints, float height) {
    std::vector<std::vector<float>> points;
    for (int i = 0; i < numPoints; ++i) {
        float theta = 2.0 * M_PI * i / numPoints;
        float x = centerX + radius * std::cos(theta);
        float z = centerZ + radius * std::sin(theta);

        points.push_back(std::vector<float>{x, height, z});
    }

    return points;
}
