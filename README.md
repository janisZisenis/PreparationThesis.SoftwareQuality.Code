# Setup for production

	1. download and install CMake
	2. download and install Visual Studio
	3. download and install MSVC Compiler 2015
		(or other Compiler, but then need to
		build Qt with this compiler)
	4. unzip the libraries folder and copy it into 'C:\'
	5. set environment variables
		BOOST_ROOT = C:\Libraries\boost_1_60_0
		CMAKE_PREFIX_PATH = C:\Libraries\Qt\Qt5.5.1\qtbase
		QT_QPA_PLATFORM_PLUGIN_PATH = C:\Libraries\Qt\Qt5.5.1\qtbase\plugins\platforms
		QTDIR = C:\Qt\Qt5.5.1\qtbase
	6. restart your computer
	7. build project with CMake
	8. open project with Visual Studio
	9. start coding