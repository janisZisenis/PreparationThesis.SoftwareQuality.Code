macro(addQCustomPlotLinkDirectory)
	link_directories(${CMAKE_SOURCE_DIR}/lib/QCustomPlot/${PLATFORM}/Debug)
endmacro(addQCustomPlotLinkDirectory)

macro(linkQCustomPlot TARGET_NAME)
	include_directories(${CMAKE_SOURCE_DIR}/src/3rdParty/QCustomPlot)
	target_link_libraries(${TARGET_NAME} QCustomPlot)
endmacro(linkQCustomPlot)
