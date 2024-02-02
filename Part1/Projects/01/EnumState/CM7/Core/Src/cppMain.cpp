#include "cppMain.h"
#include "main.h"
#include <map>

bool NonBlocking_Delay(uint32_t Delay);

enum class Led {GREEN=1, RED=3};
void toggleLED(Led led);


// State machine
enum class State {SLOW, FAST};
// Advantage 'enum class' over 'enum':
// - names local -> can reuse names for different enum classes
// - names don't convert to numbers -> debug shows names

class StateMachine {
private:
	Led led;
	State currentState = State::SLOW;
	std::map<State, State> stateTransition = { // Transition Table
			{State::SLOW, State::FAST},        // using std::map
			{State::FAST, State::SLOW}
	};
	uint32_t blinkCounter = 0;
	uint32_t maxBlink;
	uint32_t lowRateHz;
	uint32_t highRateHz;

public:
	StateMachine(Led led,
				 uint32_t maxBlink,
				 uint32_t lowRateHz,
				 uint32_t highRateHz){

		this->led = led;
		this->maxBlink = maxBlink;
		this->lowRateHz = lowRateHz;
		this->highRateHz = highRateHz;
	}
	void blink(){ // fsmExecute()
		// transition condition
		if (blinkCounter > maxBlink){
			currentState = stateTransition[currentState];
			blinkCounter = 0;
		}

		switch(currentState){
		case State::SLOW:
			if (this->NonBlocking_Delay((float)(1000/lowRateHz))){
				toggleLED(led);
				blinkCounter++;
			}
			break;

		case State::FAST:
			if (this->NonBlocking_Delay((float)(1000/highRateHz))){
				toggleLED(led);
				blinkCounter++;
			}
			break;
		}
	}

	bool NonBlocking_Delay(uint32_t Delay){
		static bool flag_init = true;
		static uint32_t wait;
		static uint32_t tickstart;

		if (flag_init == true){
			flag_init = false;

			wait = Delay;
			tickstart = HAL_GetTick();

			if (wait < HAL_MAX_DELAY){
				wait += (uint32_t)(uwTickFreq);
			}
		}

		// Delay logic
		if ((HAL_GetTick() - tickstart) < wait) // not enough time passed
		{
			return false;
		}
		else{ // waited for given amount of time --> re-initialize on next entry
			flag_init = true;
			return true;
		}
	}
};

void toggleLED(Led led){
	if(led == Led::GREEN){HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);}
	else if(led == Led::RED){HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);}
	return;
}




void cppMain(){
	// Init
	StateMachine sm1(Led::GREEN, 5,1,3);
	StateMachine sm2(Led::RED, 5,1,2);

	while(1){
		sm1.blink();
		sm2.blink();
	}
}

