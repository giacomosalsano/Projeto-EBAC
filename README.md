Here is the translation of the documentation into English, keeping the terminology in Portuguese:

---

# Registro de Nomes - Software Architecture Documentation

## 1. General Information
- **Institution:** EBAC;
- **Course:** TI do Zero;
- **Project:** Registro de Nomes ("_Name Registration_");
- **Version:** 1.0;
- **Stacks:** C++, HTML & CSS;
- **Run the Project:** `npm run dev`
- **Password:** `admin`

---

## 2. General Description

The **Registro de Nomes** project is a simple application developed in C++ that allows the registration of users with CPF, first name, last name, and job title. The information is saved in `.md` files with the user's CPF as the file name, and the content includes the registered personal data.

### 2.1 Purpose

This project aims to implement a basic information registration system that stores data in local files. It is designed to learn and apply fundamental concepts of file manipulation, data structures, and flow control in C++.

### 2.2 Scope

The system includes functionalities for:
- User registration (CPF, first name, last name, job title);
- Checking for duplicate CPF;
- Querying registered user data;
- Displaying error and success messages to the user.

---

## 3. Definitions, Acronyms, and Abbreviations

- **CPF:** Cadastro de Pessoa Física ("_Individual Taxpayer Registry_"), a number used in Brazil to identify citizens;
- **C++:** Programming language used to develop the project;
- **Biblioteca.c:** Set of standard C++ libraries used in the project (stdio.h, string.h, etc);
- **TDD:** Test Driven Development, a simple approach used to ensure the correct creation of files;

---

## 4. Project Objectives

The main goal of this project is to consolidate the concepts learned in the **EBAC - TI do Zero** course, focusing on:
- File manipulation;
- Data input validation;
- Flow control structures;
- Implementing an interactive menu.

---

## 5. Analytical Index

1. General Information
2. General Description
   - Purpose
   - Scope
3. Definitions, Acronyms, and Abbreviations
4. Project Objectives
5. Architectural Representation
6. Use Case View
7. Logical View
8. Process View
9. Deployment View
10. Implementation View
11. Size and Performance
12. Quality
13. Development Suggestions

---

## 6. Architectural Representation

The project architecture follows the **Client-Server** pattern, where:
- The **client** interacts through a menu in the terminal;
- The **server** is the system itself, which processes the data provided by the user and stores this information locally in files.

---

## 7. Use Case View

### Use Cases:
1. **Register User:**
   - Input: CPF, first name, last name, job title;
   - Validations: Verifies if the CPF has 11 digits and if it has already been registered;
   - Output: File with the registered user's data.

2. **Query User:**
   - Input: CPF;
   - Output: Displays the user data corresponding to the CPF if found.

---

## 8. Logical View

The main logic of the system is centered around the following functions:

- `registrar()`: Handles user registration and saves the information in files;
- `consultar()`: Allows the user to query a previously registered CPF;
- `validarCPF()`: Verifies if the CPF is valid and contains only numeric characters;
- `verificarArquivoExistenteFunction()`: Checks if a file (CPF) has already been registered previously.

---

## 9. Process View

The system follows the flow:
1. The user chooses an option from the menu (register or query);
2. In the registration, the system collects the data and validates the CPF;
3. In the query process, the system searches for the file corresponding to the CPF;
4. The system provides feedback to the user with error or success messages.

---

## 10. Deployment View

- The project was developed to run directly in the terminal on any operating system. To ensure compatibility with different systems, the screen clearing uses a conditional macro:
  - On Windows: `cls`
  - On Unix-based systems: `clear`

---

## 11. Implementation View

The code was implemented in C++, using standard libraries for input and output data, string manipulation, and file handling. The main functions and control structures were defined to ensure simple and efficient execution.

---

## 12. Size and Performance

### Size:
- Each user record is saved in a `.md` file, and the file size will depend on the amount of data registered.

### Performance:
- The system’s performance is adequate for the purpose of simple registration, with low memory consumption and fast execution time due to the nature of the operations.

---

## 13. Quality

The quality of the code is ensured through the use of best practices (Clean Code), such as:
- Data input validation;
- Use of control structures to avoid errors;
- Clear feedback messages to the user;
- Simulated TDD to ensure the correct creation of files.

---

## 14. Development Suggestions

### 14.1 FrontEnd Development
- Since the system runs in the terminal, future development could involve creating a graphical user interface (GUI) to improve the user experience.

### 14.2 BackEnd Improvement
- Implement a security layer to encrypt the stored data.
- Expand data manipulation functionalities, such as editing or deleting records.

### 14.3 New Features
- **Data Backup:** Create a function that automates the backup of registration files;
- **Error Handling:** Improve error handling, such as failures in the file system or data input;
- **Connectivity:** Integrate the system with a remote database to enable centralized user registration and querying;
- **User Monitoring:** Add functionality for monitoring and generating logs to track the system's usage.
