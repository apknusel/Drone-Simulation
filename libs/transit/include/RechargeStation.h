#ifndef RECHARGE_STATION_H
#define RECHARGE_STATION_H

#include "IEntity.h"

/**
 * @brief Functionality of a recharge station
 * 
 */
class RechargeStation : public IEntity {
 public:
  /**
   * @brief Construct a new Recharge Station object
   *
   * @param obj
   */
  RechargeStation(JsonObject& obj);
  /**
   * @brief Destroy the Recharge Station object
   *
   */
  ~RechargeStation();
  /**
   * @brief does essentially nothing
   *
   * @param dt
   */
  void update(double dt);
};
#endif
