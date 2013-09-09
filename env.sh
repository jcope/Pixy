#! /bin/bash
##################################
#    EMMA TECHNOLOGIES, L.L.C.
#       Copyright (c) 2013.
#       All rights reserved.
##################################
#Determine the OS

export __AVRTOOLCHAINDIR=/usr/local/CrossPack-AVR

#System Path Variables
export __ROOTDIR=`pwd`
export __TOOLDIR=${__ROOTDIR}/tools
export __SRCDIR=${__ROOTDIR}/src

#Build, Runtime Variables
export DYLD_LIBRARY_PATH=${DYLD_LIBRARY_PATH}:${__ROOTDIR}/lib
