#ifndef RECHARGE_STATION_FACTORY_H_
#define RECHARGE_STATION_FACTORY_H_

#include "IEntityFactory.h"
#include "RechargeStation.h"

/**
 * @brief Factory for creating a recharge station
 * 
 */
class RechargeStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy the Recharge Station Factory object
   *
   */
  virtual ~RechargeStationFactory() {}
  /**
   * @brief Create a recharge station factory
   *
   * @param entity
   * @return IEntity*
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
