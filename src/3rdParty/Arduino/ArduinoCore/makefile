##########################################
#        EMMA TECHNOLOGIES, L.L.C.       #
#           Copyright (c) 2013.          #
#           All rights reserved.         #
##########################################
include ${__TOOLDIR}/mk/header.mk
##########################################
MODULENAME = $(shell pwd | rev | awk -F \/ '{print $$1}' | rev)
LIB = lib$(MODULENAME)


INCLUDES = \
	-I.\
	-I${__ROOTDIR}\
	-I${__AVRTOOLCHAINDIR}/avr/include\
	-I../varients/standard

##Make sure to define the default and clean rules for directory
default: library
clean: clean_library

#########################################
include ${__TOOLDIR}/mk/footer.mk
