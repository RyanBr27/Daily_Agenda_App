//
//  main.cpp
//  Daily Agenda App
//
//  Created by Ryan Breeden on 8/15/22.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstdlib> //for file exit function

using namespace std;

void add_record();
void delete_record();
void view_agenda();


int main()
{
    int option;
    char x;
    
    bool go = true;
    while (go)
    {
    //displays all the available menu options.
           cout << "\nAvailable operations: \n\n1. Add\n2. Delete\n3. View Agenda Items\n\nEnter option: ";
           cin >> option;
        switch (option)
        {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                view_agenda();
                break;
            default:
                break;
        }
        cout << "If you continue to use program press 'y': ";
        cin >> x;
        
        if(x != 'y' )
        {
        go = false;
        }
    }
    return 0;
}


void add_record()
{
    int n = 0, count_n = 0;
    char data[100];
    string empty = "00";

    //name of the file where user information is stored.
       ifstream f("database.txt");
       string line;
       
    // the following for loop counts the total number of lines in the file.
    for (int i = 0; std::getline(f, line); ++i)
    {
        count_n++;
    }
    
    cout << "How many agenda items will you be logging in today: ";
    cin >> n;
                
    count_n = count_n + n;
    
    for (int i = 0; i < n; i++)
    {
        ofstream outfile;
        outfile.open("database.txt");
        
        //the entire data of a single agenda item is stored line-by-line.
        cout << "Create agenda ID number: ";
        cin >> data;
        outfile << data << "\t";

        cout << "Enter a description: ";
        cin >> data;
        outfile << data << "\t";
        
        outfile.close();
    }
}


void delete_record()
{
      fstream main;
      fstream temp;
      
      main.open("database.txt");
      temp.open("temp.txt");
      
      char id [100];
      char description [100];
      char a[100];
      cin.ignore();
      cout<<" \n\t Enter the ID number to delete record: ";
      cin.getline(a,100);
      while(!main.eof())
          {
              main.getline(id,100,'|');
              main.getline(description,100,'|');
              if(strcmp(id,a) == 0)
              {
                  continue;
              }
              else
              {
                  temp << id <<'|'<< description <<'\n';
              }
          }

          main.close();
          temp.close();

          main.open("database.txt");
          temp.open("temp.txt");
          while(!temp.eof())
          {
              temp.getline(id,100,'|');
              temp.getline(description,100,'|');
              main << id <<'|'<< description <<'\n';
          }
          main.close();
          temp.close();
          remove("temp.txt");
          cout<<"\n done !!! \n";
}


void view_agenda()
{
    cout << "Here is your agenda for today: " << "\n";
    
    ifstream infile;
    string input;
    infile.open("database.txt");
    
        if(!infile)
        { //file couldn't be opened
              cerr << "Error: file could not be opened" << endl;
              exit(1);
        }
    infile >> input;
       while (!infile.eof())
       { //keep reading until end-of-file (eof)
          cout << input << endl;
          infile >> input; //sets EOF flag if no value found
       }
       infile.close();
       cout << "End-of-file reached.." << endl;
}






