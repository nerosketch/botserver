cmake_minimum_required (VERSION 3.11)
project( botserver )

set( APP_NAME botserver )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_VERBOSE_MAKEFILE ON )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-result" )
#set( CMAKE_BUILD_TYPE RELEASE )
#set( CMAKE_BUILD_TYPE DEBUG )

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE RELEASE)
endif()

aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/core SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/ExternalApi SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/quest SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/storage SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/user SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/httpserver SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/third_party SRC )

set( SRC ${SRC}
	${CMAKE_CURRENT_SOURCE_DIR}/src/third_party/libscgi/parser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/third_party/libscgi/scgiServer.cpp)

set( LIBS
	config++
	event )

find_package(CURL REQUIRED)
if(CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIR})
	set(LIBS ${LIBS} ${CURL_LIBRARIES} )
else(CURL_FOUND)
	message(fatal_error "Could not find the CURL library and development files.")
endif(CURL_FOUND)

# Target libconfig
# find_path(CONFIGCPP_INCLUDES_FOLDER NAMES log4cpp/Appender.hh)
find_library(LIBCONFIG_PLUSPLUS libconfig++ REQUIRED)
if (LIBCONFIG_PLUSPLUS)
	include_directories(${LIBCONFIG_PLUSPLUS_INCLUDE_DIRS})
	message("Libconfig libs" ${LIBCONFIG_PLUSPLUS_LIBRARIES})
endif()


# Target nlohmann/json
include(FetchContent)
FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
  set(LIBS ${LIBS} nlohmann_json::nlohmann_json )
endif()



add_executable( ${APP_NAME} ${SRC} )

target_link_libraries( ${APP_NAME}
	${LIBS} )

if (WIN32) #disable console mode for VC++
	set_target_properties( ${APP_NAME} PROPERTIES WIN32_EXECUTABLE TRUE )
endif(WIN32)

