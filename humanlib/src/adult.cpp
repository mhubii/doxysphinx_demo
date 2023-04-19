#include "human/adult.hpp"

Adult::Adult(Characterisitcs characterisitcs) : Human(characterisitcs){};

std::string Adult::greet() const { return "Hello there!"; }
