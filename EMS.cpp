#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<windows.h>

using namespace std;


class emp
{
private:
    int emp_id,sal,group_id;
    string name,address;
public:
    void menu();
    void Insert();
    void Display();
    void Search();
    void Modify();
    void Delete();
    void Group();
    void Search_Group();
    void Show_Group();
};


void login()
{
    p:
    system("cls");
    char ch;
    string user,pass;
    cout<<endl<<endl<<endl<<endl<<"\t\t\t\t******************************";
    cout<<endl<<endl<<"\t\t\t\t\tLogin Process";
    cout<<endl<<endl<<"\t\t\t\t******************************";
    cout<<endl<<endl<<endl<<"\t\t\t\tEnter User Name : ";
    cin>>user;
    cout<<endl<<endl<<"\t\t\t\tEnter Passward : ";
    int t=6;
    while(t--)
    {
        ch=getch();
        pass+=ch;
        cout<<"#";
    }
    if(user=="group28" && pass=="123456")
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl<<"\t\t\t\tCongratulations...!!!";
        cout<<endl<<"\t\t\t\tLogin Successfully...!!!";
        cout<<endl<<endl<<"\t\t\t\tLoading";
        for(int i=0;i<=6;i++)
        {
            Sleep(500);
            cout<<".";

        }
    }
    else if(user!="group28" && pass=="123456")
    {
        cout<<endl<<endl<<endl<<"Your User Name Is Wrong.....";
        getch();
        goto p;
    }
    else if(user=="group28" && pass!="123456")
    {
        cout<<endl<<endl<<endl<<"Your Password Is Wrong.....";
        getch();
        goto p;
    }
    else
    {
        cout<<endl<<endl<<endl<<"Your User Name & Password both are Wrong.....";
        getch();
        exit(0);
    }
}

//Menu Function
void emp::menu()
{
    first:
    system("cls");// For Clear Screen
    cout<<"\n\n\t\t\t\tControl Panel"<<endl<<endl<<endl;
    cout<<"1.Insert Record"<<endl;
    cout<<"2.Display Record"<<endl;
    cout<<"3.Search Record"<<endl;
    cout<<"4.Modify Record"<<endl;
    cout<<"5.Delete Record"<<endl;
    cout<<"6.Group Record"<<endl;
    cout<<"7.Search Group"<<endl;
    cout<<"8.Show All Group"<<endl;
    cout<<"9.Exit"<<endl;
    cout<<endl<<"Enter Your Choice: ";
    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        Insert();
        break;
    case 2:
        Display();
        break;
    case 3:
        Search();
        break;
    case 4:
        Modify();
        break;
    case 5:
        Delete();
        break;
    case 6:
        Group();
        break;
    case 7:
        Search_Group();
        break;
    case 8:
        Show_Group();
        break;
    case 9:
        exit(0);
    default:
        cout<<endl<<"Invalid Value...Please Try Again!!!!";
    }
    getch();
    goto first;
}


//Insert Function
void emp::Insert()
{
    system("cls");
    int test_id,found=0;
    cout<<endl<<endl<<"\t\t\t\t Insert Record"<<endl<<endl;
    cout<<"Employee ID: ";
    cin>>emp_id;
    cout<<endl<<endl<<"\t\tEmployee Name: ";
    cin.ignore();
    getline(cin,name);
    cout<<endl<<endl<<"Employee Salary: ";
    cin>>sal;
    cout<<endl<<endl<<"\t\tEmployee Address: ";
    cin.ignore();
    getline(cin,address);
    cout<<endl<<endl<<"Employee Group ID: ";
    cin>>group_id;

    //File object
    fstream file ;//for employee
    fstream file1; //for group

    //file open
    file.open("emp.txt",ios::out|ios::app);
    file<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<endl;   //file input for employee
    file.close();
    file1.open("group.txt",ios::out|ios::app);
    file1<<" "<<group_id<<" "<<emp_id<<" "<<sal<<endl;  //file input for group
    file1.close();

    file.open("groupid.txt",ios::in);
    if(!file)
    {
        file1.open("groupid.txt",ios::app|ios::out);
        file1<<" "<<group_id<<endl;
        file1.close();
    }
    else
    {
        file>>test_id;
        while(1)
        {
            if(file.eof())
            {
               break;
            }
            if(test_id==group_id)
            {
                found++;

            }
            file>>test_id;
        }

        file.close();
        if(found==0)
        {
            file1.open("groupid.txt",ios::app|ios::out);
            file1<<" "<<group_id<<endl;
            file1.close();
        }
    }
    cout<<endl<<"\t\t New Record Inserted Successfully......";
}


//Display Information
void emp::Display()
{
    system("cls");
    fstream file;
    cout<<endl<<endl<<"\t\t\t\tDisplay Record"<<endl<<endl;
    file.open("emp.txt",ios::in);
    int x=0;
    file>>emp_id>>name>>sal>>address>>group_id;
    if(!file)
    {
        cout<<"File Opening Error.......";
        getch();
        menu();
    }
    while(1)
    {
        x++;
        cout<<"Information of Employee "<<x<<":"<<endl;
        cout<<endl<<"Employee ID: "<<emp_id;
        cout<<endl<<endl<<"\t\tEmployee Name: "<<name;
        cout<<endl<<endl<<"Employee Salary: "<<sal;
        cout<<endl<<endl<<"\t\tEmployee Address: "<<address;
        cout<<endl<<endl<<"Group ID: "<<group_id;
        file>>emp_id>>name>>sal>>address>>group_id;
        if(file.eof())
        {
            break;
        }
        cout<<endl<<endl<<endl<<endl;
    }
    file.close();

    cout<<endl<<endl<<endl<<"\t\t\t\tPlease,Press 0 for Go Back:";
    int a;
    cin>>a;
    if(a==0)
    {
        menu();
    }
    else
    {
        exit(0);
    }
}


//Search function
void emp::Search()
{
    system("cls");
    cout<<endl<<endl<<"\t\t\t\tSearch Record";
    fstream file;
    file.open("emp.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl<<"File Opening Error.......!!!";
        getch();
        menu();

    }
    cout<<"\n\nEmployee ID For Search : ";
    int emp_idd,found=0;
    cin>>emp_idd;

    file>>emp_id>>name>>sal>>address>>group_id;
     while(1)
    {
        if(emp_idd==emp_id)
        {
        system("cls");
        cout<<endl<<endl<<"\t\t\t\tSearch Record";
        cout<<endl<<endl<<"Employee ID: "<<emp_id;
        cout<<endl<<endl<<"\t\tEmployee Name: "<<name;
        cout<<endl<<endl<<"Employee Salary: "<<sal;
        cout<<endl<<endl<<"\t\tEmployee Address: "<<address;
        cout<<endl<<endl<<"Group ID: "<<group_id;
        found++;
        }
        file>>emp_id>>name>>sal>>address>>group_id;
        if(file.eof())
        {
            break;
        }
        cout<<endl<<endl<<endl<<endl;
    }
    file.close();
    if(found==0)
        cout<<endl<<endl<<"ID not found.......";cout<<endl<<endl<<endl<<"\t\t\t\tPlease,Press 0 for Go Back:";
    int a;
    cin>>a;
    if(a==0)
    {
        menu();
    }
    else
    {
        exit(0);
    }


}




void emp::Modify()
{

    system("cls");
    int sal1, test_id, found = 0;
    string name1, address1;

    fstream file, file1, file2, file3;

    cout << "\n\n\t\t\t\tModify Record";

    file.open("emp.txt", ios::in);
    file1.open("group.txt", ios::in);

    if (!file || !file1)
    {
        cout << "\n\nFile Opening Error.....";
        getch();
        menu();
        return;
    }

    cout << "\n\nEmployee ID for Modify: ";
    cin >> test_id;
    file2.open("emp1.txt", ios::app | ios::out);

    file >> emp_id >> name >> sal >> address >> group_id;

    while (!file.eof())
    {
        if (test_id == emp_id)
        {

            cout << "\n\n\t\t\t\tModify Record";
            cout << "\n\n\nEmployee Name: ";
            cin >> name1;
            cout << "\n\n\t\tEmployee Salary: ";
            cin >> sal1;
            cout << "\n\nEmployee Address: ";
            cin >> address1;

            file2 << emp_id << " " << name1 << " " << sal1 << " " << address1 << " " << group_id << endl;
            found++;
        }
        else
        {
            file2 << emp_id << " " << name << " " << sal << " " << address << " " << group_id << endl;
        }

        file >> emp_id >> name >> sal >> address >> group_id;
    }

    file.close();
    file2.close();

    remove("emp.txt");
    rename("emp1.txt", "emp.txt");
    file3.open("group1.txt", ios::app | ios::out);
    file1 >> group_id >> emp_id >> sal;

    while (!file1.eof())
    {
        if (test_id == emp_id)
        {
            file3 << group_id << " " << emp_id << " " << sal1 << endl;
        }
        else
        {
            file3 << group_id << " " << emp_id << " " << sal << endl;
        }
        file1 >> group_id >> emp_id >> sal;
    }

    file1.close();
    file3.close();
    remove("group.txt");
    rename("group1.txt", "group.txt");

    if (found == 0)
    {
        cout << "\n\n\t\tEmployee ID not found........";
    }
    else
    {
        cout << "\n\n\t\tRecord Modified Successfully.......";
    }
}






void emp::Delete()
{

    system("cls");

    int test_id, found = 0;
    fstream file, file1, file2, file3;

    cout << "\n\n\n\t\t\tDelete Record";
    file.open("emp.txt", ios::in);
    file1.open("group.txt", ios::in);

    if (!file || !file1)
    {
        cout << "\n\n File Opening Error.....";
        getch();
        menu();
        return;
    }

    cout << "\n\n\n Employee ID for Delete: ";
    cin >> test_id;
    file2.open("emp1.txt", ios::app | ios::out);
    if (!file2)
    {
        cout << "\n\n Error opening temporary employee file for writing!";
        return;
    }

    file >> emp_id >> name >> sal >> address >> group_id;

    while (!file.eof())
    {
        if (test_id == emp_id)
        {
            found++;
            cout << "\n\n\n Record Deleted successfully.....";
        }
        else
        {
            file2 << emp_id << " " << name << " " << sal << " " << address << " " << group_id << endl;
        }

        file >> emp_id >> name >> sal >> address >> group_id;
    }

    file.close();
    file2.close();

    remove("emp.txt");
    rename("emp1.txt", "emp.txt");

    file3.open("group1.txt", ios::app | ios::out);
    if (!file3)
    {
        cout << "\n\n Error opening temporary group file for writing!";
        return;
    }


    file1 >> group_id >> emp_id >> sal;

    while (!file1.eof())
    {
        if (test_id != emp_id)
        {

            file3 << group_id << " " << emp_id << " " << sal << endl;
        }

        file1 >> group_id >> emp_id >> sal;
    }

    file1.close();
    file3.close();
    remove("group.txt");
    rename("group1.txt", "group.txt");

    if (found == 0)
    {
        cout << "\n\n\n Employee ID not found....";
    }
}






//Group function
void emp::Group()
{
    system("cls");
    cout<<endl<<endl<<"\t\t\t\tGroup Record";
    fstream file;
    file.open("group.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl<<"File Opening Error......!!";
        getch();
        menu();
    }
    file>>group_id>>emp_id>>sal;
    while(1)
    {
        if(file.eof())
        {
            break;
        }

        cout<<endl<<endl<<endl<<endl<<"Group ID: "<<group_id;
        cout<<endl<<endl<<"\t\tEmployee ID: "<<emp_id;
        cout<<endl<<endl<<"Employee Salary: "<<sal;
        file>>group_id>>emp_id>>sal;
    }
    file.close();
}





//Search Group Function
void emp::Search_Group()
{
    system("cls");
    int test_id;
    int found=0;
    int emp_count=0,sal_count=0;
    fstream file;
    file.open("group.txt",ios::in);
    cout<<endl<<endl<<"\t\t\t\tSearch Group Record"<<endl<<endl;
    if(!file)
    {
        cout<<endl<<endl<<"File Opening Error....!!";
        getch();
        menu();
    }
    cout<<endl<<endl<<"Gruop ID for Search: ";
    cin>>test_id;
    system("cls");
    cout<<"\t\t\t\tSearch Group Record";
    file>>group_id>>emp_id>>sal;
    while(1)
    {
        if(file.eof())
        {
            break;
        }

        if(test_id==group_id)
        {
            cout<<endl<<endl<<"Group ID: "<<group_id;
            cout<<endl<<endl<<"\t\tEmployee ID: "<<emp_id;
            cout<<endl<<endl<<"Employee Salary: "<<sal;
            found++;
            emp_count++;
            sal_count=sal_count+sal;
        }
        cout<<endl;
        file>>group_id>>emp_id>>sal;
    }
    file.close();
    if(found!=0)
    {
        cout<<endl<<endl<<"\t\tGroup Id: "<<test_id;
        cout<<endl<<endl<<"\t\tTotal Employee: "<<emp_count;
        cout<<endl<<endl<<"\t\tTotal Salary: "<<sal_count;
    }
    else
    {
        cout<<"Group Id Not Found......!!!";
    }
}



void emp::Show_Group()
{
    system("cls");

    int test_id,emp_count=0,sal_count=0,emp_total=0,sal_total=0;
    fstream file,file1;
    cout<<endl<<endl<<"\t\t\t\tShow All Groups";
    file.open("groupid.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl<<"File Opening Error......!!";
        getch();
        menu();
    }

    file>>test_id;
    while(1)
    {
        if(file.eof())
        {
            break;
        }
        file1.open("group.txt",ios::in);
        file1>>group_id>>emp_id>>sal;
        while(1)
        {
            if(file1.eof())
            {
                break;
            }
            if(test_id==group_id)
            {
                emp_count++;
                sal_count=sal_count+sal;
                emp_total++;
                sal_total=sal_total+sal;
            }
            file1>>group_id>>emp_id>>sal;
        }
        file1.close();
        cout<<endl<<endl<<endl<<"\t\tGroup ID : "<<test_id;
        cout<<endl<<"\t\tTotal Employee : "<<emp_count;
        cout<<endl<<"\t\tTotal Salary : "<<sal_count;
        emp_count=0;
        sal_count=0;
        file>>test_id;
    }

    file.close();
    cout<<endl<<endl<<endl<<endl<<"\t\tOver All Employee : "<<emp_total;
    cout<<endl<<"\t\tOver All Salary : "<<sal_total;
}





//Main Function
int main()
{

    emp e;
    login();
    e.menu();
    return 0;
}


