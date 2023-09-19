cmake_minimum_required(VERSION 3.21)
project(a45_Bugnar12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS "C:/Users/Praslea/Documents/GitHub/a89-Bugnar12/Admin_movie_GUI/admin_movie_gui.ui")

set(CMAKE_PREFIX_PATH "D:/Qt/6.5.0/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(.)

add_executable(a45_Bugnar12
        Domain/Domain.cpp
        Domain/Domain.h main.cpp Tests/Tests.h Tests/Tests.cpp Repositroy/AdminRepo.h Repositroy/AdminRepo.cpp Service/Services.h Service/Services.cpp "User Interface/UI.h" "User Interface/UI.cpp" Repositroy/UserRepo.h Repositroy/UserRepo.cpp Repositroy/CSV_Repository.h Repositroy/CSV_Repository.h Repositroy/CSV_Repository.cpp Repositroy/HTML_Repository.h Repositroy/HTML_Repository.cpp Validator/Exceptions.h Validator/Exceptions.cpp Validator/Validators.h Validator/Validators.cpp GUI/adminmodegui.h GUI/adminmodegui.cpp GUI_2/designer_gui.h GUI_2/designer_gui.cpp)

target_link_libraries(a45_Bugnar12
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

set(DEBUG_SUFFIX)
if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
    set(DEBUG_SUFFIX "d")
endif ()
set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
    set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    endif ()
endif ()
if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
endif ()
foreach (QT_LIB Core Gui Widgets)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
endforeach (QT_LIB)
