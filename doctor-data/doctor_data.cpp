#include "doctor_data.h"
#include <string>

heaven::Vessel::Vessel(const std::string& name, int generation)
    : name{name},
      generation{generation}
{}

heaven::Vessel::Vessel(const std::string& name, int generation, star_map::System current_system)
    : name{name},
      generation{generation},
      current_system{current_system}
{}

heaven::Vessel heaven::Vessel::replicate(const std::string& name) const {
    return Vessel(name, this->generation + 1);
}

void heaven::Vessel::make_buster() {
    busters++;
}

bool heaven::Vessel::shoot_buster() {
    if (busters > 0) {
        busters--;
        return true;
    }
    return false;
}

std::string heaven::get_older_bob(const Vessel& probe1, const Vessel& probe2) {
    if (probe1.generation <= probe2.generation) {
        return probe1.name;
    }
    return probe2.name;
}

bool heaven::in_the_same_system(const Vessel& probe1, const Vessel& probe2) {
    return probe1.current_system == probe2.current_system;
}