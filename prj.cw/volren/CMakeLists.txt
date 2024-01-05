add_library(volren volren.cpp include/volren/volren.hpp)
set_property(TARGET volren PROPERTY CXX_STANDARD 20)
target_include_directories(volren PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(volren settings)