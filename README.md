# Password Analyzer

A C++ application that analyzes the strength of passwords by evaluating multiple factors, including length, character variety, entropy, and breach history (using the Have I Been Pwned API). The project helps users identify weak passwords and provides feedback on how to improve them for better security.

## Features

- **Password Length Check**: Verifies if the password has a minimum length of 8 characters.
- **Character Variety Check**: Ensures that the password contains a mix of uppercase letters, lowercase letters, digits, and special characters.
- **Entropy Calculation**: Measures the randomness of the password and gives feedback on its strength.
- **Breach Check**: Uses the Have I Been Pwned API to check if the password has been exposed in a known data breach.
- **Feedback**: Provides clear feedback on the password's strength and suggests improvements if necessary.

## How It Works

1. **Password Length**: The password should be at least 8 characters long to be considered acceptable.
2. **Character Variety**: The password should contain at least one uppercase letter, one lowercase letter, one digit, and one special character (e.g., `!`, `#`, `@`).
3. **Entropy**: A password with high entropy is more random and difficult to guess. The entropy score is calculated using a frequency distribution of characters in the password.
4. **Data Breach Check**: The application checks if the password has been exposed in a public data breach using the Have I Been Pwned (HIBP) API.

## Requirements

- **C++ Compiler**: The project is written in C++ and requires a C++17 compatible compiler (e.g., `g++`).
- **cURL**: The project uses the cURL library for making HTTP requests to the Have I Been Pwned API.
- **OpenSSL**: The OpenSSL library is used for hashing passwords with SHA-1.

## Installation

## Step 1: Clone the repository

```bash
git clone https://github.com/danimnunes/PasswordAnalyzer
cd password-analyzer
```

## Step 2: Install dependencies

- **cURL**: You can install cURL using your package manager:
  - On Ubuntu/Debian: `sudo apt-get install libcurl4-openssl-dev`
  - On macOS: `brew install curl`
  
- **OpenSSL**: You can install OpenSSL using your package manager:
  - On Ubuntu/Debian: `sudo apt-get install libssl-dev`
  - On macOS: `brew install openssl`

## Step 3: Compile the project

You can compile the project using `g++` (or another C++17 compatible compiler). For example:

```bash
g++ -o password-analyzer main.cpp PasswordAnalyzer.cpp APIClient.cpp -lcurl -lssl -lcrypto -std=c++17
```
This will generate the password-analyzer executable.

## Step 4: Run the program

Run the following command to start the program:

```bash
./password-analyzer
```

### Usage

1. **Enter a password** when prompted.
2. The program will analyze the password and give feedback on:
   - Strength (length, character variety).
   - Entropy (randomness of the password).
   - Whether the password has been exposed in a data breach.

### Example:

Enter a password to analyze: P@ssw0rd123 Your password has low entropy. Aim for greater randomness. Your password has been found in a data breach. Data provided by Have I Been Pwned (https://haveibeenpwned.com). Avoid using it.


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- **Have I Been Pwned**: The project uses the HIBP API to check if a password has been exposed in a data breach.
- **cURL**: Used for making HTTP requests.
- **OpenSSL**: Used for hashing passwords with SHA-1.




