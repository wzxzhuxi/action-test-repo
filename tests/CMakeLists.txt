# Tests using simple assertions
# For a proper test framework, consider Catch2:
# include(FetchContent)
# FetchContent_Declare(Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v3.5.2)
# FetchContent_MakeAvailable(Catch2)

add_executable(tests test_main.cpp)
target_link_libraries(tests PRIVATE action-test-repo)

# CTest integration
add_test(NAME action-test-repo_tests COMMAND tests)
