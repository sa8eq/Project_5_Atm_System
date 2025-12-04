# ATM System

A command-line ATM (Automated Teller Machine) simulation built in C++ that allows clients to perform common banking operations including withdrawals, deposits, and balance inquiries.

## Features

### 🏧 ATM Operations

#### Quick Withdraw
- Predefined withdrawal amounts for fast transactions
- Available denominations: $20, $50, $100, $200, $400, $600, $800, $1000
- Instant selection without typing amounts
- Automatic validation against account balance

#### Normal Withdraw
- Custom withdrawal amounts
- Amount validation (must be multiples of $5)
- Balance checking before processing
- Confirmation prompt before transaction

#### Deposit
- Add funds to your account
- Flexible amount input
- Confirmation required before processing
- Instant balance update

#### Check Balance
- View current account balance
- Quick and simple inquiry
- No transaction fees

### 🔒 Security Features

- **Login Authentication** - Secure access with account number and PIN code
- **Balance Validation** - Prevents overdrafts
- **Confirmation Prompts** - All transactions require user confirmation
- **Session Management** - Logout functionality to end sessions securely

## How It Works

### Transaction Flow

```
Login → Main Menu → Select Operation → Confirm → Update Balance → Return to Menu
```

### Validation Rules

1. **Withdrawal Amounts**: Must be multiples of $5
2. **Balance Check**: Withdrawal amount cannot exceed account balance
3. **Authentication**: Account number and PIN must match records
4. **Confirmation**: All financial transactions require user confirmation

## Getting Started

### Prerequisites
- C++ compiler with C++11 support or later
- Windows OS (uses `system()` calls for screen management)
- `Clients.txt` file with client data

### Client Data Format

The system reads client information from `Clients.txt`. Each line follows this format:
```
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
```

**Example:**
```
ACC001#//#1234#//#John Doe#//#555-0100#//#1500.00
ACC002#//#5678#//#Jane Smith#//#555-0200#//#2500.50
```

### Compilation

```bash
g++ -std=c++11 atm_system.cpp -o atm_system
```

### Running the Application

```bash
./atm_system
```

## Usage Guide

### 1. Login
```
Enter Account Number: ACC001
Enter Password: 1234
```

### 2. Main Menu Options

```
========================================================
                    Atm Main Manue
========================================================
         [1] Quick Withdraw.
         [2] Normal Withdraw.
         [3] Deposit.
         [4] Check Balance.
         [5] Logout.
========================================================
```

### 3. Quick Withdraw Menu

```
========================================================
                    Atm Main Manue
========================================================
         [1] 20      [2] 50
         [3] 100     [4] 200
         [5] 400     [6] 600
         [7] 800     [8] 1000
         [9] Exit
========================================================
```

### 4. Transaction Examples

#### Quick Withdraw Example:
```
Choose What You Want To Do. [1/5]: 1
Choose Amount You Want To Withdraw: 3

Your Current Balance is: 1500.00

Are You Sure You Want To Withdraw 100? [Y/N]
Y

Your Withdraw Has Been Successfully Made
Your Current Balance is: 1400.00
```

#### Deposit Example:
```
Choose What You Want To Do. [1/5]: 3

Enter Amount You Want To Deposit: 500

Are You Sure You Want To Deposit: 500 [Y/N] Y

Your Deposit Has Been Made Successfully
New Account Balance is: 1900.00
```

## Project Structure

```
ATM System
│
├── Authentication Module
│   ├── ShowLogInScreen()
│   ├── ValidateCredentials()
│   └── LogIn()
│
├── Transaction Modules
│   ├── Quick Withdraw
│   │   ├── ShowQuickWithdrawScreen()
│   │   └── PerformQuickWithdraw()
│   │
│   ├── Normal Withdraw
│   │   ├── ShowNormalWithdrawScreen()
│   │   └── WithDraw()
│   │
│   ├── Deposit
│   │   ├── ShowDepositScreen()
│   │   └── PerformDeposit()
│   │
│   └── Balance Inquiry
│       └── ShowCheckBalanceScreen()
│
└── Data Management
    ├── LoadFileDataToVector()
    ├── LoadVectorToFile()
    ├── ConvertLineToRecord()
    └── ConvertRecordToLine()
```

## Features Breakdown

### Withdrawal Validation
- ✅ Checks if amount is multiple of $5
- ✅ Verifies sufficient balance
- ✅ Requires confirmation
- ✅ Updates balance immediately
- ✅ Displays new balance after transaction

### Deposit Process
- ✅ Accepts any positive amount
- ✅ Requires confirmation
- ✅ Updates balance in real-time
- ✅ Shows updated balance

### Balance Inquiry
- ✅ Instant display
- ✅ No transaction required
- ✅ Current session balance

## Error Handling

The system handles various error scenarios:

1. **Invalid Login**: Prompts user to try again
2. **Insufficient Balance**: Prevents transaction and shows warning
3. **Invalid Amount** (not multiple of 5): Rejects withdrawal
4. **File Access Issues**: Handled gracefully with return values

## Security Considerations

⚠️ **Important Notes:**
- PIN codes are stored in plain text (use encryption in production)
- No transaction limits implemented (should add daily limits)
- No fraud detection (consider implementing for production)
- Session timeout not implemented (recommended for security)

## Future Enhancements

### Recommended Features
- 🔐 PIN encryption and secure storage
- 📊 Transaction history and receipt generation
- 💳 Multiple account support (checking, savings)
- 🔔 Transaction notifications
- ⏰ Session timeout for security
- 📱 Transfer between accounts
- 🧾 Mini statement generation
- 🌍 Multi-language support
- 💰 Currency selection
- 📈 Daily withdrawal limits

### Technical Improvements
- Cross-platform compatibility (Linux/Mac support)
- Database integration instead of text files
- Logging system for audit trails
- Input validation improvements
- Better error messages
- GUI interface option

## File Structure

```
atm-system/
│
├── atm_system.cpp          # Main program file
├── Clients.txt             # Client database (required)
├── README.md               # This file
└── .gitignore             # Git ignore file
```

## Testing

### Sample Test Cases

1. **Login Test**: Valid/Invalid credentials
2. **Quick Withdraw**: All preset amounts
3. **Normal Withdraw**: 
   - Valid amount (multiple of 5)
   - Invalid amount (not multiple of 5)
   - Amount exceeding balance
4. **Deposit**: Various amounts
5. **Balance Check**: After each transaction

### Creating Test Data

Create a `Clients.txt` file with test accounts:
```
TEST001#//#1111#//#Test User One#//#555-1001#//#1000.00
TEST002#//#2222#//#Test User Two#//#555-1002#//#5000.00
TEST003#//#3333#//#Test User Three#//#555-1003#//#500.00
```

## Contributing

Contributions are welcome! Areas for improvement:
- Enhanced security features
- Additional transaction types
- Better error handling
- Cross-platform support
- Unit tests
- Documentation improvements

## License

This project is open source and available for educational purposes.

## Disclaimer

This is a demonstration project for educational purposes. Do not use in production without implementing proper security measures, encryption, and compliance with banking regulations.

## Author

Created as an ATM simulation project demonstrating:
- File I/O operations
- Data structure manipulation
- User authentication
- Transaction processing
- Input validation
- Menu-driven interfaces

---

**Note**: Always ensure your `Clients.txt` file exists and is properly formatted before running the application.
