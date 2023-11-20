list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(AddCatch2)
include(CTest)

add_executable(test-catch2 test_catch2.cpp)
target_link_libraries(test-catch2 PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(test-catch2)

add_executable(test-thread-pool test_thread_pool.cpp)
target_link_libraries(test-thread-pool PUBLIC ftd::tools)


add_executable(test-timer test_timer.cpp)
target_link_libraries(test-timer PUBLIC ftd::tools)
