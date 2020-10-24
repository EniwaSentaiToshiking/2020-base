mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	DebugUtil.o \
	PIDCalculator.o \
	Straight.o \
	SetupGame.o \
	\
	TemplateGameState.o \
	GameStateManager.o \
	RunningGameState.o \
	BlockBingoGameState.o \
	GarageGameState.o \
	PlaygroundGameState.o \
	\
	InterfaceBehaviorModel.o \
	TemplateBehaviorModel.o \
	LineTraceBehaviorModel.o \
	SpinTurnBehaviorModel.o \
	StraightBehaviorModel.o \
	StopBehaviorModel.o \
	\
	InterfaceDeterminationModel.o \
	TemplateDeterminationModel.o \
	ColorDeterminationModel.o \
	DistanceDeterminationModel.o \
	SpinTurnAngleDeterminationModel.o \
	WaitTimeDterminationModel.o \
	\
	ColorSensorDeviceDriver.o \
	WheelDeviceDriver.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += \
	$(mkfile_path)app \
	$(mkfile_path)util \
	\
	$(mkfile_path)Ev3StateManager \
	\
	$(mkfile_path)GameStateManager \
	$(mkfile_path)GameStateManager/GameStates \
	$(mkfile_path)GameStateManager/GameStates/Template \
	\
	$(mkfile_path)BehaviorModel \
	\
	$(mkfile_path)DeterminationModel \
	\
	$(mkfile_path)Ev3DeviceDriver \
	\
	$(mkfile_path)Playground \
	$(mkfile_path)SetupGameTask \


INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)util \
	\
	-I$(mkfile_path)Ev3StateManager \
	\
	-I$(mkfile_path)GameStateManager \
	-I$(mkfile_path)GameStateManager/GameStates \
	-I$(mkfile_path)GameStateManager/GameStates/Template \
	\
	-I$(mkfile_path)BehaviorModel \
	\
	-I$(mkfile_path)DeterminationModel \
	\
	-I$(mkfile_path)Ev3DeviceDriver \
	\
	-I$(mkfile_path)Playground \
	-I$(mkfile_path)SetupGameTask \

#COPTS += -fno-use-cxa-atexit
