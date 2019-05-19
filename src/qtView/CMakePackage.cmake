include(${CMAKE_CURRENT_LIST_DIR}/MyQCustomTable/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQDockWidget/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQDockWidget/MyQPropertiesExplorer/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQDockWidget/MyQSolutionExplorer/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQEvaluationView/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQEvaluationView/WaveDynamic/CMakePackage.cmake)
        include(${CMAKE_CURRENT_LIST_DIR}/MyQEvaluationView/WaveDynamic/MyQWaveKinematicView/CMakePackage.cmake)
        include(${CMAKE_CURRENT_LIST_DIR}/MyQEvaluationView/WaveDynamic/MyQWaveProfileView/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQItemModel/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQMenu/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQMenu/MyQAddNodeMenu/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQMenu/MyQBindingMenu/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQMenu/MyQEditMenu/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQMenu/MyQEvaluateMenu/CMakePackage.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/MyQMenu/MyQViewMenu/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQShell/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQTableView/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQTreeView/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQUtilities/CMakePackage.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/MyQViewFactoryImp/CMakePackage.cmake)
