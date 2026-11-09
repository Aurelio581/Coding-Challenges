#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    vector<string> jokes;
    string line;
    string command;

    // Open the jokes file
    ifstream file("Jokes.txt");

    if (!file.is_open())
    {
        cout << "Error opening jokes file!" << endl;
        return 1;
    }

    // Read and store each joke
    while (getline(file, line))
    {
        jokes.push_back(line);
    }

    file.close();

    if (jokes.empty())
    {
        cout << "No jokes found!" << endl;
        return 1;
    }
// Seed the random number generator
    srand(time(0));

    // Main program loop
    while (true)
    {
        cout << "\nSay: Joke" << endl;
        cout << "Or type X to exit: ";
        getline(cin, command);

        if (command == "X")
        {
            cout << "Goodbye!" << endl;
            break;
        }

        if (command == "Joke")
        {
            // Select a random joke
            int randomIndex = rand() % jokes.size();
            string joke = jokes[randomIndex];

            // Separate setup and punchline
            size_t separator = joke.find('?');

            if (separator != string::npos)
            {
                string setup = joke.substr(0, separator + 1);
                string punchline = joke.substr(separator + 1);

                cout << "\n" << setup << endl;
                cout << "Press Enter to reveal the punchline...";
                getline(cin, command);

                cout << punchline << endl;
            }
        }
        else
        {
            cout << "Please use the correct command." << endl;
        }
    }

    return 0;
}
