/*
 * =====================================================================================
 *
 *       Filename:  string.cpp
 *
 *    Description:  My implementation of the string library
 *
 *        Version:  1.0
 *        Created:  02/21/2013 06:23:22 PM
 *       Revision:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#include "string.h"

/*
 * Default constructor for string
 * Ex: String str;
 * Ex: String str();
 */
String::String(const int cap)
{
	capacity = cap;
	s = new char[capacity];
	length = 0;
	s[0] = '\0';
}

/*
 * String constructor for a single char
 * Ex: String str = 'a';
 * Ex: String str('a');
 */
String::String(const char rhs, const int cap)
{
	capacity = cap;
	s = new char[capacity];
	length = 1;
	s[0] = rhs;
	s[1] = '\0';
}

/*
 * String constructor for C-Style strings
 * Ex: String str = "abc";
 * Ex: String str("abc");
 */
String::String(const char rhs[], const int cap)
{
	capacity = cap;
	s = new char[cap];
	length = 0;
	bool restart = false;

	do {
		for (; rhs[length] != '\0'; ++length) {
			s[length] = rhs[length];
		}

		if (capacity < length) {
			restart = true;
			delete [] s;
			s = new char[capacity *= 2];
		}
	} while (!restart);

	s[length + 1] = '\0';
}

/*
 * Copy constructor for string
 * Ex: String str = strcopy;
 */
String::String(const String& rhs, const int cap)
{
	if (cap <= rhs.length) {
		capacity = rhs.length + 1;
	} else {
		capacity = cap;
	}

	s = new char[capacity];

	for (length = 0; rhs.s[length] != '\0'; ++length) {
		s[length] = rhs.s[length];
	}

	s[length] = '\0';
}

/*
 * Destructor for String
 */
String::~String()
{
	length = 0;
	delete [] s;
}

/*
 * Copy operator for string
 * Ex: String str = rhs_str;
 */
String& String::operator = (String rhs)
{
	swap(rhs);
	return *this;
}

/*
 * Compares two strings together
 * Ex: str1 == str2;
 */
bool String::operator == (const String& rhs) const
{
	if (length != rhs.length) {
		return false;
	}

	for (int i = 0; i < length; ++i) {
		if (s[i] != rhs.s[i]) {
			return false;
		}
	}

	return true;
}

/*
 * Compares to see if two strings are less than each other
 * Ex: str1 < str2;
 */
bool String::operator < (const String& rhs) const
{
	bool lessThan = false;
	int i = 0;

	for (; s[i] != '\0' && rhs.s[i] != '\0'; ++i) {
		if (s[i] > rhs.s[i]) return false;
		if (s[i] < rhs.s[i]) lessThan = true;
	}

	if (lessThan && (s[i] == '\0') && (rhs.s[i] == '\0')) return true;
	if (lessThan && (rhs.s[i] == '\0')) return true;
	if (!lessThan && (s[i] == '\0') && (rhs.s[i] == '\0')) return false;
	if (s[i] == '\0') return true;

	return false;
}

/*
 * Adds two strings together
 * Ex: String result = left + right;
 */
String String::operator + (const String& rhs) const
{
	int index = 0;
	String result;
	result.length = length + rhs.length;

	for (; index < length; ++index) {
		result.s[index] = s[index];
	}

	for (int rhsindex = 0; rhsindex < rhs.length; ++rhsindex, ++index) {
		result.s[index] = rhs.s[rhsindex];
	}

	result.s[++index] = '\0';

	return result;
}

/*
 * Subtracts a specified number of chars from the end of a string
 * Ex: str = str1 - 5;
 * Ex: str -= 5;
 */
String String::operator - (int x) const
{
	String result;

	if (x == 0) {
		result = *this;
	} else if (x >= length) {
		return result;
	} else {
		for (int i = 0; i < (length - x); ++i) {
			result += s[i];
		}
	}


	return result;
}

/*
 * Subtracts all instances of a char from a string
 * Ex: str - 'a';
 * Ex: str -= 'a';
 */
String String::operator - (char ch) const
{
	String result;

	for (int index = 0; index < length; ++index) {
		if (s[index] != ch) {
			result += s[index];
		}
	}

	return result;
}

/*
 * Repeats a string a specified number of times with the multiplication operator
 * Ex: str = str1 * 5;
 */
String String::operator * (const int x) const
{
	String result;

	for (int index = 0; index < x; ++index) {
		result += *this;
	}

	return result;
}

/*
 * Cuts a specified number of chars from the front of a string
 * Ex: str = str1 / 3;
 */
String String::operator / (const int x) const
{
	String result;

	for (int index = x; index < length; ++index) {
		result += s[index];
	}

	return result;
}

/*
 * Returns the character from a specified index. Returns null if out of bounds.
 * Ex: char c = str[1];
 */
char String::operator [] (int index) const
{
	if (index >= length || index < 0) {
		std::exit(0);
	}

	return s[index];
}

char& String::operator [] (int index)
{
	if (index >= length || index < 0) {
		std::exit(0);
	}

	return s[index];
}

/*
 * Inputs string with the >> operator
 * Ex: std::cin >> str;
 */
std::istream& operator >> (std::istream& in, String& rhs)
{
	char temp;

	while (in) {
		in.get(temp);

		if (!in.eof()) {
			rhs += temp;
		}
	}

	return in;
}

/*
 * Outputs string with << operator
 * Ex:: std::cout << str << std::endl;
 */
std::ostream& operator << (std::ostream& out, const String& str)
{
	for (int index = 0; index < str.length; ++index) {
		out << str[index];
	}

	return out;
}

/*
 * Finds the first occurance of a char in a string with zero offset
 * Ex: str.findchar('c');
 */
int String::findchar(char find) const
{
	for (int i = 0; i < length; ++i) {
		if (s[i] == find) {
			return i;
		}
	}

	return -1;
}

/*
 * Finds how many times a string occurs in another string
 * Ex: str.findstr(find);
 */
int String::findstr(const String& find) const
{
	int result = 0;

	if (length > find.length) {
		for (int index = 0, findindex = 0; index < length; ++index, findindex = 0) {
			while (s[index + findindex] == find.s[findindex] && findindex <= find.length) {
				++findindex;

				if (findindex == find.length) {
					++result;
					index += findindex;
				}
			}
		}
	}

	return result;
}

/*
 * Checks if null character is at end of string
 * Ex: str.isClosed() == true;
 */
bool String::isClosed() const
{
	switch (length) {
		case 0:
			return s[0] == '\0';
			break;
		case 1:
			return s[1] == '\0';
			break;
		default:
			return s[length + 1] == '\0';
	}
}

void String::reallocate(const int cap)
{
	String temp(*this, cap);
	swap(temp);
}

/*
 * Swaps two strings
 * Ex: str1.swap(str2);
 */
void String::swap(String& str)
{
	char *temp = s;
	s = str.s;
	str.s = temp;

	int temp_cap = capacity;
	capacity = str.capacity;
	str.capacity = temp_cap;

	int temp_length = length;
	length = str.length;
	str.length = temp_length;
}

/*
 * Extracts the selected parts of the string based off of 1 or 2 indexes
 * Ex: str.substr(1);
 * Ex: str.substr(1, 5);
 */
String String::substr(int left, int right) const
{
	if (right > length || right <= 0) {
		right = length;
	}

	return ((*this / left) - (length - right));
}
