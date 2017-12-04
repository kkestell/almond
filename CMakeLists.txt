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
  src/context.cpp
  src/duktape/duktape.c
  src/environment.cpp
  src/volume.cpp
  src/http_server.cpp
)

set(LOCAL_INCLUDES
  src
  src/duktape
)

if ("$ENV{PLATFORM}" STREQUAL "x86_solo5")
  set(DRIVERS
    solo5net
  )
else()
  set(DRIVERS
    virtionet
  )
endif()

set(PLUGINS
  autoconf
)

set(LIBRARIES
)

include($ENV{INCLUDEOS_PREFIX}/includeos/post.service.cmake)

diskbuilder(disk disk.img)
