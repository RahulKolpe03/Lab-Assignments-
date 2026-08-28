#include<iostream>
using namespace std;

int getStatusCode(double reading){
    if(reading < 0)
    return -1;
    else if (reading < 30)
    return 0 ;
    else if (reading < 45)
    return 1 ;
    else if (reading < 60)
    return 2 ;
    else
    return 3;
}

void Status( int statusCode)
{
    switch (statusCode)
    {
    case -1 :
        cout<< "Status : Sensor_Error"<<endl;
        cout<< " Action : Sensor fault - check wiring"<<endl;
        break;

    case 0:
            cout << "Status      : NORMAL" << endl;
            cout << "Action      : No action required" << endl;
            break;

    case 1:
            cout << "Status      : WARNING" << endl;
            cout << "Action      : Alert sent to supervisor" << endl;
            break;

    case 2:
            cout << "Status      : CRITICAL" << endl;
            cout << "Action      : Cooling system triggered" << endl;
            break;

    case 3:
            cout << "Status      : SHUTDOWN" << endl;
            cout << "Action      : Emergency shutdown initiated" << endl;
            break;     
   
    
   
    }
}
double convertToFahrenheit(double celsius)
{
    return (celsius * 9 / 5) + 32;
}


int main(){

     double reading;

    cout << "Enter Temperature: ";
    cin >> reading;

    int statusCode = getStatusCode(reading);

    Status(statusCode);

    cout << "Reading     : "
         << (reading >= 25 ? "Above Average" : "Below Average")
         << endl;

    double fahrenheit = convertToFahrenheit(reading);

    cout << "Temperature : " << reading << " C / "
         << fahrenheit << " F" << endl;

    return 0;
    
}