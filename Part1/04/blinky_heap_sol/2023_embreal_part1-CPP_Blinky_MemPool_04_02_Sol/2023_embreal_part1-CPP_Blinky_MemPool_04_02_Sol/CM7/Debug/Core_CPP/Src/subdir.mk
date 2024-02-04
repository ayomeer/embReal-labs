################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core_CPP/Src/BlinkingLed.cpp \
../Core_CPP/Src/NonBlockingDelay.cpp \
../Core_CPP/Src/NoneBlockSystemTickDelay.cpp \
../Core_CPP/Src/STM32H7led.cpp 

OBJS += \
./Core_CPP/Src/BlinkingLed.o \
./Core_CPP/Src/NonBlockingDelay.o \
./Core_CPP/Src/NoneBlockSystemTickDelay.o \
./Core_CPP/Src/STM32H7led.o 

CPP_DEPS += \
./Core_CPP/Src/BlinkingLed.d \
./Core_CPP/Src/NonBlockingDelay.d \
./Core_CPP/Src/NoneBlockSystemTickDelay.d \
./Core_CPP/Src/STM32H7led.d 


# Each subdirectory must supply rules for building sources it contributes
Core_CPP/Src/%.o Core_CPP/Src/%.su Core_CPP/Src/%.cyclo: ../Core_CPP/Src/%.cpp Core_CPP/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core_CPP/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core_CPP-2f-Src

clean-Core_CPP-2f-Src:
	-$(RM) ./Core_CPP/Src/BlinkingLed.cyclo ./Core_CPP/Src/BlinkingLed.d ./Core_CPP/Src/BlinkingLed.o ./Core_CPP/Src/BlinkingLed.su ./Core_CPP/Src/NonBlockingDelay.cyclo ./Core_CPP/Src/NonBlockingDelay.d ./Core_CPP/Src/NonBlockingDelay.o ./Core_CPP/Src/NonBlockingDelay.su ./Core_CPP/Src/NoneBlockSystemTickDelay.cyclo ./Core_CPP/Src/NoneBlockSystemTickDelay.d ./Core_CPP/Src/NoneBlockSystemTickDelay.o ./Core_CPP/Src/NoneBlockSystemTickDelay.su ./Core_CPP/Src/STM32H7led.cyclo ./Core_CPP/Src/STM32H7led.d ./Core_CPP/Src/STM32H7led.o ./Core_CPP/Src/STM32H7led.su

.PHONY: clean-Core_CPP-2f-Src

