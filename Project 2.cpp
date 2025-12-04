#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;


};
sClient CurrentClient;
void ReturnToMainAtmScreen();
void ShowQuickWithdrawScreen();
void ShowATMScreen();
void LogIn();
int ReadAmount(string massege);
void ShowLogInScreen()
{
    cout << "==========================\n";
    cout << "          Login\n";
    cout << "==========================\n";
}
string ReadAccountNumber()
{
    string u;
    cout << "Enter Account Number: ";
    getline(cin >> ws, u);
    return u;
}
string ReadPaddWord()
{
    string u;
    cout << "Enter Password: ";
    getline(cin >> ws, u);
    return u;
}
vector <string> SplitWords(string S1, string delim = "#//#")
{
    vector <string> vElements;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vElements.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vElements.push_back(S1);
    }

    return vElements;
}
sClient ConvertLineToRecord(string line)
{
    vector <string> Elems = SplitWords(line);
    sClient Client;
    Client.AccountNumber = Elems[0];
    Client.PinCode = Elems[1];
    Client.Name = Elems[2];
    Client.Phone = Elems[3];
    Client.AccountBalance = stod(Elems[4]);
    return Client;
}
vector <sClient> LoadFileDataToVector(string FileName)
{
    vector <sClient> vClient;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string line;
        sClient Client;
        while (getline(MyFile, line))
        {
            Client = ConvertLineToRecord(line);
            vClient.push_back(Client);
        }
        MyFile.close();
    }
    return vClient;
}
bool ValidateCredentials(string AccountNumber, string password, sClient& CurrentClient)
{
    vector <sClient> vClient = LoadFileDataToVector(ClientsFileName);
    for (sClient& C : vClient)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == password)
        {
            CurrentClient = C;
            return true;
        }
    }
    return false;
}
enum enAtmOptions
{
    enQuickWithdraw = 1, enNormalWithDraw, enDeposit, CheckBalances, LogOut
};
short ChooseOption(short From, short To)
{
    short i;
    cout << "Choose What You Want To Do. [" << From << "/" << To << "]: ";
    cin >> i;
    return i;
}
enum enWithdrawAmount
{
    op1 = 1, op2 = 2, op3 = 3, op4 = 4, op5 = 5, op6 = 6, op7 = 7, op8 = 8, op9 = 9
};
short ChooseWithDrawAmount(short From, short To)
{
    short i = 0;
    cout << "Choose Amount You Want To With Draw: ";
    cin >> i;
    return i;
}
void PrintClientBalance(string massege)
{
    cout << massege << CurrentClient.AccountBalance << endl;
}
sClient WithdrawAmount(int Amount, sClient C)
{
    C.AccountBalance -= Amount;
    return C;
}
string ConvertRecordToLine(sClient C, string delim = "#//#")
{
    string line = "";
    line += C.AccountNumber + delim;
    line += C.PinCode + delim;
    line += C.Name + delim;
    line += C.Phone + delim;
    line += to_string(C.AccountBalance);
    return line;
}
bool LoadVectorToFile(vector <sClient> vClient, string FileName)
{
    fstream MyFile;
    
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        string line;
        for (sClient& C : vClient)
        {
            line = ConvertRecordToLine(C);
            MyFile << line << endl;
        }
        MyFile.close();
        return true;
    }
    return false;
}
bool WithDaw(int Amount, string massege)
{
    cout << "==========================\n";
    cout << massege;
    cout << "\n==========================\n";
    Amount = ReadAmount("\nEnter Amount You Want To Withdraw: ");
    vector <sClient> vClient = LoadFileDataToVector(ClientsFileName);
    char confirm = 'N';
    for (sClient& C : vClient)
    {
        if (C.AccountNumber == CurrentClient.AccountNumber && C.PinCode == CurrentClient.PinCode)
        {
            if (Amount % 5 != 0)
            {
                cout << "\nThe Amount is Not of The Multiplies of 5. Try Diffrent Amount.\n";
                system("pause>0");
                ReadAmount("\nEnter Amount You Want To Withdraw: ");
                return false;
            }
            if(C.AccountBalance < Amount)
            {
                cout << "\nThe Amount Exceeds your balance, Mkae Another Chise.\n";
                system("pause>0");
                ShowQuickWithdrawScreen();
                return false;
            }
            else
            {
                PrintClientBalance("\nYou Current Balance is: ");

                cout << "\nAre You Sure You Want To Withdraw " << Amount << "? [Y/N]\n";
                cin >> confirm;
                if (toupper(confirm) == 'Y')
                {
                    C = WithdrawAmount(Amount, C);
                    LoadVectorToFile(vClient, ClientsFileName);
                    cout << "\nYour Withdrae Has Been Successfully Made\n";
                    PrintClientBalance("\nYou Current Balance is: ");
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    
}
void PerformQuickWithdraw(enWithdrawAmount Amount)
{
    
    switch (Amount)
    {
    case enWithdrawAmount::op1:
        system("cls");
        WithDaw(20, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op2:
        system("cls");
        WithDaw(50, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op3:
        system("cls");
        WithDaw(100, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op4:
        system("cls");
        WithDaw(200, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op5:
        system("cls");
        WithDaw(400, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op6:
        system("cls");
        WithDaw(600, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op7:
        system("cls");
        WithDaw(800, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op8:
        system("cls");
        WithDaw(1000, "       Quick Withdrae");
        ReturnToMainAtmScreen();
        break;
    case enWithdrawAmount::op9:
        system("cls");
        ShowATMScreen();
        return;
    }
}
void ShowQuickWithdrawScreen()
{
    cout << "========================================================\n";
    cout << "\t\t    Atm Main Manue\n";
    cout << "========================================================\n";
    cout << "\t\t [1] 20" << "      [2] 50" << endl;
    cout << "\t\t [3] 100" << "     [4] 200\n";
    cout << "\t\t [5] 400"<< "     [6] 600\n";
    cout << "\t\t [7] 800" <<"     [8] 1000\n";
    cout << "\t\t [9] Exit\n";
    cout << "========================================================\n";
    PerformQuickWithdraw((enWithdrawAmount)ChooseWithDrawAmount(1, 9));
}
int ReadAmount(string massege)
{
    int i = 0;
    do
    {
        cout << massege;
        cin >> i;
    } while (i < 1);
    return i;
}
void ShowNormalWithdrawScreen()
{
    int Amount = 0;
    WithDaw(Amount, "       Normal Withdraw");
}
bool PerformDeposit(int amount, vector <sClient> vClient)
{
    amount = ReadAmount("\nEnter Amount You Want To Deposit ");
    char confirm = 'N';
    for (sClient& C : vClient)
    {
        if (CurrentClient.AccountNumber == C.AccountNumber && CurrentClient.PinCode == C.PinCode)
        {
            cout << "\nAre You Sure You Want To Deposit: " << amount << " [Y/N] ";
            cin >> confirm;
            if (toupper(confirm) == 'Y')
            {
                C.AccountBalance += amount;
                LoadVectorToFile(vClient, ClientsFileName);
                cout << "\nYou Deposit Has Been Made Successfully\n";
                PrintClientBalance("New Account Balance is: ");
                return true;
            }
        }
    }
    return false;
}
void ShowDepositScreen()
{
    cout << "==========================\n";
    cout << "          Deposit\n";
    cout << "==========================\n";
    vector <sClient> vClient = LoadFileDataToVector(ClientsFileName);
    int Amount = 0; 
    PerformDeposit(Amount, vClient);
}
void ShowCheckBalanceScreen()
{
    cout << "==========================\n";
    cout << "          Check Balance\n";
    cout << "==========================\n";
    PrintClientBalance("\nCurrent Account Balance is: ");
}
void PerformAtmOption(enAtmOptions option)
{
    switch (option)
    {
    case enAtmOptions::enQuickWithdraw:
        system("cls");
        ShowQuickWithdrawScreen();
        ReturnToMainAtmScreen();
        break;
    case enAtmOptions::enNormalWithDraw:
        system("cls");
        ShowNormalWithdrawScreen();
        ReturnToMainAtmScreen();
        break;
    case enAtmOptions::enDeposit:
        system("cls");
        ShowDepositScreen();
        ReturnToMainAtmScreen();
        break;
    case enAtmOptions::CheckBalances:
        system("cls");
        ShowCheckBalanceScreen();
        ReturnToMainAtmScreen();
        break;
    case enAtmOptions::LogOut:
        LogIn();
        return;
    }
}
void ShowATMScreen()
{
    cout << "========================================================\n";
    cout << "\t\t    Atm Main Manue\n";
    cout << "========================================================\n";
    cout <<  "\t\t [1] Quick Withdraw." << endl;
    cout <<  "\t\t [2] Normal Withdraw.\n";
    cout <<  "\t\t [3] Deposit.\n";
    cout <<  "\t\t [4] Check Balance.\n";
    cout <<  "\t\t [5] Logout.\n";
    cout << "========================================================\n";
    PerformAtmOption(enAtmOptions(ChooseOption(1, 5)));

}
void ReturnToMainAtmScreen()
{
    cout << "Press Any Key To Go Back To Main Atm Menue\n";
    system("pause>0");
    system("cls");
    ShowATMScreen();
}
void LogIn()
{
    bool LogInFailed = false;
    string AccountNumber, Password;
    do
    {
        system("cls");
        ShowLogInScreen();
        if (LogInFailed)
            cout << "Unvalid Username Or Password, Try Again.\n";
        AccountNumber = ReadAccountNumber();
        Password = ReadPaddWord();

        LogInFailed = !ValidateCredentials(AccountNumber, Password, CurrentClient);

    } while (LogInFailed);
    system("cls");
    ShowATMScreen();
}
int main()
{
    LogIn();
    return 0;
}