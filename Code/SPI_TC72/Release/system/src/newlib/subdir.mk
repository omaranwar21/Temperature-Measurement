################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/newlib/assert.c \
../system/src/newlib/exit.c \
../system/src/newlib/sbrk.c \
../system/src/newlib/startup.c \
../system/src/newlib/syscalls.c 

CPP_SRCS += \
../system/src/newlib/cxx.cpp 

OBJS += \
./system/src/newlib/assert.o \
./system/src/newlib/cxx.o \
./system/src/newlib/exit.o \
./system/src/newlib/sbrk.o \
./system/src/newlib/startup.o \
./system/src/newlib/syscalls.o 

C_DEPS += \
./system/src/newlib/assert.d \
./system/src/newlib/exit.d \
./system/src/newlib/sbrk.d \
./system/src/newlib/startup.d \
./system/src/newlib/syscalls.d 

CPP_DEPS += \
./system/src/newlib/cxx.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/newlib/%.o: ../system/src/newlib/%.c system/src/newlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Delay" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\TC72" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Lib" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Gpio" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\LCD" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Led" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Rcc" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\SPI" -I"../include" -I"../system/include" -I"../system/include/cmsis" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/newlib/%.o: ../system/src/newlib/%.cpp system/src/newlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/newlib/startup.o: ../system/src/newlib/startup.c system/src/newlib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -DOS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Delay" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\TC72" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Lib" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Gpio" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\LCD" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Led" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\Rcc" -I"D:\SBME 2024 assets\Courses\Mastering Microcontroller and Embedded Driver Development\Drivers\SPI_TC72\SPI" -I"../include" -I"../system/include" -I"../system/include/cmsis" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


