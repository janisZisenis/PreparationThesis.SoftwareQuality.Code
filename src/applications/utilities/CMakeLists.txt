set(LIB_NAME utilities)

#clear variables
unset(TEST_SRCS)
unset(MY_SRCS)

##############################################################
###		INCLUDE CMAKE MACROS    						   ###
##############################################################

include(${CMAKE_SOURCE_DIR}/cmake/general/FileUtilities.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/general/LibUtilities.cmake)


##############################################################
###		INCLUDE PACKAGES								   ###
##############################################################

setLibOptionOn()

include(${CMAKE_SOURCE_DIR}/src/${LIB_NAME}/CMakePackage.cmake)


##############################################################
###		CREATE LIBRARY									   ###
##############################################################

set(MY_SRCS ${MY_SRCS} ${SPECIFIC_FILES})
createLIB(${LIB_NAME} ${LIB_TYPE} ${MY_SRCS})


##############################################################
###		SUBDIRECTORIES									   ###
##############################################################

add_subdirectory(testSuite)
