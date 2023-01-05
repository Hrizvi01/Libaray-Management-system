#include <iostream>
#include <vector>
using namespace std;
struct node
{
    node* next;
    int ISSN;
    string title_name;
    string auther_name;
    int no_of_ref;
    int no_of_issu;
    node()
    {
        this->ISSN = -1;
        this->auther_name = this->title_name = "";
        this->no_of_issu = this->no_of_ref = 0;
        this->next = nullptr;
    }
    node(int ISSN, string t_name, string a_name, int ref, int issu)
    {
        this->ISSN = ISSN;
        this->auther_name = a_name;
        this->title_name = t_name;
        this->no_of_issu = issu;
        this->no_of_ref = ref;
        this->next = nullptr;
    }
};
// Making a Hash Table of 11....
class Library_Management_System
{
    vector<node*> v;
    int Hash = 11;
    void show_record(node* n)
    {
        if (n || n->ISSN != -1)
        {
            cout <<"ISSN: "<< n->ISSN << endl;
            cout << "Title: "<<n->title_name << endl;
            cout << "Author Name: "<<n->auther_name << endl;
            cout << "Number of reference books: " << n->no_of_ref<<endl;
            cout<< "Number of issuable books: " << n->no_of_issu << endl;
        }
    }
    void update_record(node* n)
    {
        cout << "Enter 1 to Change Name of Book: \n";
        cout << "Enter 2 to Change Auther Name: \n";
        cout << "Enter 3 to Change Reference Number: \n";
        cout << "Enter 4 to Change Issuable Number: \n";
        int i = 0;
        cin >> i;
        switch (i)
        {
        case 1:
            cout << "Enter New Name of Book: ";
            n->title_name = "";
            cin >> (n->title_name);
            break;
        case 2:
            cout << "Enter New Name of Auther: ";
            n->auther_name = "";
            cin >> (n->auther_name);
            break;
        case 3:
            cout << "Enter New Ref Number: ";
            cin >> n->no_of_ref;
            break;
        case 4:
            cout << "Enter New Issuance Number: ";
            cin >> n->no_of_issu;
            break;
        default:
            cout << "Error Input\n";
        }
    }
public:
    Library_Management_System()
    {
        v.reserve(11);
        for (int i = 0; i < Hash; i++)
            v.push_back(new node());
    }
    int get_Hash(int i)
    {
        return (i % Hash);
    }
    void AddBook(int ISSN, string t_name, string a_name, int ref, int issu)
    {
        node* n = new node(ISSN, t_name, a_name, ref, issu);
        int i = get_Hash(ISSN);
        if (v[i]->next == NULL)
        {
            v[i]->next = n;
            return;
        }
        node* t = v[i]->next;
        while (t->next != nullptr)
        {
            if (t->next->ISSN == -999)
                break;
            t = t->next;
        }
        t->next = n;
    }
    void ShowRecord(int ISSN)
    {
        int i = get_Hash(ISSN);
        node* n = v[i]->next;
        node* t = nullptr;
        bool flag = false;
        while (n != nullptr)
        {
            if (n->ISSN == ISSN)
            {
                t = n;
                flag = true;
                break;
            }
            n = n->next;
        }
        if (!flag)
            cout << "Not Found Record\n";
        else
            show_record(t);
    }

    void UpdateRecord(int ISSN)
    {
        int i = get_Hash(ISSN);
        node* n = v[i]->next;
        bool flag = false;
        while (n)
        {
            if (n->ISSN == ISSN)
            {
                update_record(n);
                flag = true;
                break;
            }
            n = n->next;
        }
        if (!flag)
            cout << "NO Record Found\n";
    }
    void DeleteRecord(int ISSN)
    {
        int i = get_Hash(ISSN);
        node* n = v[i]->next;
        bool flag = false;
        while (n != nullptr)
        {
            if (n->ISSN == ISSN)
            {
                n->ISSN = -999;
                n = n->next;
                flag = true;
                break;
            }
            n = n->next;
        }
        if (!flag)
        {
            cout << "_________\n";
            cout << "Record not Found\n";
            cout << "_________\n";
        }
        else
        {
            cout << "_________\n";
            cout << "Deleted Successfully\n";
            cout << "_________\n";
        }
    }
};
int main()
{
    Library_Management_System* lib = new Library_Management_System();
    int p,choice,c;
    cout << "--------------------------------------------------------------------------------------\n";
    cout << "|                       Welcome to library management system                         |\n";
    cout << "--------------------------------------------------------------------------------------\n";
   
    lib->AddBook(123, "C++", "Maarij", 12, 97);
    lib->AddBook(854, "Calculus", "Ali", 748, 933);
    lib->AddBook(562, "Maths", "asdf", 8, 33);
    lib->AddBook(463, "Physics", "chaudhary", 74, 9);
    lib->ShowRecord(123);
    cout << "_________\n";
    lib->ShowRecord(854);
    cout << "_________\n";
    lib->ShowRecord(562);
    cout << "_________\n";
    lib->ShowRecord(463);
    cout << "_________\n";
    cout << "Enter 1 to proceed: \n";
    cin >> p;
    if (p == 1) {
        system("CLS");
    cout << "Enter 1 if you want to update: \n";
    cout << "Enter 2 if you want to remove: \n";
    cout << "Enter 3 if you want to search: \n";
    cin >> choice;
    if (1)
    {

        if (choice == 1)
        {
            system("CLS");
            cout << "Books having following ISSN numbers are available in library: \n";
            cout << "(123,854,562,463)\n";
            cout << "Enter ISSN number of the book,which you want to update: \n";
            cin >> c;
            cout << "_________\n";
            lib->ShowRecord(c);
            cout << "_________\n";
            lib->UpdateRecord(c);
            cout << "after upgradation: \n";
            cout << "_________\n";
            lib->ShowRecord(c);
            cout << "_________\n";
            cout << "Enter 2 if you want to remove: \n";
            cout << "Enter 3 if you want to search: \n";
            cin >> choice;
        }
        if (choice == 2)
        {
            system("CLS");
            cout << "Books having following ISSN numbers are available in library: \n";
            cout << "(123,854,562,463)\n";
            cout << "Enter ISSN number of the book,which you want to delete: \n";
            cin >> c;
            cout << "_________\n";
            lib->ShowRecord(c);
            cout << "_________\n";
            lib->DeleteRecord(c);
            cout << "Enter 3 if you want to search: \n";
            cin >> choice;
        }
        if (choice == 3) {
            system("CLS");
            cout << "Books having following ISSN numbers are available in library: \n";
            cout << "(123,854,562,463)\n";
            cout << "Enter ISSN number of the book,which you want to search: \n";
            cin >> c;
            cout << "_________\n";
            lib->ShowRecord(c);
            cout << "_________\n";
        }
    }

    }
    system("pause");
    return 0;
}
