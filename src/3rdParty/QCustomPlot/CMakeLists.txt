cmake_minimum_required(VERSION 2.6.2)

set(LIB_NAME QCustomPlot)

project(${LIB_NAME})

#clear variables
unset(TEST_SRCS)
unset(MY_SRCS)

						
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

#############################################################
###		INLCUDE MACROS									  ###
#############################################################

include (GenerateExportHeader)


#############################################################
###		SOURCE FILES									  ###
#############################################################

FILE(GLOB CPP_FILES ${CMAKE_SOURCE_DIR}/*.cpp)
FILE(GLOB H_FILES ${CMAKE_SOURCE_DIR}/*.h)

set(MY_SRCS ${CPP_FILES} ${H_FILES})
source_group(src FILES ${MY_SRCS})


#############################################################
###		CREATE LIB_NAME									  ###
#############################################################

add_library(${LIB_NAME} SHARED ${MY_SRCS})

GENERATE_EXPORT_HEADER	(	${LIB_NAME}
							BASE_NAME ${LIB_NAME}
							EXPORT_MACRO_NAME ${LIB_NAME}_EXPORT
							EXPORT_FILE_NAME ${LIB_NAME}_Export.h
							STATIC_DEFINE ${LIB_NAME}_BUILT_AS_STATIC
						)
						

#############################################################
###		LINK QT											  ###
#############################################################


FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(Qt5PrintSupport)

INCLUDE_DIRECTORIES(${QT5Widgets_INCLUDES})
INCLUDE_DIRECTORIES(${QT5Core_INCLUDES})
INCLUDE_DIRECTORIES(${QT5Gui_INCLUDES})
INCLUDE_DIRECTORIES(${QT5PrintSupport_INCLUDES})

ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS})
ADD_DEFINITIONS(${Qt5Core_DEFINITIONS})
ADD_DEFINITIONS(${Qt5Gui_DEFINITIONS})
ADD_DEFINITIONS(${Qt5PrintSupport_DEFINITIONS})

TARGET_LINK_LIBRARIES(${LIB_NAME} Qt5::Widgets)
TARGET_LINK_LIBRARIES(${LIB_NAME} Qt5::Core)
TARGET_LINK_LIBRARIES(${LIB_NAME} Qt5::PrintSupport)

