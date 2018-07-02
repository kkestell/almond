cmake_minimum_required(VERSION 2.8.9)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

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
  src/environment.cpp
  src/http_server.cpp
  src/response.cpp
  src/request.cpp
  src/router.cpp
  src/volume.cpp
  src/stubs.c
  src/wren/wren_compiler.c
  src/wren/wren_core.c
  src/wren/wren_debug.c
  src/wren/wren_primitive.c
  src/wren/wren_utils.c
  src/wren/wren_value.c
  src/wren/wren_vm.c
)

set(LOCAL_INCLUDES
  src
  src/wren
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
