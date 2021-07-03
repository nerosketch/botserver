cmake_minimum_required (VERSION 3.5)
project( botserver )

set( APP_NAME botserver )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_VERBOSE_MAKEFILE ON )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-result" )
#set( CMAKE_BUILD_TYPE RELEASE )
set( CMAKE_BUILD_TYPE DEBUG )

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE RELEASE)
endif()

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -D_DEBUG" )
endif()

aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/core SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/dialogs SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/quest SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/storage SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/user SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/messages SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/third_party SRC )

#set( SRC ${SRC}
#	${CMAKE_CURRENT_SOURCE_DIR}/src/third_party/libscgi/parser.cpp
#	${CMAKE_CURRENT_SOURCE_DIR}/src/third_party/libscgi/scgiServer.cpp)

set( LIBS
	config++
	pthread
	systemd
	# event
	 )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

#find_package(CURL REQUIRED)
#if(CURL_FOUND)
#	include_directories(${CURL_INCLUDE_DIR})
#	set(LIBS ${LIBS} ${CURL_LIBRARIES} )
#else(CURL_FOUND)
#	message(fatal_error "Could not find the CURL library and development files.")
#endif(CURL_FOUND)

# Target libconfig
# find_path(CONFIGCPP_INCLUDES_FOLDER NAMES log4cpp/Appender.hh)
find_library(LIBCONFIG_PLUSPLUS libconfig++ REQUIRED)
if (LIBCONFIG_PLUSPLUS)
	include_directories(${LIBCONFIG_PLUSPLUS_INCLUDE_DIRS})
	message("Libconfig libs" ${LIBCONFIG_PLUSPLUS_LIBRARIES})
endif()

include(FetchContent)

# Target nlohmann/json
FetchContent_Declare(json
  GIT_REPOSITORY git://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
  GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
  set(LIBS ${LIBS} nlohmann_json::nlohmann_json )
endif()


# restinio HTTP Library target
set(RESTINIO_USE_EXTERNAL_HTTP_PARSER ON)
set(RESTINIO_FMT_HEADER_ONLY OFF)
find_package(fmt REQUIRED)
FetchContent_Declare(restinio
  GIT_REPOSITORY git://github.com/Stiffstream/restinio.git
  GIT_TAG master)
FetchContent_GetProperties(restinio)
if(NOT restinio_POPULATED)
  FetchContent_Populate(restinio)
  add_subdirectory(${restinio_SOURCE_DIR}/dev ${restinio_BINARY_DIR} EXCLUDE_FROM_ALL)
  set(LIBS ${LIBS} restinio::restinio)
endif()


add_executable( ${APP_NAME} ${SRC} )

target_link_libraries( ${APP_NAME} PRIVATE
	${LIBS} )

if (WIN32) #disable console mode for VC++
	set_target_properties( ${APP_NAME} PROPERTIES WIN32_EXECUTABLE TRUE )
endif(WIN32)
