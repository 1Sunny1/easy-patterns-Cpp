#ifndef WARRIORS_H_
#define WARRIORS_H_

#include <string>
#include <vector>
#include <tuple>
#include <random>

class Warrior {
public:
	explicit Warrior(const std::string n, size_t h, size_t s, size_t d) noexcept : name(n), health(h), strength(s), dexterity(d) { }
	virtual void showStats() const = 0;

private:
	std::string name;
	size_t health;
	size_t strength;
	size_t dexterity;
};

class Weapons {
public:
	explicit Weapons() noexcept;
	void showWeapons() const;

private:
	int random(int min, int max);

private:
	std::vector<std::string> weaponCollection = 
	{"Net", "Trident", "Gladius", "Longsword", "Javelins",
	"Knife", "Hammer", "Hatchet", "Mace", "Club"};
	std::tuple<std::string, std::string> chosenWeapons;
	std::mt19937 gen{ std::random_device{}() };
};


class Gladiator : public Warrior {
public:
	explicit Gladiator(std::string n, size_t h, size_t s, size_t d) noexcept : Warrior(n, h, s, d) { }
	virtual void showStats() const override;

private:
	Weapons weapons;
};

class Barbarian : public Warrior {
public:
	explicit Barbarian(std::string n, size_t h, size_t s, size_t d) noexcept : Warrior(n, h, s, d) { }
	virtual void showStats() const override;

private:
	Weapons weapons;
};

class Brigand : public Warrior {
public:
	explicit Brigand(std::string n, size_t h, size_t s, size_t d) noexcept : Warrior(n, h, s, d) { }
	virtual void showStats() const override;

private:
	Weapons weapons;
};

#endif // ! WARRIORS_H_

