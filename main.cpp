#include <iostream>
#include <string>
using namespace std;

int main() {
    string titles[20]={"The C++ Basics","Data Structures in Depth","Algorithms for Beginners","Clean Code","Computer Networks","Operating Systems","Database Fundamentals","Python Programming","Java for Everyone","Artificial Intelligence","Machine Learning Essentials","Deep Learning Intro","Cloud Computing","The Power of Now","A New Earth","Linear Algebra","Designing Your Life","Modern Physics","Digital Logic","Embedded Systems"};

    bool available[20]={true,true,false,true,true,false,true,false,true,true,true,false,true,true,true,true,true,true,false,false};

    int ch=1;
    while(ch!=5)
    {
        cout<<"\n===== Library Book Manager =====\n";
        cout<<"1. List all books\n";
        cout<<"2. Search for a book by title\n";
        cout<<"3. Borrow a book\n";
        cout<<"4. Return a book\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        cout<<"\n";
        //1-LIST ALL BOOKS
        if(ch==1)
        {
            cout<<"Index\tTitle\t\t\t\tStatus\n";
            for(int i=0; i<20; i++)
            {
                cout<<i<<"\t"<<titles[i];
                int len=titles[i].length();

                if(len<16)
                        cout<<"\t\t\t";
                else if(len<24)
                        cout<<"\t\t";
                else if(len<32)
                        cout<<"\t";

                if(available[i])
                    cout<<"Available\n";
                else
                    cout<<"Not Available\n";
            }
        }
        //2-SEARCH for a BOOK
        else if(ch==2)
        {
            string searchTitle;
            cout<<"Enter book title to search: ";
            cin.ignore();
            getline(cin, searchTitle);

            bool x=false;
            for(int i=0; i<20; i++)
            {
                if(titles[i]==searchTitle)
                {
                    cout<<"Book found at index "<<i<<"\n";
                    cout<<"Title: "<<titles[i]<<"\n";
                    cout<<"Status: ";
                    if(available[i])
                       cout<<"Available\n";
                    else
                        cout<<"Not Available\n";
                    x=true;
                    break;
                }
            }
            if(x==false)
                cout<<"Book not found.\n";
        }
        //3-BORROW BOOK
        else if(ch==3)
        {
            int index;
            cout<<"Enter book index to borrow: ";
            cin>>index;

            if(index<0 || index >= 20)
            {
                cout<<"Invalid index.\n";
            }
            else if(available[index]==false)
            {
                cout<<"Book is already borrowed.\n";
            }
            else
            {
                available[index]=false;
                cout<<"You have borrowed: "<<titles[index]<<"\n";
            }
        }
        //4-RETURN BOOK
        else if(ch==4)
        {
            int index;
            cout<<"Enter book index to return: ";
            cin>>index;

            if(index<0 || index >= 20)
            {
                cout<<"Invalid index.\n";
            }
            else if(available[index])
            {
                cout<<"This book is not borrowed.\n";
            }
            else
            {
                available[index]=true;
                cout<<"You have returned: "<<titles[index]<<"\n";
            }
        }

        else if(ch==5)
        {
            cout<<"Goodbye!\n";
        }

        else
        {
            cout<<"Invalid choice. Try again.\n";
        }
    }
    return 0;
}
