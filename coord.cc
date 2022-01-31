#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <random>
#include <gsl/gsl_qrng.h>

#include "coord.h"


/**
 * \brief           This function writes a vector of coords ((x,y) coordinates) to a file named by the
 *                  string argument fn.
 * \param fn        The string file name, given inside of main.
 * \param pts       The vector of points ((x,y) coordinates).
*/
void write_to_file(std::string fn, std::vector <Coord> coords) {

    std::cout << "Writing results to file: " << fn << std::endl;

    std::ofstream outfile;
    outfile.open(fn);

    if (outfile.is_open()) {
        for (auto const &p : coords) {
            outfile << p << '\n';
        }
    } else {
        std::cerr << "Error opening outfile." << std::endl;
        exit(1);
    }
}

/**
 * \brief           This function simply populates the coords vector with uniformly random
 *                  points U(0,1) using the Mersenne Twister random number by default and Sobol's
 *                  quasi-random number generator if sobol is true.
 * \param coords    The vector of coordinates.
 * \param sobol     Boolean to determine whether to use the sobol qrng or not.
 *
*/
void populate_coords(std::vector <Coord> &coords, const bool sobol) {

    // Set up rngs
    std::random_device rd;
    std::mt19937 seeded_engine(rd());

    if (sobol) {

        gsl_qrng *gsl_sobol = gsl_qrng_alloc(gsl_qrng_sobol, 2);

        for (auto &c : coords) {
            double tmp[2];
            gsl_qrng_get(gsl_sobol, tmp);
            c.x = tmp[0];
            c.y = tmp[1];
            c.radius = std::sqrt(c.x * c.x + c.y * c.y);
        }

    } else {

        // Bind uniform distribution to rng
        auto U = std::bind(std::uniform_real_distribution<>{0.0, 1.0}, seeded_engine);

        for (auto &c : coords) {
            c.x = U();
            c.y = U();
            c.radius = std::sqrt(c.x * c.x + c.y * c.y);
        }
    }
}

/**
 * \brief           This function returns true if the distance of the coordinate from the origin
 *                  is less than 1.
 * \param coord     The given coordinate
 * \return          True if the coordinate exists inside the unit circle, false otherwise.
*/
bool hit_or_miss(Coord &coord) {
    return coord.radius <= 1.0;
}