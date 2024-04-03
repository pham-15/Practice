#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdio>

using namespace std;

// Comment

int main()
{
    char choice;
    string use, username, password, confirmation_password, confirmation = "no", line;
    ofstream outfile;
    ifstream infile;

    cout << "1. Add new account and password\n";
    cout << "2. Find existing password\n";
    cout << "3. Delete existing password\n";
    cout << "4. Edit existing password\n";
    cout << "5. Quit\n";
    cin >> choice;
    cin.ignore();

    switch(choice)
    {
        case '1':{
            while (confirmation != "yes"){
                cout << "You have chose to add a new account and password\n";
                cout << "What is the password for? ";
                getline(cin, use);
                cout << "What is the username? ";
                cin >> username;

                while (true){
                    cout << "What is the password? ";
                    cin >> password;

                    cout << "Please enter your password again to confirm: ";
                    cin >> confirmation_password;

                    if (password == confirmation_password){
                    cout << "\nYou have successfully confirmed your password\n";
                    break;
                    }
                
                }
            
                cout << "\nPlease confirm that the following is correct\n";
                cout << "\nUse: " << use << endl;
                cout << "\nUsername: " << username << endl;
                cout << "\nPassword: " << password << endl;
                cout << "\nIf the information is correct enter 'yes', if not, 'no': ";
                cin >> confirmation;
                cin.ignore();
            }

            infile.open("Passwords.txt");
            outfile.open("Temp.txt");

            while (getline(infile, line)){
                outfile << line << endl;;
            }
            outfile << "\n" << left << setw(30) << use << setw(30) << username << setw(30) << password << endl;

            outfile.close();
            infile.close();

            outfile.open("Passwords.txt");
            infile.open("Temp.txt");

            while (getline(infile, line)){
                outfile << line << endl;
            }
            outfile.close();
            infile.close();

            remove("temp.txt");
             
            break;
        }

        case '2':{
            string search, line;
            int offset;

            infile.open("Passwords.txt");

            cout << "What Website/App do you want the password for? ";
            getline(cin, search);

            if (infile.is_open()){
                while (!infile.eof()){
                    getline(infile, line);
                    if ((offset = line.find(search, 0)) != string::npos){
                        cout << "The password has been found " << endl << line << endl;
                    }
                }

                infile.close();
            }

            else{
                cout << "File opening error" << endl;
            }

            break;
        }

        case '3':{
            string search;
            int offset;

            infile.open("Passwords.txt");
            outfile.open("Temp.txt");

            cout << "What Website/App do you want to delete? ";
            getline(cin, search);

            if (infile.is_open()){
                while (!infile.eof()){
                    getline(infile, line);
                    if ((offset = line.find(search, 0)) == string::npos){
                            outfile << line << endl;
                    }
                }

                infile.close();
            }

            else{
                cout << "File opening error" << endl;
            }
   

            infile.close();
            outfile.close();

            outfile.open("Passwords.txt");
            infile.open("Temp.txt");

            while (getline(infile, line)){
                outfile << line << endl;
            }
            outfile.close();
            infile.close();

            remove("temp.txt");
             
            break;
        }

        case '4':{
            int offset;
            string choice;

           infile.open("Passwords.txt");
           outfile.open("Temp.txt");

            cout << "What Website/App do you want to edit? ";
            getline(cin, use);

            if (infile.is_open()){
                while (!infile.eof()){
                    getline(infile, line);
                    if ((offset = line.find(use, 0)) != string::npos){
                        cout << "Is this what you would like to edit? Enter 'y' for yes and 'n' for no: " << endl << line << endl;
                        cin >> choice;

                        if (choice != "n"){
                            cout << "What username would you like? ";
                            cin >> username;

                            while (true){
                                cout << "What is the password? ";
                                cin >> password;

                                cout << "Please enter your password again to confirm: ";
                                cin >> confirmation_password;

                                if (password == confirmation_password)
                                {
                                cout << "\nYou have successfully confirmed your password\n";
                                break;
                                }
                            }

                            while (!infile.eof()){
                                getline(infile, line);
                                if ((offset = line.find(use, 0)) == string::npos){
                                    outfile << line << endl;
                                }
                            }
                            outfile << "\n" << left << setw(30) << use << setw(30) << username << setw(30) << password << endl;
                        }
                    }
                    else{
                        cout << "The Website/App cannot be found\n";
                    }
                }

                infile.close();
                outfile.close();
            }

            else{
                cout << "File opening error" << endl;
            }

            infile.open("Temp.txt");
            outfile.open("Passwords.txt");

            while (getline(infile, line)){
                outfile << line << endl;
            }
            outfile.close();
            infile.close();
             
            break;

        }

        case '5': {
            cout << "You have chose to quit\n";
            break;
        }
        
        default: cout << "That was not an option\n";
    
    }

    

    return 0;

}