################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/hts221/hts221.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/hts221/hts221_reg.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2dw12/lis2dw12.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2dw12/lis2dw12_reg.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2mdl/lis2mdl.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2mdl/lis2mdl_reg.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lps22hh/lps22hh.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lps22hh/lps22hh_reg.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lsm6dso/lsm6dso.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lsm6dso/lsm6dso_reg.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/stts751/stts751.c \
D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/stts751/stts751_reg.c 

C_DEPS += \
./Drivers/BSP/Components/hts221.d \
./Drivers/BSP/Components/hts221_reg.d \
./Drivers/BSP/Components/lis2dw12.d \
./Drivers/BSP/Components/lis2dw12_reg.d \
./Drivers/BSP/Components/lis2mdl.d \
./Drivers/BSP/Components/lis2mdl_reg.d \
./Drivers/BSP/Components/lps22hh.d \
./Drivers/BSP/Components/lps22hh_reg.d \
./Drivers/BSP/Components/lsm6dso.d \
./Drivers/BSP/Components/lsm6dso_reg.d \
./Drivers/BSP/Components/stts751.d \
./Drivers/BSP/Components/stts751_reg.d 

OBJS += \
./Drivers/BSP/Components/hts221.o \
./Drivers/BSP/Components/hts221_reg.o \
./Drivers/BSP/Components/lis2dw12.o \
./Drivers/BSP/Components/lis2dw12_reg.o \
./Drivers/BSP/Components/lis2mdl.o \
./Drivers/BSP/Components/lis2mdl_reg.o \
./Drivers/BSP/Components/lps22hh.o \
./Drivers/BSP/Components/lps22hh_reg.o \
./Drivers/BSP/Components/lsm6dso.o \
./Drivers/BSP/Components/lsm6dso_reg.o \
./Drivers/BSP/Components/stts751.o \
./Drivers/BSP/Components/stts751_reg.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/hts221.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/hts221/hts221.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/hts221_reg.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/hts221/hts221_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lis2dw12.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2dw12/lis2dw12.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lis2dw12_reg.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2dw12/lis2dw12_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lis2mdl.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2mdl/lis2mdl.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lis2mdl_reg.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lis2mdl/lis2mdl_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lps22hh.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lps22hh/lps22hh.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lps22hh_reg.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lps22hh/lps22hh_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lsm6dso.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lsm6dso/lsm6dso.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/lsm6dso_reg.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/lsm6dso/lsm6dso_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/stts751.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/stts751/stts751.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/stts751_reg.o: D:/git_repos/embReal-labs/Part1/03/IKS01A3/Drivers/BSP/Components/stts751/stts751_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../../Drivers/BSP/Components/lsm6dso -I../../Drivers/BSP/Components/lis2dw12 -I../../Drivers/BSP/Components/lis2mdl -I../../Drivers/BSP/Components/hts221 -I../../Drivers/BSP/Components/lps22hh -I../../Drivers/BSP/Components/stts751 -I../../Drivers/BSP/IKS01A3 -I../../Drivers/BSP/Components/Common -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/hts221.cyclo ./Drivers/BSP/Components/hts221.d ./Drivers/BSP/Components/hts221.o ./Drivers/BSP/Components/hts221.su ./Drivers/BSP/Components/hts221_reg.cyclo ./Drivers/BSP/Components/hts221_reg.d ./Drivers/BSP/Components/hts221_reg.o ./Drivers/BSP/Components/hts221_reg.su ./Drivers/BSP/Components/lis2dw12.cyclo ./Drivers/BSP/Components/lis2dw12.d ./Drivers/BSP/Components/lis2dw12.o ./Drivers/BSP/Components/lis2dw12.su ./Drivers/BSP/Components/lis2dw12_reg.cyclo ./Drivers/BSP/Components/lis2dw12_reg.d ./Drivers/BSP/Components/lis2dw12_reg.o ./Drivers/BSP/Components/lis2dw12_reg.su ./Drivers/BSP/Components/lis2mdl.cyclo ./Drivers/BSP/Components/lis2mdl.d ./Drivers/BSP/Components/lis2mdl.o ./Drivers/BSP/Components/lis2mdl.su ./Drivers/BSP/Components/lis2mdl_reg.cyclo ./Drivers/BSP/Components/lis2mdl_reg.d ./Drivers/BSP/Components/lis2mdl_reg.o ./Drivers/BSP/Components/lis2mdl_reg.su ./Drivers/BSP/Components/lps22hh.cyclo ./Drivers/BSP/Components/lps22hh.d ./Drivers/BSP/Components/lps22hh.o ./Drivers/BSP/Components/lps22hh.su ./Drivers/BSP/Components/lps22hh_reg.cyclo ./Drivers/BSP/Components/lps22hh_reg.d ./Drivers/BSP/Components/lps22hh_reg.o ./Drivers/BSP/Components/lps22hh_reg.su ./Drivers/BSP/Components/lsm6dso.cyclo ./Drivers/BSP/Components/lsm6dso.d ./Drivers/BSP/Components/lsm6dso.o ./Drivers/BSP/Components/lsm6dso.su ./Drivers/BSP/Components/lsm6dso_reg.cyclo ./Drivers/BSP/Components/lsm6dso_reg.d ./Drivers/BSP/Components/lsm6dso_reg.o ./Drivers/BSP/Components/lsm6dso_reg.su ./Drivers/BSP/Components/stts751.cyclo ./Drivers/BSP/Components/stts751.d ./Drivers/BSP/Components/stts751.o ./Drivers/BSP/Components/stts751.su ./Drivers/BSP/Components/stts751_reg.cyclo ./Drivers/BSP/Components/stts751_reg.d ./Drivers/BSP/Components/stts751_reg.o ./Drivers/BSP/Components/stts751_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

