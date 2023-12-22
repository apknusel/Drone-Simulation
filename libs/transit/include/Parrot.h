#ifndef PARROT_H_
#define PARROT_H_

#include <vector>

#include "CircleStrategy.h"
#include "IEntity.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Parrots move using beeline strategy based on a specified
// velocity and direction.
/**
 * @class Parrot
 * @brief Represents a Parrot in a physical system.
 * Parrots move using beeline strategy based on a specified velocity and
 * direction.
 */
class Parrot : public IEntity {
 public:
    /**
     * @brief Drones are created with a name
     * @param obj JSON object containing the drone's information
     */
    Parrot(JsonObject& obj);

    /**
     * @brief Destructor
     */
    ~Parrot();

    /**
     * @brief Updates the drone's position
     * @param dt Delta time
     */
    void update(double dt);

    /**
     * @brief Removing the copy constructor operator
     * so that drones cannot be copied.
     */
    Parrot(const Parrot& Parrot) = delete;

    /**
     * @brief Removing the assignment operator
     * so that drones cannot be copied.
     */
    Parrot& operator=(const Parrot& Parrot) = delete;

 private:
    IStrategy* movementStrategy = nullptr;
};

#endif
