mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	DebugUtil.o \
	PIDCalculator.o \
	Straight.o \
	SetupGame.o \
	RunningGameState.o \
	PlaygroundGameState.o \
	GameStateManager.o \
	ColorSensorDeviceDriver.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += \
	$(mkfile_path)app \
	$(mkfile_path)util \
	$(mkfile_path)GameStateManager \
	$(mkfile_path)Playground \
	$(mkfile_path)Ev3DeviceDriver \


INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)util \
	-I$(mkfile_path)GameStateManager \
	-I$(mkfile_path)Playground \
	-I$(mkfile_path)Ev3DeviceDriver \

#COPTS += -fno-use-cxa-atexit
