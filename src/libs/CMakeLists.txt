file(GLOB LIST_DIRS LIST_DIRECTORIES true *)

set(LIBS_ADDED "")

foreach(DIR ${LIST_DIRS})
    if(IS_DIRECTORY ${DIR})
        add_subdirectory(${DIR})
    endif()
endforeach()

set(LIBS_ADDED ${LIBS_ADDED} PARENT_SCOPE)
