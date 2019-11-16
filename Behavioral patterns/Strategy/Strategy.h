#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <memory>
#include <list>
#include <vector>

class Sort {
public:
	virtual void sort(std::vector<int>&) const = 0;
	virtual void sort(std::list<int>&) const = 0;
};

class HeapSort : public Sort {
public:
	virtual void sort(std::vector<int>&) const override;
	virtual void sort(std::list<int>&) const override;
};

class QuickSort : public Sort {
public:
	virtual void sort(std::vector<int>&) const override;
	virtual void sort(std::list<int>&) const override;
};

class MergeSort : public Sort {
public:
	virtual void sort(std::vector<int>&) const override;
	virtual void sort(std::list<int>&) const override;
};

class SortingStrategy final {
public:
	void sort(std::vector<int>& c) {
		sorter->sort(c);
	}

	void sort(std::list<int>& c) {
		sorter->sort(c);
	}

	void setSorter(std::unique_ptr<Sort>& _sorter) {
		sorter = std::move(_sorter);
	}

private:
	std::unique_ptr<Sort> sorter;
};

#endif