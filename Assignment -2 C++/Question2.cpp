
// Question 2 - Hospital Patient Registry

#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;   // must be set via initializer list only

public:
    // Constructor 1 - Default
    Patient()
        : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "[Constructor] Default patient registered." << endl;
    }

    // Constructor 2 - Emergency admission (id and name only)
    Patient(int id, const string& nm)
        : patientId(id), name(nm), age(0), ward("Emergency"), bloodGroup("Unknown") {
        cout << "[Constructor] Emergency: " << name << endl;
    }

    // Constructor 3 - Full admission details
    Patient(int id, const string& nm, int ag, const string& wd, const string& bg)
        : patientId(id), name(nm), age(ag), ward(wd), bloodGroup(bg) {
        cout << "[Constructor] Full admission: " << name << endl;
    }

    // Destructor
    ~Patient() {
        cout << "[Destructor] Patient " << name << " discharged." << endl;
    }

    void displayRecord() const {
        cout << "Patient Record:\n"
             << "  ID        : " << patientId << "\n"
             << "  Name      : " << name << "\n"
             << "  Age       : " << age << "\n"
             << "  Ward      : " << ward << "\n"
             << "  Blood Grp : " << bloodGroup << "\n";
    }

    void transferWard(const string& newWard) {
        cout << "Ward Transfer: " << name << " -> " << newWard << endl;
        ward = newWard;
    }

    string getName() const { return name; }
};

int main() {
    cout << "===== CREATING STACK PATIENTS =====\n";
    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");  // full admission
    Patient p2(1002, "Raj Patel");                            // emergency
    Patient p3;                                               // default

    cout << "\n===== CREATING DYNAMIC ARRAY (HEAP) =====\n";
    Patient* ward = new Patient[4];   // must use default constructor for array

    cout << "\n===== DISPLAYING ALL 4 HEAP PATIENTS =====\n";
    for (int i = 0; i < 4; i++) {
        ward[i].displayRecord();
    }

    cout << "\n===== TRANSFER DEMO =====\n";
    p2.transferWard("ICU");

    cout << "\n===== DEALLOCATING HEAP ARRAY =====\n";
    delete[] ward;   // 4 destructor calls here

    cout << "\n===== END OF main() - STACK OBJECTS GO OUT OF SCOPE =====\n";
    // p3, p2, p1 destructors fire automatically in reverse order of creation
    return 0;
}