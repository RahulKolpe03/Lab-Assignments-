#include <iostream>
using namespace std;

// Function to read temperatures
void readTemperatures(double temperature[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter temperature for Floor "
                 << i + 1 << ", Room " << j + 1 << ": ";

            cin >> temperature[i][j];
        }
    }
}

// Function to display temperatures
void displayTemperatures(double temperature[3][3])
{
    cout << "\nRoom1\tRoom2\tRoom3" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << " : ";

        for (int j = 0; j < 3; j++)
        {
            cout << temperature[i][j] << "\t";
        }

        cout << endl;
    }
}

// Function to find hottest room
void findHottestRoom(double temperature[3][3])
{
    double hottest = temperature[0][0];

    int hottestFloor = 0;
    int hottestRoom = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] > hottest)
            {
                hottest = temperature[i][j];
                hottestFloor = i;
                hottestRoom = j;
            }
        }
    }

    cout << "\nHottest Room : Floor "
         << hottestFloor + 1
         << ", Room "
         << hottestRoom + 1
         << " -> "
         << hottest << " C" << endl;
}

// Function to find floor with highest average
void findHottestFloor(double temperature[3][3])
{
    double highestAverage = 0;
    int hottestFloor = 0;

    for (int i = 0; i < 3; i++)
    {
        double sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum = sum + temperature[i][j];
        }

        double average = sum / 3;

        if (average > highestAverage)
        {
            highestAverage = average;
            hottestFloor = i;
        }
    }

    cout << "Hottest Floor : Floor "
         << hottestFloor + 1
         << " (avg "
         << highestAverage << " C)" << endl;
}

// Function to count warning rooms
int countWarningRooms(double temperature[3][3])
{
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] >= 30)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    double temperature[3][3];

    // Read all temperatures
    readTemperatures(temperature);

    // Display temperature table
    displayTemperatures(temperature);

    // Find hottest room
    findHottestRoom(temperature);

    // Find hottest floor
    findHottestFloor(temperature);

    // Count warning rooms
    int warningRooms = countWarningRooms(temperature);

    cout << "Rooms at WARNING or above : "
         << warningRooms << endl;

    return 0;
}