/*
 * =====================================================================================
 *
 *       Filename:  bigint.cpp
 *
 *    Description:  Implementation for bigint
 *
 *        Version:  1.0
 *        Created:  01/28/2013 07:14:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *   Organization:  Kent State University
 *
 * =====================================================================================
 */
#include "bigint.h"

void bigint::zero()
{
	for (int i = 0; i < BIGINTSIZE; ++i) {
		digits[i] = 0;
	}
}

bigint::bigint()
{
	zero();
}

bigint::bigint(int x)
{
	zero();

	for (int i = 0; x != 0; ++i) {
		digits[i] = x % 10;
		x /= 10;
	}
}

bigint::bigint(const char x[])
{
	zero();

	int chari = 0;

	do {
		++chari;
	} while (x[chari] != '\0');

	--chari;

	for (int bigi = 0; x[bigi] != '\0'; ++bigi, --chari) {
		digits[chari] = (int(x[bigi]) - int('0'));
	}
}

bool bigint::operator == (const bigint& rhs) const
{
	for (int i = 0; i < BIGINTSIZE; ++i) {
		if (digits[i] != rhs.digits[i]) return false;
	}

	return true;
}

bool bigint::operator == (int rhs) const
{
	for (int i = 0; rhs != 0; ++i) {
		if (digits[i] != rhs % 10) return false;
		rhs /= 10;
	}

	return true;
}

bool bigint::operator == (const char rhs[]) const
{
	int chari = 0;

	do {
		++chari;
	} while (rhs[chari] != '\0');

	--chari;

	for (int bigi = 0; rhs[bigi] != '\0'; ++bigi, --chari) {
		if (digits[chari] != int(rhs[bigi]) - int('0')) return false;
	}

	return true;
}

void bigint::output(std::ostream& out) const
{
	int bigi = BIGINTSIZE,
		outi = 0;

	do {
		--bigi;
	} while(digits[bigi] == 0);

	do {
		if (outi % 80)
			out << digits[bigi];
		else
			out << std::endl << digits[bigi];

		--bigi, ++outi;
	} while (bigi >= 0);
}

std::ostream& operator << (std::ostream& out, const bigint& num)
{
	num.output(out);
	return out;
}

std::istream& operator >> (std::istream& in, bigint& num)
{
	int tempi = 0;
	char next,
		 temp[BIGINTSIZE];

	in >> next;

	while (next != ';' && !in.eof()) {
		temp[tempi] = next;
		in >> next;
		++tempi;
	}

	temp[tempi] = 0;
	num = bigint(temp);

	return in;
}

bigint bigint::operator + (bigint rhs) const
{
	int i = 0,
		remainder = 0,
		temp = 0;

	while (i < BIGINTSIZE) {
		remainder = rhs.digits[i] + digits[i] + remainder;
		temp = remainder % 10;
		remainder /= 10;
		rhs.digits[i] = temp;
		++i;
	}

	return rhs;
}

bigint bigint::operator * (const bigint& rhs) const
{
	bigint partial = *this,
		   result;

	for (int i = 0; i < BIGINTSIZE; ++i, (partial = *this)) {
		partial.times_single_digit(rhs[i]);
		partial.times10(i);
		result = result + partial;
	}

	return result;
}

void bigint::times10(const int x)
{
	for (int i = (BIGINTSIZE - 1); i >= 0; --i) {
		digits[i] = digits[i - x];
	}

	for (int i = (x - 1); i >= 0; --i) {
		digits[i] = 0;
	}
}

void bigint::times_single_digit(const int x)
{
	int place_value = 0,
		carry = 0;

	for (int i = 0; i < BIGINTSIZE; ++i) {
		place_value = (x * digits[i]) + carry;
		carry = place_value / 10;
		digits[i] = place_value % 10;
	}
}
