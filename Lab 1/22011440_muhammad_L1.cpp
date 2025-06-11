#include <iostream>
using namespace std; 
    struct Student{
    
        int Id;
        string name;
        int contact;
        string email;
    
    };
    
int main() {
    int num_Students= 5;
    Student students[num_Students];
    
    int i= 0;
    
    for(int i=0;i<num_Students;i++){;
        cout<<"Students Id: ";
        cin>>students[i].Id;
        cout<<"Students Name: ";
        cin>>students[i].name;
        cout<<"Students Contact: ";
        cin>>students[i].contact;
        cout<<"Students Email: ";
        cin>>students[i].email;
        cout<<endl;
    }
    
    cout<<"==== Students Data Entered ===="<<endl;
    
    for(int i=0;i<num_Students;i++){
        cout<<"Students"<< (i + 1)<<":\n";
        cout << "ID: " << students[i].Id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Contact: " << students[i].contact << endl;
        cout << "Email: " << students[i].email << endl;
        cout << endl;
    }
    return 0;
}
