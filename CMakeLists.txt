cmake_minimum_required (VERSION 2.6)
project( botserver )

set( APP_NAME botserver )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_VERBOSE_MAKEFILE ON )
#set( CMAKE_BUILD_TYPE RELEASE )
set( CMAKE_BUILD_TYPE DEBUG )

AUX_SOURCE_DIRECTORY( ${CMAKE_CURRENT_SOURCE_DIR}/src SRC )

set( LIBS )

FIND_PACKAGE(CURL)
IF(CURL_FOUND)
INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
SET(LIBS ${LIBS} ${CURL_LIBRARIES} )
ELSE(CURL_FOUND)
MESSAGE(FATAL_ERROR "Could not find the CURL library and development files.")
ENDIF(CURL_FOUND)

add_executable( ${APP_NAME} ${SRC} )

target_link_libraries( ${APP_NAME}
	${LIBS} )

if (WIN32) #disable console mode for VC++
	set_target_properties( ${APP_NAME} PROPERTIES WIN32_EXECUTABLE TRUE )
endif(WIN32)

