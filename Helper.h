
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
class Helper
{

private:
    string acc_no, name, adress, pin, dob;
    double open_amt = 0;

public:
    void menu()
    {
        int choice;
        do
        {

            cout << "\t\t\t\t\t||Click 1 for Open Account          ||" << endl;
            cout << "\t\t\t\t\t||Click 2 for Balance Enquiry       ||" << endl;
            cout << "\t\t\t\t\t||Click 3 for Deposit Money         ||" << endl;
            cout << "\t\t\t\t\t||Click 4 for WidthDrawl            ||" << endl;
            cout << "\t\t\t\t\t||Click 5 for Show all Account      ||" << endl;
            cout << "\t\t\t\t\t||Click 6  for close an Account     ||" << endl;
            cout << "\t\t\t\t\t||Click 7 for Quit                  ||" << endl;
            cout << "\t\t\t\t\t||enter your Choice                  :";
            cin >> choice;

            if (choice == 1)
            {
                openAccount();
            }
            else if (choice == 2)
            {
                string ac_n;
                cout << "\t\t\t\t\tEnter Account-No to Check Balance Enquiry:";
                cin >> ac_n;
                double bal = bal_check(ac_n);
                if (bal != 0)
                {
                    cout << "\t\t\t\t\tAvailable Balance:" << bal << endl;
                }
            }
            else if (choice == 3)
            {
                deposit_money();
            }
            else if (choice == 4)
            {
                widthrawl_bal();
            }
            else if (choice == 5)
            {
                 show_all_acc();
            }
            else if (choice == 6)
            {
                delete_acc();
            }
            else if (choice == 7)
            {
                 cout << "\t\t\t\t\t Thank You For Using Digital Banking... :\n";
            }
            else{
                cout << "\t\t\t\t\t INVALID INPUT ... :\n";
            }

        } while (choice != 7);
    }

    // starting of opening account
    void openAccount()
    {
        cout << "\t\t\t\t\t||enter your name||:";
        cin >> name;
        cout << "\t\t\t\t\t||enter your adress||:";
        cin >> adress;
        cout << "\t\t\t\t\t||enter your dob||:";
        cin >> dob;
        cout << "\t\t\t\t\t||enter opening Amount||:";
        cin >> open_amt;
        int x = (rand() % 900) + 100;
        acc_no = "BK" + to_string(x);

        pin = dob;
        //  cout<<acc_no<<endl;
        fstream data;
        int token = 0;
        data.open("database.txt", ios::in | ios::app);
        if (!data)
        {

            fstream data1;
            data1.open("database.txt", ios::in);
            data1 << acc_no << "\t\t\t\t\t\t" << name << "\t\t\t\t\t\t" << adress << "\t\t\t\t\t\t" << dob << "\t\t\t\t\t\t" << open_amt << "\t\t\t\t\t\t" << pin << endl;
            cout << "Data Inserted..." << endl;
        }

        else
        {
            data << acc_no << "\t\t\t\t\t\t" << name << "\t\t\t\t\t\t" << adress << "\t\t\t\t\t\t" << dob << "\t\t\t\t\t\t" << open_amt << "\t\t\t\t\t\t" << pin << endl;
            cout << "Data Inserted..." << endl;
        }
    }

    // ending of opening Account
    double bal_check(string acc)
    {
        string an, n, ad, b, amt, p, check_pin;
        fstream data3;
        int c = 0;
        double avl_bal = 0;
        // fstream data2;
        data3.open("database.txt", ios::in);
        data3 >> an >> n >> ad >> b >> amt >> p;
        // cout<<an<<endl;

        // FIRST SCANNING ALL DATA FOR SEARCH OF ACC-NO
        while (!data3.eof())
        {
            // cout<<an<<endl;

            // MATCHING ACCOUNT NO TO THE DATA FETCH DATA FROM DATABASE
            if (an == acc)
            {
            m:
                cout << "\t\t\t\t\tEnter Your Pin..:";
                cin >> check_pin;

                // MATCHING PIN NO TO THE  RESPECTIVE ACCOUNT DATA FETCH DATA FROM DATABASE

                if (check_pin == pin)
                {
                    avl_bal = stod(amt);
                    ;
                    c++;
                    break;
                }
                else
                {
                    cout << "\t\t\t\t\tPlease Enter Correct Pin" << endl;
                    goto m;
                }
            }
            data3 >> an >> n >> ad >> b >> amt >> p;
        }
        // cout<<c<<endl;
        if (c == 1)
        {
            return avl_bal;
        }
        else
        {
            cout << "\t\t\t\t\tAccount Doesn't Exist..." << endl;
            return 0.0;
        }
    }

    // deposit money method
    /*
    FOR DEPOSIT MONEY WE NEED TO CHECK THE ACCOUNT NO AND IF ACCOUNT NO DOESNT MATCH THEN WE TRANSFER THE DATA FROM ONE DATABASE TO 
    ONOTHER DATABASE AND IF THE DATA MATCHED THEN WE NEED TO ADD THE AMT AND ADD THIS DATA TO THE NEW DATABASE AND THE AT THE END WE NEED 
    TO REMOVE OLD DATABASE AND RENAME TO NEW DATABASE TO OLD ONE
    */

    void deposit_money()
    {
        string a_n;
        double d_a;
        bool found = false;
        cout << "\t\t\t\t\tPlease Enter Account Number :";
        cin >> a_n;
        cout << "\t\t\t\t\t Enter Amount :";
        cin >> d_a;
        string an, n, ad, b, amt, p;
        fstream data3, d_data;
        data3.open("database.txt");
        d_data.open("database1.txt", ios::app | ios::out);

        // for storing all data to check the account no is matching or not
        data3 >> an >> n >> ad >> b >> amt >> p;

        while (!data3.eof())
        {

            // cout<<an<<" "<<n<<" "<<ad<<" "<<b<<" "<<amt<<" "<<p<<endl;
            if (a_n == an)
            {
                double total = stod(amt) + d_a;

                d_data << an << "\t\t\t\t\t\t" << n << "\t\t\t\t\t\t" << ad << "\t\t\t\t\t\t" << b << "\t\t\t\t\t\t" << total << "\t\t\t\t\t\t" << p << endl;
                found = true;
                //    cout<<"Total Balance : "<<amt<<endl;
                //    break;
            }
            else
            {
                d_data << an << "\t\t\t\t\t\t" << n << "\t\t\t\t\t\t" << ad << "\t\t\t\t\t\t" << b << "\t\t\t\t\t\t" << amt << "\t\t\t\t\t\t" << p << endl;
            }

            data3 >> an >> n >> ad >> b >> amt >> p;
        }

        data3.close();
        d_data.close();
        // finally remove old file and rename new file to old file
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (!found)
        {
            cout << "\t\t\t\t\t Account Doesn't Exist... :";
        }
        else
        {
            cout << "\t\t\t\t\t Money Deposited... :";
        }
    }



    // for widthrawl
    void  widthrawl_bal(){
         string a_n;
        double d_a;
        bool found = false;
        cout << "\t\t\t\t\tPlease Enter Account Number :";
        cin >> a_n;
        cout << "\t\t\t\t\t Enter Amount for Widthdrawl :";
        cin >> d_a;
        string an, n, ad, b, amt, p;
        fstream data3, d_data;
        data3.open("database.txt");
        d_data.open("database1.txt", ios::app | ios::out);

        // for storing all data to check the account no is matching or not
        data3 >> an >> n >> ad >> b >> amt >> p;
        bool insuf_bal=false;
        while (!data3.eof())
        {

            // cout<<an<<" "<<n<<" "<<ad<<" "<<b<<" "<<amt<<" "<<p<<endl;
        
            if (a_n == an)
            {
              
            //   if amt is greater than the widthrawl amt value will be updated else same value is passed to the database 
                if(stod(amt) > d_a){

                
               
                double total = stod(amt) - d_a;

                d_data << an << "\t\t\t\t\t\t" << n << "\t\t\t\t\t\t" << ad << "\t\t\t\t\t\t" << b << "\t\t\t\t\t\t" << total << "\t\t\t\t\t\t" << p << endl;
                found = true;
                }

                else{
                     cout << "\t\t\t\t\t Insufficient Balnce...";
                     d_data << an << "\t\t\t\t\t\t" << n << "\t\t\t\t\t\t" << ad << "\t\t\t\t\t\t" << b << "\t\t\t\t\t\t" << amt << "\t\t\t\t\t\t" << p << endl;
                     found = true;

                     insuf_bal=true;
                }
                //    cout<<"Total Balance : "<<amt<<endl;
                //    break;
           

          
            }
           
            else
            {
                d_data << an << "\t\t\t\t\t\t" << n << "\t\t\t\t\t\t" << ad << "\t\t\t\t\t\t" << b << "\t\t\t\t\t\t" << amt << "\t\t\t\t\t\t" << p << endl;
            }

            data3 >> an >> n >> ad >> b >> amt >> p;
        
    }

        data3.close();
        d_data.close();
        // finally remove old file and rename new file to old file
       
        if (!found)
        {
            cout << "\t\t\t\t\t Account Doesn't Exist... :";
        }
        else
        {
            remove("database.txt");
            rename("database1.txt", "database.txt");

            if(!insuf_bal){
            cout << "\t\t\t\t\t Money Widthraw Succesfully... :";
            }
           
        }
        
    }

//for show all account
void show_all_acc(){
      string an, n, ad, b, amt, p;
        fstream data;
        data.open("database.txt");
         data >> an >> n >> ad >> b >> amt >> p;
                cout << "Account Number \t\t\t\t\t\t" <<"Name" << "\t\t\t\t\t\t" << "Address"<< "\t\t\t\t\t\t" << "DOB" << "\t\t\t\t\t\t" << "Balance" << "\t\t\t\t\t\t" << "Pin"<< endl;
        while (!data.eof())
        {
                cout << an << "\t\t\t\t\t\t" << n << "\t\t\t\t\t\t" << ad << "\t\t\t\t\t\t" << b << "\t\t\t\t\t\t" << amt << "\t\t\t\t\t\t" << p<< endl;
                 data >> an >> n >> ad >> b >> amt >> p;
       
        }

}

void delete_acc(){


 string a_n;
        double d_a;
        bool found = false;
        cout << "\t\t\t\t\tPlease Enter Account Number for Delete the Account:";
        cin >> a_n;
        string an, n, ad, b, amt, p;
        fstream data3, d_data;
        data3.open("database.txt");
        d_data.open("database1.txt", ios::app | ios::out);

        // for storing all data to check the account no is matching or not
        data3 >> an >> n >> ad >> b >> amt >> p;

        while (!data3.eof())
        {

            // cout<<an<<" "<<n<<" "<<ad<<" "<<b<<" "<<amt<<" "<<p<<endl;
            if (a_n == an)
            {
               
                found = true;
              
            }
            else
            {
                d_data << an << "\t\t\t\t\t\t" << n << "\t\t\t\t\t\t" << ad << "\t\t\t\t\t\t" << b << "\t\t\t\t\t\t" << amt << "\t\t\t\t\t\t" << p << endl;
            }

            data3 >> an >> n >> ad >> b >> amt >> p;
        }

        data3.close();
        d_data.close();
        // finally remove old file and rename new file to old file
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (!found)
        {
            cout << "\t\t\t\t\t Account Doesn't Exist... :\n";
        }
        else
        {
            cout << "\t\t\t\t\t Account Deleted.. :\n";
        }



}

};
