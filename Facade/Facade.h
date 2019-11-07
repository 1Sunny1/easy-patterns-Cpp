#ifndef FACADE_H_
#define FACADE_H_

#include "miscellaneous.h"
#include "Warriors.h"

#include <memory>

template<typename T, typename Y>
class FightFacade final {
public:
	explicit FightFacade(std::unique_ptr<T> f1, std::unique_ptr<Y> f2) noexcept :
		fighter1(std::move(f1)), fighter2(std::move(f2)) { }

	void showLocation() const;
	void showTotalAmountOfBetsAndValue() const;
	void showFighters() const;
	void showAmountOfPeople() const;

private:
	std::unique_ptr<T> fighter1;
	std::unique_ptr<Y> fighter2;
	std::unique_ptr<Bets> betsies = std::make_unique<Bets>();
};

template<typename T, typename Y>
void FightFacade<T, Y>::showLocation() const {
	betsies->showPlaceInfo();
}

template<typename T, typename Y>
void FightFacade<T, Y>::showTotalAmountOfBetsAndValue() const {
	betsies->totalBets();
	std::cout << '\n';
	std::cout << "Total bets value: " << betsies->totalBetsValue() << '\n';
}

template<typename T, typename Y>
void FightFacade<T, Y>::showFighters() const {
	fighter1->showStats();
	std::cout << '\n';
	fighter2->showStats();
}
template<typename T, typename Y>
void FightFacade<T, Y>::showAmountOfPeople() const {
	std::cout << "Total amount of people in this city: " << betsies->getAmountOfPeople();
}
#endif // ! FACADE_H_

