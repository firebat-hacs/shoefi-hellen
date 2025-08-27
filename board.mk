BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp \


BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# this is usually used by Bluetooth
DDEFS += $(PRIMARY_COMMUNICATION_PORT_USART2)

# Override problematic compiler flag that causes build errors
# This removes the -Wno-delete-non-abstract-non-virtual-dtor flag from RUSEFI_OPT
RUSEFI_OPT := $(filter-out -Wno-delete-non-abstract-non-virtual-dtor,$(RUSEFI_OPT))

# this includes knock and mux control settings
include $(BOARDS_DIR)/hellen/hellen-common-mega144.mk

ONBOARD_MEMS_TYPE=LIS2DH12
