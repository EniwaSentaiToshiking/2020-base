mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
    ObjectDetector.o \
    GrayLineDetector.o \
    PointDetector.o \
    DistanceDetector.o \
    DirectionDetector.o \
    ColorDetector.o \
    BlackLineDetector.o \
    BrightnessDetector.o \
    ClockDetector.o \
    AdaptiveDirectionDetector.o \
    SonarSensorDriver.o \
    TouchSensorDriver.o \
    ColorSensorDriver.o \
    WheelMotorDriver.o \
    ArmMotorDriver.o \
    TailMotorDriver.o \
    RunCommander.o \
    ArmCommander.o \
    TailCommander.o \
    WheelInfo.o \
    Localization.o \
    CourseMonitor.o \
    Lot.o \
    SpeedCal.o \
    UI.o \
    PID.o \
    PIDController.o \
    Filter.o \
    Logger.o \
    RunStatus.o \
    CourseRun.o \
    SampleCourseRun.o \
    Parking.o \
    Stop.o \
    RunStyle.o \
    LineTrace.o \
    Grid.o \
    Straight.o \
    Turning.o \
    Spin.o \
    Clothoid.o \
    RunPattern.o \
    RunManager.o \


SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += \
    $(mkfile_path)/Detectors \
    $(mkfile_path)/Devices \
    $(mkfile_path)/Observer \
    $(mkfile_path)/UI \
    $(mkfile_path)/Utils \
    $(mkfile_path)/RunStyles \
    $(mkfile_path)/RunMethods \
    $(mkfile_path)/RunMethods/Commanders \
    $(mkfile_path)/RunMethods/Status \

INCLUDES += \
    -I$(mkfile_path)/Detectors \
    -I$(mkfile_path)/Devices \
    -I$(mkfile_path)/Observer \
    -I$(mkfile_path)/UI \
    -I$(mkfile_path)/Utils \
    -I$(mkfile_path)/RunStyles \
    -I$(mkfile_path)/RunMethods \
    -I$(mkfile_path)/RunMethods/Commanders \
    -I$(mkfile_path)/RunMethods/Status \
