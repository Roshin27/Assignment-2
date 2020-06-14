#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
string n_name;

int userRegistration()
{
    cout<<"\n Enter your name:";
    cin>>n_name;
    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}

int existingBooking()
{
    system("cls");
    cout<<"\n\tBooking Summary\n";
    cout<<"\t----------------------\n";
    //check if record already exist..
    ifstream read;
    read.open("booking.dat");

    int hoursbook = 8;

    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
     int recordFound =0;

    if(read)
    {
	string line;
	char key = 'A';
	int i = 9;

	   while(getline(read, line)) {
	   	   char temp = line[0];
	   	   int index = (temp - 65);
	   	   arr[index]=1;
		   recordFound = 1;
	  }
        if(recordFound == 1)
        {
        cout<<"\n Booking Summary by hours:";
        char key = 'A';
        int hours = 9;
        for(int i = 0; i<=12; i++)
        {
        	if(arr[i] == 0)
        	cout<<"\n "<<key<<" "<<hours<<" - Available";
        	else
        	cout<<"\n "<<key<<" "<<hours<<" - Booked";
        	hours++; key++;
        }

	}

	read.close();
    }
    else
    {
    char key = 'A';
	for(int i = 9; i<=21; i++)
	{
	if(i==9)
	cout<<"\n "<<key<<"  0"<<i<<" - Available";
	else
	cout<<"\n "<<key<<"  "<<i<<" - Available";
	key++;
	}
    }

    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}

int bookSlot()
{
    system("cls");

    cout<<"\n ----- Book Your Slot ---- \n";

    cout<<"\n ----- Availbale slots ---- \n";

    //check if record already exist..
    ifstream read;
    read.open("booking.dat");

    int hoursbook = 8;

    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0;

    if(read)
    {
	string line;
	char key = 'A';
	int i = 9;

	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"\n----Booking Summary----";
	char key = 'A';
	int hours = 9;
	for(int i = 0; i<=12; i++)
	{
	if(i == 0){
	if(arr[i] == 0)
	cout<<"\n "<<key<<" 0"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<" 0"<<hours<<" - Booked";
	}

	else
	{
	if(arr[i] == 0)
	cout<<"\n "<<key<<" "<<hours<<" - Available";
	else
	cout<<"\n "<<key<<" "<<hours<<" - Booked";
	}
	hours++; key++;
	}

	}

	read.close();
    }
	if(recordFound == 0){
	cout<<"\n Booking Available for following hours :";
	char key = 'A';
	for(int i = 9; i<=21; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<"  0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<"  "<<i<<" - Available";
		key++;
	}

	}

   char choice;
   cout<<"\n\n Input your choice : ";
   cin>>choice;

   if( !(choice >= 'A' && choice <='Z'))
   {
	cout<<"\n Error : Invalid Selection";
	cout<<"\n Please selction correct value from menu A- Z";
	cout<<"\n Press any key to continue";
	getchar();getchar();
	system("cls");
	bookSlot();
   }

   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0)
      isBooked = 0;

   if(isBooked ==1)
   {
   	cout<<"\n Sorry!!Booking is already done for this Hour";
   	cout<<"\n Please select another time !!";
   	cout<<"\n Press any key to continue!!";
   	getchar();getchar();
   	system("cls");
   	bookSlot();
   }


   ofstream out;
   out.open("booking.dat", ios::app);


   if(out){
	   out<<choice<<":"<<n_name.c_str()<<"\n";
	   out.close();
	   cout<<"\n Slot booked for time "<< (choice-65) + 9 <<" for one hour successfully !!";
    }
    else
    {
    	cout<<"\n Error while saving booking";
    }

    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;
}


int main(int argc, char** argv) {
	while(1)
	{
		system("cls");
		cout << "Content-type:text/html\r\n\r\n";
        cout << "<html>\n";
        cout << "<head>\n";
        cout << "<title>\t\t\tCALANDER SLOT BOOKING SYSTEM\n</title>\n";
		cout << "</head>\n";
        cout << "<body>\n";
        cout << "<h2>\t\t----------------------------------------------\n\n</h2>";

		cout<<"   1. User Registration\n";
		cout<<"   2. Check Existing Slots\n";
		cout<<"   3. Book Slot\n";
		cout<<"   0. Exit\n";
		int choice;

		cout<<"\n Enter you choice: ";
		cin>>choice;

		switch(choice)
		{
		    case 1: userRegistration();
		    break;

			case 2: existingBooking();
			break;

			case 3: bookSlot();
			break;

			case 0:
		        while(1)
		        {
				 system("cls");
		        	cout<<"\n Are you sure, you want to exit? y | n \n";
		        	char ex;
		        	cin>>ex;
		        	if(ex == 'y' || ex == 'Y')
		        		exit(0);
		        	else if(ex == 'n' || ex == 'N')
                     		{
                     		 break;
                    		}
                     else{
                     	cout<<"\n Invalid choice !!!";
                     	getchar();
                     }
             	 }	break;

            default: cout<<"\n Invalid choice. Enter again ";
                     getchar();

		}

	}
	cout << "</body>\n";
    cout << "</html>\n";
	return 0;
}

