cmake_minimum_required(VERSION 3.19)
project(renergieCH LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets OpenGLWidgets Gui)

include(FetchContent)

# CATCH2
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2
  GIT_TAG v3.9.1  # Change as needed
)

FetchContent_MakeAvailable(catch2)
#

qt_standard_project_setup()

# specify that there is anexecutable and required sources
qt_add_executable(${PROJECT_NAME}
    WIN32 MACOSX_BUNDLE

    main.cpp

    include/mainwindow.h
    src/mainwindow.cpp

    src/mainwindow.ui
)

qt_add_executable(tests
)

# define where the headers are
target_include_directories(${PROJECT_NAME} PUBLIC
    include
    form/include
    writer/include
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(tests PUBLIC
    include
    form/include
    writer/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::OpenGLWidgets
        Qt::Gui
)

target_link_libraries(tests
    PRIVATE
        Catch2::Catch2WithMain)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET ${PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
