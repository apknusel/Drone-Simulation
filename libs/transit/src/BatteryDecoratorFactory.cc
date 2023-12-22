#include "BatteryDecoratorFactory.h"

IEntity* BatteryDecoratorFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("battery drone") == 0) {
    std::cout << "Battery Drone Created" << std::endl;
    return new BatteryDecorator(new Drone(entity));
  }
  return nullptr;
}
