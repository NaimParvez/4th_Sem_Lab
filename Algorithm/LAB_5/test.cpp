
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    // Create a file named test.txt and input 4 elements, each in 2 lines
    ofstream file("test.txt");
    file << "1\n2\n3\n4\n";
    file.close();

    // Read the elements from the file and store them in two vectors
    ifstream infile("test.txt");
    vector<int> v1, v2;
    int num;
    for (int i = 0; i < 2; i++) {
        infile >> num;
        v1.push_back(num);
    }
    for (int i = 0; i < 2; i++) {
        infile >> num;
        v2.push_back(num);
    }
    infile.close();

    // Combine the two vectors into pairs
    vector<pair<int, int>> pairs;
    for (int i = 0; i < 2; i++) {
        pairs.push_back(make_pair(v1[i], v2[i]));
    }

    // Print the pairs
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
