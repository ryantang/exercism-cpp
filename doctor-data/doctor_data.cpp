#include "doctor_data.h"
#include <iostream>

// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

heaven::Vessel::Vessel(std::string name, int generation) {
    this->name = name;
    this->generation = generation;
    this->busters = 0;
};

heaven::Vessel::Vessel(std::string name, int generation, star_map::System current_system) {
        this->name = name;
        this->generation = generation;
        this->current_system = current_system;
        this->busters = 0;
};

heaven::Vessel heaven::Vessel::replicate(std::string name) {
    return Vessel(name, this->generation + 1, star_map::System::Sol);
}

void heaven::Vessel::make_buster() {
    this->busters++;
}

bool heaven::Vessel::shoot_buster() {
    if (this->busters > 0) {
        this->busters--;
        return true;
    }
    return false;
}

std::string heaven::get_older_bob(Vessel probe1, Vessel probe2) {
    if (probe1.generation <= probe2.generation) {
        return probe1.name;
    }
    return probe2.name;
}

bool heaven::in_the_same_system(Vessel probe1, Vessel probe2) {
    return probe1.current_system == probe2.current_system;
}

