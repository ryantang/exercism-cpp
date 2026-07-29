namespace targets {

class Alien {
    public:
        Alien(int x, int y) {
            x_coordinate = x;
            y_coordinate = y;
        }

        int get_health() {return hp;}

        bool hit() {
            if (hp > 0) {
                hp--;
            } 
            return true;}

        bool is_alive() {return hp > 0;}

        bool teleport(int x, int y) {
            x_coordinate = x;
            y_coordinate = y;
            return true;
        }
        
        bool collision_detection(targets::Alien other) {
            return x_coordinate == other.x_coordinate
                && y_coordinate == other.y_coordinate;
        }

        int x_coordinate{0};
        int y_coordinate{0};

    private:
        int hp{3};
};

// TODO: Insert the code for the alien class here

}  // namespace targets
