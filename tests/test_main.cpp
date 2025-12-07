#include <cassert>
#include <iostream>

#include "action-test-repo/action-test-repo.hpp"

// =============================================================================
// Tests for Pure Functions
// =============================================================================

void test_greet() {
    assert(action-test-repo::greet("World") == "Hello, World!");
    assert(action-test-repo::greet("") == "Hello, !");
    std::cout << "[PASS] test_greet" << std::endl;
}

void test_add() {
    assert(action-test-repo::add(2, 3) == 5);
    assert(action-test-repo::add(-1, 1) == 0);
    assert(action-test-repo::add(0, 0) == 0);
    std::cout << "[PASS] test_add" << std::endl;
}

void test_parse_int_success() {
    auto result = action-test-repo::parse_int("42");
    assert(result.is_ok());
    assert(result.value() == 42);

    auto negative = action-test-repo::parse_int("-123");
    assert(negative.is_ok());
    assert(negative.value() == -123);

    std::cout << "[PASS] test_parse_int_success" << std::endl;
}

void test_parse_int_failure() {
    auto result = action-test-repo::parse_int("abc");
    assert(result.is_err());

    auto empty = action-test-repo::parse_int("");
    assert(empty.is_err());

    auto trailing = action-test-repo::parse_int("42abc");
    assert(trailing.is_err());

    std::cout << "[PASS] test_parse_int_failure" << std::endl;
}

void test_result_map() {
    auto result = action-test-repo::parse_int("10");
    auto doubled = result.map([](int x) { return x * 2; });
    assert(doubled.is_ok());
    assert(doubled.value() == 20);

    auto err = action-test-repo::parse_int("invalid");
    auto doubled_err = err.map([](int x) { return x * 2; });
    assert(doubled_err.is_err());

    std::cout << "[PASS] test_result_map" << std::endl;
}

int main() {
    std::cout << "Running tests for action-test-repo..." << std::endl;
    std::cout << std::endl;

    test_greet();
    test_add();
    test_parse_int_success();
    test_parse_int_failure();
    test_result_map();

    std::cout << std::endl;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
