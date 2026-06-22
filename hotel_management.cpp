#include <iostream>
#include <string>
using namespace std;

// ─── Room Structure ───────────────────────────────────────────────────────────
struct Room {
    int    roomNumber;
    string guestName;
    int    days;
    bool   isBooked;
};

// ─── Global Data ──────────────────────────────────────────────────────────────
const int TOTAL_ROOMS = 10;
Room rooms[TOTAL_ROOMS];

// Room rate per night (in Rs.)
const int ROOM_RATE = 1500;

// ─── Initialize Rooms ─────────────────────────────────────────────────────────
void initRooms() {
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].guestName  = "";
        rooms[i].days       = 0;
        rooms[i].isBooked   = false;
    }
}

// ─── Display All Rooms ────────────────────────────────────────────────────────
void displayRooms() {
    cout << "\n========================================\n";
    cout << "         ROOM STATUS OVERVIEW\n";
    cout << "========================================\n";
    cout << "Room No. | Status     | Guest Name\n";
    cout << "---------|------------|----------------\n";

    for (int i = 0; i < TOTAL_ROOMS; i++) {
        cout << "   " << rooms[i].roomNumber << "     | ";
        if (rooms[i].isBooked) {
            cout << "Booked     | " << rooms[i].guestName << "\n";
        } else {
            cout << "Available  | ---\n";
        }
    }
    cout << "========================================\n";
}

// ─── Book a Room ──────────────────────────────────────────────────────────────
void bookRoom() {
    int roomNo;
    cout << "\n--- BOOK A ROOM ---\n";
    cout << "Enter Room Number (1-" << TOTAL_ROOMS << "): ";
    cin  >> roomNo;

    // Validate room number
    if (roomNo < 1 || roomNo > TOTAL_ROOMS) {
        cout << "Invalid room number!\n";
        return;
    }

    int index = roomNo - 1;

    if (rooms[index].isBooked) {
        cout << "Sorry! Room " << roomNo << " is already booked by "
             << rooms[index].guestName << ".\n";
        return;
    }

    cout << "Enter Guest Name: ";
    cin.ignore();
    getline(cin, rooms[index].guestName);

    cout << "Enter Number of Days: ";
    cin  >> rooms[index].days;

    if (rooms[index].days <= 0) {
        cout << "Invalid number of days!\n";
        rooms[index].guestName = "";
        return;
    }

    rooms[index].isBooked = true;

    int total = rooms[index].days * ROOM_RATE;
    cout << "\n✓ Room " << roomNo << " booked successfully!\n";
    cout << "  Guest  : " << rooms[index].guestName << "\n";
    cout << "  Days   : " << rooms[index].days << "\n";
    cout << "  Rate   : Rs." << ROOM_RATE << "/night\n";
    cout << "  Total  : Rs." << total << "\n";
}

// ─── Check Out ────────────────────────────────────────────────────────────────
void checkOut() {
    int roomNo;
    cout << "\n--- CHECK OUT ---\n";
    cout << "Enter Room Number to Check Out (1-" << TOTAL_ROOMS << "): ";
    cin  >> roomNo;

    if (roomNo < 1 || roomNo > TOTAL_ROOMS) {
        cout << "Invalid room number!\n";
        return;
    }

    int index = roomNo - 1;

    if (!rooms[index].isBooked) {
        cout << "Room " << roomNo << " is not currently booked.\n";
        return;
    }

    int total = rooms[index].days * ROOM_RATE;

    cout << "\n========== BILL / INVOICE ==========\n";
    cout << "  Room No : " << roomNo              << "\n";
    cout << "  Guest   : " << rooms[index].guestName << "\n";
    cout << "  Days    : " << rooms[index].days    << "\n";
    cout << "  Rate    : Rs." << ROOM_RATE << "/night\n";
    cout << "  Total   : Rs." << total             << "\n";
    cout << "=====================================\n";
    cout << "Thank you for staying with us!\n";

    // Free the room
    rooms[index].guestName = "";
    rooms[index].days      = 0;
    rooms[index].isBooked  = false;

    cout << "✓ Room " << roomNo << " is now available.\n";
}

// ─── Search Guest ─────────────────────────────────────────────────────────────
void searchGuest() {
    string name;
    cout << "\n--- SEARCH GUEST ---\n";
    cout << "Enter Guest Name: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (rooms[i].isBooked && rooms[i].guestName == name) {
            cout << "\nGuest Found!\n";
            cout << "  Room No : " << rooms[i].roomNumber << "\n";
            cout << "  Name    : " << rooms[i].guestName  << "\n";
            cout << "  Days    : " << rooms[i].days        << "\n";
            cout << "  Due     : Rs." << rooms[i].days * ROOM_RATE << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No guest found with the name \"" << name << "\".\n";
    }
}

// ─── Show Available Rooms ─────────────────────────────────────────────────────
void showAvailableRooms() {
    cout << "\n--- AVAILABLE ROOMS ---\n";
    bool anyAvailable = false;
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (!rooms[i].isBooked) {
            cout << "  Room " << rooms[i].roomNumber << " - Available\n";
            anyAvailable = true;
        }
    }
    if (!anyAvailable) {
        cout << "  No rooms available right now.\n";
    }
}

// ─── Main Menu ────────────────────────────────────────────────────────────────
int main() {
    initRooms();

    int choice;

    cout << "\n  Welcome to HOTEL SUNRISE MANAGEMENT SYSTEM\n";
    cout << "  Room Rate: Rs." << ROOM_RATE << " per night\n";
    cout << "  Total Rooms: " << TOTAL_ROOMS << "\n";

    while (true) {
        cout << "\n========================================\n";
        cout << "           MAIN MENU\n";
        cout << "========================================\n";
        cout << "  1. View All Rooms\n";
        cout << "  2. Book a Room\n";
        cout << "  3. Check Out\n";
        cout << "  4. Search Guest\n";
        cout << "  5. Show Available Rooms\n";
        cout << "  6. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin  >> choice;

        switch (choice) {
            case 1:
                displayRooms();
                break;

            case 2:
                bookRoom();
                break;

            case 3:
                checkOut();
                break;

            case 4:
                searchGuest();
                break;

            case 5:
                showAvailableRooms();
                break;

            case 6:
                cout << "\nThank you! Goodbye.\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter 1-6.\n";
        }
    }

    return 0;
}
