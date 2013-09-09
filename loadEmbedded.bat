::##################################
::#    EMMA TECHNOLOGIES, L.L.C.
::#       Copyright (c) 2013.
::#       All rights reserved.
::##################################
@echo off

::Program Settings
set HEXFILE="bin\Pixy.hex"

::Set Tool Locations
set AVRDUDE="C:\Program Files\WinAvr\bin\avrdude"
::set AVRDUDEFLAGS=-pm328p -carduino -PCOM3 -b115200 -Uflash:w:%HEXFILE%:a
set AVRDUDEFLAGS=-CC:\Users\Jeremy\Tools\arduino-1.0.3\hardware/tools/avr/etc/avrdude.conf -patmega328p -carduino -P\\.\COM6 -b115200 -D -Uflash:w:%HEXFILE%:a

::Execute Commands
echo %AVRDUDE% %AVRDUDEFLAGS%
%AVRDUDE% %AVRDUDEFLAGS%
echo "Done"
