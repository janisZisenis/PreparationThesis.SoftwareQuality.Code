SET(EXE_NAME CECloud)

#clear variables
unset(MY_SRCS)

#################################################################
###		INCLUDE CMAKE MACROS    						      ###
#################################################################

include (${CMAKE_SOURCE_DIR}/cmake/general/LibUtilities.cmake)
include (${CMAKE_SOURCE_DIR}/cmake/general/FileUtilities.cmake)
include (${CMAKE_SOURCE_DIR}/cmake/Qt/Link.cmake)
include (${CMAKE_SOURCE_DIR}/cmake/QCustomPlot/Link.cmake)


#################################################################
###   	LINK DIRECTORIES		   			    	  	      ###
#################################################################

addQCustomPlotLinkDirectory()

#################################################################
###   	EXCECUTABLE		   			    	  				  ###
#################################################################

OrganizeMainFiles()

SET(MY_SRCS ${MY_SRCS} ${SPECIFIC_FILES})
ADD_EXECUTABLE(${EXE_NAME} ${MY_SRCS})

#################################################################
###		LINK LIBRARY									      ###
#################################################################

linkBoost(${EXE_NAME})
target_link_libraries(${EXE_NAME} utilities)
target_link_libraries(${EXE_NAME} model)
target_link_libraries(${EXE_NAME} item)
target_link_libraries(${EXE_NAME} presenter)
target_link_libraries(${EXE_NAME} qtView)
target_link_libraries(${EXE_NAME} QCustomPlot)
linkQt(${EXE_NAME})
linkQCustomPlot(${EXE_NAME})