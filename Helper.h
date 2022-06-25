
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
class Helper{

     private:
        string acc_no,name,adress,pin,dob;
        double open_amt=0;
     public:
        void menu(){
            int choice;
            do{
               
                cout<<"\t\t\t\t\t||Click 1 for Open Account\t\t\t\t\t||"<<endl;
                cout<<"\t\t\t\t\t||Click 2 for Balance Enquiry       ||"<<endl;
                cout<<"\t\t\t\t\t||Click 3 for Deposit Money         ||"<<endl;
                cout<<"\t\t\t\t\t||Click 4 for WidthDrawl            ||"<<endl;
                cout<<"\t\t\t\t\t||Click 5 for close An Account      ||"<<endl;
                cout<<"\t\t\t\t\t||Click 6 for Show all Account      ||"<<endl;
                cout<<"\t\t\t\t\t||Click 7 for Quit                  ||"<<endl;
                cout<<"\t\t\t\t\t||enter your Choice                  :";
                cin>>choice;

                if (choice==1)
                {
                    openAccount();
                }
                else if(choice==2){
                string ac_n;
                cout<<"\t\t\t\t\tEnter Account-No to Check Balance Enquiry:";
                cin>>ac_n;
                 double bal= bal_check(ac_n);
                 if (bal!=0)
                 {
                     cout<<"\t\t\t\t\tAvailable Balance:"<<bal<<endl;
                 }
                 
               
                }
                else if(choice==3){

                }
                else if(choice==4){

                }
                else if(choice==5){

                }
                else if(choice==6){

                }
                else if(choice==7){

                }

                




            }while(choice!=7);

        } 


//starting of opening account 
        void openAccount(){
                cout<<"\t\t\t\t\t||enter your name||:";
                cin>>name;
                cout<<"\t\t\t\t\t||enter your adress||:";
                cin>>adress;
                cout<<"\t\t\t\t\t||enter your dob||:";
                cin>>dob;
                cout<<"\t\t\t\t\t||enter opening Amount||:";
                cin>>open_amt;
                 int x= (rand()% 900 )+ 100 ;
                 acc_no="BK"+to_string(x);

                 pin=dob;
               //  cout<<acc_no<<endl;
                fstream data;
                int token=0;
                data.open("database.txt",ios::in|ios::app);
                if(!data){

                    fstream data1;
                     data1.open("database.txt",ios::in);
                     data1<<acc_no<<"\t\t\t\t\t\t"<<name<<"\t\t\t\t\t\t"<<adress<<"\t\t\t\t\t\t"<<dob<<"\t\t\t\t\t\t"<<open_amt<<"\t\t\t\t\t\t"<<pin<<endl;
                     cout<<"Data Inserted..."<<endl;
                }

                else{ 
                    data<<acc_no<<"\t\t\t\t\t\t"<<name<<"\t\t\t\t\t\t"<<adress<<"\t\t\t\t\t\t"<<dob<<"\t\t\t\t\t\t"<<open_amt<<"\t\t\t\t\t\t"<<pin<<endl;
                    cout<<"Data Inserted..."<<endl;
                   
                }
               
                   

        }  

//ending of opening Account
        double bal_check(string acc){
            string an,n,ad,b,amt;
            fstream data3;
            int c=0;
            double avl_bal=0;
            // fstream data2;
            data3.open("database.txt",ios::in);
            data3>>an>>n>>ad>>b>>amt;
            // cout<<an<<endl;
            while (!data3.eof())
            {
                // cout<<an<<endl;
              if (an==acc)
              {
               
               avl_bal=stod(amt);;
               c++;
               break;
              }
              data3>>an>>n>>ad>>b>>amt;
            }
            // cout<<c<<endl;
            if (c==1)
            {
              return avl_bal;
            }
            else
            {
                cout<<"Account Doesn't Exist..."<<endl;
                return 0.0;
            }
            
            

        }









};