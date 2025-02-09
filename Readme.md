# nlogger

nlogger is a logging library for logging in c++.

## Requirements

- C++23

## Examples

### Hello World

```cpp
#include <nlogger/nlogger.hpp>

using namespace Neptunium931;

int main() {
    auto logger = Nlogger;
    logger.info("Hello, world!");
    return 0;
}
```

### SetLogLevel

```cpp
int main() {
    auto logger = Nlogger;
    logger.setLogLevel(Nlogger::LogLevel::Error); // define log level
    logger.info("Hello, world!"); // will not be printed
    logger.error("Hello, world!"); // will be printed
    return 0;
}
```
