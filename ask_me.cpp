#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std;

struct Person 
{
    string name;
    string password;
    int id;
};

int main() 
{
    int n;
    
    Person p;

    map<int, string> emp;
    cout << "welcome to my program" << endl << "Enter your choice: " << endl;
    vector<Person> registeredUsers;
    fstream file;
    //vector <string> data_of_user;
    while(cin >> n)
    {
        if(n == 1) // sign up
        {
            std::cin >> p.name >> p.password >> p.id;
            cin.ignore(); // Ignore the newline character after reading the integer
            string path = p.name + ".txt";
            file.open(path.c_str(), ios::in | ios::out | ios::app);
            registeredUsers.push_back(p);
            emp[p.id] = path;
            string data_of_user = "users_data.txt";
            file.open(data_of_user.c_str(), ios::in | ios::out | ios::app);
            file << "user 1 :" << p.id << "      " << p.name << "      " << p.password << endl;
            cout << "User signed up successfully." << endl;
            file.close();
            continue;
        }
        else if(n == 2) // log in
        {
            string name, pass;
            cin >> name >> pass;
            cin.ignore(); // Ignore the newline character after reading the string
            string path = name + ".txt";
            bool userFound = false;
            for(auto user : registeredUsers)
            {
                if(user.name == name && user.password == pass)
                {
                    file.open(path.c_str(), ios::in | ios::out | ios::app);
                    file.close();
                    cout << "Login successful ." << endl;
                    userFound = true;
                    break;
                }
                
            }
            if(!userFound)
            {
                cout << "Invalid username or password." << endl;
                continue;
            }
        }
        else
        {
            cout << "Number is not valid" << endl << "Please choose the correct number" << endl << "1. Sign up" << endl << "2. Log in" << endl;
            continue;
        }

        int choice = 0;
        bool isRunning = true;
        while(isRunning)
        {
            //اللي جاتلي 1
            //اللي بعتها للناس 2
            cout << "1. print questions to me" << endl;
            cout << "2. print questions for me" << endl;
            cout << "3. answer questions" << endl;
            cout << "4. Delete question" << endl;
            cout << "5. Ask question" << endl;
            cout << "6. list system users" << endl;
            cout << "7. feed" << endl;
            cout << "8. log out" << endl;

            cin >> choice;
            string line;
            switch(isRunning = true, choice)
            {
                case 1:
                      int id_ans;
                      cin >> id_ans;
                      for(auto it = emp.begin(); it != emp.end(); ++it)
                        {
                            if(it->first == id_ans)
                            {
                               file.open(it->second.c_str(), ios::in | ios::out | ios::app);
                                while(getline(file, line))
                                {
                                    cout << line << endl;
                                }
                            }
                            file.close();
                        }
                    break;

                case 2:
                        int other_id;
                        cin >> other_id;
                        for(auto it = emp.begin(); it != emp.end(); ++it)
                        {
                            if(it->first != other_id)
                            {
                                file.open(it->second.c_str(), ios::in);
                                while(getline(file, line))
                                {
                                    cout << line << endl;
                                }
                            }
                            file.close();
                        }
                    break;

                case 3:
                    cout << "Enter id for question you need to reply it: " << endl;
                    int replyId;
                    cin >> replyId;
                    cin.ignore();       
                    for(auto it = emp.begin(); it != emp.end(); ++it)
                    {
                        if(it->first == replyId)
                        {
                            string ans;
                            getline(cin, ans);
                            string path = it->second;// + "/n" + line + ".";    
                            file.open(path.c_str(), ios::in | ios::out | ios::app);   
                            file << ans << "." << endl;                            
                        }
                        file.close();
                    }                    
                    break;

                case 4:
                    
                    int delet_Id;
                    cin >> delet_Id;       
                    for(auto it = emp.begin(); it != emp.end(); ++it)
                    {
                        if(it->first == delet_Id)
                        {
                            file.open(it->second.c_str(), ios::in | ios::out | ios::app); 
                            file.clear();
                            file.seekg(0, ios::beg);
                        }
                        file.close();
                    }
                    break;

                case 5:
                        cout << "Enter id for question you need to reply it: " << endl;
                        int Id;
                        cin >> Id;
                        cin.ignore();
                        for(auto it = emp.begin(); it != emp.end(); ++it)
                        {
                            if(it->first == Id)
                            {
                                string question;
                                //cin.ignore();
                                getline(cin, question);
                                string path = it->second ;//+ "/n" + line + "?";                                
                                file.open(path.c_str(), ios::in | ios::out | ios::app);    
                                file << question << "?" << endl;                           
                            }
                            file.close();
                        }
                    
                    
                    break;

                case 6:
                
                        for(auto it = emp.begin(); it != emp.end(); ++it)
                        {
                            file.open(it->second.c_str(), ios::in | ios::out | ios::app);
                            cout << "User ID: " << it->first << ", File Path: " << it->second << endl;
                            file.close();
                        }
                        break;

                case 7:

                        for(auto it = emp.begin(); it != emp.end(); ++it)
                        {
                            file.open(it->second.c_str(), ios::in | ios::out | ios::app);
                            string  savedQuestion;
                            line = it->second;
                            while(getline(file, line))
                            {
                                if (!line.empty() && line.back() == '\r') 
                                {
                                    line.pop_back();
                                }
                                if (line.empty()) 
                                {
                                    continue;
                                }
                                if(line.back() == '?') 
                                {
                                    savedQuestion = line;
                                }
                                else if(line.back() == '.' && !savedQuestion.empty()) 
                                {
                                    cout << savedQuestion << endl;
                                    cout << line << endl;
                                }                                
                            }
                            file.close();
                            line.clear();
                        
                        }
                    break;
                  /**/  

                case 8:
                    cout << "log out successfully." << endl;
                    isRunning = false;
                    file.clear();
                    file.close();
                    break;

                default:
                    cout << "Invalid choice choose a valid option from 1 to 8 from the menu" << endl;
                    break;
            }
        }
    
    }
    return 0;
}