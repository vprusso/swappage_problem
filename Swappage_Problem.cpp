/*
	swappage_problem.cpp 

	author : Vincent Russo (vincentrusso1@gmail.com)
	version  1.00
	last updated: June 10, 2011

	This is based on the paper "Beatty Sequences, Fibonacci Numbers,
	and the Golden Ratio" - Vincent Russo and Loren Schwiebert
	(http://www.fq.math.ca/Papers/49-2/RussoSchwiebert.pdf)

	This code generates the sequences of interest up to some finite 
	number of terms. This code is supplemental, and may be of use to
	others who wish to generate these sequences for other similar problems.
*/

#include <iostream>
#include <cmath>

// Golden ratio
const double GRATIO = ( (1 + sqrt(5.0)) / 2 );

// Lower Wythoff Sequence
double L ( int n ) { return floor(n*GRATIO); }

// Upper Wythoff Sequence 
double U ( int n ) { return floor(n*pow(GRATIO,2)); }

// The sequence V (or W) defined as the swappage
// of the Lower Wythoff Seqeucne
double V ( int n )
{
	if ( int(U(n)) % 2 == 0 )
		return U(n);
	else
		return U(n) - 1;
}

// The sequence S(n) = V(n)/2
double S(int n) { return V(n)/2; }

int main() 
{
	// An example use. Generating the terms of the sequences of interest.

	int num_terms = 20;

	std::cout << "First " << num_terms << " terms of the Lower Wythoff Sequence. " << std::endl;
	for ( int n = 1; n < num_terms; ++n ) 
		std::cout << L(n) << std::endl;

	std::cout << "First " << num_terms << " terms of the Upper Wythoff Sequence. " << std::endl;
	for ( int n = 1; n < num_terms; ++n ) 
		std::cout << U(n) << std::endl;

    std::cout << "First " << num_terms << " terms of the Swappage of L. " << std::endl;
	for ( int n = 1; n < num_terms; ++n ) 
		std::cout << V(n) << std::endl;

	return 0;
}