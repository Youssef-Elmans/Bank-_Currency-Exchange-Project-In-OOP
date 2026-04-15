Bank Management System (C++)
This is a professional Console-based Bank Application developed using C++. The project demonstrates a deep understanding of Object-Oriented Programming (OOP) and software architecture by separating the business logic from the user interface.

 Project Architecture (Step-by-Step)
The project is organized into layers to make the code clean, readable, and easy to maintain:

1. The Core Layer (The Brain)
Everything starts with the data and business rules. I built core classes that represent the main pillars of the bank:

clsBankClient: Handles all client data (Accounts, Balances, Pins) and core banking logic like withdrawing and depositing.

clsUser: Manages the employees who use the system, including their login credentials and specific access rights.

clsCurrency: A dedicated system for global currencies and exchange rates.

2. The Logic Layer (Transactions & Security)
On top of the core objects, I implemented advanced logic:

Permission System (Bitmasking): Each user has specific permissions. The system checks if a user is allowed to perform an action (like deleting a client) before showing the screen.

Data Persistence: I used File Handling to ensure all data is saved permanently in .txt files.

Logging System: The app automatically records every login and every money transfer into separate log files for security tracking.

3. The Presentation Layer (The UI Screens)
Instead of putting everything in main.cpp, I used a Screen-based Architecture:

clsScreen (Base Class): All screens inherit from this class to ensure a consistent look (Headers, Titles, etc.).

Modular Screens: Every feature (Add Client, Transfer, Currency Calculator) has its own dedicated class. This makes the app very easy to expand.

4. Support Library (Utilities)
To keep the code DRY (Don't Repeat Yourself), I built helper libraries:

clsDate: For professional date/time handling and formatting.

clsString: For advanced text processing and data parsing.

clsInputValidation: To make the app "crash-proof" by validating every piece of data the user enters.

Tech Stack
Language: C++

Concepts: Inheritance, Encapsulation, Polymorphism, File I/O, Bitwise Operations.
