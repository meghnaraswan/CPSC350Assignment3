

#include <stdio.h>
#include "SyntaxCheckerStack.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void SyntaxCheck(string fileName) {
    typedef GenStack<char> myStack; //creating stack object with char in place of the generic typ from the template
    myStack ms(10);
    ifstream ifs (fileName); //constructs ifstream object and opens user input file
    if (ifs.is_open()) { //shows if the stream is associated with the file
        int lineCount = 1; //initialize the line count to 0
        int colCount = 0; //initialize the line count to 0
        char c = ifs.get(); //extracts character from the stream
        colCount++; //increments column on line
        while (ifs.good()) { //checks the state of the stream (so checks to see if the stream is good)
            char pop_ch = '\0'; //initialize the popped character as empty
            switch(c){
                case '(':
                case '{':
                case '[':
                    ms.push(c); //if the character from the file is (, {, or [, these values will be pushed to the stack
                    break;
                case '\n':
                    ++lineCount; //if the character is a new line, line count is incremented
                    colCount = 0; //column will be reassigned as 0 as we read the new line
                    break;
                case ')': //if charcter is )
                    pop_ch = ms.pop();
                    if(pop_ch == '{') { //if the top of the stack is {, ) does not correspond with { so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount << ": expected } and found )"<< endl;
                    }
                    else if (pop_ch == '[') { //if the top of the stack is [, ) does not correspond with [ so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": expected ] and found )"<< endl;
                    } else if (pop_ch == '\0') { //if stack is empty, ( must be missing so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": found ), matching ( is missing"<< endl;
                    }
                    break;
                case '}': //if charcter is }
                    pop_ch = ms.pop();
                    if(pop_ch == '(') { //if the top of the stack is (, } does not correspond with ( so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": expected ) and found }"<< endl;
                    } else if (pop_ch == '[') { //if the top of the stack is [, } does not correspond with [ so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": expected ] and found }"<< endl;
                    } else if (pop_ch == '\0') { //if stack is empty, { must be missing so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": found }, matching { is missing"<< endl;
                    }
                    break;
                case ']': //if charcter is ]
                    pop_ch = ms.pop();
                    if(pop_ch == '{') { //if the top of the stack is {, ] does not correspond with { so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": expected } and found ]"<< endl;
                    } else if (pop_ch == '(') { //if the top of the stack is (, ] does not correspond with ( so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": expected ) and found ]"<< endl;
                    } else if (pop_ch == '\0') { //if stack is empty, [ must be missing so error occurs
                        cout << "Line count is " << lineCount << ", column is " << colCount<< ": found ], matching [ is missing"<< endl;
                    }
                    break;
                default:
                    break;
            } //end of switch statement
            c = ifs.get(); //extracts character from the stream
            colCount++; //increments column on line
        } //end of while loop
        for(int i = ms.getSize() - 1; i >= 0; i--){ //if stack is still not empty (meaning no close brackets or parentheses have been found)
            char pop_ch = ms.pop();
            if(pop_ch == '('){ //if ( is at the top of the stack, ) is missing
                cout << "Reached end of file: missing )" << endl;
            } else if (pop_ch == '{'){ //if { is at the top of the stack, } is missing
                cout << "Reached end of file: missing }" << endl;
            } else if (pop_ch == '['){ //if [ is at the top of the stack, ] is missing
                cout << "Reached end of file: missing ]" << endl;
            }
        }
        cout << lineCount << " lines processed." << endl;
        ifs.close(); //closes file
    } else { //if file can't open, there will be an error message
        std::cout << "Error opening file";
    }
}


int main (int argc, char **argv) {
    string userFileName; //user file name variable
    if (argc < 2) { //if the arguments on the command line are less than 2 (meaning the user did not add the file name), then return an error
        cout << "You did not add a file name";
        return 0; //exit
    } else { //else, userFileName is the commandline user input
        userFileName = argv[1];
    }
    SyntaxCheck(userFileName); //call SyntaxCheck() function
    cout << "That's All!!!" << endl; //notify user that program that Syntax Checker is finished running
    return 0;
}
