file(GLOB EXEC_SOURCES *.cpp)
file(GLOB EXEC_HEADERS *.h)

add_executable(little ${EXEC_SOURCES} ${EXEC_HEADERS})
target_link_libraries(little ${LIBS_ADDED})