#include <iostream>
#include <string>
#include "TestPtrHandle.h"

template<typename T>
struct Vector {
	T x, y, z;
};

typedef Vector<float> Vectorf;
typedef Vector<int> Vectori;
typedef Vector<unsigned char> Vectorc;

int main(int argc, char** argv) {
		
	PoolAllocator pool;

	PtrHandle<int> phi = pool.allocateWithHandle<int>();
	phi.get() = 255;
	*phi = 123;
	pool.printTilNext();

	auto fixedArray = pool.allocateArray<Vectorc, 10>();

	fixedArray[0] = {255, 255, 255};
	fixedArray[1] = {255, 255, 255};

	pool.printTilNext();

	std::cin.get();

	return 0;
}