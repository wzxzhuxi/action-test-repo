#pragma once

#include <string>
#include <string_view>

#include "action-test-repo/result.hpp"

namespace action_test_repo {

// =============================================================================
// Pure Functions - No side effects, same input always produces same output
// =============================================================================

/**
 * @brief Pure function: creates a greeting message
 */
auto greet(std::string_view name) -> std::string;

/**
 * @brief Pure function: adds two integers
 */
auto add(int a, int b) -> int;

/**
 * @brief Pure function with Result: parses string to integer
 * Returns Result<int> instead of throwing exceptions
 */
auto parse_int(std::string_view input) -> Result<int>;

} // namespace action_test_repo
