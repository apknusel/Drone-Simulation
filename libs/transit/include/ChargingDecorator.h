#ifndef CHARGING_DECORATOR_H_
#define CHARGING_DECORATOR_H_

#include "BatteryDecorator.h"
#include "BeelineStrategy.h"
#include "SimulationModel.h"

/**
 * @brief Decorator to add the ability for a drone to charge another drone
 * 
 */
class ChargingDecorator : public BatteryDecorator {
 public:
  /**
   * @brief Construct a new Charging Decorator object
   *
   * @param drone
   */
  ChargingDecorator(BatteryDecorator* drone);
  /**
   * @brief Destroy the Charging Decorator object
   *
   */
  ~ChargingDecorator();
  /**
   * @brief Update the drones position and pathing
   *
   * @param dt
   */
  void update(double dt);
  /**
   * @brief Get the drone that needs to be charged
   *
   */
  void getDroneToCharge();

 private:
  double chargeTime = 0.0;
  BatteryDecorator* drone = nullptr;
  BatteryDecorator* deadDrone = nullptr;
  IStrategy* toDeadDrone = nullptr;
};

#endif  // CHARGING_DECORATOR_H_
