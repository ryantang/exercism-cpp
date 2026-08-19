#include <string>

namespace star_map {
    enum class System{
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
    };
}

namespace heaven {
    class Vessel {
        public:
            Vessel(const std::string& name, int generation);
            Vessel(const std::string& name, int generation, star_map::System current_system);
            Vessel replicate(const std::string& name) const;
            void make_buster();
            bool shoot_buster();

            std::string name;
            int generation;
            star_map::System current_system{star_map::System::Sol};
            int busters{0};
    };
    std::string get_older_bob(const Vessel& probe1, const Vessel& probe2);
    bool in_the_same_system(const Vessel& probe1, const Vessel& probe2);
}

