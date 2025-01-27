// Copyright (c) 2025, Tymothé BILLEREY <tymothe_billerey@fastmail.fr>
// See end of file for extended copyright information.
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
// This file is part of nlogger.
//
// BSD 3-Clause License
//
// Copyright (c) 2025, Tymothé BILLEREY <tymothe_billerey@fastmail.fr>
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice
// this
// list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
