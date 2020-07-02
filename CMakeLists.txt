cmake_minimum_required (VERSION 2.6)
project( botserver )

set( APP_NAME botserver )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_VERBOSE_MAKEFILE ON )
#set( CMAKE_BUILD_TYPE RELEASE )
set( CMAKE_BUILD_TYPE DEBUG )

aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/core SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/ExternalApi SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/quest SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/storage SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/user SRC )

set( LIBS
	config++)

find_package(CURL)
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

add_executable( ${APP_NAME} ${SRC} )

target_link_libraries( ${APP_NAME}
	${LIBS} )

if (WIN32) #disable console mode for VC++
	set_target_properties( ${APP_NAME} PROPERTIES WIN32_EXECUTABLE TRUE )
endif(WIN32)

