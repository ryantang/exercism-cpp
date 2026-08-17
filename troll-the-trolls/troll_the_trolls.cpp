namespace hellmath {

    enum class AccountStatus {
        troll,
        guest,
        user,
        mod
    };

    enum class Action {
        read,
        write,
        remove
    };

    bool display_post(AccountStatus poster, AccountStatus viewer) {
        if (poster == AccountStatus::troll and viewer != AccountStatus::troll) {
            return false;
        }
        return true;
    }

    bool permission_check(Action action, AccountStatus status) {
        switch (status) {
            case AccountStatus::guest:
                if (action == Action::read) {
                    return true;
                }
                return false;
            case AccountStatus::troll:
            case AccountStatus::user:
                if (action == Action::read or action == Action::write) {
                    return true;
                }
                return false;
            case AccountStatus::mod:
                return true;
        }
    }

    bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
        if (player1 == AccountStatus::troll && player2 == AccountStatus::troll) {
            return true;
        }
        if ((player1 == AccountStatus::user && player2 == AccountStatus::user) ||
            (player1 == AccountStatus::user && player2 == AccountStatus::mod) ||
            (player1 == AccountStatus::mod && player2 == AccountStatus::user) ||
            (player1 == AccountStatus::mod && player2 == AccountStatus::mod)) {
            return true;
        } 
        return false;
    }

    bool has_priority(AccountStatus player1, AccountStatus player2) {
        switch (player1) {
            case AccountStatus::troll:
                return false;
            case AccountStatus::guest:
                if (player2 == AccountStatus::troll) {
                    return true;
                }
                return false;
            case AccountStatus::user:
                if (player2 == AccountStatus::troll || player2 == AccountStatus::guest) {
                    return true;
                }
                return false;
            case AccountStatus::mod:
                if (player2 == AccountStatus::mod) {
                    return false;
                }
                return true;
        }
    }
}  // namespace hellmath
