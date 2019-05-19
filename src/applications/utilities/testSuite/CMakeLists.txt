set(LIB_NAME utilities)
set(TEST_NAME ${LIB_NAME}Test)

#clear variables
unset(ALL_SOURCES)
unset(TEST_SRCS)

add_definitions(-DGTEST_LINKED_AS_SHARED_LIBRARY)

##############################################################
###		INCLUDE CMAKE MACROS    						   ###
##############################################################

include(${CMAKE_SOURCE_DIR}/cmake/general/LibUtilities.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/general/FileUtilities.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/GMock/Link.cmake)


##############################################################
###		INCLUDE PACKAGES								   ###
##############################################################

setTestSuiteOptionOn()
include(${CMAKE_SOURCE_DIR}/src/${LIB_NAME}/CMakePackage.cmake)


##############################################################
###		OWN FILES										   ###
##############################################################

OrganizeMainFiles()

#############################################################
###		LINK DIRECTORIES								  ###
#############################################################

addGMockLinkDirectory()

##############################################################
###		CREATE EXECUTABLE								   ###
##############################################################

set(TEST_SRCS ${TEST_SRCS} ${SPECIFIC_FILES})
add_executable(${TEST_NAME} ${TEST_SRCS})


##############################################################
###		LINK LIBRARIES									   ###
##############################################################

linkGMock(${TEST_NAME})
target_link_libraries(${TEST_NAME} ${LIB_NAME})
