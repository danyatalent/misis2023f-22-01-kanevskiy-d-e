add_library(settings INTERFACE)
target_compile_features(settings INTERFACE cxx_std_20)

find_package(glad REQUIRED)
target_link_libraries(settings INTERFACE glad::glad)

find_package(glfw3 REQUIRED)
target_link_libraries(settings INTERFACE glfw)

find_package(GLUT)
target_link_libraries(settings INTERFACE GLUT::GLUT)

find_package(GLEW REQUIRED)
target_link_libraries(settings INTERFACE GLEW::GLEW)

find_package(OpenCV REQUIRED)
if( OpenCV_FOUND )
  # Additional Include Directories
  include_directories( ${OpenCV_INCLUDE_DIRS} )

  # Additional Library Directories
  link_directories( ${OpenCV_LIB_DIR} )

  # Additional Dependencies
  target_link_libraries( settings INTERFACE ${OpenCV_LIBS} )
endif()

find_package(OpenGL REQUIRED)
target_link_libraries(settings INTERFACE OpenGL::GL)

#addd_subdirectory(lib)
#dd_subdirectory(cube)
#add_subdirectory(hello_triangle)
add_subdirectory(volren)
add_subdirectory(test_app)