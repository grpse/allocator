#ifndef TESTPTRHANDLE_H
#define TESTPTRHANDLE_H

#include <PoolAllocator.h>
#include <PtrHandle.h>

struct Composite {
	int a;
};

PoolAllocator g_mem;
int g_counter = 0;

void testAll();
void testEvadingTheScope();
void testCopyingHandle();
PtrHandle<Composite> copyCompositeHandle();

void testAll() {

	testEvadingTheScope();
	testCopyingHandle();
}

void testEvadingTheScope() {

	g_mem.printTilNext();
	{
		PtrHandle<Composite> myHComp = copyCompositeHandle();
		myHComp->a = g_counter++;
	}
	g_mem.printTilNext();

	{
		PtrHandle<Composite> myHComp = g_mem.allocateWithHandle<Composite>();
		myHComp->a = g_counter++;
	}
	g_mem.printTilNext();
}

void testCopyingHandle() {

}

PtrHandle<Composite> copyCompositeHandle() {

	PtrHandle<Composite> hComp = g_mem.allocateWithHandle<Composite>();
	hComp->a = g_counter++;
	g_mem.printTilNext();
	return hComp;
}

#endif /*TESTPTRHANDLE_H*/