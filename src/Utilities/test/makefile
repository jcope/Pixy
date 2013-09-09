##########################################
#        EMMA TECHNOLOGIES, L.L.C.       #
#           Copyright (c) 2013.          #
#           All rights reserved.         #
##########################################
include ${__TOOLDIR}/mk/header.mk
##########################################
Module = $(shell pwd | rev | awk -F \/ '{print $$2}' | rev)
UnitTest = $(Module)_UT
LIB = lib$(UnitTest)
Library2UnitTest = $(Module)
UT_Main = ${__ROOTDIR}/test/main.o

default: unittest
clean: clean_unittest

#TODO
#UT_DEPENDENCIES = $(Library2UnitTest) $(UT_Main) 
UT_DEPENDENCIES = $(UT_Main)

INCLUDES = \
	-I.\
	-I${__ROOTDIR}\
	-I${__ROOTDIR}/src/include\
	-I${__TOOLDIR}

LIBS = \
	-lgtest\
	-l$(Module)

LIBS_PATH = \
	-L.\
	-L..\
	-L${__TOOLDIR}/gtest

#########################################
include ${__TOOLDIR}/mk/footer.mk
