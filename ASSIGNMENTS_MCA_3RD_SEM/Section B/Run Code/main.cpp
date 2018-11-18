//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include "q6.cpp"
#include "q7.cpp"
#include "q8.cpp"
#include "q9.cpp"
#include "q10.cpp"
#include "q11.cpp"

using namespace std;

class mainloop{
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : mainloop class for calling function of included files
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines functions which can be accessed publicly such as :-
     1. q6() for calling function of q6.cpp
     2. q7() for calling function of q7.cpp
     3. q8() for calling function of q8.cpp
     4. q9() for calling function of q9.cpp
     5. q10() for calling function of q10.cpp
     6. q11() for calling function of q11.cpp
     7. helper() for calling member functions
     ------------------------------------------------------------------------------------------------
     */
public:
    void q6();
    void q7();
    void q8();
    void q9();
    void q10();
    void q11();
    void helper();
};
void mainloop::q6() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q6.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q6.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    equivalence_tester obj;
    obj.helper();
}
void mainloop::q7() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q7.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q7.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    stock obj;
    obj.helper();
}

void mainloop::q8() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q8.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q8.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    priceGrowth obj;
    obj.helper();
}

void mainloop::q9() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q9.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q9.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    triathlon obj;
    obj.helper();
}

void mainloop::q10() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q10.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q10.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    planningAParty obj;
    obj.helper();
}
void mainloop::q11() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling functions of q11.cpp
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating object of q11.cpp class and calling its main
     ------------------------------------------------------------------------------------------------
     */
    saveDelhiCity obj;
    obj.helper();
}

void mainloop::helper() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling member functions
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling member functions with while loop and switch cases
     ------------------------------------------------------------------------------------------------
     */
    bool done = true;
    while(done) {
        cout << "\n\n\n\t\t---------Sectiob B Menu--------------\n";
        cout << "\n1.Equivalence Tester\n2.Stock Buy-Sell\n3.Buy Licence \n4.Minimum Completion Time for Triathlon"
        << "\n5.Planning a party\n6.Save Delhi City\n8.Exit\n";
        char choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case '1' :    q6();
                break;
            case '2' :    q7();
                break;
            case '3' :    q8();
                break;
            case '4' :    q9();
                break;
            case '5' :    q10();
                break;
            case '6' :    q11();
                break;
            case '7' :    done = false;
                break;
            default:    cout << "\nInvalid Input\n";
        }
    }
}


int main() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating object of this class and calling helper()
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   by calling helper() , the functions of included files are called.
     ------------------------------------------------------------------------------------------------
     */
    mainloop obj;
    obj.helper();
    return 0;
}

