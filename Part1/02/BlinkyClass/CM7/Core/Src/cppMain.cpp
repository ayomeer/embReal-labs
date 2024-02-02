#include "cppMain.h"
#include "main.h"

#include "BlinkingLed.h"
#include "MemPool.h"
#include <memory> // for smart pointers

constexpr uint8_t NUMELEMENTS = 4;

void cppMain(){

	// create MemPool on heap
	auto sptr_LedMemPool = std::make_unique<MemPool<BlinkingLed, NUMELEMENTS>>();

	// allocate
	BlinkingLed* bl0 = sptr_LedMemPool->Allocate(); // first element problem!!!

	BlinkingLed* bl1 = sptr_LedMemPool->Allocate();
	bl1->setPortPin(LD1_GPIO_Port, LD1_Pin);
	bl1->setFrequency(4);

	BlinkingLed* bl2 = sptr_LedMemPool->Allocate();
	bl2->setPortPin(LD2_GPIO_Port, LD2_Pin);
	bl2->setFrequency(2);

	BlinkingLed* bl3 = sptr_LedMemPool->Allocate();
	bl3->setPortPin(LD3_GPIO_Port, LD3_Pin);
	bl3->setFrequency(1);

	while(1){
		bl1->processBlinking();
		bl2->processBlinking();
		bl3->processBlinking();
	}
}


