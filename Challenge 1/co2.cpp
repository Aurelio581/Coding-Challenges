#include <iostream>
#include <iomanip>
using namespace std;

// Function to get the distance travelled
double getDistance()
{
    double distance;

    cout << "Enter the distance travelled (miles): ";
    cin >> distance;

    return distance;
}

//  to get the fuel type
int getFuelType()
{
    int fuel;

    cout << "\nfuel type:" << endl;
    cout << "1. Diesel" << endl;
    cout << "2. Petrol" << endl;
    cout << "Enter your choice: ";
    cin >> fuel;

    return fuel;
}

// to calculate CO2 emissions until be true
void calculateResult(double distance, int fuel)
{
    double fuelConsumption = 9.66;
    double emissions;
    double litresUsed;

    litresUsed = (distance * fuelConsumption) / 100;

    if (fuel == 1)
    {
        emissions = 2.68;
        cout << "\ntype: Diesel" << endl;
    }
    else
    {
        emissions = 2.31;
        cout << "\ntype: Petrol" << endl;
    }

    double co2 = litresUsed * emissions;

// Display the results, setprecision(2) to display the results with two decimal places
    cout << fixed << setprecision(2);
    cout << "Distance: " << distance << " miles" << endl;
    cout << "Fuel used: " << litresUsed << " litres" << endl;
    cout << "CO2 emissions: " << co2 << " kg" << endl;
}

// Main function
int main()
{
    double distance;
    int fuel;

    cout << "CO2 Calculator" << endl;

    distance = getDistance();
    fuel = getFuelType();

    calculateResult(distance, fuel);

    return 0;
}
