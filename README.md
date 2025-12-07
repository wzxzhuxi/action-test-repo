# action-test-repo

[![CI](https://github.com/YOUR_USERNAME/action-test-repo/actions/workflows/ci.yml/badge.svg)](https://github.com/YOUR_USERNAME/action-test-repo/actions/workflows/ci.yml)

A C++ project

## Build

```bash
cmake -B build -G Ninja
cmake --build build
```

## Usage

```cpp
#include "action-test-repo/action-test-repo.hpp"

int main() {
    auto msg = action_test_repo::hello();
    return 0;
}
```

## Install

```bash
cmake --install build --prefix /usr/local
```

## License

MIT License
