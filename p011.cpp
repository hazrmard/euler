#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    cout << "Number of arguments: " << argc << "\n";
    int dim = stoi(argv[1]);
    string path = argv[2];
    cout << path;

    return 0;
}
