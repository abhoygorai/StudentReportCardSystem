#include <bits/stdc++.h>
#include <fstream>
#include <dirent.h>
#include <sstream>

using namespace std;

bool isExist(string check)
{
    DIR *directory;
    struct dirent *x;
    if ((directory = opendir("data\\")) != NULL)
    {
        while ((x = readdir(directory)) != NULL)
        {
            if (check == x->d_name)
            {
                return true;
            }
        }
    }
    closedir(directory);
    return false;
}

void calculate()
{
    int a, b;
    cout << "Enter 2 elements: ";
    cin >> a >> b;
    cout << "Sum = " << a + b << endl
         << endl;
}

int main()
{
    cout << endl
         << "This is a Login and Registration system" << endl;
    int d;
    while (d != 3)
    {
        cout << "---------------" << endl
             << "1. Fetch Details" << endl
             << "2. Register" << endl
             << "3. Exit" << endl
             << "---------------" << endl
             << endl;
        cin >> d;
        switch (d)
        {
        case 1:
        {
            string name, roll;
            string math, eng, phy, comp;

            cout << "Enter your Roll Number: ";
            cin >> roll;

            if (!isExist(roll + ".txt"))
            {
                cout << "No records found" << endl
                     << endl;
                break;
            }

            ifstream read("data\\" + roll + ".txt");

            getline(read, name);
            getline(read, math);
            getline(read, eng);
            getline(read, phy);
            getline(read, comp);

            stringstream math_o(math);
            int math_i = 0;
            math_o>>math_i;
            stringstream eng_o(eng);
            int eng_i = 0;
            eng_o>>eng_i;
            stringstream phy_o(phy);
            int phy_i = 0;
            phy_o>>phy_i;
            stringstream comp_o(comp);
            int comp_i = 0;
            comp_o>>comp_i;

            int total=math_i + eng_i + phy_i + comp_i;

            float percent = (math_i + eng_i + phy_i + comp_i)/4.0;

            cout<<endl<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\tName: "<<name<<endl<<endl
                <<"\t\t\tRoll: "<<roll<<endl<<endl
                <<"Math: \t\t\t\t\t\t\t\t"<<math_i<<endl 
                <<"English: \t\t\t\t\t\t\t"<<eng_i<<endl 
                <<"Physics: \t\t\t\t\t\t\t"<<phy_i<<endl 
                <<"Computer: \t\t\t\t\t\t\t"<<comp_i<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t    --------"<<endl
                <<"Total: \t\t\t\t\t\t\t\t"<<total<<endl
                <<"Percentage: \t\t\t\t\t\t\t"<<percent<< " %" <<endl;

                if(percent > 33)
                    cout<<"\t\t\t\t\t\t\tStatus: Pass"<<endl;
                else
                    cout<<"\t\t\t\t\t\t\tStatus: Fail"<<endl;
            cout<<"--------------------------------------------------------------------------"<<endl;
            
            break;
        }
        case 2:
        {
            cout << "\t\t\tWelcome to Registration system" << endl
                 << endl;

            string name,surname, roll;
            ofstream file;
            int math=0, eng=0, phy=0, comp=0;

            cout << "Enter your Roll Number: ";
            cin >> roll;

            if (isExist(roll + ".txt"))
            {
                cout << endl
                     << "Already registered" << endl
                     << endl;
            }
            else
            {
                cout << "Enter you name: ";
                cin>>name>>surname;
                

                cout<<"Enter Maths marks: ";
                cin>>math;
                cout<<"Enter Eng marks: ";
                cin>>eng;
                cout<<"Enter Phy marks: ";
                cin>>phy;
                cout<<"Enter Comp marks: ";
                cin>>comp;

                file.open("data//" + roll + ".txt");
                file << name <<" "<<surname<< endl;
                file << math <<endl;
                file << eng <<endl;
                file << phy <<endl;
                file << comp <<endl;
                cout << endl
                     << "Succesfully Registered" << endl
                     << endl;
            }
            break;
        }
        default:
        {
            cout << endl
                 << "Invalid entry" << endl
                 << endl;
            break;
        }
        }
    }

    return 0;
}