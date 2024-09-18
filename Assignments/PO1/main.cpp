/*****************************************************************************
*
*  Author:           Daniel Granados 
*  Email:            dagranadosnog0204@my.msutexas.edu
*  Label:            PO1
*  Title:            Fraction Class
*  Course:           2143-OOP
*  Semester:         Fall 2024
*
*  Description:
*        This program will create a class called function and will formate the given numbers in a "_ / _" setup.
*        It will read in input from a file and assign the values into the format, it will overload the operators +, -, *, /, ==
*        The methods will have the neccesary code to adjust the fractions utilizing the overloaded operators, with respect 
*        to the mathematical rules of adding, subtracting, multiplying, and dividing fractions. This program will have two special
*        functions that allow us to get the prerequisite information which is the greatest common factor and the least factor to 
*        go ahead and proceed with the calculations, along with a function that will change the result into the simpliest form. 
*
*  Usage:
*        Set the fractions with the operation you want to run in the input file
*        For example, type 3/4 + 1/2 if you want to add those fractions together
*        The result will be printed into the output file after the program is done running 
* 
*  Files:
        data.txt            (input file)
        FractionsOOP2.cpp   ()
        output.txt          (Output file)
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

class Fraction{
private:
    int num;                                      //Initializes the variable num
    int den;                                      //Initializes the variable den

   
public:
    Fraction() {
        num = den = 1;                            //Default Operator when nothing is passed in 
    }
    Fraction(int n, int d) {    
                                 
            den = d;                              //Sets the inputted integer as the denominator
            num = n;                              //Sets the inputted integer as the numerator
                                                  
    }  
    Fraction(string f) {
        num = f[0] - 48;                          //Takes the inputted string's ASCII value and subtracts 48 to get an integer, sets this number as numerator
        den = f[2] - 48;                          //Takes the inputted string's ASCII value and subtracts 48 to get an integer, sets this number as denominator
        Fraction(num, den);                       //Creates an instance of the class with the new integers coverted from the string 
    }

    friend ostream& operator <<(ostream& os, const Fraction& rhs) {
        return os << rhs.num << "/" << rhs.den;
    }


    /*************************************************************************
        Function: operator+
        Purpose: Adds two Fraction objects and returns the result.
        Parameters: - rhs: A reference to the Fraction object to be added.
        Returns: A Fraction object representing the sum of the two fractions.

    *************************************************************************/ 
    Fraction operator+(const Fraction& rhs) {
        int factor = lcf(this->den, rhs.den);      //Calculates the lowest common factor of both denominators 
        int den = factor;                          //sets the factor calculated as the final denominator 
        int multipleA = factor / this->den;        //Calculates the multiple to multiply denumerator-A by 
        int multipleB = factor / rhs.den;          //Calculates the multiple to multiply denumerator-B by 
        int numA = this->num *= multipleA;         //Multiplies numerator-A by the multiple
        int numB = multipleB * rhs.num;            //Multiplies numerator-B by the multiple
        int num = numA + numB;                     //Adds both numerators together 
        simple(num, den);                          //simplifies the fraction after the operation
        return Fraction(num, den);                 //Returns the final fraction
    }

     /***************************************************************************
        Function: operator*
        Purpose: Multiplies two Fraction objects and returns the result.
        Parameters: - rhs: A reference to the Fraction object to be multiplied.
        Returns: A Fraction object representing the product of the two fractions.
    ******************************************************************************/
    Fraction operator*(const Fraction& rhs) {
        int num = this->num * rhs.num;             //Multiplies both numerators together 
        int den = this->den * rhs.den;             //Multiplies both denominators together
        simple(num, den);                          //Simplifies the fraction after the operation
        return Fraction(num, den);                 //Returns the final fraction
        
    }

    /*****************************************************************************
        Function: operator/
        Purpose: Divides the current Fraction object by another Fraction object.
        Parameters: - rhs: A reference to the Fraction object to divide by.
        Returns: A Fraction object representing the result of the divisions
    *****************************************************************************/
    Fraction operator/(const Fraction& rhs) {
        int num = this->num * rhs.den;             //Cross multiply the first numerator by the second denominator
        int den = this->den * rhs.num;             //Cross multiply the first denominator by the second numerator 
        simple(num, den);                          //Simplifies the fraction after the operation
        return Fraction(num, den);                 //Returns the final fraction
    }

    /************************************************************************************
        Function: operator-
        Purpose: Subtracts one Fraction object from another and returns the result.
        Parameters: - rhs: A reference to the Fraction object to be subtracted.
        Returns: A Fraction object representing the difference between the two fractions.
    ************************************************************************************/
    Fraction operator-(const Fraction& rhs) {
        int factor = lcf(this->den, rhs.den);       //Calculates the lowest common factor of both denominators 
        int den = factor;                           //Sets the factor calculated as the final denominator 
        int multipleA = factor / this->den;         //Calculates the multiple to multiply denumerator-A by 
        int multipleB = factor/rhs.den;             //Calculates the multiple to multiply denumerator-B by 
        int numA = this->num*=multipleA;            //Multiplies numerator-A by the multiple 
        int numB = multipleB * rhs.num;             //Multiplies numerator-B by the multiple 
        int num = numA - numB;                      //subctracts the numerators together 
        simple(num, den);                           //Simplifies the fraction after the operation
        return Fraction(num, den);                  //returns the final fraction
    }

    /*****************************************************************************
        Function: operator==
        Purpose: compares two fractions and checks if they are equal
        Parameters: - rhs: A reference to the Fraction object to compare by.
        Returns: true if both fractions are equal otherwise it returns false 
    *****************************************************************************/
    bool operator==(const Fraction& rhs) {

        int num1 = this->num;                       //sets the numerator of the first fraction
        int den1 = this->den;                       //sets the denominator of the first fraction
        int num2 = rhs.num;                         //sets the numerator of the second fraction
        int den2 = rhs.den;                         //sets the denominator of the second fraction
        simple(num1, den1);                         //Reduces the first fraction into its simplest form
        simple(num2, den2);                         //Reduces the second fraction into its simplest form

        return (num1 == num2)&&(den1 == den2);      //Compares if both simplified fractions are equal
    }

    /************************************************************************************
        Function: lcf
        Purpose: finds the least common factor of two given numbers by using the gcd
        Parameters: two integers 
        Returns: the least common factor 
    ************************************************************************************/
    int lcf(int a, int b)                           //I found this function at www.geeksforgeeks.org/cpp-program-for-program-to-find-lcm-of-two-numbers/
    {
        return (a / gcd(a, b)) * b;                 //calculates and Returns the least common factor 
    }

    /************************************************************************************
        Function: print
        Purpose: print the fraction in the correct format to the console 
        Parameters: N/A
        Returns: N/A
    ************************************************************************************/
    void print() {
        cout << num << "/" << den;                  //Prints the numbers in the correct fraction format
    }

    /************************************************************************************
        Function: simple
        Purpose: use the gcd to simplify the numbers into their lowest possible form
        Parameters: the address of two integers 
        Returns: N/A
    ************************************************************************************/
     void simple(int& n, int& d) {
        int divisor = gcd(n, d);                    //Initializes the variable divisor and sets it equal to the gcd of the given numbers 
        n /= divisor;                               //Divides the n integer by the divisor 
        d /= divisor;                               //Divides the d integer by the divisor
    }

     /************************************************************************************
        Function: gcd
        Purpose: find the greatest common factor between two numbers 
        Parameters: two integers 
        Returns: the greatest common factor 
    ************************************************************************************/
    int gcd(int a, int b) {
        while (b != 0) {                            //a Conditional loop that keeps going while b is not 0 
            int temp = b;                           //initializes a temporary integer with the value of b
            b = a % b;                              //Sets b with the modulus of the values in a and b 
            a = temp;                               //Sets a with the value in temp then loops 
        }
        return a;                                   //Returns the last value set in a when the loop ends
    }
};




int main()
{
    ifstream input;                                 //Initializes the input file
    input.open("data.txt");                         //Opens the input file data.txt
    ofstream output;                                //Initializes the output file 
    output.open("output.txt");                      //Opens the output file output.txt

    
    string f1, op, f2;                              //Initializes the variable string f1, op, f2
    while (input >> f1 >> op >> f2) {               //Conditional loop that runs as long as there is a value to set for f1, op, and f2
        Fraction F1(f1);                            //Creates an instance of Fraction named F1 with the string set in f1
        Fraction F2(f2);                            //Creates an instance of Fraction named F2 with the string set in f2

        Fraction result;                            //Creates an instance of Fraction named result with nothing passed in

        if (op == "+") {                            //Compares the string in op with +, if the strings match then 
            result = F1 + F2;                       //Add F1 by F2 then set the product in result
        }
        else if (op == "-") {                       //Compares the string in op with -, if the strings match then
            result = F1 - F2;                       //Subtract F1 by F2 then set the product in result 
        }
        else if (op == "*") {                       //Compares the string in op with *, if the strings match then
            result = F1 * F2;                       //Multiply F1 by F2 then set the product in result 
        }
        else if (op == "/") {                       //Compares the string in op with /, if the strings match then
            result = F1 / F2;                       //Divide F1 by F2 then set the product in result 
        }
        else if (op == "=") {                       //Compares the string in op with =, if the strings match then
            F1 == F2;                               //Compare F1 and F2 to see if they're equal 
        }
        else {                                      //If the strings does not match any of the cases then 
            cout<< "Unknown operator: "<<op<< endl; //Print error code followed the given string in op
            continue;                               //Let the loop proceed
        }

        output<<F1<<" "<<op<<" "<<F2<<" = "<<result << endl; //Print to the output file the Fractions with the operator given and the result

    }


    return 0;
}
