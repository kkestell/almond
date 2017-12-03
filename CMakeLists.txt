cmake_minimum_required(VERSION 2.8.9)
if (NOT DEFINED ENV{INCLUDEOS_PREFIX})
  set(ENV{INCLUDEOS_PREFIX} /usr/local)
endif()
include($ENV{INCLUDEOS_PREFIX}/includeos/pre.service.cmake)
project (service)

set(CMAKE_MODULE_PATH "/Users/kkestell/src/almond/cmake/modules")

find_package(LuaJIT REQUIRED)

set(SERVICE_NAME "Almond")

set(BINARY "almond")

set(SOURCES
  almond.cpp
)

set(LOCAL_INCLUDES
  "."
  ${LUAJIT_INCLUDE_DIR}
)

set(DRIVERS
  # virtionet   # Virtio networking
  # virtioblock # Virtio block device
  # ... Others from IncludeOS/src/drivers
)

set(PLUGINS
  # syslogd    # Syslog over UDP
  # ...others
)

# STATIC LIBRARIES:
set(LIBRARIES
  ${LUAJIT_LIBRARIES}
)

include($ENV{INCLUDEOS_PREFIX}/includeos/post.service.cmake)

# Create in-memory filesystem from folder
#diskbuilder(my_folder)
