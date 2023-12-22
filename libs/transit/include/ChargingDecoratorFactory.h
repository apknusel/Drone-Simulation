#ifndef CHARGING_DRONE_FACTORY_H_
#define CHARGING_DRONE_FACTORY_H_

#include <vector>

#include "ChargingDecorator.h"
#include "IEntityFactory.h"

/**
 *@brief Human Factory to produce Human class.
 **/
class ChargingDecoratorFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy the Charging Decorator Factory object
   *
   */
  virtual ~ChargingDecoratorFactory() {}
  /**
   * @brief Create a charging decorator drone
   *
   * @param entity
   * @return IEntity*
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
