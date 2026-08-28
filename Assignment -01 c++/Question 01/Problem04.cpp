#include <iostream>
#include <cstdlib>
using namespace std;

// Function to classify temperature
int classifyTemperature(int temperature, int warn, int critical)
{
    if (temperature < warn)
    {
        return 0;   // Normal
    }
    else if (temperature < critical)
    {
        return 1;   // Warning
    }
    else if (temperature < 60)
    {
        return 2;   // Critical
    }
    else
    {
        return 3;   // Shutdown
    }
}

// Function to display usage
void displayUsage()
{
    cout << "Usage   : ./sensor_monitor <warn> <critical> <num_readings>" << endl;
}

// Function to display results
void displayResults(int normal, int warning, int critical, int shutdown)
{
    cout << "Results : Normal:" << normal
         << "  Warning:" << warning
         << "  Critical:" << critical
         << "  Shutdown:" << shutdown << endl;
}

int main(int argc, char* argv[])
{
    // Check if arguments are missing
    if (argc != 4)
    {
        displayUsage();

        cout << "Error   : Missing arguments" << endl;

        return 1;
    }

    // Convert command line arguments from string to integer
    int warn = atoi(argv[1]);
    int critical = atoi(argv[2]);
    int num_readings = atoi(argv[3]);

    // Validate warning and critical thresholds
    if (warn >= critical)
    {
        cout << "Error   : Warn threshold must be less than Critical threshold"
             << endl;

        return 1;
    }

    // Validate number of readings
    if (num_readings < 1 || num_readings > 500)
    {
        cout << "Error   : Number of readings must be between 1 and 500"
             << endl;

        return 1;
    }

    // Display configuration
    cout << "Config  : Warn=" << warn
         << "C  Critical=" << critical
         << "C  Readings=" << num_readings << endl;

    // Counters
    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    // Generate and classify readings
    for (int i = 0; i < num_readings; i++)
    {
        int temperature = rand() % 70;

        int status = classifyTemperature(
            temperature,
            warn,
            critical
        );

        if (status == 0)
        {
            normal++;
        }
        else if (status == 1)
        {
            warning++;
        }
        else if (status == 2)
        {
            criticalCount++;
        }
        else
        {
            shutdown++;
        }
    }

    // Display final result
    displayResults(
        normal,
        warning,
        criticalCount,
        shutdown
    );

    return 0;
}