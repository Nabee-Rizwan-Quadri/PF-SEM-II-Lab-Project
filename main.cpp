#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
string choice = "y"; //Used to store user action choice (declared globally because its used in every function)
 
//Declaration of functions in void because no value will be returned to main function
void createReceipt();
void clearReceipt();
void openReceipt();
 
 
int main()
{
	    	int menu;
 
	    	//welcome message
	    	cout << "\n==========================================" << endl;
	    	cout << "|---------Grocery Store Invoice----------|";
	    	cout << "\n==========================================\n" << endl;
 
    	//Menu to call switch cases
	    	cout << "What action you want to perform?\n1-Create Receipt\n2-Open Receipt\n3-Clear Receipt\n4-Exit Program\n\nchoice: ";
	    	cin >> menu;
 
    	//Switch cases to call UDFs
	    	switch(menu)
	    	{
       	 case 1:
               	 	createReceipt();
                    break;
 
       	 case 2:
       	         	openReceipt();
                    break;
 
        	case 3:
                    clearReceipt();
                    break;
 
       	 case 4:
               	 	cout << endl << "Program ended!!" << endl;
                    break;
	    	}
	return 0;
}
 
//Function used to generate a new receipt by creating a new session
void createReceipt()
{
    	//Declaration of all variables used in this UDF
    	string user;
	    	float userinputnumber, receipttotal = 0, customercash = 0, balance = 0, sessiontotalcash = 0, sessiontotalitem = 0 ; // used to store user price input
	    	int  itemnumber = 1, receiptno = 0, itemssold = 0;
 
    	cout << "\nStart a new session? (y/n): ";
    	cin >> choice ;
 
    	cout << "\nEnter username: ";
    	cin >> user;
 
    	//Naming the file through which it will be called
    	ofstream outfile;
    	//Opening file to write by appending method
        outfile.open("File1.txt", ios_base::app);
 
    	cout << "\nNEW SESSION STARTED BY: " << user << endl;
    	outfile << "\nNEW SESSION STARTED BY: " << user << endl;
 
 
	    	//as long user input is not n, run this loop
	    	while(choice != "n")
	    	{
 
       	 if(choice == "y")
       	 {
                receiptno += 1; // Increase receipt number after each loop
                itemnumber = 1; // Reset item number to 1 after new loop has started
                itemssold = 0; // Reset items sold to 0 after new loop has started
                receipttotal =0; // Reset receipt total to 0 after new loop has started
 
                //Decoration
            	cout << "\n==========================================" ;
                outfile << "\n=========================================" ;
 
            	cout << "\n|---------------Receipt: " << receiptno << "---------------|" << endl;
                outfile << "\n|---------------Receipt: " << receiptno << "---------------|" << endl;
 
            	cout << "==========================================\nPress (0) to close\n" << endl;
        	    outfile << "==========================================\n" << endl;
 
            	//take user input, add it to receipt total and continue to do so until user enters 0
            	//Also keeps track of total items sold
            	do
     	       {
                    cout << "Price of item " << itemnumber << ": Rs ";cin >> userinputnumber;
                    outfile << "Price of item " << itemnumber << ": Rs "<< userinputnumber << endl ;
 
                    itemssold += 1;
           	     receipttotal += userinputnumber;
                    sessiontotalcash += userinputnumber;
                    itemnumber++;
            	}
                while(userinputnumber != 0);
 
                itemssold -= 1;
                sessiontotalitem += itemssold;
 
 
 
                //print current receipt total
            	cout << "_________________________________" << endl;
 
            	cout << "Gross total:\t Rs " << receipttotal << endl;
            	cout << "Customer payment:Rs ";
            	cin >> customercash;
                balance = customercash - receipttotal;
            	cout << "Balance:\t Rs " << balance << endl;
 
            	cout << "_________________________________" << endl;
                outfile << "_________________________________" << endl;
 
            	cout << "Total items: " << itemssold  << endl;
                outfile << "Items sold:\t " << itemssold << endl;
 
            	cout << "Receipt total:\t Rs " << receipttotal << endl;
     	       outfile << "Receipt total:\t Rs " <<  receipttotal<<endl;
 
            	cout << "=========================================" << endl;
                outfile << "\=========================================" << endl;
 
            	cout << "|---------Thank you for shopping--------|" << endl;
            	cout << "|-----------Please come again-----------|" << endl;
            	cout << "=========================================" << endl;
 
            	cout << "\n==========================================" << endl;
                outfile << "\n==========================================" << endl;
 
            	cout << "|-----------End of Receipt: " << receiptno << "------------|" << endl;
                outfile << "|-----------End of Receipt: " << receiptno << "------------|" << endl;
 
            	cout << "==========================================\n" << endl;
                outfile << "==========================================\n" << endl;
 
            	cout << "Open new receipt? (y/n): ";
            	cin >> choice;
       	 }
 
       	 //if user choice wasn't neither y or n display invalid input message and tell user to repeat the input
       	 else if(choice != "n")
       	 {
            	cout << "\nInvalid input, try again!" << endl;
            	cout << "Open new receipt? (y/n): ";
            	cin >> choice;
            	cout << endl;
       	 }
	    	}
	    	cout << "\nTotal items sold in session: " << sessiontotalitem << endl;
	    	outfile << "\nTotal items sold in session: " << sessiontotalitem << endl;
 
    	cout << "Total cash accumulated in session: " << sessiontotalcash << endl;
    	outfile << "Total cash accumulated in session: " << sessiontotalcash << endl;
 
  	  cout << "\nEND OF SESSION BY: " << user << endl;
    	outfile << "\nEND OF SESSION BY: " << user << endl;
 
        outfile.close();
 
 
 
 
	    	cout << endl;
 
}
 
//Function to open text file and view its saved content
void openReceipt()
{
	while(choice != "n")
	{
    	if(choice == "y")
    	{
        	string line;
 
        	cout << "\nOpen text file of receipt? (y/n): ";
        	cin >> choice;
 
        	cout << "\nOpening file..." << endl;
        	cout << "\nSTART OF FILE \n" << endl;
 
        	ifstream file ("File1.txt");
 
        	if (file.is_open())
        	{
            	while ( file.good() )
 
            	{
                    getline (file,line);
                    cout << line << endl;
            	}
 
            file.close();
 
        	cout << "END OF FILE \n";
        	break;
        	}
 
        	else
        	cout << "Unable to open file";
 
    	}
    	else if(choice != "n")
    	{
        	cout << "\nInvalid input, try again!" << endl;
        	cout << "Open text file of receipt? (y/n): ";
        	cin >> choice;
    	}
	}
}
 
//Function used to truncate the text file
void clearReceipt()
{
	cout << "\nAre you sure you want to clear all data stored in receipt file (y/n): ";
	cin >> choice;
 
	while(choice != "n")
	{
    	if(choice == "y")
    	{
        	cout << "\ntruncating file...\n" << endl;
 
        	ofstream outfile;
            outfile.open("File1.txt", ofstream::out | ofstream::trunc);
            outfile.close();
 
        	cout << "The file has been successfully truncated" << endl;
 
        	break;
    	}
 
    	else if(choice != "n")
    	{
        	cout << "\nInvalid input, try again!" << endl;
        	cout << "\nAre you sure you want to clear all data stored in receipt file (y/n): ";
        	cin >> choice;
    	}
	}
}