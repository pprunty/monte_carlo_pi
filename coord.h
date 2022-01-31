#ifndef COORD_H_OMJSZLDH
#define COORD_H_OMJSZLDH

#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>


/**
 * \brief Simple structure to store coordinates of a (x,y) coordinate
 */
struct Coord {
    double x;
    double y;
    double radius;

    Coord() = default;

    Coord(double inx, double iny) : x{inx}, y{iny} {};

    bool operator<(const Coord& rhs) const {
        return x < rhs.x || (*this == rhs);
    }

    // Write the definition of this in point.cc
    bool operator==(const Coord &rhs) const {
        /* Place more likely outcome first for branch predictor. */
        if (x != rhs.x && y != rhs.y) {
            return false;
        } else {
            return true;
        }
    }
};

/**
 * \brief       Overloading output stream operator for a Coord.
 *              The operator should simply print the x and y coordinates of Coord "in"
 *
 * \param os    Reference to output stream
 * \param in    Reference to Coord which we want to print.
 *
 * \return      Reference to output stream
 */
inline std::ostream &operator<<(std::ostream &os, const Coord &in) {
    os << std::fixed << std::setw(9) << in.x << ", " << std::setw(9) << in.y;
    return os;
}

void write_to_file(std::string fn, std::vector <Coord> pts);

void populate_coords(std::vector<Coord>& pts, const bool sobol);

bool hit_or_miss(Coord& c);

#endif /* end of include guard: COORD_H_OMJSZLDH */
