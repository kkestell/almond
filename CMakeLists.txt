cmake_minimum_required(VERSION 2.8.9)

if (NOT DEFINED ENV{INCLUDEOS_PREFIX})
  set(ENV{INCLUDEOS_PREFIX} /usr/local)
endif()

include($ENV{INCLUDEOS_PREFIX}/includeos/pre.service.cmake)

project(service)

set(SERVICE_NAME "Almond")

set(BINARY "almond")

set(SOURCES
  src/main.cpp
  src/duktape/duktape.c
  src/context.cpp
  src/volume.cpp
  src/environment.cpp
)

set(LOCAL_INCLUDES
  src
  src/duktape
  src/dukglue
)

set(DRIVERS
)

set(PLUGINS
)

set(LIBRARIES
)

include($ENV{INCLUDEOS_PREFIX}/includeos/post.service.cmake)

diskbuilder(disk disk.img)
