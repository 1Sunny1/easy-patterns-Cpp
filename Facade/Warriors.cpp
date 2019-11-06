#include "Warriors.h"
#include <iostream>

void Warrior::showStats() const {
	std::cout << "Name: " << this->name << '\n';
	std::cout << "Health: " << this->health << '\n';
	std::cout << "Strength: " << this->strength << '\n';
	std::cout << "Dexterity: " << this->dexterity << '\n';
}

Weapons::Weapons() noexcept {
	chosenWeapons = std::make_tuple(weaponCollection[random(0, 9)], weaponCollection[random(0, 9)]);
}

void Weapons::showWeapons() const {
	std::cout << "Fighter equipment: " << std::get<0>(chosenWeapons) << ", " << std::get<1>(chosenWeapons) << '\n';
}

int Weapons::random(int min, int max) {
	return std::uniform_int_distribution<int>{min, max}(gen);
}

void Gladiator::showStats() const {
	Warrior::showStats();
	weapons.showWeapons();
}

void Barbarian::showStats() const {
	Warrior::showStats();
	weapons.showWeapons();
}

void Brigand::showStats() const {
	Warrior::showStats();
	weapons.showWeapons();
}