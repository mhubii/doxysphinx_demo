#pragma once

#include <iostream>
#include <string>

/**
 * @brief A human.
 *
 */
class Human {
public:
  /**
   * @brief Human characteristics.
   *
   */
  struct Characterisitcs {
    double weight; /**< The weight.*/
    double height; /**< The height.*/
  };

  Human() = delete;

  /**
   * @brief Construct a new Human object.
   *
   * @param characterisitcs Human characteristics
   */
  Human(Characterisitcs characterisitcs) : characteristics_(characterisitcs){};

  /**
   * @brief Greet method.
   *
   * @return std::string
   */
  virtual std::string greet() const = 0;

  /**
   * @brief Getter for #characteristics_.
   *
   * @return const Characterisitcs&
   */
  inline const Characterisitcs &characterisitcs() const { return characteristics_; };

protected:
  Characterisitcs characteristics_; /**< Human characteristics.*/
};
