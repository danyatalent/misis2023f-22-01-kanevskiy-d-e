add_library(settings INTERFACE)
target_compile_features(settings INTERFACE cxx_std_20)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(settings INTERFACE GLUT::GLUT)
target_link_libraries(settings INTERFACE GLEW::GLEW)
target_link_libraries(settings INTERFACE OpenGL::GL)




find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_CONFIGURED_INPUT ${DOXYGEN_IN})

    add_custom_target(doc ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIGURED_INPUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Documentation with doxygen"
    VERBATIM )
endif()

if(DOXYGEN_FOUND)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
    DESTINATION .)
endif()

add_subdirectory(volren)
add_subdirectory(test_app)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION bin)