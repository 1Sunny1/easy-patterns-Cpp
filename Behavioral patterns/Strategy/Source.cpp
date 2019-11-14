#include "Strategy.h"

int main() {
	WeaponType weapon;
	weapon.setWeapon(WeaponType::type::SHOTGUN);
	weapon.showWeapon();
	
	weapon.setWeapon(WeaponType::type::SNIPER_RIFLE);
	weapon.showWeapon();
	system("pause");
	return 0;
}