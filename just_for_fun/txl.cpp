#include <iostream>
#include <string>
using namespace std;

enum Sex{male, female};

typedef struct Member
{
    string name;
    Sex sex;
    int age;
    string telephone;
    string address;
    struct Member *next;
}Member;

struct List
{
    Member *head = nullptr;
    Member *tail = nullptr;
}list;

void f_mainpage()
{
    cout<<"Welcome to Telephone Organize System"<<endl<<endl;
    cout<<  "Option Meun\n"
        <<  "1.Add Member\n"
        <<  "2.Show Member\n"
        <<  "3.Delete Member\n"
        <<  "4.Search Member\n"
        <<  "5.Modify Member\n"
        <<  "6.Delete All Member\n"
        <<  "7.Exit\n";
}

void f_add()
{
    system("cls");
    Member *newmember = new Member;
    newmember->next = nullptr;
    if(list.head)
    {
        list.tail->next = newmember;
        list.tail = newmember;
    }
    else
    {
        list.head = newmember;
        list.tail = newmember;
    }
    cout<<"Add Member"<<endl;
    cout<<"Please enter the new member's name:";
    cin>>newmember->name;
    // cin.ignore();
    // getline(cin, newmember->name);
    cout<<"Please enter the new member's sex (male / female):";
    string str_sex;
    cin >> str_sex;
    while(true)
    {
        if(str_sex == "male")
        {
            newmember->sex = male;
            break;
        }
        else if(str_sex == "female")
        {
            newmember->sex = female;
            break;
        }
        else
        {
            cout<<"Invalid input. Please enter 'male' or 'female':"<<endl;
            cin >> str_sex;
        }
    }
    cout<<"Please enter the new member's age:";
    cin>>newmember->age;
    cout<<"Please enter the new member's telephone number:";
    cin>>newmember->telephone;
    cout<<"Please enter the new member's address:";
    cin>>newmember->address;
    // cin.ignore();
    // getline(cin, newmember->address);
    cout<<"Add Successfully!"<<endl;
    cout<<"name\tsex\tage\ttelephone\taddress"<<endl;
    cout<<newmember->name<<"\t"<<(newmember->sex ? "female" : "male")<<"\t"<<newmember->age<<"\t"<<newmember->telephone<<"\t"<<newmember->address<<endl;
}

void f_show()
{
    system("cls");
    cout<<"Members List"<<endl;
    Member *ptnode = list.head;
    cout<<"number\tname\tsex\tage\ttelephone\taddress"<<endl;
    int i = 1;
    while(ptnode)
    {
        cout<<i++<<"\t"<<ptnode->name<<"\t"<<(ptnode->sex ? "female" : "male")<<"\t"<<ptnode->age<<"\t"<<ptnode->telephone<<"\t"<<ptnode->address<<endl;
        if(ptnode->next)
        {
            ptnode = ptnode->next;
        }
        else
        {
            break;
        }
    }
}

Member *min_f_search_name(string tar_name)
{
    bool findout = false;
    Member *ptnode = list.head;
    while(ptnode)
    {
        if(ptnode->name == tar_name)
        {
            findout = true;
            break;
        }
        if(ptnode->next)
        {
            ptnode = ptnode->next;
        }
        else
        {
            break;
        }
    }
    if(findout)
    {
        return ptnode;
    }
    else
    {
        return nullptr;
    }
}

void f_delete()
{
    system("cls");
    cout<<"Delete Member"<<endl;
    cout<<"Please enter the target's name:";
    string tar_name;
    cin>>tar_name;
    Member *tar_mem = min_f_search_name(tar_name);
    if(tar_mem)
    {
        if(tar_mem == list.head)
        {   
            if(tar_mem == list.tail)
            {
                delete tar_mem;
                list.head = nullptr;
                list.tail = nullptr;
            }
            else
            {
                list.head = tar_mem->next;
                delete tar_mem;
            }
        }
        else
        {
            Member *father_mem = list.head;
            while(father_mem->next)
            {
                if(father_mem->next == tar_mem)
                {
                    break;
                }
                else
                {
                    father_mem = father_mem->next;
                }
            }
            father_mem->next = tar_mem->next;
            if(tar_mem == list.tail)
            {
                list.tail = father_mem;
            }
            delete tar_mem;
        }
        cout<<"Successfully Delete!"<<endl;
    }
    else
    {
        cout<<"Nonexistent Member"<<endl;
    }
}

void f_search()
{
    system("cls");
    cout<<"Search Member"<<endl;
    cout<<"Please enter the target's name:";
    string tar_name;
    cin>>tar_name;
    Member *tar_mem = min_f_search_name(tar_name);
    if(tar_mem)
    {
        cout<<"name\tsex\tage\ttelephone\taddress"<<endl;
        cout<<tar_mem->name<<"\t"<<(tar_mem->sex ? "female" : "male")<<"\t"<<tar_mem->age<<"\t"<<tar_mem->telephone<<"\t"<<tar_mem->address<<endl;
    }
    else
    {
        cout<<"Nonexistent Member"<<endl;
    }
}

void f_modify()
{
    system("cls");
    cout<<"Modify Member"<<endl;
    cout<<"Please enter the target's name:";
    string tar_name;
    cin>>tar_name;
    Member *tar_mem = min_f_search_name(tar_name);
    if(tar_mem)
    {
        cout<<"Please enter the new member's name:";
        cin>>tar_mem->name;
        cout<<"Please enter the new member's sex (male / female):";
        string str_sex;
        cin >> str_sex;
        while(true)
        {
            if(str_sex == "male")
            {
                tar_mem->sex = male;
                break;
            }
            else if(str_sex == "female")
            {
                tar_mem->sex = female;
                break;
            }
            else
            {
                cout<<"Invalid input. Please enter 'male' or 'female':"<<endl;
                cin >> str_sex;
            }
        }
        cout<<"Please enter the new member's age:";
        cin>>tar_mem->age;
        cout<<"Please enter the new member's telephone number:";
        cin>>tar_mem->telephone;
        cout<<"Please enter the new member's address:";
        cin>>tar_mem->address;
        // cin.ignore();
        // getline(cin, newmember->address);
        cout<<"Modify Successfully!"<<endl;
        cout<<"name\tsex\tage\ttelephone\taddress"<<endl;
        cout<<tar_mem->name<<"\t"<<(tar_mem->sex ? "female" : "male")<<"\t"<<tar_mem->age<<"\t"<<tar_mem->telephone<<"\t"<<tar_mem->address<<endl;
    }
    else
    {
        cout<<"Nonexistent Member"<<endl;
    }
}

void f_delete_all()
{
    system("cls");
    Member *ptmem = list.head;
    Member *de_ptmem = ptmem;
    while(ptmem)
    {
        de_ptmem = ptmem;
        ptmem = ptmem->next;
        delete de_ptmem;
    }
    list.head = nullptr;
    list.tail = nullptr;
    cout<<"Successfully Delete All the Member!"<<endl;
}

void (*f_switch(int option, bool *exit))()
{
    switch(option)
    {
        case 1:
            return f_add;
        case 2:
            return f_show;
        case 3:
            return f_delete;
        case 4:
            return f_search;
        case 5:
            return f_modify;
        case 6:
            return f_delete_all;
        case 7:
            *exit = true;
            return nullptr;
        default:
            cout<<"illegal input!"<<endl;
            return nullptr;
    }
}

int main (void)
{
    bool exit = false;
    while(!exit)
    {
        f_mainpage();
        int option = 0;
        cout<<"please input the number here:";
        cin >> option;
        void (*action)() = f_switch(option, &exit);
        if(action)
        {
            action();
        }
        system("pause");
        system("cls");
    }
    return 0;
}