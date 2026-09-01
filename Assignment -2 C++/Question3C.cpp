#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int R, C;

    cout << "Enter number of rows: ";
    cin >> R;

    cout << "Enter number of columns: ";
    cin >> C;


    // Allocate outer array
    int** map = new int*[R];

    // Allocate each row
    for (int i = 0; i < R; i++) {
        map[i] = new int[C];
    }


    // Random number seed
    srand(time(0));


    // Fill the map
    for (int i = 0; i < R; i++) {

        for (int j = 0; j < C; j++) {

            map[i][j] = rand() % 5;
        }
    }


    // Display map
    cout << "\n===== GAME MAP (" << R << " x " << C << ") ====="
         << endl;

    for (int i = 0; i < R; i++) {

        for (int j = 0; j < C; j++) {

            cout << map[i][j] << "  ";
        }

        cout << endl;
    }


    // Legend
    cout << "\nLegend: ";
    cout << "0=Grass  ";
    cout << "1=Water  ";
    cout << "2=Mountain  ";
    cout << "3=Forest  ";
    cout << "4=Dungeon";
    cout << endl;


    // Count tiles
    int count[5] = {0};


    for (int i = 0; i < R; i++) {

        for (int j = 0; j < C; j++) {

            count[map[i][j]]++;
        }
    }


    // Display tile count
    cout << "\nTile Count:" << endl;

    cout << "Grass    : " << count[0] << endl;
    cout << "Water    : " << count[1] << endl;
    cout << "Mountain : " << count[2] << endl;
    cout << "Forest   : " << count[3] << endl;
    cout << "Dungeon  : " << count[4] << endl;


    // Deallocate each row
    for (int i = 0; i < R; i++) {

        delete[] map[i];
    }

    // Deallocate outer array
    delete[] map;


    return 0;
}