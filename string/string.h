/*
 * =====================================================================================
 *
 *       Filename:  string.h
 *
 *    Description:  My implementation of the string library
 *
 *        Version:  1.0
 *        Created:  02/21/2013 06:19:52 PM
 *       Revision:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#ifndef ELIGUNDRY_STRING_H_
#define ELIGUNDRY_STRING_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>

#define DEFAULT_STRING_CAPACITY 128

class String {
public:
	/*
	 * Default constructor for string with optional capacity
	 * Ex: String str;
	 * Ex: String str();
	 * Ex: String str(28);
	 */
	String(int cap = DEFAULT_STRING_CAPACITY);

	/*
	 * String constructor for a single char
	 * Ex: String str = 'a';
	 * Ex: String str('a');
	 * Ex: String str('a', 28);
	 */
	String(const char, int cap = DEFAULT_STRING_CAPACITY);

	/*
	 * String constructor for C-Style strings
	 * Ex: String str = "abc";
	 * Ex: String str("abc");
	 * Ex: String str("abc", 100);
	 */
	String(const char[], int cap = DEFAULT_STRING_CAPACITY);

	/*
	 * Copy constructor for string
	 * Ex: String str = strcopy;
	 * Ex: String str(strcopy, 50);
	 */
	String(const String&, int cap = DEFAULT_STRING_CAPACITY);

	/*
	 * Destructor for String
	 */
	~String();

	/*
	 * Copy operator for string
	 * Ex: String str = rhs_str;
	 */
	String& operator = (String);

	/*
	 * Compares two strings together
	 * Ex: str1 == str2;
	 * Ex: str1 != str2;
	 */
	bool operator == (const String&) const;
	bool operator != (const String& rhs) const { return !(*this == rhs); };

	/*
	 * Compares a string to a character array
	 * Ex: str == 'abc';
	 * Ex: str != 'abc';
	 */
	bool operator == (const char rhs[]) const { return *this == String(rhs); };
	bool operator != (const char rhs[]) const { return !(*this == String(rhs)); };
	bool operator == (const char rhs) const { return *this == String(rhs); };
	bool operator != (const char rhs) const { return !(*this == String(rhs)); };

	/*
	 * Compares to see if two strings are greater or less than
	 * Ex: str1 < str2;
	 * Ex: str1 > str2;
	 * Ex: str1 >= str2;
	 * Ex: str1 <= str2;
	 */
	bool operator < (const String&) const;
	bool operator > (const String& rhs) const { return rhs < *this; };
	bool operator <= (const String& rhs) const { return (*this < rhs) || (*this == rhs); };
	bool operator >= (const String& rhs) const { return (rhs < *this) || (*this == rhs); };

	/*
	 * Adds two strings together
	 * Ex: String result = left + right;
	 * Ex: String str1 += str2;
	 * Ex: String result = left + "!!";
	 * Ex: String result = left + '!';
	 */
	String operator + (const String&) const;
	String operator + (const char rhs[]) const { return *this + String(rhs); };
	String operator + (char rhs) const { return *this + String(rhs); };
	String& operator += (const String& rhs) { return *this = *this + rhs; };
	String& operator += (const char rhs[]) { return *this = *this + String(rhs); };
	String& operator += (char rhs) { return *this = *this + String(rhs); };

	/*
	 * Friend functions to add a char or char[] in front of a string
	 * Ex: str = 't' + rhs;
	 * Ex: str = "the " + rhs;
	 */
	friend String operator + (const char lhs, const String& rhs) { return String(lhs) + rhs; };
	friend String operator + (const char lhs[], const String& rhs) { return String(lhs) + rhs; };

	/*
	 * Subtracts a specified number of chars from the end of a string
	 * Ex: str = str1 - 5;
	 * Ex: str -= 5;
	 */
	String operator - (const int) const;
	String& operator -= (const int x) { return *this = *this - x; };

	/*
	 * Subtracts all instances of a char from a string
	 * Ex: str - 'a';
	 */
	String operator - (const char) const;
	String& operator -= (const char ch) { return *this = *this - ch; };

	/*
	 * Repeats a string a specified number of times with the multiplication operator
	 * Ex: str = str1 * 5;
	 * Ex: str *= 5;
	 */
	String operator * (const int) const;
	String& operator *= (const int x) { return *this = *this * x; };

	/*
	 * Cuts a specified number of chars from the front of a string
	 * Ex: str = str1 / 3;
	 * Ex: str /= 3;
	 */
	String operator / (const int) const;
	String& operator /= (const int x) { return *this = *this / x; };

	/*
	 * Returns the character from a specified index. Returns null if out of
	 * bounds.
	 * Ex: char c = str[1];
	 */
	char operator [] (const int) const;
	char& operator [] (const int);

	/*
	 * Inputs string with the >> operator
	 * Ex: std::cin >> str;
	 */
	friend std::istream& operator >> (std::istream&, String&);

	/*
	 * Outputs string with << operator
	 * Ex:: std::cout << str << std::endl;
	 */
	friend std::ostream& operator << (std::ostream&, const String&);

	/*
	 * Finds the first occurance of a char in a string with zero offset
	 * Ex: str.findchar('c');
	 * Ex: str.findchar('c', 10);
	 */
	int findchar(const char, int offset = 0, bool polarity = true) const;

	/*
	 * Finds how many times a string occurs in another string
	 * Ex: str.findstr(find);
	 */
	int findstr(const String&) const;

	/*
	 * Returns the length of the string
	 * Ex: int x = str.getLength();
	 */
	int getLength() const { return length; };

	/*
	 * Returns the memory capacity of the string
	 * Ex: int x = str.getCapacity();
	 */
	int getCapacity() const { return capacity; };

	/*
	 * Checks if null character is at end of string
	 * Ex: str.isClosed() == true;
	 */
	bool isClosed() const { return s[length] == '\0'; };

	/*
	 * Justifies a string to a specified width
	 * Ex: str.justify(50);
	 */
	String justify(const int) const;

	/*
	 * Finds the next blank space in a string
	 * Ex: str.nextBlank();
	 * Ex: str.nextBlank(3);
	 */
	int nextBlank(int start = 0) const;

	/*
	 * Finds the next non-blank char in a string
	 * Ex: str.nextNonBlank();
	 * Ex: str.nextNonBlank(3);
	 */
	int nextNonBlank(int start = 0) const;

	/*
	 * Reallocates string's capacity to a specified value
	 * Ex: str.reallocate(40);
	 */
	void reallocate(const int);

	/*
	 * Replaces a char in a string with another char or string
	 * Ex: str.replaceChar('\n', ' ');
	 */
	String replaceChar(const char, const char) const;
	String replaceChar(const char, const String&) const;

	/*
	 * Reverses the contents of a string
	 * Ex: str.reverse();
	 */
	String reverse() const;

	/*
	 * Splits a string on a specified char. Defaults to every char
	 * Ex: str.split();
	 * Ex: str.split(' ');
	 * Ex: str.split('a');
	 */
	std::vector<String> split(char ch = '\0') const;

	/*
	 * Strips NL chars from a string
	 * Ex: str.strip_nl();
	 */
	String strip_nl() const { return *this - '\n'; };

	/*
	 * Swaps two strings
	 * Ex: str1.swap(str2);
	 */
	void swap(String&);

	/*
	 * Extracts the selected parts of the string based off of 1 or 2 indexes
	 * Ex: str.substr(1);
	 * Ex: str.substr(1, 5);
	 */
	String substr(int, int right = 0) const;

	/*
	 * Zips two string together like a zipper
	 * Ex: str.zip(str2);
	 */
	String zip(const String&) const;

private:
	char *s;
	int length;
	int capacity;

};

#endif

