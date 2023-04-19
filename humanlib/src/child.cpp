#include "human/child.hpp"

Child::Child(Characterisitcs characterisitcs) : Human(characterisitcs){};

std::string Child::greet() const { return "What's up!"; }
