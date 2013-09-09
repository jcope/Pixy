##########################################
#        EMMA TECHNOLOGIES, L.L.C.       #
#           Copyright (c) 2013.          #
#           All rights reserved.         #
##########################################
include ${__TOOLDIR}/mk/header.mk
##########################################

SOURCE = main.cpp

INCLUDES = \
	-I.\
	-I./src/include\
	-I./src\
	-I./src/3rdParty/Arduino\
	-I./src/3rdParty/Arduino/ArduinoCore\
	-I./src/3rdParty/Arduino/varients/standard

PROGRAM_DEPENDENCIES = \
	$(OBJDIR)/$(SOURCE:.cpp=.$(OBJEXT))

PROGRAM_MODULES = \
	${__ROOTDIR}/src/DisplayMatrix\
	${__ROOTDIR}/src/DisplayManager\
	${__ROOTDIR}/src/Utilities\
	${__ROOTDIR}/src/Demo


PROGRAM_LIBRARIES = \
	-lDisplayMatrix\
	-lDisplayManager\
	-lUtilities\
	-lDemo

ifeq (${__TARGET},ARDUINO)


PROGRAM_MODULES :=\
	${__ROOTDIR}/src/3rdParty/Arduino/ArduinoCore\
	${__ROOTDIR}/src/3rdParty/Arduino/SPI\
	${__ROOTDIR}/src/3rdParty/Arduino/ShiftPWM\
	${__ROOTDIR}/src/DisplayMatrix\
	${__ROOTDIR}/src/DisplayManager\
	${__ROOTDIR}/src/Utilities\
	${__ROOTDIR}/src/Demo

PROGRAM_LIBRARIES := \
	-lShiftPWM\
	-lDisplayMatrix\
	-lDisplayManager\
	-lUtilities\
	-lDemo\
	-lSPI\
	-lArduinoCore
endif

PROGRAM_LIB_INCLUDES = \
	-L./lib

##Make sure to define the default and clean rules for directory
default: program
clean: clean_all

##########################################
include ${__TOOLDIR}/mk/footer.mk


