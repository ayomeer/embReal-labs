#include <BlinkingLed.h>
#include "cppMain.h"
#include "main.h"

#include "MemPool.h"
#include <memory> // for smart pointers

constexpr uint32_t NUMELEMENTS = 4; // 3 used + 1 for workaround

void cppMain(){

	// create MemPool on heap
	auto sptr_LedMemPool = std::make_unique<MemPool<BlinkingLed, 4>>();

	// allocate
	BlinkingLed* bl0 = sptr_LedMemPool->Allocate(); // first element problem!!!

	BlinkingLed* bl1 = sptr_LedMemPool->Allocate();
	bl1->setFrequency(4);
	bl1->setPinPort(LD1_GPIO_Port, LD1_Pin);



	BlinkingLed* bl2 = sptr_LedMemPool->Allocate();
	bl2->setFrequency(2);
	bl2->setPinPort(LD2_GPIO_Port, LD2_Pin);

	BlinkingLed* bl3 = sptr_LedMemPool->Allocate();
	bl3->setFrequency(1);
	bl3->setPinPort(LD3_GPIO_Port, LD3_Pin);

	while(1){
		bl1->processBlinking();
		bl2->processBlinking();
		bl3->processBlinking();
	}
}




