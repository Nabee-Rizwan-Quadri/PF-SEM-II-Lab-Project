# Shop Receipt Generation sofware
# PF-SEM-II-Lab-Project
Contains the lab project of Programing Fundamentals in C++

1.Introduction
This is a software that is used for the generation of receipt at the time of purchase with items sold and cash received as well as generation of invoice of total items sold and total cash received of all the receipt in the same session.

1.1Purpose 
This is a software that is used for the generation of receipt at the time of purchase with items sold and cash received as well as generation of invoice of total items sold and total cash received of all the receipt in the same session.

1.2Project Scope
This software can be implemented anywhere from small grocery stores to giant shopping malls. Especially those places which require receipts both at the time of purchase and at the end of each session. It can be used as a digital book which holds the records total cash collected.

1.3Product Features
This product has the following features:
1.Can save cash received as well as items sold in each transaction and generate its receipt in a single session.
2.Can tell total cash received as well as total items sold up till that receipt in a single session.
3.Can record multiple transactions.
4.Can store multiple transactions in a single file in ascending order.
5.Can view stored file stored file.
6.Can tunicate a file.



2.System Features
This software offers a vast variety of options to choose from. It can generate a new receipt, taking input from the user for the price of the items indefinitely according to the requirements of the user. Simultaneously while taking input from the user it saves the inputs as well as the outputs in a text file i.e. the items sold and cash received in the current receipt and also the summed total items sold and cash received of all the receipts in the session. The saved text file can be viewed in the program. It contains the data of all the previous sessions.The saved text file can also be erased, using the program, to delete the data of all previous sessions.
2.1	Description and Priority
●Creating a new receipt

This feature has top priority as the other two features are dependent on it. It is used to generate a receipt and save its content in a text file for later use.

●Viewing previously saved receipt

This feature has medium priority. It is used to open and view the file previously saved by the user.

●Erasing all receipts

This feature has low priority as it will not be used that often. It is used to clear the data stored in the text file by the user.
Note: Once the data has been erased it cannot be retrieved again.
2.2	Functional Requirements
Certain conditions need to be met for the program to be run as intended. They are mentioned below:

1.The minimum system requirements to run a C++ IDE must be met in order to open this program otherwise the program will not run.
2.The program needs to be opened in a C++ viewer. Otherwise the program will not run.
3.The user inputs should match the options present in the program. An error of invalid input will be shown otherwise.
4.The user may not input any other value except for an integer value or a decimal point value when prompted to enter the price of an item. An error of invalid input will be shown otherwise.
5.The user may not enter a letter when prompted to enter the price of an item. An error of invalid input will be shown otherwise.
6.The user may not enter any values other than y or n when prompted for a yes or no answer. An error of invalid input will be shown otherwise.

3.C++ Functions used
 Following are the C++ functions used in this program
●Library of iostream and fstream
●Global data declaration
●Data types used are Integer, Float and string
