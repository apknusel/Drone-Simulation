#include "BatteryDecorator.h"

BatteryDecorator::BatteryDecorator(Drone* drone, double batteryPercentage)
    : Drone(const_cast<JsonObject&>(drone->getDetails())),
      drone(drone),
      maxBatteryPercentage(batteryPercentage),
      batteryPercentage(batteryPercentage) {}

BatteryDecorator::~BatteryDecorator() {
  if (drone) delete drone;
}

void BatteryDecorator::chargeBattery() {
  batteryPercentage = maxBatteryPercentage;
  std::cout << getName() << " charged to " << batteryPercentage << std::endl;
}

void BatteryDecorator::updateBattery(double dt) {
  float dischargeRate =
      dt / (0.5 * 60.0);  // Battery fully discharged in 30 seconds
  batteryPercentage -= dischargeRate;
  if (batteryPercentage <= 0) {
    batteryPercentage = 0.0;
  }
}

float BatteryDecorator::getBatteryCharge() { return batteryPercentage; }

void BatteryDecorator::update(double dt) {
  if (batteryPercentage > 0) {
    Drone::update(dt);
  }
  if (!available) {
    updateBattery(dt);
  }
}
