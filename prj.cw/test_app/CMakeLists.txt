add_executable(test_app "test_app.cpp")
target_link_libraries(test_app volren settings)
install(TARGETS test_app DESTINATION bin)