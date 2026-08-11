#include <string>
#include <vector>

namespace election {


struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// Returns the number of votes for the given candidate.
int vote_count(const ElectionResult& candidate) {
    return candidate.votes;
}

// Adds `additional_votes` to the given candidate's vote count.
void increment_vote_count(ElectionResult& candidate, int additional_votes) {
    candidate.votes += additional_votes;
}

// Finds the candidate with the most votes, prefixes their name with
// "President " in place, and returns a reference to their ElectionResult.
ElectionResult& determine_result(std::vector<ElectionResult>& final_count) {
    std::size_t top_result_index{0};
    for (std::size_t i{0}; i < final_count.size(); i++) {
        if (final_count.at(i).votes > final_count.at(top_result_index).votes) {
            top_result_index = i;
        }
    }

    ElectionResult& winner{final_count.at(top_result_index)};
    winner.name = "President " + winner.name;
    return winner;
}

}  // namespace election
