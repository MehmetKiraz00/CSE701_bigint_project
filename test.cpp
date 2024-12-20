/**
 * @file test.cpp
 * @author Mehmet Kiraz (kirazm@mcmaster.ca) 400553551
 * @brief Course Project for CSE 701 
 *        BigInt Class 
 * @version 1.0
 * @date 2024-12-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>
#include "bigint.hpp"
using namespace std;

/**
 * @brief Tests a pair of numbers for all operations
 * 
 * @param var1 
 * @param var2 
 */
void operationExe(bigInt var1, bigInt var2)
{
    bigInt finalResult1;
    bigInt finalResult2;
    bool finalBool1;
    bool finalBool2;
    cout << "\n------------Start--------------\n";
    cout << "---------Operator:(<<)---------\n";
    try
    {

        cout << "Var1 value : " << var1 << "\n";
        cout << "Var2 value : " << var2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(+ )---------\n";
    try
    {
        finalResult1 = var1 + var2;
        finalResult2 = var2 + var1;
        cout << "Sum of " << var1 << " and " << var2 << " ==> " << finalResult1 << "\n";
        cout << "Sum of " << var2 << " and " << var1 << " ==> " << finalResult2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(+=)---------\n";
    try
    {
        cout << "Sum and assign of " << var1 << " and " << var2 << " ==> ";
        var1 += var2;
        cout << var1 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(- )---------\n";
    try
    {
        finalResult1 = var1 - var2;
        finalResult2 = var2 - var1;
        cout << "Substraction of " << var1 << " and " << var2 << " ==> " << finalResult1 << "\n";
        cout << "Substraction of " << var2 << " and " << var1 << " ==> " << finalResult2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(-=)---------\n";
    try
    {
        cout << "Subtraction and assign of " << var1 << " and " << var2 << " ==> ";
        var1 -= var2;
        cout << var1 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(* )---------\n";
    try
    {
        finalResult1 = var1 * var2;
        finalResult2 = var2 * var1;
        cout << "Multiplication of " << var1 << " and " << var2 << " ==> " << finalResult1 << "\n";        
        cout << "Multiplication of " << var2 << " and " << var1 << " ==> " << finalResult2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(*=)---------\n";
    try
    {
        cout << "Multiplication and assign of " << var1 << " and " << var2 << " ==> ";
        var1 *= var2;
        cout << var1 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(> )---------\n";
    try
    {
        finalBool1 = var1 > var2;
        finalBool2 = var2 > var1;
        cout << "Check " << var1 << " greater than  " << var2 << " ==> " << finalBool1 << "\n";
        cout << "Check " << var2 << " greater than  " << var1 << " ==> " << finalBool2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(< )---------\n";
    try
    {
        finalBool1 = var1 < var2;
        finalBool2 = var2 < var1;
        cout << "Check " << var1 << " smaller than  " << var2 << " ==> " << finalBool1 << "\n";
        cout << "Check " << var2 << " smaller than  " << var1 << " ==> " << finalBool2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(>=)---------\n";
    try
    {
        finalBool1 = var1 >= var2;
        finalBool2 = var2 >= var1;
        cout << "Check " << var1 << " greater than equal  " << var2 << " ==> " << finalBool1 << "\n";
        cout << "Check " << var2 << " greater than equal  " << var1 << " ==> " << finalBool2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(<=)---------\n";
    try
    {
        finalBool1 = var1 <= var2;
        finalBool2 = var2 <= var1;
        cout << "Check " << var1 << " smaller than equal  " << var2 << " ==> " << finalBool1 << "\n";
        cout << "Check " << var2 << " smaller than equal  " << var1 << " ==> " << finalBool2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(==)---------\n";
    try
    {
        finalBool1 = var1 == var2;
        finalBool2 = var2 == var1;
        cout << "Check " << var1 << " equal  to  " << var2 << " ==> " << finalBool1 << "\n";
        cout << "Check " << var2 << " equal  to " << var1 << " ==> " << finalBool2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(==)---------\n";
    try
    {
        finalBool1 = var1 != var2;
        finalBool2 = var2 != var1;
        cout << "Check " << var1 << " not equal  to  " << var2 << " ==> " << finalBool1 << "\n";
        cout << "Check " << var2 << " not equal  to " << var1 << " ==> " << finalBool2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "---------Operator:(-unary)---------\n";
    try
    {
        finalResult1 = -var1;
        finalResult2 = -var2;
        cout << " Unary of " << var1 << " is  : " << finalResult1 << "\n";
        cout << " Unary of " << var2 << " is  : " << finalResult2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "--------------End--------------\n";
}

/**
 * @brief main function that has a vector of test cases to go through
 * 
 * @return int 
 */
int main()
{
    vector<string> inputs = {
    "-00000000000000000000000000000000000003567",
    "1",
    "5643987458",
    "-9328402873",
    "jjshafgskoewdssmnfdiweo",
    "324-03294",
    "34530958943859034",
    "123456789012345678901234567890123456789012345678901234567890123456",
    "-123456789012345678901234567890123456789012345678901234567890123456",
    "-std::string",
    "lkEVDTyer3+T&(%2'^+)",
    "987654321098765432109876543210987654321098765432109876543210987654",
    "31",
    "-121",
    "0",
    "5",
    "-46",
    "-94"
    };

    bigInt bigint1;
    bigInt bigint2;
    int count = 0;
    for (const auto &line : inputs)
    {
        try
        {
            bigInt temp(line);
            if (count == 0)
                bigint1 = temp;
            else
                bigint2 = temp;
            count++;
            if (count >= 2)
            {
                count = 0;
                try
                {
                    operationExe(bigint1, bigint2);
                }
                catch (const exception &err)
                {
                    std::cerr << "Error during operation execution: " << err.what() << "\n";
                }
            }
        }
        catch (const exception &err)
        {
            std::cerr << "Invalid input \"" << line << "\": " << err.what() << "\n";
        }
    }
    return 0;
}

