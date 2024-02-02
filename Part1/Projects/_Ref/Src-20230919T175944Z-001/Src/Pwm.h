#ifndef SRC_PWM_H_
#define SRC_PWM_H_

#include <stdint.h>


// PWM Range ESC
#define PWM_MIN 3200 // Command: 0%   thrust
#define PWM_MAX 6400 // Command: 100% thrust
#define PWM_DEADZONE 100


class Pwm
{
public:
	Pwm(int minCount=3200, int maxCount=6400, int deadzoneCount=0);
	int setPWM(float u);
	void setMin();

private:
	int minCount;
	int maxCount;
	int deadzoneCount;
	int rangeCount;

	// "Count" suffix refers to 16-bit Timer Count, for which
	// PWM Signal is high
};


#endif /* SRC_PWM_H_ */
