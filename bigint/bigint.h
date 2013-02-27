/*
 * =====================================================================================
 *
 *       Filename:  bigint.h
 *
 *    Description:  Header for bigint
 *
 *        Version:  1.0
 *        Created:  01/28/2013 07:05:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *   Organization:  Kent State University
 *
 * =====================================================================================
 */
#ifndef ELI_BIGINT_H_
#define ELI_BIGINT_H_

#include <iostream>

const int BIGINTSIZE = 100;

class bigint {
public:
	bigint();
	bigint(int);
	bigint(const char[]);

	bool operator == (const bigint&) const;
	bool operator == (int) const;
	bool operator == (const char[]) const;

	bool operator != (const bigint& rhs) const { return !(*this == rhs); };

	int operator [] (const int spot) const { return digits[spot]; };
	int& operator [] (const int spot) { return digits[spot]; };

	bigint operator + (bigint) const;
	bigint operator * (const bigint&) const;

	void times10(const int);
	void times_single_digit(const int);
	void output(std::ostream&) const;

private:
	int digits[BIGINTSIZE];
	void zero();
};

// Outputs bigint with out operator
std::ostream& operator << (std::ostream&, const bigint&);

// Inputs bigint with in operator
std::istream& operator >> (std::istream&, bigint&);

#endif

