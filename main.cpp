#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out("BAZA_OF_CARD.TXT",std::ios::app);
    const int size = 4;
    int arr[size];
    int number_counter = 0;
    bool flag = false;
    int k = 0;
    int help_number = 0;
    int help_arr_to_write[size];

    bool stop_flag = 1;
    int counter = 0;
    while(stop_flag == true)
    {

        cout<<"Hello our customer ,can you write your credit card and our computer program check her(for example 1234 5678 8974 4324) "<<endl;

        for(int i=0; i<size; i++)
        {
            cin>>arr[i];
            k = arr[i];
            help_number = arr[i];
            help_arr_to_write[i] = arr[i];
            while(k>=1)
            {
                k = help_number;
                help_number = help_number/10;
                number_counter++;
            }

            if(number_counter-1 < 4  || number_counter-1 > 4)
            {
               flag = true;
            }

            number_counter = 0;
        }

        if(flag == true)
        {
            cout<<"Error ,false number card "<<endl;
            break;
        }

        cout<<"Your card is ";

        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        int help_number = 0;
        int tmp = arr[0];

        while(tmp != 0)
        {
            help_number = tmp % 10;
            tmp = tmp / 10;
        }

        if(help_number == 4)
        {
            cout<<"You have Visa card "<<endl;
        }
        else if(help_number == 5)
        {
            cout<<"You have MasterCard "<<endl;
        }
        else
        {
            cout<<"You have another card "<<endl;
        }

        int composition = 0;
        int sum_composition = 0;

        for(int i=0; i<size; i = i+2)
        {
            composition = arr[i] * 2;
            if(composition > 9)
            {
                composition = composition - 9;
                arr[i] = composition;
            }
            else
            {
                arr[i] = composition;
            }
        }

        int all_sum = 0;

        for(int i=0; i<size; i++)
        {
            all_sum = all_sum + arr[i];
        }

        if(all_sum % 10 == 0)
        {
            cout<<"You have good card. We write her in our system file"<<endl;

            for(int i=0; i<size; i++)
            {
                if(i<size - 1)
                {
                    out<<help_arr_to_write[i]<<" ";
                }
                else
                {
                    out<<help_arr_to_write[i];
                }

            }

            out<<endl;
        }
        else
        {
            cout<<"Error ,you have false card "<<endl;
        }

        cout<<"Do you want enter another card? If yes ,enter 1 ,else enter 0 "<<endl;
        cin>>stop_flag;

    }

    cout<<"Write to file...."<<endl;
    cout<<"Done"<<endl;

    out.close();


    return 0;
}
