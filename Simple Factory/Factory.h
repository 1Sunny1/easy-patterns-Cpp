#ifndef FACTORY_H_
#define FACTORY_H_

#include <memory>
#include <string>
#include <vector>

template<typename T>
class WarriorFactory {
public:
	std::unique_ptr<T> create(std::string n, size_t s, size_t h, size_t a) {
		return std::make_unique<T>(n, s, h, a);
	}
};

class Warrior {
public:
	explicit Warrior(std::string n, size_t s, size_t h, size_t a) noexcept
		: name(n), strength(s), health(h), agility(a) {}

	virtual void showStats() const = 0;
private:
	std::string name;
	size_t strength;
	size_t health;
	size_t agility;
};

class Gladiator : public Warrior {
public:
	explicit Gladiator(std::string n, size_t s, size_t h, size_t a) noexcept : Warrior(n, s, h, a) {}
	virtual void showStats() const override;
	void showEquipment() const;
private:
	std::vector<std::string> equipment = { "Gladius", "Dagger", "Spear", "Net", "Trident" };
};

class Centurion : public Warrior {
public:
	explicit Centurion(std::string n, size_t s, size_t h, size_t a) noexcept : Warrior(n, s, h, a) {}
	virtual void showStats() const override;
	void showEquipment() const;
private:
	std::vector<std::string> equipment = { "Gladius", "Dagger", "Spear", "Javelins", "Long Sword" };
};

#endif // !
