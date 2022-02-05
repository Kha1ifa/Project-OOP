#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


class Person
{
private:
    char* PERSON_NAME;
    char* PERSON_AGE;
    char* PERSON_TELEPHONE_NUMBER;
    char* PERSON_PROFESSION;
    char* PERSON_CNIC;
    char* DATE_OF_JOIN;
    char* Complain;
public:
    Person();

    void set_Person_Name(char*);
    void set_Person_Age(char*);
    void set_Person_Telephone_Number(char*);
    void set_Person_Profession(char*);
    void set_Person_Cnic(char*);
    void set_Date_Of_Join(char*);
    void set_complain(char*);

    char* get_Person_Name()const;
    char* get_Person_Age()const;
    char* get_Person_Telephone_Number()const;
    char* get_Person_Profession()const;
    char* get_Person_Cnic()const;
    char* get_Date_Of_Join()const;
    char* get_complain()const;

    char* resize(char*)const;

    //hostel class-----------------------------------------------
    virtual void set_Room_Catagory(int);

    //standard class-----------------------
    virtual void set_Food_Bill_Standard(int);

    virtual void set_Total_Bill_Standard();

    //premium class----------------------------


    virtual void set_Food_Bill_Premium(int);
    virtual void set_Total_Bill_Premium();

    //------------------------------------------------------------
    virtual void Display()const;
    virtual void displaycomplain()const;

    ~Person();
};

Person::Person()
{
    PERSON_AGE = nullptr;
    
    PERSON_NAME = nullptr;
    
    PERSON_TELEPHONE_NUMBER = nullptr;
    
    PERSON_PROFESSION = nullptr;
    
    PERSON_CNIC = nullptr;
    
    DATE_OF_JOIN = nullptr;
    
    Complain = nullptr;
}

void Person::set_Person_Name(char* Person_Name)
{
    PERSON_NAME = resize(Person_Name);
}

void Person::set_Person_Age(char* Person_Age)
{
    PERSON_AGE = resize(Person_Age);
}

void Person::set_Person_Telephone_Number(char* Person_Telephone_Number)
{
    PERSON_TELEPHONE_NUMBER = resize(Person_Telephone_Number);
}

void Person::set_Person_Profession(char* Person_Profession)
{
    PERSON_PROFESSION = resize(Person_Profession);
}

void Person::set_Person_Cnic(char* Person_Cnic)
{
    long long length = strlen(Person_Cnic)+1;
    if (length==16)
    {
        PERSON_CNIC = resize(Person_Cnic);
    }
    else
    {
        int count = 0;
        while (count < 4)
        {

            cout << endl << "\t-->CNIC Length doesn't match the credentials--------"<<"eg: 00000-0000000-0 " << endl;
            if (count==3)
            {
                cout << endl << "\tThis Is Your Last Chance..... " << endl;
            }
            cout << endl << "\tTry Again: ";
            cin.getline(Person_Cnic, 16);
            long long length_1 = strlen(Person_Cnic) + 1;
            if (length_1 == 16)
            {
                PERSON_CNIC = resize(Person_Cnic);
                break;
            }
            else
            {
                count++;
            }
        }
    }
}

void Person::set_Date_Of_Join(char* Date_Of_Join)
{
    DATE_OF_JOIN = resize(Date_Of_Join);
}

void Person::set_complain(char* complain)
{
    Complain = resize(complain);
}



char* Person::get_Date_Of_Join()const
{
    return DATE_OF_JOIN;
}

char* Person::get_Person_Name() const
{
    return PERSON_NAME;
}

char* Person::get_Person_Age() const
{
    return PERSON_AGE;
}

char* Person::get_Person_Telephone_Number() const
{
    return PERSON_TELEPHONE_NUMBER;
}

char* Person::get_Person_Profession() const
{
    return PERSON_PROFESSION;
}

char* Person::get_Person_Cnic()const
{
    return PERSON_CNIC;
}

char* Person::get_complain()const
{
    return Complain;
}

char* Person::resize(char* Arr_1) const //resize function simply choose the exact len of array to store name
{
    long long len_1 = strlen(Arr_1)+1;
    char* temp_Arr_1 = new char[len_1];
    strcpy(temp_Arr_1, Arr_1);
    temp_Arr_1[len_1] = '\0';
    return temp_Arr_1;
}

void Person::set_Room_Catagory(int)
{

}

void Person::set_Food_Bill_Standard(int)
{

}

void Person::set_Total_Bill_Standard()
{
}

void Person::set_Food_Bill_Premium(int)
{

}

void Person::set_Total_Bill_Premium()
{

}

void Person::Display() const
{

}

void Person::displaycomplain() const
{

}

Person::~Person()
{
    delete[]PERSON_NAME;
    delete[]PERSON_AGE;
    delete[]PERSON_TELEPHONE_NUMBER;
    delete[]PERSON_PROFESSION;
    delete[]DATE_OF_JOIN;
    PERSON_NAME = nullptr;
    PERSON_AGE = nullptr;
    PERSON_PROFESSION = nullptr;
    PERSON_TELEPHONE_NUMBER = nullptr;
    DATE_OF_JOIN = nullptr;
}

class Hostel:public Person
{
private:
    int ROOM_CATAGORY;
    
public:
    
    Hostel();

    void set_Room_Catagory(int);

    void Display()const;
    void displaycomplain()const;

};

Hostel::Hostel()
{
    ROOM_CATAGORY = 0;
}

void Hostel::set_Room_Catagory(int Room_Catagory)
{
    ROOM_CATAGORY = Room_Catagory;
}



void Hostel::Display() const
{
    ofstream Write_in_file;
    Write_in_file.open("Person Information.txt", fstream::app);
    cout << endl << "\t--------------------------Person Information---------------------(" <<  get_Date_Of_Join() << ")---" << endl;
    cout << endl << "\tRoom Catagory selected " << ROOM_CATAGORY << endl;
    cout << endl << "\tPerson Name is : " << get_Person_Name() << endl;
    cout << endl << "\tPerson Age is : " << get_Person_Age() << endl;
    cout << endl << "\tPerson Telephone Number is : " << get_Person_Telephone_Number() << endl;
    cout << endl << "\tPerson Profession is : " << get_Person_Profession() << endl;
    cout << endl << "\tPerson CNIC Number is : " << get_Person_Cnic() << endl << endl;
    

    Write_in_file << endl << "\t--------------------------Person Information---------------------(" << get_Date_Of_Join() << ")---" << endl;
    Write_in_file << endl << "\tRoom Catagory selected " << ROOM_CATAGORY << endl;
    Write_in_file << endl << "\tPerson Name is : " << get_Person_Name() << endl;
    Write_in_file << endl << "\tPerson Age is : " << get_Person_Age() << endl;
    Write_in_file << endl << "\tPerson Telephone Number is : " << get_Person_Telephone_Number() << endl;
    Write_in_file << endl << "\tPerson Profession is : " << get_Person_Profession() << endl;
    Write_in_file << endl << "\tPerson CNIC Number is : " << get_Person_Cnic() << endl;
    

    
    
}

void Hostel::displaycomplain() const
{
    ofstream writecomplain;
    writecomplain.open("Complains.txt", fstream::app);
    
    writecomplain <<endl <<"\t----------Complain----------" << endl;
    writecomplain <<endl << get_complain() << endl;
    
}

class Premium_Rooms : public Person
{
private:
    int MONTHLY_RESIDENCE_BILL_PREMIUM = 10000;
    int FOOD_BILL_PREMIUM;
    int TOTAL_BILL_PREMIUM;
public:
    Premium_Rooms();

    void set_Food_Bill_Premium(int);
    void set_Total_Bill_Premium();

    

    void Display()const;
};

Premium_Rooms::Premium_Rooms()
{
    FOOD_BILL_PREMIUM = 0;
    TOTAL_BILL_PREMIUM = 0;
}


void Premium_Rooms::set_Food_Bill_Premium(int Food_Bill_Premium)
{
    FOOD_BILL_PREMIUM = Food_Bill_Premium;
}

void Premium_Rooms::set_Total_Bill_Premium()
{
    
    TOTAL_BILL_PREMIUM = FOOD_BILL_PREMIUM + MONTHLY_RESIDENCE_BILL_PREMIUM;
}



void Premium_Rooms::Display() const
{
    ofstream Write_in_file;
    Write_in_file.open("Premium_Rooms.txt", fstream::app);
    cout << endl << "\t--------------------------Person Information For Premium Room----------------(" << get_Date_Of_Join() << ")--------" << endl;
    cout << endl << "\tPerson Name is : " << get_Person_Name() << endl;
    cout << endl << "\tPerson Age is : " << get_Person_Age() << endl;
    cout << endl << "\tPerson Telephone Number is : " << get_Person_Telephone_Number() << endl;
    cout << endl << "\tPerson Profession is : " << get_Person_Profession() << endl;
    cout << endl << "\tPerson CNIC Number is : " << get_Person_Cnic() << endl;
    cout << endl << "\tPerson Monthly Residence Bill is : " << MONTHLY_RESIDENCE_BILL_PREMIUM << endl;
    cout << endl << "\tPerson Food Bill is : " << FOOD_BILL_PREMIUM << endl;
    cout << endl << "\tPerson Total Expense is : " << TOTAL_BILL_PREMIUM << endl << endl;

    //written in file for backup!
    Write_in_file << endl << "--------------------------Person Information For Premium Room----------------(" << get_Date_Of_Join() << ")--------" << endl;
    Write_in_file << endl << "\tPerson Name is : " << get_Person_Name() << endl;
    Write_in_file << endl << "\tPerson Age is : " << get_Person_Age() << endl;
    Write_in_file << endl << "\tPerson Telephone Number is : " << get_Person_Telephone_Number() << endl;
    Write_in_file << endl << "\tPerson Profession is : " << get_Person_Profession() << endl;
    Write_in_file << endl << "\tPerson CNIC Number is : " << get_Person_Cnic() << endl;
    Write_in_file << endl << "\tPerson Monthly Residence Bill is : " << MONTHLY_RESIDENCE_BILL_PREMIUM << endl;
    Write_in_file << endl << "\tPerson Food Bill is : " << FOOD_BILL_PREMIUM << endl;
    Write_in_file << endl << "\tPerson Total Expense is : " << TOTAL_BILL_PREMIUM << endl;
}


class Standard_Rooms : public Person
{
private:
    int MONTHLY_RESIDENCE_BILL_STANDARD = 5000;
    int FOOD_BILL_STANDARD;
    int TOTAL_BILL_STANDARD;
public:
    Standard_Rooms();
    
    void set_Food_Bill_Standard(int);
    void set_Total_Bill_Standard();

    

    void Display()const;

};

Standard_Rooms::Standard_Rooms()
{
    FOOD_BILL_STANDARD = 0;
    TOTAL_BILL_STANDARD = 0;
}

void Standard_Rooms::set_Food_Bill_Standard(int Food_Bill_Standard)
{
    FOOD_BILL_STANDARD = Food_Bill_Standard;
}

void Standard_Rooms::set_Total_Bill_Standard()
{

    TOTAL_BILL_STANDARD = FOOD_BILL_STANDARD + MONTHLY_RESIDENCE_BILL_STANDARD;
}



void Standard_Rooms::Display() const
{
    
    ofstream Write_in_file;
    Write_in_file.open("Standard_Rooms.txt", fstream::app);
    cout << endl << "\t--------------------------Person Information For Standard Room----------------(" << get_Date_Of_Join() <<  ")--------" << endl;
    cout << endl << "\tPerson Name is : " << get_Person_Name() << endl;
    cout << endl << "\tPerson Age is : " << get_Person_Age() << endl;
    cout << endl << "\tPerson Telephone Number is : " << get_Person_Telephone_Number() << endl;
    cout << endl << "\tPerson Profession is : " << get_Person_Profession() << endl;
    cout << endl << "\tPerson CNIC Number is : " << get_Person_Cnic() << endl;
    cout << endl << "\tPerson Monthly Residence Bill is : " << MONTHLY_RESIDENCE_BILL_STANDARD << endl;
    cout << endl << "\tPerson Food Bill is : " << FOOD_BILL_STANDARD << endl;
    cout << endl << "\tPerson Total Expense is : " << TOTAL_BILL_STANDARD << endl << endl;

    //written in file for backup!
    Write_in_file << endl << "\t--------------------------Person Information For Standard Room----------------(" << get_Date_Of_Join() << ")--------" <<endl;
    Write_in_file << endl << "\tPerson Name is : " << get_Person_Name() << endl;
    Write_in_file << endl << "\tPerson Age is : " << get_Person_Age() << endl;
    Write_in_file << endl << "\tPerson Telephone Number is : " << get_Person_Telephone_Number() << endl;
    Write_in_file << endl << "\tPerson Profession is : " << get_Person_Profession() << endl;
    Write_in_file << endl << "\tPerson CNIC Number is : " << get_Person_Cnic() << endl;
    Write_in_file << endl << "\tPerson Monthly Residence Bill is : " << MONTHLY_RESIDENCE_BILL_STANDARD << endl;
    Write_in_file << endl << "\tPerson Food Bill is : " << FOOD_BILL_STANDARD << endl;
    Write_in_file << endl << "\tPerson Total Expense is : " << TOTAL_BILL_STANDARD << endl;
    


}

int main()
{
    
    int size = 100, choice;
    char* Person_Name = new char[size];
    char* Person_Age = new char[size];
    char* Person_Cnic = new char[size];
    char* Person_Telephone_Number = new char[size]; //new char dynamic char array
    char* Person_Profession = new char[size];
    char* Date_Of_Join = new char[size];
    char* Complain = new char[size];
    int Press;

    
    while (1) {
        
        
    cout << endl << "\t------------WELCOME TO MY HOSTEL-------------" << endl;
    cout << endl << "\tWe have two catagories of rooms here!" << endl;
    cout << endl << "\tFirst one is standard and second one is premium" << endl;
    cout << endl << "\tstandard room without food is 5000 Rs Only, and Premium room without food is 10000 Rs Only " << endl;
    cout << endl << endl <<endl <<"\t---------------PRESS 4 TO EXIT PROGRAM--------------";

    cout << endl << "\t>>>Now! Press '1' for 'Standard room' and Press '2' for 'PREMIUM ROOM' AND PRESS '3' FOR 'ADD COMPLAIN': ";
    cin >> Press;

    
    
    if (Press==1)
    {
        
        cout << endl << "\t------------Now please fill your personal details-------------" << endl;
        cin.ignore(); //ignore all garbage information
        cout <<endl<< "\tEnter Your Name: ";
        cin.getline(Person_Name, size); //getline reads the input string or a line
        
        cout << endl << "\tEnter Your Age: ";
        cin.getline(Person_Age, size); //it simply allow all the spaces or anything in name or telephone while inserting
        
        cout <<endl<< "\tEnter your telephone number: ";
        cin.getline(Person_Telephone_Number, size);
        
        cout <<endl<< "\tEnter Your CNIC Number: ";
        cin.getline(Person_Cnic, size);

        cout<<endl <<"\tEnter Your Profession: ";
        cin.getline(Person_Profession, size);
        
        
        
        
        Person* Access[4]; //polymorphism // pointer object //which access other classes

        Access[1] = new Hostel(); // pointing towards hostel class dynamically
        Access[1]->set_Person_Name(Person_Name); // setting person name through setter
        Access[1]->set_Person_Age(Person_Age);
        Access[1]->set_Person_Telephone_Number(Person_Telephone_Number);
        Access[1]->set_Person_Profession(Person_Profession);
        Access[1]->set_Person_Cnic(Person_Cnic);
        Access[1]->set_Room_Catagory(Press);
        
        cout <<endl<< "\t-->Kindly Sir enter the date of your joining: ";
        cin.getline(Date_Of_Join, size);
        Access[1]->set_Date_Of_Join(Date_Of_Join); //this sets the date of join for hostel class
        Access[2] = new Standard_Rooms();
        Access[2]->set_Person_Name(Person_Name);
        Access[2]->set_Person_Age(Person_Age);
        Access[2]->set_Person_Telephone_Number(Person_Telephone_Number);
        Access[2]->set_Person_Profession(Person_Profession);
        Access[2]->set_Person_Cnic(Person_Cnic);
        Access[2]->set_Date_Of_Join(Date_Of_Join); //this sets the date of join for standard room class

        cout <<endl<< "\t-->Now if you have to add food during your stay press 1 otherwise press 2: Press: ";
        cin >> choice;
        if (choice==1)
        {
            cout << endl<< "\t-------------Hope will see you next time!-------------" << endl << endl << endl;

            Access[2]->set_Food_Bill_Standard(4000);
            Access[2]->set_Food_Bill_Premium(0);
            Access[2]->set_Total_Bill_Standard();
            Access[1]->Display(); //Display all information of hostel
            Access[2]->Display(); //Display all information regarding standard room
            
        }
        else
        {
            cout << endl<< "\t-------------Hope will see you next time!-------------" << endl << endl << endl;
            Access[2]->set_Food_Bill_Standard(0);
            Access[2]->set_Total_Bill_Standard();
            Access[1]->Display(); //Display all information of hostel
            Access[2]->Display(); //Display all information regarding standard room

        }
        
    }
    
        
        
    else if (Press==2)
    {
        
        cout << endl << "\t------------Now please fill your personal details-------------" << endl;
        cin.ignore(); //ignore all garbage information
        cout <<endl<< "\tEnter Your Name: ";
        cin.getline(Person_Name, size); //getline reads the input string or a line
        
        cout << endl << "\tEnter Your Age: ";
        cin.getline(Person_Age, size); //it simply allow all the spaces or anything in name or telephone while inserting
        
        cout <<endl<< "\tEnter your telephone number: ";
        cin.getline(Person_Telephone_Number, size);
        
        cout <<endl<< "\tEnter Your CNIC Number: ";
        cin.getline(Person_Cnic, size);

        cout<<endl <<"\tEnter Your Profession: ";
        cin.getline(Person_Profession, size);
        
        
        Person* Access[4]; //polymorphism // pointer object //which access other classes

        Access[1] = new Hostel(); // pointing towards hostel class dynamically
        Access[1]->set_Person_Name(Person_Name); // setting person name through setter
        Access[1]->set_Person_Age(Person_Age);
        Access[1]->set_Person_Telephone_Number(Person_Telephone_Number);
        Access[1]->set_Person_Profession(Person_Profession);
        Access[1]->set_Person_Cnic(Person_Cnic);
        Access[1]->set_Room_Catagory(Press);
        
        
        
        cout << endl << "\t-->Kindly Sir enter the date of your joining: ";
        cin.getline(Date_Of_Join, size);
        
        Access[1]->set_Date_Of_Join(Date_Of_Join); //this sets the date of join for hostel class
        Access[3] = new Premium_Rooms();
        Access[3]->set_Person_Name(Person_Name);
        Access[3]->set_Person_Age(Person_Age);
        Access[3]->set_Person_Telephone_Number(Person_Telephone_Number);
        Access[3]->set_Person_Profession(Person_Profession);
        Access[3]->set_Person_Cnic(Person_Cnic);
        Access[3]->set_Date_Of_Join(Date_Of_Join); //this sets the date of join for Premium room class

        cout <<endl<< "\t-->Now if you have to add food during your stay press 1 otherwise press 2: Press: ";
        cin >> choice;
        if (choice == 1)
        {
            Access[3]->set_Food_Bill_Premium(6000);
            Access[3]->set_Total_Bill_Premium();
            Access[3]->set_Food_Bill_Standard(0);
            Access[1]->Display();
            Access[3]->Display();
        }
        else
        {
            cout <<endl<< "\t-------------Hope will see you next time!-------------" << endl<<endl<<endl;
            Access[3]->set_Food_Bill_Premium(0);
            Access[3]->set_Total_Bill_Premium();
            Access[1]->Display();
            Access[3]->Display();
        }
    }
        
        
    
        else if(Press==3) //for complain
        {
            cin.ignore();
            cout <<endl<<"\t Complain: ";
            cin.getline(Complain, size);
            
            Person* Access[4];
            Access[1] = new Hostel();
            Access[1]->set_complain(Complain);
            Access[1] -> displaycomplain();
            
        }
        
        
        else if(Press == 4)
        {
            break;
        }


    }
    
    
    return 0;
}
