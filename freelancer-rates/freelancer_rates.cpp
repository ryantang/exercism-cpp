#include <cmath>
constexpr double HOURS_IN_WORKDAY{8.0};
constexpr double DAYS_IN_MONTH{22.0};

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate * HOURS_IN_WORKDAY;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount * (100.0 - discount) / 100.0;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double discounted_monthly_rate{apply_discount(daily_rate(hourly_rate) * DAYS_IN_MONTH, discount)};
    return static_cast<int>(std::ceil(discounted_monthly_rate));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double unrounded_days_in_budget{budget / apply_discount(daily_rate(hourly_rate), discount)};
    return static_cast<int>(std::floor(unrounded_days_in_budget));
}
