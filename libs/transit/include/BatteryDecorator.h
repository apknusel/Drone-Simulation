#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "Drone.h"

/**
 * @brief Decorator for a drone to add battery functionality
 */
class BatteryDecorator : public Drone {
 public:
  /**
   * @brief Construct a new Battery Decorator object
   *
   * @param drone
   * @param batteryPercentage
   */
  BatteryDecorator(Drone* drone, double batteryPercentage = 4.0);
  /**
   * @brief Destroy the Battery Decorator object
   *
   */
  ~BatteryDecorator();
  /**
   * @brief updates the drones battery and position
   *
   * @param dt
   */
  void update(double dt);
  /**
   * @brief charges the batteery to max capacity
   *
   */
  void chargeBattery();
  /**
   * @brief Get the charge of the battery
   *
   * @return float
   */
  float getBatteryCharge();

 private:
  /**
   * @brief Updates the charge of the battery based on dt
   *
   * @param dt
   */
  void updateBattery(double dt);
  float batteryPercentage;
  float maxBatteryPercentage;
  Drone* drone;
};

#endif  // BATTERY_DECORATOR_H_
