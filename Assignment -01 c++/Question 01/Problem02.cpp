#include <iostream>
#include <iomanip>
using namespace std;

// Input readings
void inputReadings(double arr[], int reading)
{
    for (int i = 0; i < reading; i++)
    {
        cin >> arr[i];
    }
}

// Print valid readings
int printValidReadings(double arr[], int reading)
{
    int skip = 0;

    cout << "Valid readings : ";

    for (int i = 0; i < reading; i++)
    {
        if (arr[i] < 0)
        {
            skip++;
            continue;
        }

        cout << arr[i] << "  ";
    }

    cout << endl;

    return skip;
}

// Find first critical reading
void findFirstCritical(double arr[], int reading)
{
    for (int i = 0; i < reading; i++)
    {
        if (arr[i] < 0)
        {
            continue;
        }

        if (arr[i] >= 45)
        {
            cout << "First critical : Index "
                 << i << " -> "
                 << arr[i] << " C" << endl;

            break;
        }
    }
}

// Calculate min, max and average
void calculateStats(double arr[], int reading)
{
    double max = 0;
    double min = 0;
    double sum = 0;
    double average = 0;

    int validCount = 0;

    for (int i = 0; i < reading; i++)
    {
        if (arr[i] < 0)
        {
            continue;
        }

        if (validCount == 0)
        {
            min = arr[i];
            max = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }

        sum = sum + arr[i];
        validCount++;
    }

    average = sum / validCount;

    cout << fixed << setprecision(2);

    cout << "Min : " << min << " C" << endl;
    cout << "Max : " << max << " C" << endl;
    cout << "Avg : " << average << " C" << endl;
}

// Count categories
void countCategories(double arr[], int reading)
{
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < reading; i++)
    {
        if (arr[i] < 0)
        {
            continue;
        }

        if (arr[i] < 30)
        {
            normal++;
        }
        else if (arr[i] < 40)
        {
            warning++;
        }
        else if (arr[i] < 50)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << "Normal : " << normal << endl;
    cout << "Warning : " << warning << endl;
    cout << "Critical : " << critical << endl;
    cout << "Shutdown : " << shutdown << endl;
}

int main()
{
    int reading;
    double arr[100];

    cout << "Readings entered : ";
    cin >> reading;

    cout << "Enter " << reading << " temperature readings:" << endl;

    inputReadings(arr, reading);

    int skip = printValidReadings(arr, reading);

    cout << "Skipped (errors) : " << skip << endl;

    findFirstCritical(arr, reading);

    calculateStats(arr, reading);

    countCategories(arr, reading);

    return 0;
}