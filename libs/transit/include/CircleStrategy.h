#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "PathStrategy.h"

/**
 * @brief this class inherits from the IStrategy class and is responsible for
 * generating the circle that the drone will take.
 */
class CircleStrategy : public PathStrategy {
 public:
    /**
     * @brief Construct a new Circle Strategy object
     *
     * @param position Starting position
     * @param destination End destination
     */
    CircleStrategy();

    /**
     * @brief Generates points for a circle
     *
     * @param centerX The X center of the circle
     * @param centerZ The Y center of the circle
     * @param radius The raidus of the circle
     * @param numPoints The number of points on the circle to be generated
     * @param height The hight of the circle
     * @return std::vector<std::vector<float>>
     */
    std::vector<std::vector<float>> generatePointsOnCircle(float centerX,
                                                           float centerZ,
                                                           double radius,
                                                           int numPoints,
                                                           float height);
};

#endif
