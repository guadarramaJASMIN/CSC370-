#include <iostream>
//allowing strings
#include <sstream>
#include <iomanip>
using namespace std;




//Run Length encode class
    class RunLengthEncode

   {

    static string RUN(int number, char c);

    static bool isCHAR(char ch);

    static bool special(char z);

    public:
    static string en(const string& x);


};


//----------------------------------------------------------



    //encode used to format
    string RUN(int number, char c)

    {
//if it's repeated more than four times we format it
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "/%02d%c", number, c);
        return buffer;

    }

 //----------------------------------------------------------

//for special characters

     bool special(char ch)
     {
        string spec = "+=,.{}[]:;'""";

        int i = spec.find(ch);

        return i >= 0 && i < spec.length();


    }


//--------------------------------------------

//checks to see if it's a valid input
//making sure its a valid input
bool isCHAR(char ch)
{
    return
    //'a' and 'z'
    //'A' AND 'Z'
    //0-9
    //space
    //special character

            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9') ||
            ch == ' ' || special(ch);


}

//----------------------------------------------
//takes input and returns encoded output string
     string en(const string& x)
     {
        //for output
        string out;
        //number of char/count
        int q = 1;

        //loops over every character and compares them
        for (int v = 1; v < x.length(); ++v)
        {

    //makes sure it's a valid input and if's the same char as the previously looked character
            if (isCHAR(x[v]) && x[v] == x[v - 1])
            {

                q += 1;

            }

            else
            {
                //resets the q to one and basically saying previous char wasn't the same one and
                //run is over
                out += (q <= 4) ? string(q, x[v - 1]) : RUN(q, x[v - 1]);
                q = 1;


            }


        }

        //last safety net
         //gives results if its repeated whether #>4 or #<4
        if (isCHAR(x.back()))
        {

            out += (q <= 4) ? string(q, x.back()) : RUN(q, x.back());

        }

        //either way returns output
        return out;

    }


///MAIN-----------------------------------------------------
int main()
{

    //asking user to enter input
    cout<< "Enter a string: "<< endl;

    //variable; string input
    string input;

    //getting the line from the user and reading it
    getline(cin, input);

    //can't be a character bigger than 50
    if(input.length()>50)
    {
        //print the error
        cout<< "ERROR, TOO BIG!" <<endl;
        return 1;

    }

    else
    {
        //give the encoded string
        string encode = en(input);
        //print it
        cout<< "Encoded output: " << encode<< endl;
    }


    return 0;

}

//------------------------------------------------