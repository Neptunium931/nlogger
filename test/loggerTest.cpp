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
  std::cout << content;

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
  std::cout << content;

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
  std::cout << content;

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
  std::cout << content;

  cr_assert_eq(content, "panic");
  std::filesystem::remove(fileName);
}
