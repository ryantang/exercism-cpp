#include <array>
#include <string>
#include <vector>

const int PERFECT_SCORE{100};
const int FAILING_SCORE{40};
const int LOWEST_PASSING_SCORE{FAILING_SCORE + 1};

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> floor_scores {};
    for (double score: student_scores) {
        int rounded_down_score{static_cast<int>(score)};
        floor_scores.push_back(rounded_down_score);
    }
    // for (std::size_t i{0}; i < student_scores.size(); i++) {
    //     int rounded_down_score{static_cast<int>(student_scores.at(i))};
    //     floor_scores.push_back(rounded_down_score);
    // }

    return floor_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int failing_students{0};
    for (int score: student_scores) {
        if (score <= FAILING_SCORE) {
            failing_students++;
        }
    }

    return failing_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int passing_band{highest_score - FAILING_SCORE};

    std::array<int, 4> grade_thresholds{};
    for (int i{0}; i < 4; i++) {
        grade_thresholds[i] = LOWEST_PASSING_SCORE + passing_band * i / 4;
    }
    
    return grade_thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> rankings{};
    for (std::size_t i{0}; i < student_scores.size(); i++) {
        std::size_t rank{i + 1};
        std::string entry{std::to_string(rank) + ". " 
                        + student_names.at(i) + ": " 
                        + std::to_string(student_scores.at(i))};
        rankings.push_back(entry);
    }

    return rankings;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam. Assumes no more than 1 perfect score.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (size_t i{0}; i < student_scores.size(); i++) {
        if (student_scores.at(i) == PERFECT_SCORE) {
            return student_names.at(i);
        }
    }

    return "";
}
