#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate distance between two points
inline double distanceBetween(double x1, double y1,
                              double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to convert degrees to radians
inline double toRadians(double degrees)
{
    return degrees * (M_PI / 180.0);
}

// Function to restrict value between minVal and maxVal
inline double clamp(double value, double minVal, double maxVal)
{
    if (value < minVal)
    {
        return minVal;
    }
    else if (value > maxVal)
    {
        return maxVal;
    }
    else
    {
        return value;
    }
}

// Function to check whether point is inside safe zone
inline bool isInSafeZone(double x, double y,
                         double cx, double cy,
                         double radius)
{
    double distance = distanceBetween(x, y, cx, cy);

    if (distance <= radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Home position
    double homeX = 0.0;
    double homeY = 0.0;

    // Safe zone radius
    double radius = 50.0;

    // Three waypoints
    double x1 = 20.0;
    double y1 = 15.0;

    double x2 = 30.0;
    double y2 = 40.0;

    double x3 = 60.0;
    double y3 = 20.0;

    // Waypoint 1
    double distance1 = distanceBetween(homeX, homeY, x1, y1);

    cout << "Waypoint 1 : (" << x1 << ", " << y1 << ")" << endl;
    cout << "Distance   : " << distance1 << endl;

    if (isInSafeZone(x1, y1, homeX, homeY, radius))
    {
        cout << "Safe Zone  : Yes" << endl;
    }
    else
    {
        cout << "Safe Zone  : No" << endl;
    }

    // Waypoint 2
    double distance2 = distanceBetween(homeX, homeY, x2, y2);

    cout << "\nWaypoint 2 : (" << x2 << ", " << y2 << ")" << endl;
    cout << "Distance   : " << distance2 << endl;

    if (isInSafeZone(x2, y2, homeX, homeY, radius))
    {
        cout << "Safe Zone  : Yes" << endl;
    }
    else
    {
        cout << "Safe Zone  : No" << endl;
    }

    // Waypoint 3
    double distance3 = distanceBetween(homeX, homeY, x3, y3);

    cout << "\nWaypoint 3 : (" << x3 << ", " << y3 << ")" << endl;
    cout << "Distance   : " << distance3 << endl;

    if (isInSafeZone(x3, y3, homeX, homeY, radius))
    {
        cout << "Safe Zone  : Yes" << endl;
    }
    else
    {
        cout << "Safe Zone  : No" << endl;
    }

    return 0;
}