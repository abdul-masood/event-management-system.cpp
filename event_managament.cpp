#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class event
{
	private:
		string id,name,phone,event,college,address;
	public:
		void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
};
void event::menu()
{
	menustart:
	int choice;
	char x;
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   EVENT MANAGEMENT SYSTEM   |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Insert Participant"<<endl;
	cout<<"\t\t\t 2. Display Participant"<<endl;
	cout<<"\t\t\t 3. Modify Participant"<<endl;
	cout<<"\t\t\t 4. Search Participant"<<endl;
	cout<<"\t\t\t 5. Delete Participant"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tChoose Option:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Enter Your Choose: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Add another participant(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		exit(0);

	default:
		cout<<"\n\t\t\t Invalid choice...Please Try Again..";
	}
	getch();
	goto menustart;
}
void event::insert()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Add Participant Details------------------------------------------------"<<endl;
	cout<<"\t\t\tEnter Participant id: ";
	cin>>id;
	cout<<"\t\t\tEnter Participant name: ";
	cin>>name;
	cout<<"\t\t\tEnter Participant phone: ";
	cin>>phone;
	cout<<"\t\t\tEnter Participant event: ";
	cin>>event;
	cout<<"\t\t\tEnter Participant college: ";
	cin>>college;
	cout<<"\t\t\tEnter Participant address: ";
	cin>>address;
	file.open("ParticipantRecord.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< event <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
	file.close();
}
void event::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Participant Details Table-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo Data is Present...";
		file.close();
	}
	else
	{
		file >> id >> name >> phone >> event >> college >> address;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Participant id: "<<id<<endl;
			cout<<"\t\t\t Participant name: "<<name<<endl;
			cout<<"\t\t\t Participant phone: "<<phone<<endl;
			cout<<"\t\t\t Participant event: "<<event<<endl;
			cout<<"\t\t\t Participant college: "<<college<<endl;
			cout<<"\t\t\t Participant address: "<<address<<endl;
			file >> id >> name >> phone >> event >> college >> address;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo Data Is Present...";
		}
	}
	file.close();
}
void event::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Participant Modify Details-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo Data is present..,";
		file.close();
	}
	else
	{
		cout<<"\n Enter Participant id of Participant which you want to modify: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> phone >> event >> college >> address;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< event <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
			}
			else
			{
				cout<<"\t\t\tEnter Participant id: ";
				cin>>id;
				cout<<"\t\t\tEnter Participant name: ";
				cin>>name;
				cout<<"\t\t\tEnter Participant phone: ";
				cin>>phone;
				cout<<"\t\t\tEnter Participant event: ";
				cin>>event;
				cout<<"\t\t\tEnter Participant college: ";
				cin>>college;
				cout<<"\t\t\tEnter Participant address: ";
				cin>>address;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< event <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
				found++;
			}
			file >> id >> name >> phone >> event >> college >> address;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
void event::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Participant Search data------------------------"<<endl;
		cout<<"\n\t\t\tNo Data is Preasent...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Participant Search data------------------------"<<endl;
		cout<<"\nEnter id of Participantwhich you want to search: ";
		cin>>participant_id;
		file >> id >> name >> phone >> event >> college >> address;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Participant id: "<<id<<endl;
				cout<<"\t\t\t Participant name: "<<name<<endl;
				cout<<"\t\t\t Participant phone: "<<phone<<endl;
				cout<<"\t\t\t Participant event: "<<event<<endl;
				cout<<"\t\t\t Participant college: "<<college<<endl;
				cout<<"\t\t\t Participant address: "<<address<<endl;
				found++;
			}
			file >> id >> name >> phone >> event >> college >> address;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Participant id Not Found...";
		}
		file.close();
	}
}
void event::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Delete Participant Details-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo Data is present...";
		file.close();
	}
	else
	{
		cout<<"\n Enter id of participant which you want to delete data: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> phone >> event >> college >> address;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< event <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tSuccessfully Delete Data";
			}
			file >> id >> name >> phone >> event >> college >> address;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Participant id not found...";
		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
main()
{
	event project;
	project.menu();
	return 0;
}

