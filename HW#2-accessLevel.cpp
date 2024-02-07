#include <iostream>
using namespace std;
//working with strings
#include <string>

//access level class
class AccessLevel
{
    //public class
    public :



//method string
//parameters:
// array for privilege levels for users
// number of users
//min permission required
    string accessL(int right[], int users, int minPermisson)
    {
        string a;

     //for loop each user's privilege level
    for(int x =0; x <users; ++x)
    {

        //determines access
        if(right[x] >= minPermisson)
        {
            //accepted
            a += 'A';

        }

        else
        {
            //denied
            a += 'D';

        }

    }
    // RETURN string
     return a;
    }

};

///--------------------------------------------------------------------
int main()
{
    //instance for access level class
    AccessLevel al;
    //num of users
    int users;
    //min permission variable
    int minPER;
    //string results
    string output;


    //asking the user for total number of users
    cout << "Enter the number of users: " <<endl;
    cin >> users;

    //safety net if users is less than 0 or bigger than 50
    //ITS INVALID AND THEY SHOULD TRY AGAIN
    if(users <0 || users >50)
    {
        cout<<"INVALID INPUT! Try again"<<endl;
        cin >>users;


    }

    //if the number user puts in is 0 then it should quit
    else if (users ==0)
    {

       cout<<"NO USERS. EXIT!"<<endl;
       return 0;

    }

    //array tp store priv... levels for each user
    int right[users];

    //asks for eac users level
    cout <<"Enter the privilege level for each user"<<endl;

    //for loop to make sure we get level for each user entered
    for(int u =0; u <users; ++u)
    {
        cout<<"Privilege level for user" << (u+1)<<":"<<endl;
        cin >>right[u];

    }


    //asks user for minimum permission
    cout<< "Enter minimum permission REQUIRED : " <<endl;
    cin >> minPER;

    //has to be inside the safety net not less than 0 or greater than 100
    while(minPER <0 || minPER >100)
    {
       cout<< "Invalid! try again!"<<endl;
       cin>>minPER;

    }


    //calling method to determine users access
    output = al.accessL(right,users,minPER);

    //display output
    cout<< "Access level for users are: " << output<< endl;


    return 0;
}
