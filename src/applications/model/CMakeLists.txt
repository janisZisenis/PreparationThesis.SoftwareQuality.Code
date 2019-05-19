set(LIB_NAME model)

#clear variables
unset(TEST_SRCS)
unset(MY_SRCS)

##############################################################
###		INCLUDE CMAKE MACROS    						   ###
##############################################################

include(${CMAKE_SOURCE_DIR}/cmake/general/LibUtilities.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/Boost/Link.cmake)


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
###		LINK LIBRARIES									   ###
##############################################################

linkBoost(${LIB_NAME})
target_link_libraries(${LIB_NAME} utilities)

##############################################################
###		TEST SUITE									   ###
##############################################################

# add_subdirectory(${LIB_NAME}Test)
