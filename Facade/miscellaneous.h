#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <random>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

namespace Random {
	static std::mt19937 gen{ std::random_device{}() };
	template<typename T>
	inline static T getRandomT(T min, T max) {
		return std::uniform_int_distribution<T>{min, max}(gen);
	}
}

class Map {
public:
	explicit Map() noexcept;
	void showPlaceInfo() const;
	size_t getCitySize() const;

private:
	std::string selectTerrain();
	size_t selectCitySize();

private:
	std::string selectedTerrain;
	size_t selectedCitySize;

	std::vector<std::string> terrains {
	"Tundra", "Taiga", "Mountains", "Plains",
	"Forest", "Swamp", "Jungle", "Desert", "Savanna" };

	std::unordered_map<size_t, size_t> citySize {
		{4, 100},
		{3, 50},
		{2, 10},
		{1, 1}
	};
};

class Audience : public Map {
public:
	explicit Audience() noexcept;
	size_t getAmountOfPeople() const;
	size_t getRichPeople() const;
	size_t getLittleRichPeople() const;
	size_t getPoorPeople() const;

private:
	size_t setAmountOfPeople();

private:
	size_t amountOfPeople;
	size_t richPeople;
	size_t littleRichPeople;
	size_t poorPeople;
};

class Bets : public Audience {
public:
	explicit Bets() noexcept;
	void totalBets() const;
	int totalBetsValue();

private:
	size_t amountOfBettingPeople;
	size_t amountOfRichPeopleBetting;
	size_t amountOfLittleRichPeopleBetting;
	size_t amountOfPoorPeopleBetting;
};

#endif