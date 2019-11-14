#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <string>
#include <tuple>
#include <memory>

class Weapon {
public:
	explicit Weapon(std::size_t _muzz_vel, std::string _name) noexcept : name(_name), muzzle_velocity(_muzz_vel) { }
	virtual std::string getWeaponName() const = 0;
	virtual size_t getMuzzleVelocity() const = 0;
private:
	size_t muzzle_velocity;
	std::string name;
};

class Sniper_Rifle : public Weapon {
public:
	explicit Sniper_Rifle(std::size_t _muzz_vel, std::string _name) noexcept : Weapon(_muzz_vel, _name) { }
	virtual std::string getWeaponName() const override;
	virtual size_t getMuzzleVelocity() const override;
	void showScopeRanges() const;
private:
	std::tuple<double, double> zoomRanges = std::make_tuple(1.0, 5.0);
};

class Shotgun : public Weapon {
public:
	explicit Shotgun(std::size_t _muzz_vel, std::string _name) noexcept : Weapon(_muzz_vel, _name) { }
	virtual std::string getWeaponName() const override;
	virtual size_t getMuzzleVelocity() const override;
	void showEffectiveRange() const;
private:
	size_t effectiveRange {200};
};

class WeaponType final {
public:
	WeaponType() : weapon(nullptr) { }
	enum class type { SHOTGUN, SNIPER_RIFLE };
	void setWeapon(const type _type) {
		switch (_type) {
			case type::SHOTGUN: std::make_unique<Shotgun>(weapon); break;
			case type::SNIPER_RIFLE: std::make_unique<Sniper_Rifle>(weapon); break;
		}
	}
	void showWeapon() const;
private:
	std::unique_ptr<Weapon> weapon;

};

#endif