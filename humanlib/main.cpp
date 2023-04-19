#include <iostream>

#include "human/adult.hpp"
#include "human/child.hpp"

using namespace std;

int main() {
  Child child({0.5 /*height*/, 20. /*weight*/});
  Adult adult({1.8 /*height*/, 80. /*weight*/});

  cout << "Child says: " << child.greet() << endl;
  cout << "Adult says: " << adult.greet() << endl;

  return 0;
}