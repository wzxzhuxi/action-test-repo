#include "action-test-repo/action-test-repo.hpp"

namespace action-test-repo {

auto greet(std::string_view name) -> std::string {
    return std::string("Hello, ") + std::string(name) + "!";
}

auto add(int a, int b) -> int {
    return a + b;
}

auto parse_int(std::string_view input) -> Result<int> {
    try {
        size_t pos = 0;
        int result = std::stoi(std::string(input), &pos);
        if (pos != input.size()) {
            return Result<int>::err("Invalid integer: trailing characters in '" + std::string(input) + "'");
        }
        return Result<int>::ok(result);
    } catch (const std::exception&) {
        return Result<int>::err("Invalid integer: '" + std::string(input) + "'");
    }
}

} // namespace action-test-repo
