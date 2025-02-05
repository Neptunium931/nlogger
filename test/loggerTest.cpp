// Copyright (c) 2025, Tymothé BILLEREY <tymothe_billerey@fastmail.fr>
// See end of file for extended copyright information.
#include "nlogger.hpp"
#include <criterion/criterion.h>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace
{
auto
logAllLevel(Neptunium931::Nlogger &logger)
{
  logger.debug("debug");
  logger.info("info");
  logger.warn("warn");
  logger.error("error");
  logger.panic("panic");
}

auto
getFileContent(const std::filesystem::path &fileName)
{
  auto file = std::ifstream(fileName);
  std::string lines;
  std::string line;
  while (std::getline(file, line))
  {
    lines += line;
  }
  return lines;
}
}

Test(logger, stdout)
{
  auto logger = Neptunium931::Nlogger();
  logger.setOutStream(std::cout);
}

Test(logger, file)
{
  auto fileName = std::filesystem::temp_directory_path() / "test0.log";
  auto file = std::ofstream(fileName);
  auto logger = Neptunium931::Nlogger(file);
  logger.setOutStream(file);
  std::filesystem::remove(fileName);
}

Test(logger, textInFile)
{
  auto fileName = std::filesystem::temp_directory_path() / "test1.log";
  auto file = std::ofstream(fileName);
  auto logger = Neptunium931::Nlogger(file);
  auto log = std::string("testLog");
  logger.debug(log);
  file.close();
  auto line = getFileContent(fileName);
  cr_assert_eq(line, log);
  std::filesystem::remove(fileName);
}

Test(logger, LevelInfo)
{
  auto fileName = std::filesystem::temp_directory_path() / "test2.log";
  auto file = std::ofstream(fileName);
  auto logger = Neptunium931::Nlogger(file);
  logger.setLevel(Neptunium931::LogLevel::INFO);
  logAllLevel(logger);
  file.close();
  auto content = getFileContent(fileName);
  cr_assert_eq(content, "infowarnerrorpanic");
  std::filesystem::remove(fileName);
}

Test(logger, LevelWarn)
{
  auto fileName = std::filesystem::temp_directory_path() / "test3.log";
  auto file = std::ofstream(fileName);
  auto logger = Neptunium931::Nlogger(file);
  logger.setLevel(Neptunium931::LogLevel::WARN);
  logAllLevel(logger);
  file.close();
  auto content = getFileContent(fileName);
  cr_assert_eq(content, "warnerrorpanic");
  std::filesystem::remove(fileName);
}

Test(logger, LevelError)
{
  auto fileName = std::filesystem::temp_directory_path() / "test4.log";
  auto file = std::ofstream(fileName);
  auto logger = Neptunium931::Nlogger(file);
  logger.setLevel(Neptunium931::LogLevel::ERROR);
  logAllLevel(logger);
  file.close();
  auto content = getFileContent(fileName);
  cr_assert_eq(content, "errorpanic");
  std::filesystem::remove(fileName);
}

Test(logger, LevelPanic)
{
  auto fileName = std::filesystem::temp_directory_path() / "test5.log";
  auto file = std::ofstream(fileName);
  auto logger = Neptunium931::Nlogger(file);
  logger.setLevel(Neptunium931::LogLevel::PANIC);
  logAllLevel(logger);
  file.close();
  auto content = getFileContent(fileName);
  cr_assert_eq(content, "panic");
  std::filesystem::remove(fileName);
}
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
