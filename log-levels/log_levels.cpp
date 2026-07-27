#include <string>
#include <iostream>

namespace log_line {
std::string message(std::string line) {
    int colonIndex = line.find(':');
    int messageStart = colonIndex + 2;
    return line.substr(messageStart);
}

std::string log_level(std::string line) {
    int leftBracketIndex = line.find('[');
    int rightBracketIndex = line.find(']');
    int levelLeftIndex = leftBracketIndex + 1;
    int levelLength = rightBracketIndex - leftBracketIndex - 1;
    return line.substr(levelLeftIndex, levelLength);
}

std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
