file(GLOB ENTITY_HEADERS include/*.h)
file(GLOB ENTITY_SOURCES src/*.cpp)

add_library(entity ${ENTITY_SOURCES} ${ENTITY_HEADERS})

target_include_directories(
    entity
    PUBLIC
        include
        $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

list(APPEND LIBS_ADDED "entity")
set(LIBS_ADDED ${LIBS_ADDED} PARENT_SCOPE)

export(PACKAGE entity)