#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate RMS
double computeRMS(double* signal, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + (*(signal + i) * *(signal + i));
    }

    return sqrt(sum / n);
}

// Function to normalise the signal
void normalise(double* signal, int n)
{
    double max = 0;

    // Find maximum absolute value
    for (int i = 0; i < n; i++)
    {
        if (abs(*(signal + i)) > max)
        {
            max = abs(*(signal + i));
        }
    }

    // Divide every element by maximum
    for (int i = 0; i < n; i++)
    {
        *(signal + i) = *(signal + i) / max;
    }
}

// Function to count zero crossings
int countZeroCrossings(double* signal, int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if ((*(signal + i) > 0 && *(signal + i + 1) < 0) ||
            (*(signal + i) < 0 && *(signal + i + 1) > 0))
        {
            count++;
        }
    }

    return count;
}

// Function to apply gain
void applyGain(double* signal, int n, double gainFactor)
{
    for (int i = 0; i < n; i++)
    {
        *(signal + i) = *(signal + i) * gainFactor;
    }
}

// Function to display array
void displaySignal(double* signal, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(signal + i) << " ";
    }

    cout << endl;
}

int main()
{
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};

    int n = 7;

    cout << "Original Signal : ";
    displaySignal(signal, n);

    // Calculate RMS
    double rms = computeRMS(signal, n);

    cout << "RMS : " << rms << endl;

    // Count zero crossings
    int crossings = countZeroCrossings(signal, n);

    cout << "Zero Crossings : " << crossings << endl;

    // Normalise
    normalise(signal, n);

    cout << "After Normalise : ";
    displaySignal(signal, n);

    // Apply gain
    double gainFactor = 2.0;

    applyGain(signal, n, gainFactor);

    cout << "After Gain : ";
    displaySignal(signal, n);

    return 0;
}