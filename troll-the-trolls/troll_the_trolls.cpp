/// Rules governing the Hellmath forum: account privileges, post visibility,
/// and player-vs-player combat eligibility.
namespace hellmath {

    /// Account tiers on the forum, ordered from highest to lowest privilege.
    /// The numeric value of each enumerator is used as a priority rank
    /// (lower value == higher priority), so declaration order matters.
    enum class AccountStatus {
        mod,
        user,
        guest,
        troll,
    };

    /// Actions a user can attempt to perform on the forum, ordered from
    /// least to most powerful.
    enum class Action {
        read,
        write,
        remove
    };

    // internal helper method(s)
    namespace { 
        /// Returns true if the account is either a regular user or a moderator.
        /// Used to test whether two players form a valid non-troll combat pair.
        bool is_user_or_mod(AccountStatus account) {
            return account == AccountStatus::user || account == AccountStatus::mod;
        }
    }

    /// Decides whether `poster`'s message should be shown to `viewer`.
    /// Troll posts are visible only to other trolls; every other combination
    /// is visible.
    /// @param poster  The account that authored the post.
    /// @param viewer  The account viewing the feed.
    /// @return true if the post should be displayed to the viewer.
    bool display_post(AccountStatus poster, AccountStatus viewer) {
        // show troll posts only to other trolls
        return !(poster == AccountStatus::troll && viewer != AccountStatus::troll);
    }

    /// Determines whether an account is authorized to perform an action.
    /// Permission tiers:
    ///   - mod:            read, write, remove
    ///   - user, troll:    read, write
    ///   - guest:          read only
    /// @param action  The action being attempted.
    /// @param status  The account performing the action.
    /// @return true if the action is permitted for the given status.
    bool permission_check(Action action, AccountStatus status) {
        switch (status) {
            case AccountStatus::mod:
                return true;
            case AccountStatus::user:
            case AccountStatus::troll:
                return action == Action::read || action == Action::write;
            case AccountStatus::guest:
                return action == Action::read;
            default:
                return false;
        }
    }

    /// Determines whether two players may engage in combat.
    /// Valid pairings are two trolls, or any two accounts drawn from
    /// {user, mod}. Guests never fight.
    /// @param player1  The initiating player.
    /// @param player2  The opposing player.
    /// @return true if the two players form a legal combat pair.
    bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
        bool both_trolls = player1 == AccountStatus::troll && player2 == AccountStatus::troll;
        bool both_user_or_mod = is_user_or_mod(player1) && is_user_or_mod(player2);

        return both_trolls || both_user_or_mod;
    }

    /// Determines whether `player1` outranks `player2` in combat priority.
    /// Priority is derived from AccountStatus's declaration order: earlier
    /// enumerators have higher priority (lower numeric value).
    /// @return true if player1 has strictly higher priority than player2.
    bool has_priority(AccountStatus player1, AccountStatus player2) {
        return static_cast<int>(player1) < static_cast<int>(player2);
    }
}  // namespace hellmath
