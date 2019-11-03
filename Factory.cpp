#include "Factory.h"

//#include <algorithm>
#include <iterator>
#include <iostream>

void Warrior::showStats() const {
	std::cout << "Name: " << this->name << '\n';
	std::cout << "Health: " << this->health << '\n';
	std::cout << "Strength: " << this->strength << '\n';
	std::cout << "Agility: " << this->agility << '\n';
}

void Gladiator::showStats() const {
	Warrior::showStats();
	std::cout << "Equipment: ";
	showEquipment();
}

void Gladiator::showEquipment() const {
	std::copy(std::begin(equipment), std::end(equipment), std::ostream_iterator<std::string>(std::cout, ", "));
}

void Centurion::showStats() const {
	Warrior::showStats();
	std::cout << "Equipment: ";
	showEquipment();
}

void Centurion::showEquipment() const {
	std::copy(std::begin(equipment), std::end(equipment), std::ostream_iterator<std::string>(std::cout, ", "));
}