#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int M = 100;
    char* ps;
    char c;
    int n = 0;

    while (c=cin.get())
    {
        if (c!='\n')
        {
            n++;
            if (n==1)
            {
                ps = new char[n+1];
                ps[0] = c;
                ps[1] = '\0';
            }
            else
            {
                char* str_curr = new char [n+1];
                strcpy(str_curr, ps);
                str_curr[n-1] = c;
                str_curr[n]='\0';
                delete [] ps;
                ps = nullptr;
                ps = new char [n];
                strcpy(ps, str_curr);
                delete [] str_curr;
                str_curr=nullptr;
            }
        }
        else break;
    }
    if (n>M) {
        cout<<"Слишком много чисел (больше " << M << " )"<<endl; return -2;
    }

    int leng =1;
    for (int i =0; i< n; i++)
    {
        switch (ps[i])
        {
        case '0':
            leng+=4; ///zero
            break;
        case '1':
            leng+=3; ///one
            break;
        case '2':
            leng+=3; ///two
            break;
        case '3':
            leng+=5; ///three
            break;
        case '4':
            leng+=4; ///four
            break;
        case '5':
            leng+=4; ///five
            break;
        case '6':
            leng+=3; ///six
            break;
        case '7':
            leng+=5; ///seven
            break;
        case '8':
            leng+=5; ///eight
            break;
        case '9':
            leng+=4; ///nine
            break;
        }
    }
    char slova[11][6] {{"Zero"}, {"One"}, {"Two"}, {"Three"}, {"Four"}, {"Five"}, {"Six"}, {"Seven"}, {"Eight"}, {"Nine"}};
    ///cout << leng << "  " << slova[3]<<endl;
    char* curr_str = new char [leng];
    for (int i =0; i< n; i++)
    {
        switch (ps[i])
        {
        case '0':
            strcat(curr_str, slova[0]); ///zero
            break;
        case '1':
            strcat(curr_str, slova[1]); ///one
            break;
        case '2':
            strcat(curr_str, slova[2]); ///two
            break;
        case '3':
            strcat(curr_str, slova[3]); ///three
            break;
        case '4':
            strcat(curr_str, slova[4]); ///four
            break;
        case '5':
            strcat(curr_str, slova[5]); ///five
            break;
        case '6':
            strcat(curr_str, slova[6]); ///six
            break;
        case '7':
            strcat(curr_str, slova[7]); ///seven
            break;
        case '8':
            strcat(curr_str, slova[8]); ///eight
            break;
        case '9':
            strcat(curr_str, slova[9]); ///nine
            break;
        }
    }
    delete [] ps;
    ps = nullptr;
    ps = new char [leng];
    strcpy(ps, curr_str);
    delete [] curr_str;
    curr_str=nullptr;
    cout<<ps<<endl;
    delete [] ps;
    ps = nullptr;
    return 0;
}
