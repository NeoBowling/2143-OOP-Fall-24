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
*        how to use the program if necessary
*
*  Files: data.txt          (list of all source files used in this program)
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

class Fraction{
private:
    int num;
    int den;

   
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
        Fraction(num, den);                       //Creates an instance of the class with the string coverted into integers 
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
            
            int num1 = this->num;                   //sets the numerator of the first fraction
            int den1 = this->den;                   //sets the denominator of the first fraction
            int num2 = rhs.num;                     //sets the numerator of the second fraction
            int den2 = rhs.den;                     //sets the denominator of the second fraction
            simple(num1, den1);                     //Reduces the first fraction into its simplest form
            simple(num2, den2);                     //Reduces the second fraction into its simplest form

            return (num1 == num2) && (den1 == den2);
    }

    int lcf(int a, int b)                           //I found this function at www.geeksforgeeks.org/cpp-program-for-program-to-find-lcm-of-two-numbers/
    {
        return (a / gcd(a, b)) * b;
    }
    void print() {
        cout << num << "/" << den;
    }

     void simple(int& n, int& d) {
        int divisor = gcd(n, d);
        n /= divisor;
        d /= divisor;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};




int main()
{
    ifstream input;
    input.open("data.txt");
    ofstream output;
    output.open("after.txt");

    
    string f1, op, f2;
    while (input >> f1 >> op >> f2) {
        Fraction F1(f1);
        Fraction F2(f2);

        Fraction result;

        if (op == "+") {
            result = F1 + F2;
        }
        else if (op == "-") {
            result = F1 - F2;
        }
        else if (op == "*") {
            result = F1 * F2;
        }
        else if (op == "/") {
            result = F1 / F2;
        }
        else if (op == "=") {
            F1 == F2;
        }
        else {
            cout << "Unknown operator: " << op << endl;
            continue;
        }

        cout << F1 << " " << op << " " << F2 << " = " << result << endl;

    }


    return 0;
}


