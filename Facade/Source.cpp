#include <iostream>

#include "Facade.h"

//Episode two from "easy patterns Cpp" series: Facade

auto main() -> int {
	auto marcus = std::make_unique<Barbarian>("Marcus", 12, 54,76);
	auto julius = std::make_unique<Gladiator>("Julius", 76, 51, 16);
	FightFacade<Barbarian, Gladiator> fight(std::move(marcus), std::move(julius));

	fight.showFighters();
	std::cout << '\n';
	fight.showLocation();
	std::cout << '\n';
	fight.showAmountOfPeople();
	std::cout << '\n';
	fight.showTotalAmountOfBetsAndValue();

	system("pause");
	return 0;
}