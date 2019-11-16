#include "Strategy.h"

#include <algorithm>

//DISCLAIMER!!!::: those sorts are temporary workarounds since i am working at implementing modern ones.

void HeapSort::sort(std::vector<int>& c) const {
	std::sort(std::begin(c), std::end(c));
}

void HeapSort::sort(std::list<int>& c) const {
	c.sort();
}

void QuickSort::sort(std::vector<int>& c) const {
	std::sort(std::begin(c), std::end(c)); 
}

void QuickSort::sort(std::list<int>& c) const {
	c.sort();
}

void MergeSort::sort(std::vector<int>& c) const {
	std::sort(std::begin(c), std::end(c));
}

void MergeSort::sort(std::list<int>& c) const {
	c.sort();
}
