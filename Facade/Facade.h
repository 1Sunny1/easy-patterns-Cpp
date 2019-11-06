#ifndef FACADE_H_
#define FACADE_H_

#include "miscellaneous.h"
#include "Warriors.h"

#include <memory>
#include <optional>

template<typename T, typename Y>
class FightFacade final {
public:
	explicit FightFacade(std::unique_ptr<T> f1, std::unique_ptr<Y> f2) noexcept :
		fighter1(std::move(f1), fighter2(std::move(f2))) { }

	void showLocation() const;
	void showTotalAmountOfBetsAndValue() const;
	void showFighters() const;

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
	std::cout << "Total bets value: " << betsies->totalBetsValue();
}

template<typename T, typename Y>
void FightFacade<T, Y>::showFighters() const {
	std::optional<T>(fighter1->showStats());
	std::optional<Y>(fighter2->showStats());
}

#endif // ! FACADE_H_

