#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main() 
{
    static const int kPlayerCount = 4;
    static const int kRbiCount = 4;

    // Store pairs (PlayerID, RBI average)
    map<int, double> result; 


    FILE *infile;
     
    // Open person.dat for reading
    infile = fopen ("data.txt", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // Read data from file 
    ifstream input("data.txt");
    for (int currPlayer = 1; currPlayer <= kPlayerCount; currPlayer++)
    {
        int playerId;
        input >> playerId;

        // Read RBIs and compute average
        int rbi;
        input >> rbi;
        double total = rbi;
        for (int i = 2; i <= kRbiCount; i++)
        {
            input >> rbi;
            total += rbi;
        }
        const double average = total / kRbiCount;

        // Store player ID and RBI average in the map
        result[playerId] = average;
    }


    // Output results to console
    for (auto it = result.begin(); it != result.end(); ++it)
    {
        cout << "Player: "      << it->first  << endl;
        cout << "Average RBI: " << it->second << endl;
        cout << "--------" << endl;        
    }
}