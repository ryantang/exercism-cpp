#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    // TODO: Return true if you need a license for that kind of vehicle.
    return kind == "car" || kind == "truck";
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    std::string best_option{option1};
    if (option2 < option1) {
        best_option = option2;
    }
    return best_option + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    double fair_price;
    if (age < 3) {
        fair_price = 0.8 * original_price;
    } else if (age < 10) {
        fair_price = 0.7 * original_price;
    } else {
        fair_price = 0.5 * original_price;
    }
    return fair_price;
}

}  // namespace vehicle_purchase
