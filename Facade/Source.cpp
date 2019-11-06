#include <iostream>
#include <memory>

#include "Facade.h"

auto main() -> int {
	auto marcus = std::make_unique<Barbarian>("Marcus", 12, 54,76);
	auto julius = std::make_unique<Gladiator>("Julius", 76, 51, 16);
	FightFacade<Barbarian, Gladiator> fight(marcus, julius);

	system("pause");
	return 0;
}