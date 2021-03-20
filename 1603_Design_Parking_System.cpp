//
// Created by mincong.he on 2021/3/19.
//
#include "AlgoUtils.h"

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) : _big(big), _medium(medium), _small(small) {

    }

    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (_big < 1) {
                    return false;
                }
                _big--;
                break;
            case 2:
                if (_medium < 1) {
                    return false;
                }
                _medium--;
                break;
            case 3:
                if (_small < 1) {
                    return false;
                }
                _small--;
                break;
            default:
                return false;
        }
        return true;
    }

private:
    int _big;
    int _medium;
    int _small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main(int argc, char **argv) {
    ParkingSystem p(1, 1, 0);
    EXPECT_TRUE(p.addCar(1))
    EXPECT_TRUE(p.addCar(2))
    EXPECT_FALSE(p.addCar(3))
    EXPECT_FALSE(p.addCar(1))
    return EXIT_SUCCESS;
}