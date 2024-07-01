cmake_minimum_required(VERSION 3.14)

project(lesson_2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core LinguistTools)

set(TS_FILES lesson_2_ru_RU.ts)
add_executable(lesson_2
  main.cpp
  ${TS_FILES}
  counter.h
  counter.cpp
  res.qrc
  progress.h
  progress.cpp
  lcd.h
)

target_link_libraries(lesson_2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

include(GNUInstallDirs)
install(TARGETS lesson_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
