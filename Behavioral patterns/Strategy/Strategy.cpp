#include "Strategy.h"

#include <iostream>

std::string Weapon::getWeaponName() const {
	return name;
}

size_t Weapon::getMuzzleVelocity() const {
	return muzzle_velocity;
}

std::string Sniper_Rifle::getWeaponName() const {
	return Weapon::getWeaponName();
}

size_t Sniper_Rifle::getMuzzleVelocity() const {
	return Weapon::getMuzzleVelocity();
}

void Sniper_Rifle::showScopeRanges() const {
	std::cout << "Scope ranges from " << std::get<0>(zoomRanges) << " to " << std::get<1>(zoomRanges);
}

std::string Shotgun::getWeaponName() const {
	return Weapon::getWeaponName();
}

size_t Shotgun::getMuzzleVelocity() const {
	return Weapon::getMuzzleVelocity();
}

void Shotgun::showEffectiveRange() const {
	std::cout << "Effective range of " << getWeaponName() << " is " << effectiveRange;
}

void WeaponType::showWeapon() const {
	if (weapon != nullptr)
		std::cout << "Weapon name : " << weapon->getWeaponName() << "\nMuzzle velocity: " << weapon->getMuzzleVelocity();
	else
		std::cout << "Object weapon has no state type.\n";
}
