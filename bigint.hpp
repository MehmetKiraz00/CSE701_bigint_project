/**
 * @file bigint.hpp
 * 
 * @author Mehmet Kiraz (kirazm@mcmaster.ca) 400553551
 * @brief Course Project for CSE 701 
 *        BigInt Class 
 * @version 1.0
 * @date 2024-12-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

class bigInt
{
public:
    
    bigInt(const string &); 
    bigInt(const int64_t &);
    bigInt(const bigInt &);
    bigInt(); 

    // comparison operators
    bigInt &operator=(const bigInt &);
    bool operator>(const bigInt &);
    bool operator<(const bigInt &);
    bool operator>=(const bigInt &);
    bool operator<=(const bigInt &);
    friend bool operator==(const bigInt &, const bigInt &);
    friend bool operator!=(const bigInt &, const bigInt &);
    friend ostream &operator<<(ostream &, const bigInt &);

    // arithmetic operators
    bigInt operator+(const bigInt &);
    bigInt &operator+=(const bigInt &);
    bigInt operator-(bigInt);     // subtraction
    bigInt &operator-=(const bigInt &);
    bigInt operator-();           // unary
    bigInt operator*(const bigInt &);
    bigInt &operator*=(const bigInt &);



    // getters and setter
    void numSetter(const string &);
    string numGet() const;
    bool signGet() const;


private:
    string tempNum;
    string makeAddition(string, string);
    string makeSubtraction(string, string);
    string makeZero(string, size_t);
    bool signBool;
};

/**
 * @brief Construct a new big Int::big Int object
 * 
 * @param string 
 */
bigInt::bigInt(const string &string)
{
    numSetter(string);
}

/**
 * @brief Construct a new big Int::big Int object
 *        can take max 64 bit signed int
 * @param number 
 */
bigInt::bigInt(const int64_t &number)
{
    stringstream stringStreamVar;
    string strNum;
    stringStreamVar << number;
    stringStreamVar >> strNum;

    numSetter(strNum);
}

/**
 * @brief Construct a new big Int::big Int object
 *        for copy and assign
 * @param bigint 
 */
bigInt::bigInt(const bigInt &bigint)
{
    tempNum = bigint.tempNum;
    signBool = bigint.signBool;
}

/**
 * @brief Construct a new big Int::big Int object
 * 
 */
bigInt::bigInt()
{
    tempNum = "0";
    signBool = false;
}

/**
 * @brief = operator overload
 *        we look at the reference of 2 vars and 
 *        if they are not the same then we only assign 
 *        numA <-- numB
 * 
 * @param numB LFS operand 
 * @return bigInt& 
 */
bigInt &bigInt::operator=(const bigInt &numB)
{
    if (this == &numB)
        return *this; 

    tempNum = numB.tempNum;  
    signBool = numB.signBool;

    return *this; // Return the updated object
}

/**
 * @brief == operator overload 
 *        we compare the values and signs of two vars
 *        if they have the same value for both than they are the same
 * @param numA 
 * @param numB 
 * @return true 
 * @return false 
 */
bool operator==(const bigInt &numA, const bigInt &numB)
{
    string numStrA = numA.numGet();
    string numStrB = numB.numGet();
    bool signBoolA = numA.signGet();
    bool signBoolB = numB.signGet();

    bool areNumEqual = (numStrA == numStrB);
    bool areSignEqual = (signBoolA == signBoolB);

    return areNumEqual && areSignEqual;
}

/**
 * @brief < operator overload
 *        Compare the signs of two vars and if the RHS has negative sign then RHS is smaller
 *        same goes for vice versa
 *        For the other case we compare the lengths. If one var has lesser amount then its smaller
 *        if both of the signs are negative then we just look at the strings lexicographically
 *          
 *        For lexicographically looking at strings I used c++ string.compare(string) function
 * @param numB 
 * @return true 
 * @return false 
 */
bool bigInt::operator<(const bigInt &numB)
{

    bool signA = signGet();
    bool signB = numB.signGet();

    if (!signA && signB)
        return false;
    else if (signA && !signB)
        return true;
    string numAStr = numGet();
    string numBStr = numB.numGet();
    if (signA == false)
    {
        if (numAStr.length() < numBStr.length())
            return true; 
        else if (numAStr.length() > numBStr.length())
            return false; 
        else
            return numAStr < numBStr;
    }
    else
    {
        if (numAStr.length() > numBStr.length())
            return true; 
        else if (numAStr.length() < numBStr.length())
            return false; 
        else
            return numAStr.compare(numBStr) > 0; 
    }
}

/**
 * @brief <= operator overload
 *        using == and < operators for this overload
 * @param numB 
 * @return true 
 * @return false 
 */
bool bigInt::operator<=(const bigInt &numB)
{
    return (*this < numB) || (*this == numB);
}

/**
 * @brief > operator overload
 *        using == and < operators for this overload
 * @param b The bigInt object to compare with.
 * @return true if *this is greater than b.
 * @return false otherwise.
 */
bool bigInt::operator>(const bigInt &b)
{
    return !((*this < b) || (*this == b));
}

/**
 * @brief >= operator overload
 *        using == and > operator for this overload
 * @param numB 
 * @return true 
 * @return false 
 */
bool bigInt::operator>=(const bigInt &numB)
{
    return (*this > numB) || (*this == numB);
}

/**
 * @brief != operator overload
 *        using == operator for this overload and taking the reverse
 * 
 * @param numA 
 * @param numB 
 * @return true 
 * @return false 
 */
bool operator!=(const bigInt &numA, const bigInt &numB)
{
    return !(numA == numB);
}

/**
 * @brief << operator overload
 *        we first add the sign and then we get the number string
 * @param output 
 * @param numA 
 * @return ostream& 
 */
ostream &operator<<(ostream &output, const bigInt &numA)
{
    if (numA.signGet())
        output << "-" << numA.numGet();
    else
        output << numA.numGet();
    return output;
}

/**
 * @brief we get a string and set it and validate it
 *        handles exceptions when the input is invalid
 * @param string 
 */
void bigInt::numSetter(const string &string)
{
    for (uint64_t i = 0; i < string.size(); i++)
    {
        bool isValid = (i == 0) ? (string[i] == '-' || isdigit(string[i])) : isdigit(string[i]);
        if (!isValid)
            throw invalid_argument("Invalid input");
    }
    if (isdigit(string[0]))
    {
        tempNum = string;
        signBool = false;
    }
    else
    {
        tempNum = string.substr(1);
        signBool = true;
    }
}

/**
 * @brief a getter
 * 
 * @return string 
 */
string bigInt::numGet() const
{
    return tempNum;
}

/**
 * @brief if sign exists then a getter
 * 
 * @return true 
 * @return false 
 */
bool bigInt::signGet() const
{
    return signBool;
}

/**
 * @brief + operator overload
 *        addtion or subtraction is done based on sign
 *        if different sign then addition or subtraction based on length
 *        if same sign then addition
 * @param numB 
 * @return bigInt 
 */
bigInt bigInt::operator+(const bigInt &numB)
{
    bigInt result;
    const bool sameSign = (signGet() == numB.signGet());
    if (sameSign)
    {
        result.numSetter(makeAddition(numGet(), numB.numGet()));
        result.signBool = signGet();
    }
    else
    {
        const bool isLarger = (numGet().length() > numB.numGet().length()) || (numGet().length() == numB.numGet().length() && numGet() > numB.numGet());
        if (isLarger)
        {
            result.numSetter(makeSubtraction(numGet(), numB.numGet()));
            result.signBool = signGet();
        }
        else
        {
            result.numSetter(makeSubtraction(numB.numGet(), numGet()));
            result.signBool = numB.signGet();
        }
    }
    if (result.numGet() == "0")
        result.signBool = false;
    return result;
}

/**
 * @brief += operator overload
 *        using + operator to overload this operator
 * @param numB 
 * @return bigInt& 
 */
bigInt &bigInt::operator+=(const bigInt &numB)
{
    *this = *this + numB;
    return *this;
}

/**
 * @brief unary/negation operator overload
 *        change the sign of the object
 *        if 0 don't do anything
 * @return bigInt 
 */
bigInt bigInt::operator-()
{
    bigInt unary;
    unary.numSetter(numGet()); 
    if (numGet() != "0")
        unary.signBool = !signGet();
    return unary;
}

/**
 * @brief - operator overload
 *        we change the 2nd var sign then use + operator to overload the operator
 * @param numB 
 * @return bigInt 
 */
bigInt bigInt::operator-(bigInt numB)
{
    numB.signBool = !(numB.signGet());
    return (*this) + numB;
}

/**
 * @brief -= operator overload
 *        using - operator to overload this operator
 * @param numB 
 * @return bigInt& 
 */
bigInt &bigInt::operator-=(const bigInt &numB)
{
    *this = *this - numB;
    return *this;
}

/**
 * @brief * operator overload
 *        we use the M*N matrix multiplication index by index
 *        if carry exists then forward to prev bit
 *        if any leading zeros exists then remove before return
 * 
 *        the algorithm for the logic has been sourced online
 *        https://leetcode.com/problems/multiply-strings/solutions/1563507/c-simple-easy-and-short-solution-brief-explanation/
 * @param numB 
 * @return bigInt 
 */
bigInt bigInt::operator*(const bigInt &numB)
{
    bigInt product;
    product.signBool = (signGet() != numB.signGet()); 
    string multiplicand = numGet();
    string multiplier = numB.numGet();

    uint64_t multiplicandLength = multiplicand.size();
    uint64_t multiplierLength = multiplier.size();

    string res(multiplicandLength + multiplierLength, '0');

    // Core multiplication logic (referenced section)
    for (uint64_t i = multiplicandLength; i-- > 0;)
    {
        for (uint64_t j = multiplierLength; j-- > 0;)
        {
            int tSum = (res[1 + i + j] - '0') + 
                       (multiplicand[i] - '0') * (multiplier[j] - '0');
            res[i + j] += tSum / 10;
            res[1 + i + j] = tSum % 10 + '0';
        }
    }
    if (!res.empty() && res[0] == '0')
    {
        res.substr(1); 
        if (res.empty())
            res = "0"; 
    }
    product.tempNum = res;
    return product;
}

/**
 * @brief *= operator overload
 *        using * operator to overload this operator
 * @param numB 
 * @return bigInt& 
 */
bigInt &bigInt::operator*=(const bigInt &numB)
{
    *this = *this * numB;
    return *this;
}

/**
 * @brief this is a helper function to + operator overloading
 *        add values idx by idx and also add 0s to make the length same
 *        the logic has been inspired by here
 *        https://leetcode.com/problems/multiply-strings/solutions/
 * @param tempX 
 * @param tempY 
 * @return string 
 */
string bigInt::makeAddition(string tempX, string tempY)
{
    if (tempX.length() > tempY.length())
        tempY = makeZero(tempY, tempX.length() - tempY.length());
    if (tempX.length() < tempY.length())
        tempX = makeZero(tempX, tempY.length() - tempX.length());

    string res = "";
    uint64_t makeAddition, carry = 0;
    for (uint64_t idx = tempX.length(); idx-- > 0;)
    {
        makeAddition = (uint64_t)tempX[idx] - '0' + (uint64_t)tempY[idx] - '0' + carry;
        if (makeAddition > 9)
        {
            res = to_string(makeAddition % 10) + res;
            carry = makeAddition / 10;
        }
        else
        {
            res = to_string(makeAddition) + res;
            carry = 0;
        }
    }
    if (carry != 0)
        res = to_string(carry) + res;
    return res;
}

/**
 * @brief this is a helper funtion to - operator overloading
 *        essentially same idea of makeAddition but discards the leading zeros
 *        if the result is zero then leaves the last zero
 *        again logic was inspired from here 
 *        https://leetcode.com/problems/multiply-strings/solutions/
 * 
 * @param tempX 
 * @param tempY 
 * @return string 
 */
string bigInt::makeSubtraction(string tempX, string tempY)
{
    string sub = (tempX.length() > tempY.length()) ? tempX : tempY;

    if (tempX.length() > tempY.length())
        tempY = makeZero(tempY, tempX.length() - tempY.length());
    if (tempX.length() < tempY.length())
        tempX = makeZero(tempX, tempY.length() - tempX.length());

    for (uint64_t idx = tempX.length(); idx-- > 0;)
    {
        if (tempX[idx] < tempY[idx])
        {
            tempX[idx] += 10;
            tempX[idx - 1]--;
        }
        sub[idx] = ((tempX[idx] - '0') - (tempY[idx] - '0')) + '0';
    }

    // erase leading zeros
    while (sub[0] == '0' && sub.length() != 1)
        sub.erase(0, 1);

    return sub;
}

/**
 * @brief makes 2 strings equal length by adding zeros
 * 
 * @param string 
 * @param n 
 * @return string 
 */
string bigInt::makeZero(string string, size_t n)
{
    while (n != 0)
    {
        string = "0" + string;
        n--;
    }
    return string;
}