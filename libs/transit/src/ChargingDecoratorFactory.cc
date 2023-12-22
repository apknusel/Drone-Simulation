#include "ChargingDecoratorFactory.h"

IEntity* ChargingDecoratorFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("charging drone") == 0) {
    std::cout << "Charging Drone Created" << std::endl;
    return new ChargingDecorator(new BatteryDecorator(new Drone(entity)));
  }
  return nullptr;
}
