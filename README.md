# Part 1

## Week 1
- Blinky (C)
  - Using toggle and delay functions from HAL
- NonBlockingDely (C)
  - Blinky Non-Blocking delay using `SystemTick`
- EnumState (C++)
  - Enum State Machine

## Week 2
- BlinkyClass
  - Non-Blocking delay using `SystemTick` to write **software-delay class**
  - Using **namespace** `myhal` to organize LED class and non-blocking delay class into a package
  - Heap memory pool using smartpointer

## Week 3
- autoconsole (C++)
  - auto type
  - print to console
 
- IKS01A3 (C++)
  - `Motion`-class for Gyro and Accelerometer
  - Circular buffer as array container 
  - Buffer mean using array container iterator
  - `#define SPIRITLEVEL` -> **Kormanyo vector ringbuffer** (.data) for sensor data averaging
 
# Importing as CubeIDE Project

1) Pull Repo (if updating, do `git reset @{u}` beforehand)
2) Delete .location files for project and sub-projects under ´.metadata\.plugins\org.eclipse.core.resources\.projects´
3) Open CubeIDE using *different workspace* than the repo itself
4) Import Existing Project and wait for indexer to finish
5) Build sub-projects

Should even have run configurations ready
