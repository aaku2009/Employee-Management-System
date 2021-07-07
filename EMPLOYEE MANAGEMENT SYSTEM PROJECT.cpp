#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//#include<cstdio>
//#include<unistd.h>
using namespace std;

class employee{
    private:
        					// Variables required for employee details
        char name[15];		//name of employee
        char id[5];			//id of employee
        char designation[10];//destination of employee
        int age;			//age of employee
        int ctc;			//ctc of employee
        int experience;		//experience of employee

        // waiting functions for pressing enter button
        void waitForEnter(){
            cout<<"\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }
 
       
        void listEmployees(){ //list out the total employees with Name, Id and Designation
            system("cls");	//clearing the screen
            FILE *file;		//initializing file pointer
            file= fopen("data.txt", "r");	//opening data.txt file
            cout<<"\n\t      List of Employees	\n";
            cout<<"\n----------------------------------------------";
            cout<<"\n ID        |*|   NAME       |*|  DESIGNATION\n";
            cout<<"----------------------------------------------";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF)
                cout<<"\n "<<id<<"\t\t"<<name<<"\t\t  "<<designation;
            fclose(file);
            waitForEnter();
        }

        void showDetails(){ //Displays all details according to Employee's id
            system("cls");		//clearing screen
            FILE *file;			//initialize file pointer
            char checkId[5];	//new variable for id verification
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;		
            file= fopen("data.txt", "r");//opening of file 
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                if(strcmp(checkId,id)==0){			 	//if entered id and stored data id same then move forward
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<name;				//displaying employee details
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age;
                    cout<<"\n---------------------";
                    cout<<"\nCTC: "<<ctc;
                    cout<<"\n---------------------";
                    cout<<"\nExperience: "<<experience;
                    cout<<"\n---------------------";
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(){	 	//edits Designation and CTC of an employee
            system("cls");				//screen clear
            char checkId[5];			
            cout<<"\nEnter employee id: ";
            cin>>checkId;				//enter id of editing person
            char newDesignation[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;		//new designation
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;				//new ctc
            FILE *file, *tempfile;		//initializng file and tempfile pointer files variables.
            file= fopen("data.txt", "r");//opening the data file  for reading purpose
            tempfile= fopen("temp.txt", "w");//creating new temp.txt file 
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, experience );//coping data from data.txt to temp.txt with updated designation and ctc.
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");		//removing data.txt
            int isRenamed= rename("temp.txt", "data.txt");//renaming temp.txt into data.txt
            waitForEnter();
        }

        void addNewEmployee(){ 				//creating new employee records
            system("cls");						//screen clearing
            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of Employee: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee ID [max 4 digits]: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Designation: ";
            cin>>designation;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nEnter 'y' to save above information\n";	//for confirmation press y.
            cin>>ch;
            if(ch=='y'){
                FILE  *file;				//initialising file pointer
                file= fopen("data.txt","a");//appending the data.txt, Data is added to the end of the file. If the file does not exist, it will be created
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );//printing data in to data.txt file
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();//go back to creating employee screen
            waitForEnter();
        }

        void deleteEmployeeDetails(){ 		//deleting the records
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;			//id for a person whose details will be deleting.
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;					//confirmation for deleting
            if(ch=='y'){
                FILE *file, *tempfile;		//initializing file and tempfile pointer files
                file= fopen("data.txt", "r");//opening of data.txt file
                tempfile= fopen("temp.txt", "w");//creating temp.txt file
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)	//not valid comparision then copy the data file into temp file
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);		//closing file
                fclose(tempfile);	//closing tempfile
                int isRemoved= remove("data.txt");//removing data.txt file
                int isRenamed= rename("temp.txt", "data.txt");//rename temp.txt as data.txt
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();	//again back to deleteEmployee function
        }


    public:
        				
        void options(){ 			//MENU
       		 int login(); 				//login function declaration
                login();				//calling login screen function
            while(true){
                system("cls");			//clearing screen
                
                		// Options to choose an action
                cout<<"\n\t\t\t###>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<###";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To Add New Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To Modify Existing Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To View Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To View List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                
                int choice;
                cin>>choice;
              			  // Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");	//clearing screen
                        cout<<"\n\n\t\t\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM \n\n\t\t\t\t\t\t THANK YOU VISIT AGAIN...\n\n ";
                        Sleep(10);		//pause the program for 10 seconds
                        return ;
                    case 1:
                        addNewEmployee();		//calling function
                        break;
                    case 2:
                        editExisting();		//calling function
                        break;
                    case 3:
                        showDetails();		//calling function
                        break;
                    case 4:
                        listEmployees();		//calling function
                        break;
                    case 5:
                        deleteEmployeeDetails();		//calling function
                        break;
                    default:
                        cout<<"\n Sorry! I don't understand that!could you please repeat it again...\n";
                        break;
                }

            }
        }

};

int main(){
    					// Call the options function first for choosing required choices
    employee emp;		//creating object with the help of class
    emp.options();		//calling options() functions with object name
    return 0;
}

int login(){ 			//login procedure
   string pass ="";		//string variable
   char ch;				//char variable
   cout <<"\n\n\n\n\t\t\t\t\t>>>>>>>>EMPLOYEE MANAGEMENT SYSTEM<<<<<<<<<";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   	
	   	//_getch() function wait's for an input from the keyboard but doesn't show the key to the console.
   ch =_getch();			//entering the passoward,Reads a keystoke and saves it to the ch, but doesn't display it in the console.
   while(ch != 13){			//character 13 is ASCII value of enter
      pass.push_back(ch);	//passing the passoward into string
      cout << '*';			// Since nothing has been displayed from the keystroke we display an asterisk ( '*' ) for every key.
      ch =_getch();			//Reads a keystoke and saves it to the ch, but doesn't display it in the console.
   }
   
   if(pass == "1BY18EC012"){	//password 
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Change 'a' to how many * we want
	{
		Sleep(500);			//pause the program for 500 seconds
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";
      
      system("PAUSE");		//pause the program with printing the message Press any key to continue
		
      system("CLS");		//clearing screen
   }else{
      cout << "\nAccess Aborted...\n";
      login();				//back to login screen again
   }
}

