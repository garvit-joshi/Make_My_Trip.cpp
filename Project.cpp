#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class mmt
{
	int age, password;
	char name[20];
public:
	void getdetails()
	{
		cin.ignore();
		cout << "Enter Your Name:";
		cin.getline(name, 20);
		cout << "Enter Your Age:";
		cin >> age;
		cout << "Enter Password:";
		cin >> password;
		cout << "Welcome " << name << "!!Please Remember Your Password,You Are Now a Registered Member Of MAKE MY TRIP";
	}
	void display()
	{
		cout << "\nName:" << name;
		cout << "\nAge:" << age;
	}
	int finddata(char user[20], int pass, int& flag)
	{
		if (strcmp(user, name) == 0 && pass == password)
		{
			cout << "Welcome!!" << user;
			flag = 1;
			return 0;
		}
		return 0;
	}
};
class bookingt
{
	int dodd, dodm, dody, doad, doam, doay, ch1;
	char aname[20], dods[20], doas[20], trainn[20];
public:
	void getdetails(char name[20])
	{
		cin.ignore();
		strcpy(aname, name);
		cout << "Enter Departure Station:";
		cin.get(dods, 100);
		cout << "Enter Arrival Station:";
		cin.get(doas, 100);
		cout << "Enter Date of Departure:";
		cout << "\nDay/Month/Year:";
		cin >> dodd >> dodm >> dody;
		cout << "\n\nEnter Date Of Arrival:";
		cout << "\nDay/Month/Year:";
		cin >> doad >> doam >> doay;
	tr:
		cout << "Selected Trains Are Available:";
		cout << "\n1.Satabdi Express";
		cout << "\n2.Chennai Express";
		cout << "\n3.Amritsar Mail";
		cout << "\nEnter Your Choice:";
		cin >> ch1;
		switch (ch1)
		{
		case 1:
		{
			strcpy(trainn, "Satabdi Express");
			break;
		}
		case 2:
		{
			strcpy(trainn, "Chennai Express");
			break;
		}
		case 3: {
			strcpy(trainn, "Amritsar Express");
			break;
		}
		default:
		{
			cout << "Enter A Valid Choice:";
			goto tr;
		}
		}
	}
	int finddata(char fname[20], int& flag)
	{
		if (strcmp(fname, aname) == 0)
		{
			cout << "Name:" << aname;
			cout << "\nArriving City:" << doas;
			cout << "\nDate of Arriving In Train" << doad << "/" << doam << "/" << doay;
			cout << "\nDeparture City" << dods;
			cout << "\nDate Of Departure In Train" << dodd << "/" << dodm << "/" << dody;
			cout << "\nTrain Name:" << trainn << "\n\n";
			flag = 2;
		}
		else if (flag == 1)
		{
			flag = 0;
		}
		return 0;
	}
};
class bookingh
{
	int dodd, dodm, dody, doad, doam, doay, ch1;
	char city[20], aname[20], hoteln[20];
public:
	void getdetails(char name[20])
	{
		cin.ignore();
		strcpy(aname, name);
		cout << "Enter City:";
		cin.get(city, 100);
		cout << "Enter Date of Arriving In Hotel:";
		cout << "\nDay/Month/Year:";
		cin >> doad >> doam >> doay;
		cout << "\n\nEnter Date Of Departure In Hotel";
		cout << "\nDay/Month/Year:";
		cin >> dodd >> dodm >> dody;
	ho:
		cout << "Selected Hotels Are Available:";
		cout << "\n1.KINGS PALACE(*****)";
		cout << "\n2.KAUSHIK IN(***)";
		cout << "\n3.HOTEL CANDY IN(*******)";
		cout << "\nEnter Your Choice:";
		cin >> ch1;
		switch (ch1)
		{
		case 1:
		{
			strcpy(hoteln, "KINGS PALACE");
			break;
		}
		case 2:
		{
			strcpy(hoteln, "KAUSHIK INN");
			break;
		}
		case 3:
		{
			strcpy(hoteln, "HOTEL CANDY IN");
			break;
		}
		default:
		{
			cout << "Enter A Valid Choice:";
			goto ho;
		}
		}
	}
	int finddata(char fname[20], int& flag)
	{
		if (strcmp(fname, aname) == 0)
		{
			cout << "Name:" << aname;
			cout << "\nCity:" << city;
			cout << "\nDate of Arriving In Hotel:" << doad << "/" << doam << "/" << doay;
			cout << "\nExpected Date Of Departure In Hotel:" << dodd << "/" << dodm << "/" << dody;
			cout << "\nHotel Name:" << hoteln << "\n\n";
			flag = 2;
		}
		else if (flag == 1)
		{
			flag = 0;
		}
		return 0;
	}
};
int main()
{
	mmt a;
	int ch1, ch2, age, i, flag = 2, password, flag1 = 1;
	char name[20], dname[20];
	char ch3, ch4;
	cout << "\n\n\n\t\t\tWELCOME TO TOUR PLANNER\n\t\t\t(A MAKE MY TRIP INITIATIVE)\n\t\t\t\t\t\t-Garvit Joshi(garvitjoshi9@gmail.com)";
	cout << "\n1.Sign Up";
	cout << "\n2.Already A Member?";
	cout << "\n3.Login Admin:";
	cout << "\n\nEnter Your Choice:";
	cin >> ch1;
	ofstream ofile("TRIPDATA.txt", ios::out | ios::app | ios::binary);
	if (ch1 == 1)
	{
		a.getdetails();
		ofile.write((char*)&a, sizeof(a));
		ofile.close();
		cout << "\n\n\n\n©GARVIT JOSHI(MAKE MY TRIP)";
		ofile.close();
		return 0;
	}
	else if (ch1 == 2)
	{
		ifstream ifile("TRIPDATA.txt", ios::in | ios::binary);
		cin.ignore();
		cout << "Enter Your User Name:";
		cin.get(name, 100);
		strcpy(dname, name);
		cout << "Enter Your Password(Case Senstive):";
		cin >> password;
		ifile.seekg(0);
		while (ifile.read((char*)&a, sizeof(a)))
		{
			a.finddata(name, password, flag);
		}
		if (flag == 2)
		{
			cout << "Sorry!User Name and password Are Not matching";
			cout << "\n\n\n\n©GARVIT JOSHI(MAKE MY TRIP)";
			return 0;
		}
		ifile.close();
	}
	else if (ch1 == 3)
	{
		ifstream ifile("TRIPDATA.txt", ios::in | ios::binary);
		ifile.seekg(0);
		cin.ignore();
		cout << "Enter Password(Admin):";
		cin >> password;
		if (password == 789)
		{
			while (ifile.read((char*)&a, sizeof(a)))
			{
				a.display();
			}
		}
		else
		{
			cout << "Wrong Password:";
			cout << "\n\n\n\n©GARVIT JOSHI(MAKE MY TRIP)";
			return 0;
		}
		ifile.close();
		cout << "Do you want to delete all the data:(Y or N):";
		cin >> ch3;
		if (ch3 == 'Y' || ch3 == 'y')
		{
			cout << "\n\nAre You Sure(Y or N):";
			cin >> ch4;
			if (ch4 == 'Y' || ch4 == 'y')
			{
				ofstream ofile1("TRIPDATA.txt", ios::out | ios::trunc);
				ofstream ofile2("TRAINDATA.txt", ios::out | ios::trunc);
				ofstream ofile3("HOTELDATA.txt", ios::out | ios::trunc);
				ofile1.close();
				ofile2.close();
				ofile3.close();
				cout << "All The data Has Been Deleted From the Files:";
			}
			else
			{
				cout << "The Data Has Not been Deleted :";
			}
		}
		else if (ch3 == 'N' || ch3 == 'n')
		{
			cout << "The Data has Not been Deleted:";
			cout << "\n\n\n\n©GARVIT JOSHI(MAKE MY TRIP)";
			return 0;
		}
		cout << "\n\n\n\n©GARVIT JOSHI(MAKE MY TRIP)";
		return 0;
	}
	else
	{
		cout << "Please!!Enter A Valid Choice";
		return 0;
	}
notvalid:
	cout << "\nPlease Select From The Following Options:";
	cout << "\n1.MY BOOKINGS:";
	cout << "\n2.TRAIN BOOKING:";
	cout << "\n3.HOTEL BOOKINGS:";
	cout << "\nEnter Your Choice:";
	cin >> ch1;
	bookingt train;
	bookingh hotel;
	if (ch1 == 1)
	{
		cout << "Hy!!" << name << " Please tell Us Which Booking You wish to See:";
		cout << "\n1.Hotel Booking:";
		cout << "\n2.Train Bookings:";
		cout << "\nEnter Your Choice:";
		cin >> ch2;
		switch (ch2)
		{
		case 1:
		{
			ifstream ifile("HOTELDATA.txt", ios::in | ios::binary);
			ifile.seekg(0);
			while (ifile.read((char*)&hotel, sizeof(hotel)))
			{
				hotel.finddata(name, flag1);
			}
			if (flag1 == 0)
			{
				cout << "Sorry!!" << name << "There Are No Hotel Bookings By Your Name:";
			}
			break;
		}
		case 2:
		{
			ifstream ifile("TRAINDATA.txt", ios::in | ios::binary);
			ifile.seekg(0);
			while (ifile.read((char*)&train, sizeof(train)))
			{
				train.finddata(name, flag1);
			}
			if (flag1 == 0)
			{
				cout << "Sorry!!" << name << "There Are No Train Bookings By Your Name:";
			}
			break;
		}
		default:cout << "Enter A valid choice:";
		}
	}
	else if (ch1 == 2)
	{
		train.getdetails(name);
		ofstream ofile("TRAINDATA.txt", ios::out | ios::binary | ios::app);
		ofile.write((char*)&train, sizeof(train));
		cout << "Train Has Been Booked";
		ofile.close();
	}
	else if (ch1 == 3)
	{
		cout << "Name=" << dname << endl;
		hotel.getdetails(dname);
		ofstream ofile("HOTELDATA.txt", ios::out | ios::binary | ios::app);
		ofile.write((char*)&hotel, sizeof(hotel));
		cout << "Hotel Has Been Booked";
		ofile.close();
	}
	else
	{
		cout << "Please!!Enter A Valid Choice" << name << "\n\n";
		goto notvalid;
	}
	cout << "\n\n\n\n©GARVIT JOSHI(MAKE MY TRIP)";
	return 0;
}
