cmake_minimum_required(VERSION 2.6)

project("test_arduino_blink")

set (PROJECT_SOURCES	main.cpp)

include(../../frontends/arduino/arduino.cmake) 
include(../cmake/example.cmake)
