#include "CommandParser.h"

#include <cctype>

std::string CommandParser::trim(const std::string& s)
{
    const auto start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return {};
    const auto end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

bool CommandParser::parse(const std::string& input,
                          ParsedCommand& outCommand,
                          std::string& errorMsg)
{
    errorMsg.clear();
    outCommand = ParsedCommand{};

    std::string line = trim(input);
    if (line.empty()) {
        errorMsg = "Empty command line";
        return false;
    }

    const std::size_t n = line.size();
    std::size_t i = 0;

    auto skipSpaces = [&i, &line, n]() {
        while (i < n && std::isspace(static_cast<unsigned char>(line[i]))) {
            ++i;
        }
    };
    auto findFlagOrCmdEnd = [&i, &line, n]() {
        while (i < n && !std::isspace(static_cast<unsigned char>(line[i]))) {
            ++i;
        }
    };

    skipSpaces();

    std::size_t cmdStart = i;
    findFlagOrCmdEnd();

    if (cmdStart == i) {
        errorMsg = "Wrong command format.";
        return false;
    }

    outCommand.name = line.substr(cmdStart, i - cmdStart);
    outCommand.args.clear();

    while (true) {
        skipSpaces();
        if (i >= n)
            break;

        if (line[i] != '-') {
            errorMsg = "Wrong command format.";
            return false;
        }

        std::size_t flagStart = i;
        ++i;
        findFlagOrCmdEnd();

        std::string flag = line.substr(flagStart, i - flagStart);

        skipSpaces();
        if (i >= n || line[i] != '{') {
            errorMsg = "Wrong command format.";
            return false;
        }

        ++i;
        std::size_t argStart = i;
        while (i < n && line[i] != '}') {
            ++i;
        }
        if (i >= n) {
            errorMsg = "Wrong command format.";
            return false;
        }
        std::string arg = line.substr(argStart, i - argStart);
        ++i;
        outCommand.args[flag] = trim(arg);
    }

    return true;
}
