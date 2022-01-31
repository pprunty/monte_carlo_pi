/**
 * \file        monte_carlo_pi.cc
 * \brief       This assignment uses a Monte Carlo method to approximate pi. It is
 *              particularly useful as a first assignment for those looking to study Monte
 *              Carlo and stochastic methods.
 * \author      P.Prunty
 * \version     1.0
 * \date        2020-03-25
 */

#include <vector>

#include "coord.h"

int main(void) {

    // The number of simulations
    long N;

    // Response from user whether they want to use a quasi-random number generator
    std::string user_response;
    bool sobol;

    std::cout << "Enter the number of simulations N to approximate π = ";
    std::cin >> N;
    std::cout << "Would you like to use Sobol's quasi-random number generator [y/n]?  ";
    std::cin >> user_response;

    sobol = true ? user_response == "y" || user_response == "yes" : false;

    // Initialize vector of size N
    std::vector<Coord> coords (N);

    // Populate the coords with uniform random points
    populate_coords(coords, sobol);

    // Initialize vectors to store hit and miss coordinates
    std::vector<Coord> misses;
    std::vector<Coord> hits;

    // Perform Monte Carlo approximation
    for (auto& c : coords) {
        if (hit_or_miss(c)) {
            hits.push_back(c);
        }
        else {
            misses.push_back(c);
        }
    }

    // Write results to a file
    write_to_file(std::string("points.txt"), coords);
    write_to_file(std::string("hits.txt"), hits);
    write_to_file(std::string("misses.txt"), misses);

    // Print approximation of pi
    std::cout << "Approximation of π = " << std::setprecision(8)
    << static_cast<double>(hits.size()) / N * 4 << " for " << N
    << " simulations." << '\n';

}