#ifndef BATTERY_DRONE_FACTORY_H
#define BATTERY_DRONE_FACTORY_H

#include <vector>

#include "BatteryDecorator.h"
#include "IEntityFactory.h"

/**
 *@brief Human Factory to produce Human class.
 **/
class BatteryDecoratorFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy the Battery Decorator Factory object
   *
   */
  virtual ~BatteryDecoratorFactory() {}
  /**
   * @brief Create a the battery decorator drone
   *
   * @param entity
   * @return IEntity*
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
