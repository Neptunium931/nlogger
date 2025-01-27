#ifndef NLOGGER_HPP
#define NLOGGER_HPP
#include <iostream>

namespace Neptunium931
{
enum LogLevel : std::uint8_t
{
  DEBUG,
  INFO,
  WARN,
  ERROR,
  PANIC
};

class Nlogger
{
public:
  Nlogger(std::ostream &out = std::cout)
    : oStream(out) {};
  auto setOutStream(std::ostream &out) -> void;
  auto setLevel(LogLevel nemlevel) -> void;

  auto debug(const std::string &message) -> void;
  auto info(const std::string &message) -> void;
  auto warn(const std::string &message) -> void;
  auto error(const std::string &message) -> void;
  auto panic(const std::string &message) -> void;

private:
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
  std::ostream &oStream;
  LogLevel level = LogLevel::DEBUG;
};

// NOLINTBEGIN(misc-definitions-in-headers)
auto
Nlogger::setOutStream(std::ostream &out) -> void
{
  oStream.rdbuf(out.rdbuf());
}

auto
Nlogger::setLevel(LogLevel nemlevel) -> void
{
  this->level = nemlevel;
};

auto
Nlogger::debug(const std::string &message) -> void
{
  if (this->level > LogLevel::DEBUG)
  {
    return;
  }
  oStream << message << "\n";
}

auto
Nlogger::info(const std::string &message) -> void
{
  if (this->level > LogLevel::INFO)
  {
    return;
  }
  oStream << message << "\n";
}
auto
Nlogger::warn(const std::string &message) -> void
{
  if (this->level > LogLevel::WARN)
  {
    return;
  }
  oStream << message << "\n";
}
auto
Nlogger::error(const std::string &message) -> void
{
  if (this->level > LogLevel::ERROR)
  {
    return;
  }
  oStream << message << "\n";
}
auto
Nlogger::panic(const std::string &message) -> void
{
  oStream << message << "\n";
}
// NOLINTEND(misc-definitions-in-headers)
};
#endif // !NLOGGER_HPP
