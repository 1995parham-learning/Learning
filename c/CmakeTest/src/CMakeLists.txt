add_executable (CMakeTest CMakeTest.c)

find_package(PkgConfig)
pkg_check_modules(GLIB REQUIRED glib-2.0)
include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})
target_link_libraries(CMakeTest ${GLIB_LIBRARIES})
