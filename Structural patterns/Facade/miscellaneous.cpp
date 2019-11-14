#include "miscellaneous.h"
#include <iostream>

Map::Map() noexcept {
	selectedCitySize = selectCitySize();
	selectedTerrain = selectTerrain();
}

void Map::showPlaceInfo() const {
	std::cout << "Place: " << selectedTerrain << " arena.\nCity size: " << selectedCitySize << ".\n";
}

size_t Map::selectCitySize() {
	return citySize[Random::getRandomT<int>(1, 4)];
}

size_t Map::getCitySize() const {
	return selectedCitySize;
}

std::string Map::selectTerrain() {
	return terrains[Random::getRandomT<int>(0, 8)];
}

Audience::Audience() noexcept {
	amountOfPeople = setAmountOfPeople();
	richPeople = amountOfPeople * 0.09;
	littleRichPeople = amountOfPeople * 0.28;
	poorPeople = amountOfPeople * 0.63;
}

size_t Audience::setAmountOfPeople() {
	return getCitySize() * Random::getRandomT<int>(1, 100) * Random::getRandomT<int>(1, 10);
}

size_t Audience::getAmountOfPeople() const {
	return amountOfPeople;
}

size_t Audience::getRichPeople() const {
	return richPeople;
}

size_t Audience::getLittleRichPeople() const {
	return littleRichPeople;
}

size_t Audience::getPoorPeople() const {
	return poorPeople;
}

Bets::Bets() noexcept {
	amountOfRichPeopleBetting = getRichPeople() * Random::getRandomT<int>(5, 9) / 100;
	amountOfLittleRichPeopleBetting = getLittleRichPeople() * Random::getRandomT<int>(4, 6) / 100;
	amountOfPoorPeopleBetting = getPoorPeople() * Random::getRandomT<int>(1, 4) / 100;
	amountOfBettingPeople = amountOfRichPeopleBetting + amountOfLittleRichPeopleBetting + amountOfPoorPeopleBetting;
}

void Bets::totalBets() const {
	std::cout << "Total bets in this fight: " << amountOfBettingPeople;
}

int Bets::totalBetsValue() {
	auto betsValSum = 0;

	for (int i = 0; i < amountOfRichPeopleBetting; ++i)
		betsValSum += Random::getRandomT<int>(10, 100);

	for (int i = 0; i < amountOfLittleRichPeopleBetting; ++i)
		betsValSum += Random::getRandomT<int>(5, 50);

	for (int i = 0; i < amountOfPoorPeopleBetting; ++i)
		betsValSum += Random::getRandomT<int>(1, 10);

	return betsValSum;
}
