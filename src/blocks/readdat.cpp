#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream infile("checkpoints.dat", ios::binary);
    if (!infile) {
        cout << "Error opening file" << endl;
        return 1;
    }
    
    // read data from the file
    int n;
    infile.read((char*)&n, sizeof(int));
    
    infile.close();
    return 0;
}
