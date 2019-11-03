#include "Factory.h"

#include <iostream>

//Episode one from "easy patterns Cpp" series: Factory

auto main() -> int {
	WarriorFactory<Gladiator> factoryGlad;
	auto marcus = factoryGlad.create("Marcus", 12, 134, 16);
	marcus->showStats();

	WarriorFactory<Centurion> factoryCent;
	auto augustus = factoryCent.create("Augustus", 22, 253, 19);
	augustus->showStats();

	WarriorFactory<Gladiator> factoryGlad2;
	auto julius = factoryGlad2.create("Julius", 54, 65, 23);
	julius->showStats();

	std::cout << '\n';
	system("pause");
	return 0;
}
