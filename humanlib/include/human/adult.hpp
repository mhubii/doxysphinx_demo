#pragma once

#include "human/human.hpp"

/**
 * @brief An adult human.
 *
 */
class Adult : public Human {
public:
  /**
   * @brief Construct a new Adult object.
   *
   * @param characterisitcs Human characteristics
   */
  Adult(Characterisitcs characterisitcs);

  /**
   * @brief Adult greet method.
   *
   * @return std::string
   */
  virtual std::string greet() const override;
};
