#include <string>

namespace log_line {
std::string message(const std::string& line) {
    size_t colon_index = line.find(':');
    size_t message_start = colon_index + 2; // skips ": " in the log line
    return line.substr(message_start);
}

std::string log_level(const std::string& line) {
    size_t left_bracket_index = line.find('[');
    size_t right_bracket_index = line.find(']');
    size_t level_left_index = left_bracket_index + 1;
    size_t level_length = right_bracket_index - left_bracket_index - 1;
    return line.substr(level_left_index, level_length);
}

std::string reformat(const std::string& line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
