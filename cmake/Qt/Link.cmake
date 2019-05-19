macro(linkQt TARGET_NAME)

	SET(CMAKE_AUTOMOC ON)
	SET(CMAKE_INCLUDE_CURRENT_DIR ON)

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

	TARGET_LINK_LIBRARIES(${TARGET_NAME} Qt5::Widgets)
	TARGET_LINK_LIBRARIES(${TARGET_NAME} Qt5::Core)
	TARGET_LINK_LIBRARIES(${TARGET_NAME} Qt5::PrintSupport)

endmacro(linkQt)

macro(setQtAutoMocOn)
	set(CMAKE_AUTOMOC ON) #invokes meta object compiler for custombuild
endmacro(setQtAutoMocOn)
