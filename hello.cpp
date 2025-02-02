#include <iostream>
#include <cstdlib> // For system("cls")
#include <vector>
#include <cctype>
#include <limits> // For input validation

using namespace std;

int main() {
    int welcome, movie, seat_number, num_seats, selected_time, seatCount,hallChoice,hall_price;
    char seat_row;
    string selected_movie;
    float movie_price = 0;

    while (true) {
        system("cls");
        cout << "======================================" << endl;
        cout << "         Movie Ticket Booking         " << endl;
        cout << "======================================" << endl;
        cout << "1. Booking                            " << endl;
        cout << "2. Menu                               " << endl;
        cout << "3. Exit                               " << endl;
        cout << "======================================" << endl;
        cout << "Enter The Number To Continue: ";
        cin >> welcome;

        if (welcome == 1) {
            break; // Exits the loop and moves to movie selection
        }

        switch (welcome) {
            case 2:
                system("cls");
                cout << "=============" << endl;
                cout << " Use Your IQ " << endl;
                cout << "=============" << endl;
                cout << "Press enter to return to the menu..." << endl;
                cin.ignore();  // Ignore newline character
                cin.get();     // Wait for user input
                continue; // Restart loop instead of exiting
            case 3:
                system("cls");
                cout << "==========================" << endl;
                cout << "GoodBye See you next time!" << endl;
                cout << "==========================" << endl;
                return 0; // Exit the program normally
            default:
                cout << "Invalid input. Try again!" << endl;
                cin.ignore();
                cin.get();
        }
    }
    
while(true){
    system("cls");
    cout << "=========================================" << endl;
    cout << "1. Avengers: Endgame            " << endl;
    cout << "2. Spider-Man: No Way Home      " << endl;
    cout << "3. Interstellar                " << endl;
    cout << "4. The Dark Knight Rises        " << endl;
    cout << "5. The Lion King (2019)         " << endl;
    cout << "6. Joker                        " << endl;
    cout << "7. Inception                    " << endl;
    cout << "8. Black Panther                " << endl;
    cout << "9. Star Wars: The Force Awakens  " << endl;
    cout << "10. Frozen II                  " << endl;
    cout << "=========================================" << endl;
    cout << "Enter Movie you want to Watch: ";
    cin >> movie;

    if(movie > 10){
       cout <<"Choose again: "<<endl;
       cin.ignore();
       cin.get();
       continue;
    }
}
    system("cls");
    cout << "=========================================" << endl;
    cout << "Select a Hall Type:" << endl;
    cout << "1. 4D Hall - $10 extra" << endl;
    cout << "2. 3D Hall - $5 extra" << endl;
    cout << "3. 2D Hall - $2.5 extra" << endl;
    cout << "=========================================" << endl;
    cout << "Enter hall choice (1-3): ";
    cin >> hallChoice;
    
    switch (hallChoice) {
        case 1: hall_price = 10; break;
        case 2: hall_price = 5; break;
        case 3: hall_price = 2.5; break;
        default:
            cout << "Invalid hall choice! Exiting...\n";
            return 0;
    }

    string times[] = {
        "10:00 - 11:30", "12:00 - 13:30", "14:00 - 14:30",
        "15:00 - 15:30", "16:00 - 16:30", "17:00 - 17:30"
    };

    while (true) { // Loop until valid inputs
        system("cls");
        cout << "=================" << endl;
        for (int i = 0; i < 6; i++) {
            cout << "[" << i + 1 << "]. " << times[i] << endl;
        }
        cout << "=================" << endl;
        cout << "Enter the time: ";
        cin >> selected_time;

        if (selected_time >= 1 && selected_time <= 6) {
            cout << "You selected: " << times[selected_time - 1] << endl;
            break; // Exit the loop when a valid choice is made
        } else {
            cout << "Invalid choice! Please choose again." << endl;
            cin.ignore();
            cin.get();
        }
    }

    vector<vector<bool>> seats(5, vector<bool>(8, false)); // 5 rows (A-E), 8 columns (1-8)

    // Display the seating arrangement with prices for each type of seat
    system("cls");
    cout << "=================================================\n";
    cout << "                   Movie Theater                \n";
    cout << "=================================================\n";
    cout << "Seat Pricing:\n";
    cout << "VIP: Rows A and B - $5.00 extra\n";
    cout << "Special: Rows C and D - $3.00 extra\n";
    cout << "\n===============================================\n";
    
// Ask how many seats the user wants
cout << "\nHow many seats do you want? (up to 40 seats): "; // You can change the limit based on your theater's capacity
cin >> seatCount;

// Validate input (ensure that it's a positive number)
if (seatCount < 1) {
    cout << "Invalid number of seats! Please restart the booking.\n";
    return 0;
}

// Validate that there are enough seats available
int totalAvailableSeats = 40; // Assuming there are 5 rows with 8 seats each (5 * 8 = 40)
int bookedSeatsCount = 0;

for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
        if (!seats[i][j]) {
            bookedSeatsCount++;
        }
    }
}

if (seatCount > bookedSeatsCount) {
    cout << "Not enough available seats. Only " << bookedSeatsCount << " seats are available. Please select fewer seats.\n";
    return 0;
}

// Manually ask for each seat
int seatNumber;
char seatRow;
float additionalCharge = 0;
vector<string> bookedSeats;

for (int i = 0; i < seatCount; i++) {
    cout << "\nEnter seat " << (i + 1) << " (e.g., 3A): ";
    cin >> seatNumber >> seatRow;
    seatRow = toupper(seatRow);

    // Validate seat
    int rowIndex = seatRow - 'A'; 
    if (rowIndex >= 0 && rowIndex < 5 && seatNumber >= 1 && seatNumber <= 8 && !seats[rowIndex][seatNumber - 1]) {
        seats[rowIndex][seatNumber - 1] = true;
        bookedSeats.push_back(to_string(seatNumber) + seatRow);
        cout << "You have successfully selected seat " << seatNumber << seatRow << ".\n";

        // Additional charge based on row
        if (seatRow == 'A' || seatRow == 'B') {
            additionalCharge += 5.00;
        } else if (seatRow == 'C' || seatRow == 'D') {
            additionalCharge += 3.00;
        }
    } else {
        cout << "Invalid or already taken seat. Restart the booking.\n";
        return 0;
    }
}
// Calculate total price
float totalAmount = movie_price + additionalCharge + hall_price;

// Display final booking details
system("cls");
cout << "=========================================" << endl;
cout << "Movie Selected: " << selected_movie << endl;
cout << "Time Selected: " << times[selected_time - 1] << endl;
cout << "Seats Selected: ";
for (const string& seat : bookedSeats) {
    cout << seat << " ";
}
cout << "\n========================================";
cout << "\nTicket Price: $" <<hall_price <<endl;
cout << "\n========================================";
cout << "\nSeats Price: $" << additionalCharge << endl;
cout << "========================================"<<endl;
cout << "Total Price: $" << totalAmount << endl;
cout << "=========================================" << endl;
float userPayment = 0;
    while (userPayment < totalAmount) {
        float additionalPayment;
        cout << "Enter payment amount: $";
        cin >> additionalPayment;
        userPayment += additionalPayment;

        if (userPayment < totalAmount) {
            cout << "Insufficient payment! You still owe: $" << (totalAmount - userPayment) << "\n";
        }
    }

    cout << "=========================================\n";
    cout << "Payment successful! Change: $" << userPayment - totalAmount << "\n";
    cout << "=============================================================\n";
    cout << "Thank you for using the Movie Ticket Booking system!\n";
    cout << "=============================================================\n";
    return 0; // Ensures proper program exit
}