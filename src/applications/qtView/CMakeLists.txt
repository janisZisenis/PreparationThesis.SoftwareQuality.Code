set(LIB_NAME qtView)

#clear variables
unset(TEST_SRCS)
unset(MY_SRCS)

##############################################################
###		INCLUDE CMAKE MACROS    						   ###
##############################################################

include(${CMAKE_SOURCE_DIR}/cmake/Qt/QtFileTypes.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/Qt/Link.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/QCustomPlot/Link.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/general/LibUtilities.cmake)


##############################################################
###		SPECIFICS FILE TYPES FOR LIBRARY	    		   ###
##############################################################

addQtFileTypesToCollect()


##############################################################
###		INCLUDE PACKAGES								   ###
##############################################################

setLibOptionOn()
include(${CMAKE_SOURCE_DIR}/src/${LIB_NAME}/CMakePackage.cmake)


##############################################################
###		PRE CREATE BLOCK								   ###
##############################################################

addQCustomPlotLinkDirectory()
setQtAutoMocOn()


##############################################################
###		CREATE LIBRARY									   ###
##############################################################

set(MY_SRCS ${MY_SRCS} ${SPECIFIC_FILES})
createLIB(${LIB_NAME} ${LIB_TYPE} ${MY_SRCS})


##############################################################
###		POST CREATE BLOCK								   ###
##############################################################

linkBoost(${LIB_NAME})
linkQCustomPlot(${LIB_NAME})
target_link_libraries(${LIB_NAME} utilities)
target_link_libraries(${LIB_NAME} model)
target_link_libraries(${LIB_NAME} item)
target_link_libraries(${LIB_NAME} presenter)
linkQt(${LIB_NAME})
