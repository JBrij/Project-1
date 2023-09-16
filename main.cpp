// Description: This program will find the population growth rate in a given time frame.
//
// Author: Justin Brijmohan
// Date: 9/17/23


#include <iostream>
#include <iomanip>



using namespace std;

double estimatedPopulation (double population, double birthRate, double deathRate)
{
    return (population + ( birthRate * population ) / 100 - ( deathRate * population ) / 100);

}
double growthRate (double birthRate, double deathRate)
{
    double popGrowthRate;
    popGrowthRate = birthRate - deathRate;

    return popGrowthRate;
}


int main()
{
    double  population;
    double  birthRate;
    double  deathRate;
    int  year;
    double  popGrowthRate;
    double  estPop;

    cout << "Enter the starting population: ";
    cin >> population;
    if (population < 2)
    {
      cout << endl << "Population must be greater than 2" << endl;
      return 1;
    }


    cout << "Enter the birth rate (%): ";
    cin >> birthRate;
    if (birthRate < 0)
    {
      cout << endl << "Birth rate cannot be negative." << endl;
      return 1;
    }

    cout << "Enter the death rate (%): ";
    cin >> deathRate;
    if (deathRate < 0)
    {
      cout << endl << "Death rate cannot be negative." << endl;
      return 1;
    }

    cout << "Enter the number of years to project: ";
    cin >> year;

    popGrowthRate = growthRate(birthRate, deathRate);

    cout << endl << setw(5) << "Year"  << setw(30) << " Estimated Population" << setw(20) << "Growth Rate" << endl;
    for (int i = 1; i <= year; i++)
    {
        population = estimatedPopulation(population, birthRate, deathRate);
        cout << setw(3) << i << setw(22) << fixed << setprecision(0) << population << setw(26) << popGrowthRate << "%" << endl;
    }

    return 0;
}
