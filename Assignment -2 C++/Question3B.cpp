#include <iostream>
using namespace std;

// Physics namespace
namespace Physics {

    double clamp(double val, double min, double max) {

        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}


// GameMath namespace
namespace GameMath {

    int clamp(int val, int min, int max) {

        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}


int main() {

    // Physics clamp
    double velocity = Physics::clamp(120.5, 0.0, 100.0);

    // GameMath clamp
    int health = GameMath::clamp(150, 0, 100);

    cout << "Physics Clamp : " << velocity << endl;
    cout << "GameMath Clamp: " << health << endl;


    // Physics lerp
    double result1 = Physics::lerp(10.0, 20.0, 0.5);

    // GameMath lerp
    double result2 = GameMath::lerp(100.0, 200.0, 0.25);

    cout << "Physics Lerp  : " << result1 << endl;
    cout << "GameMath Lerp : " << result2 << endl;


    // Limited namespace scope
    {
        using namespace Physics;

        cout << "Limited Scope Clamp: "
             << clamp(150.0, 0.0, 100.0) << endl;
    }

    return 0;
}