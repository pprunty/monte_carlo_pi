#include <iostream> //<! std::cout
#include <iomanip>  //<! std::set_precision
#include <limits>   //<! std::numeric_limits
#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/sqrt.hpp>

/**
 * \brief       This is an example of how Archimeses of Syracuse actually computes pi. Archimedes approximates the
 *              circumfrence of a circle of radius r (we take r = 0.5) by the perimeter a of the circumscribed polygon and
 *              the perimeer b of the inscribed polygon. The algorithm is based on the fact that the harmonic mean of two
 *              numbers x and y is smaller than their geometric mean: 2xy/(x+y) < sqrt(x*y). The Archimedes recursion
 *              formulae for the perimeters a and b are: a_n+1 = (2a_n*b_n)/(a_n+b_n), b_n+1 = sqrt(b_n*a_n+1), n not
 *              equal to zero, with the initial values a_0 = 2*sqrt(3), b_0 = 3 (radius = 0.5).
 * \param N           The number of iterations.
 * \return      void function
*/
template <typename T> 
void ArchimedesPi(int N) {	// N == number of iterations

	T an, anpl, bn, bnpl;

	an = T(2.0)*boost::multiprecision::sqrt(T(3.0)); bn = T(3.0);


	for (int n=1; n<=N; ++n) {
		
		anpl = T(2.0)*an*bn / (an+bn); 
		bnpl = boost::multiprecision::sqrt(bn*anpl);

		an = anpl; bn = bnpl;

	}

	std::cout << "N value: " << std::setprecision(std::numeric_limits<T>::digits10) 
	<< N << "/" << "Pi: " << bn << "\n\n";

	std::cout << "Error: " << std::setprecision(8) 
	<< boost::multiprecision::abs(bn-an) << "\n\n";

}


/**
 * \brief       This is the main function, which calls the archimes function a number of times and siplays a
 *              subset of each output.
 * \return      void main function.
*/
int main(void) {
	
	int N = 100;

	for (int n=0; n<=N; n+=10) {
		ArchimedesPi < boost::multiprecision::cpp_dec_float_100>(n);
	}

}


