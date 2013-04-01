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
	// Calculate the length of the string
	for (length = 0; rhs[length] != '\0'; ++length) {}

	// Resize the capacity as needed
	if (length > cap - 1) {
		capacity = length + 1;
	} else {
		capacity = cap;
	}

	s = new char[capacity];

	// Copy chars to string
	for (int index = 0; rhs[index] != '\0'; ++index) {
		s[index] = rhs[index];
	}

	s[length] = '\0';
}

/*
 * Copy constructor for string
 * Ex: String str = strcopy;
 */
String::String(const String& rhs, const int cap)
{
	// Check if capacity is shorter than length
	if (cap <= rhs.length) {
		capacity = rhs.length + 1;
	} else {
		capacity = cap;
	}

	s = new char[capacity];

	// Copy chars to string
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
 * Assignment operator for string
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

	for (int index = 0; index < length; ++index) {
		if (s[index] != rhs.s[index]) {
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
	int index = 0;

	for (; s[index] != '\0' && rhs.s[index] != '\0'; ++index) {
		if (s[index] > rhs.s[index]) {
			return false;
		}

		if (s[index] < rhs.s[index]) {
			lessThan = true;
		}
	}

	if (lessThan && (s[index] == '\0') && (rhs.s[index] == '\0')) {
		return true;
	}

	if (lessThan && (rhs.s[index] == '\0')) {
		return true;
	}

	if (!lessThan && (s[index] == '\0') && (rhs.s[index] == '\0')) {
		return false;
	}

	if (s[index] == '\0') {
		return true;
	}

	return false;
}

/*
 * Adds two strings together
 * Ex: String result = left + right;
 */
String String::operator + (const String& rhs) const
{
	String result(*this, length + rhs.length + 1);
	result.length = length + rhs.length;

	for (int rhsindex = 0, index = length; rhsindex < rhs.length; ++rhsindex, ++index) {
		result.s[index] = rhs.s[rhsindex];
	}

	result.s[result.length] = '\0';

	return result;
}

/*
 * Subtracts a specified number of chars from the end of a string
 * Ex: str = str1 - 5;
 * Ex: str -= 5;
 */
String String::operator - (const int x) const
{
	if (x == 0) {
		return *this;
	}

	String result;

	if (x < length) {
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
String String::operator - (const char ch) const
{
	if (findchar(ch) == -1) {
		return *this;
	}

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
	String result(length * x + 1);

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
	String result(capacity - x);

	for (int index = x; index < length; ++index) {
		result += s[index];
	}

	return result;
}

/*
 * Returns the character from a specified index. Returns null if out of bounds.
 * Ex: char c = str[1];
 */
char String::operator [] (const int index) const
{
	try {
		return s[index];
	} catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << std::endl;
	}
}

char& String::operator [] (const int index)
{
	try {
		return s[index];
	} catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << std::endl;
	}
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
 * Ex: str.findchar('c', 10);
 */
int String::findchar(const char find, const int offset, const bool polarity) const
{
	for (int index = offset; index < length; ++index) {
		if ((s[index] == find) == polarity) {
			return index;
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
	if (find == *this) {
		return 1;
	} else if (length < find.length) {
		return 0;
	}

	int result = 0;

	for (int index = findchar(find.s[0]); index < length && index != -1; index = findchar(find.s[0], ++index)) {
		if (substr(index, find.length) == find) {
			++result;
		}
	}

	return result;
}

/*
 * Justifies a string to a specified width
 * Ex: str.justify(50);
 */
String String::justify(const int width) const
{
	String result = *this;
	int index = 0;

	while (result.length < width) {
		index = result.nextBlank(index);
		result = result.substr(0, index + 1) + ' ' + result.substr(index + 1);
		index = result.nextNonBlank(index);
	}

	return result;
}

/*
 * Finds the next blank space in a string
 * Ex: str.nextBlank();
 * Ex: str.nextBlank(3);
 */
int String::nextBlank(const int start) const
{
	if (findchar(' ', 0) == -1) {
		return -1;
	}

	for (int index = start; true; ++index) {
		if (index >= length) {
			index = 0;
		}

		if (s[index] == ' ') {
			return index;
		}
	}

	return -1;
}

int String::nextNonBlank(const int start) const
{
	if (findchar(' ', 0, false) == -1) {
		return -1;
	}

	for (int index = start; true; ++index) {
		if (index >= length){
			index = 0;
		}

		if (s[index] != ' ') {
			return index;
		}
	}

	return -1;
}

/*
 * Reallocates string's capacity to a specified value
 * Ex: str.reallocate(40);
 */
void String::reallocate(const int cap)
{
	String temp(*this, cap);
	swap(temp);
}

/*
 * Replaces a char in a string with another char
 * Ex: str.replaceChar('\n', ' ');
 */
String String::replaceChar(const char find, const char replace) const
{
	String result(*this, length + 1);

	for (int index = 0; index < result.length; ++index) {
		if (result.s[index] == find) {
			result.s[index] = replace;
		}
	}

	return result;
}

String String::replaceChar(const char find, const String& replace) const
{
	String result;

	for (int index = 0; index < length; ++index) {
		if (s[index] == find) {
			result += replace;
		} else {
			result += s[index];
		}
	}

	return result;
}

/*
 * Reverses the contents of a string
 * Ex: str.reverse();
 */
String String::reverse() const
{
	String result(length + 1);

	for (int index = length - 1; index >= 0; --index) {
		result += s[index];
	}

	return result;
}

/*
 * Splits a string on a specified char. Defaults to every char
 * Ex: str.split();
 * Ex: str.split(' ');
 * Ex: str.split('a');
 */
std::vector<String> String::split(const char ch) const
{
	std::vector<String> result;

	if (ch == '\0') {
		for (int index = 0; index < length; ++index) {
			result.push_back(s[index]);
		}

		return result;
	}

	String temp;

	for (int index = 0; index < length; ++index) {
		if (s[index] != ch) {
			temp += s[index];
		} else {
			result.push_back(temp);
			temp = s[++index];
		}
	}

	return (result.push_back(temp), result);
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
 * Extracts the selected parts of the string based off of an index and length
 * Ex: str.substr(1);
 * Ex: str.substr(1, 5);
 */
String String::substr(int left, int right) const
{
	String result;

	if (left < 0) {
		left = 0;
	}

	if (right == 0 || (left + right) > length) {
		right = length;
	} else {
		right += left;
	}

	for (; left < right && s[left] != '\0'; ++left) {
		result += s[left];
	}

	return result;
}

/*
 * Zips two string together like a zipper
 * Ex: str.zip(str2);
 */
String String::zip(const String& rhs) const
{
	String result(length + rhs.length + 1);

	for (int index = 0; index < result.capacity; ++index) {
		if (index < length) {
			result += s[index];
		}

		if (index < rhs.length) {
			result += rhs.s[index];
		}
	}

	return result;
}

/*
 * Get's line of text from an input
 * Ex: getline(file);
 */
String getline(std::istream& in)
{
	String line;
	char ch = '\0';

	for (in.get(ch); ch != '\n' && !in.fail(); in.get(ch)) {
		line += ch;
	}

	return line;
}
