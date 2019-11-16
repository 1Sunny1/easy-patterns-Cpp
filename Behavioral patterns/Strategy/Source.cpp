#include "Strategy.h"

#include <iostream>
#include <iterator>

int main() {
	std::unique_ptr<Sort> heap = std::make_unique<HeapSort>();
	std::unique_ptr<Sort> quick = std::make_unique<QuickSort>();
	std::unique_ptr<Sort> merge = std::make_unique<MergeSort>();

	SortingStrategy sorter;
	std::vector<int> intvcoll = { 9,8,6,432,5,765,23,65,8,423,76,432,54,7,54,54,56,76,321 };
	std::list<int> intlcoll = { 35,7,3,2,5,7,43,2,75,32,21,54,786,432,21,2,32,4,5,67,7,213 };

	sorter.setSorter(heap);
	std::cout << "Before sorting:\n";
	std::copy(std::begin(intvcoll), std::end(intvcoll), std::ostream_iterator<int>(std::cout, " "));

	sorter.sort(intvcoll);

	std::cout << "\nAfter sorting:\n";
	std::copy(std::begin(intvcoll), std::end(intvcoll), std::ostream_iterator<int>(std::cout, " "));

	sorter.setSorter(merge);

	std::cout << "\nBefore sorting:\n";
	std::copy(std::begin(intlcoll), std::end(intlcoll), std::ostream_iterator<int>(std::cout, " "));

	sorter.sort(intlcoll);

	std::cout << "\nAfter sorting:\n";
	std::copy(std::begin(intlcoll), std::end(intlcoll), std::ostream_iterator<int>(std::cout, " "));

	std::cout << '\n';
	system("pause");
	return 0;
}