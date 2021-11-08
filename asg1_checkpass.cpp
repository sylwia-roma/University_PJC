#include <iostream>



/* the function examines and returns length of given string */
int slen(const char *s)
{
    int result;
    result = 0;
    while (s[result] != '\0')
        result++;
    return result;
}

/* the function computes and returns number
   of different characters in given string
*/
int nrDiffChars(const char *s)
{
    int result;
    int L;   //length of the string s
    int k,i;
    bool stop;

    L = slen(s);
    result = L;
    for (k=L-1; k>0; k--) {
        stop = false;
        i = k-1;
        while (stop==false)
            if (i<0)
                stop = true;
            else
                if (s[i]==s[k]) {
                    result--;
                    stop = true;
                }
                else
                    i--;
    } //for

    return result;
}

/* the function examines correctness of given password;
   if incorrect, writes messages about ALL causes of incorrectness
*/
bool checkpass(const char *pass)
{
    using std::cout;  using std::endl;

    bool PasswordOK;   //whether given password is OK (correct);
                       //result of the function
    int L;   //length of the password
    int NDC;   //number of different characters in the password
    bool hasDigit;   //whether the password contains at least 1 digit
    bool hasUpCase;   //whether the password contains at least 1
                      //uppercase (English) letter
    bool hasLowCase;   //whether the password contains at least 1
                       //lowercase (English) letter
    bool hasOtherChar;   //whether the password contains at least 1 character
                         //that is neither a digit nor an (Englist) letter

    L = slen(pass);

    NDC = nrDiffChars(pass);

    hasDigit = false;
    hasUpCase = false;
    hasLowCase = false;
    hasOtherChar = false;
    for (int i=0; i<L; i++)
        if (pass[i]>='0' && pass[i]<='9')   //pass[i] is a digit
            hasDigit = true;
        else if (pass[i]>='A' && pass[i]<='Z')
                     //pass[i] is an uppercase (English) letter
            hasUpCase = true;
        else if (pass[i]>='a' && pass[i]<='z')
                     //pass[i] is a lowercase (English) letter
            hasLowCase = true;
        else   //pass[i] is neither a digit nor an (English) letter
            hasOtherChar = true;

    PasswordOK = true;
    if (L<8) {
        PasswordOK = false;
        cout << "Too short" << endl;
    }
    if (NDC<6) {
        PasswordOK = false;
        cout << "Too few different characters" << endl;
    }
    if (hasDigit==false) {
        PasswordOK = false;
        cout << "No digit" << endl;
    }
    if (hasUpCase==false) {
        PasswordOK = false;
        cout << "No upprecase letter" << endl;
    }
    if (hasLowCase==false) {
        PasswordOK = false;
        cout << "No lowercase letter" << endl;
    }
    if (hasOtherChar==false) {
        PasswordOK = false;
        cout << "No non-alphanumeric character" << endl;
    }

    return PasswordOK;   //return the result
}



int main()
{
    using std::cout;  using std::cin;  using std::endl;


    const char * passes[] =
    {
        "AbcDe93", "A1b:A1b>", "Ab:Acb<",
        "abc123><", "Zorro@123", nullptr
    };

    for (int i=0; passes[i]!=nullptr; i++) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i]))
            cout << "OK" << endl;
        cout << endl;
    }


    cout << endl;
    cout << "Press <ENTER> to exit the program... " << endl;
    cin.get();
    return 0;
}
