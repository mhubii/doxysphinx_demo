#pragma once

#include "human/human.hpp"

/**
 * @brief A child human.
 *
 */
class Child : public Human {
public:
  /**
   * @brief Construct a new Child object.
   *
   * @param characterisitcs Human charactersitics.
   */
  Child(Characterisitcs characterisitcs);

  /**
   * @brief Child greet method.
   *
   * @return std::string
   */
  virtual std::string greet() const override;
};
