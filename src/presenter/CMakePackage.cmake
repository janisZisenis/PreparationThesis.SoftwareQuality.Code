include(${CMAKE_CURRENT_LIST_DIR}/MenuPresenter/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/MenuPresenter/ViewMenuPresenter/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/MenuPresenter/AddNodeMenuPresenter/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/MenuPresenter/EditMenuPresenter/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/MenuPresenter/EvaluateMenuPresenter/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/MenuPresenter/BindingMenuPresenter/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/EvaluationViewPresenter/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/EvaluationViewPresenter/WaveDynamic/CMakePackage.cmake)
		include(${CMAKE_CURRENT_LIST_DIR}/EvaluationViewPresenter/WaveDynamic/WaveKinematicPresenter/CMakePackage.cmake)
		include(${CMAKE_CURRENT_LIST_DIR}/EvaluationViewPresenter/WaveDynamic/WaveProfilePresenter/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/DockViewPresenter/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/DockViewPresenter/CMakePackage.cmake)
		include(${CMAKE_CURRENT_LIST_DIR}/DockViewPresenter/SolutionExplorerPresenter/CMakePackage.cmake)
		include(${CMAKE_CURRENT_LIST_DIR}/DockViewPresenter/PropertiesExplorerPresenter/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/CoordinateSystemRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/DefaultRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/MorisonRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/PileRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/SedimentRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/SedimentTransportRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/WaterRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/WaveDynamicRootBuilder/CMakePackage.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/RootBuilder/WaveRootBuilder/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/RootBuilderFactory/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/Shell/CMakePackage.cmake)
