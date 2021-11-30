CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
PROJECT(applibs C)

set(AZURE_SPHERE_REMOTE ON CACHE  BOOL "ENABLE AZURE SPHERE REMOTE" FORCE )

################################################################################
# Source groups
################################################################################
set(Source
    "comms_manager.c"
    "src/gpio.c"
    "src/i2c.c"
    "src/pwm.c"
    "src/log.c"
    "src/adc.c"
    "src/spi.c"
    "src/storage.c"
    "src/remotex.c"
)
source_group("Source" FILES ${Source})

set(ALL_FILES
    ${Source}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
target_link_libraries (${PROJECT_NAME} gcc_s c)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/HardwareDefinitions/inc")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/HardwareDefinitions/inc/hw")

target_compile_definitions(${PROJECT_NAME} PUBLIC AZURE_SPHERE_REMOTE)
