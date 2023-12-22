#include "ChargingDecorator.h"

ChargingDecorator::ChargingDecorator(BatteryDecorator* drone)
    : BatteryDecorator(drone, 10.0), drone(drone) {}

ChargingDecorator::~ChargingDecorator() {
  if (drone) delete drone;
}

void ChargingDecorator::update(double dt) {
  if (available) {
    getDroneToCharge();
  }

  if (toDeadDrone) {
    toDeadDrone->move(this, dt);
    if (toDeadDrone->isCompleted()) {
      chargeTime += dt;
      this->rotate(dt * this->getSpeed());
      if (chargeTime > 8.0) {
        deadDrone->chargeBattery();
        std::cout << IEntity::getName() << " finished charging "
                  << deadDrone->getName() << std::endl;
        delete toDeadDrone;
        toDeadDrone = nullptr;
        chargeTime = 0.0;
      }
    }
  } else if (toFinalDestination) {
    toFinalDestination->move(this, dt);
    if (toFinalDestination->isCompleted()) {
      delete toFinalDestination;
      toFinalDestination = nullptr;
      model->deadBatteryDrones.pop_front();
      chargeBattery();
      available = true;
      deadDrone = nullptr;
    }
  }
}

void ChargingDecorator::getDroneToCharge() {
  if (model && model->deadBatteryDrones.size() > 0) {
    deadDrone = model->deadBatteryDrones.front();
    if (deadDrone) {
      available = false;
      Vector3 deadDronePosition = deadDrone->getPosition();
      toDeadDrone = new BeelineStrategy(position, deadDronePosition);
      toFinalDestination = new BeelineStrategy(
          deadDronePosition, model->rechargeStation->getPosition());
    }
  }
}
