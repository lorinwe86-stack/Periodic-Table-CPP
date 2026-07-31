#include <iostream>
#include <string>

using namespace std;

int main() {
    string elements[50] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
    int currentElementsCount = 10;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "1. Display all elements\n";
        cout << "2. Add a new element\n";
        cout << "3. Search for an element\n";
        cout << "4. Update an element\n";
        cout << "5. Delete an element\n";
        cout << "6. exit\n";
        cout << "====================================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n--- All Elements ---\n";
                for (int i = 0; i < currentElementsCount; i++) {
                    cout << i + 1 << " - " << elements[i] << "\n";
                }
                break;
            }
            case 2: {
                if (currentElementsCount < 50) {
                    string newElement;
                    cout << "Enter the new element name: ";
                    cin >> newElement;
                    elements[currentElementsCount] = newElement;
                    currentElementsCount++;
                    cout << "Element added successfully!\n";
                } else {
                    cout << "Array is full!\n";
                }
                break;
            }
            case 3: {
                string target;
                cout << "Enter the element to search for: ";
                cin >> target;
                bool isFound = false;

                for (int i = 0; i < currentElementsCount; i++) {
                    if (elements[i] == target) {
                        cout << "Element found at position: " << i + 1 << "\n";
                        isFound = true;
                        break; 
                    }
                }

                if (isFound == false) {
                    cout << "not found\n";
                }
                break;
            }
            case 4: {
                string oldElement, newElement;
                cout << "Enter the element you want to update: ";
                cin >> oldElement;
                bool isFound = false;

                for (int i = 0; i < currentElementsCount; i++) {
                    if (elements[i] == oldElement) {
                        cout << "Enter the new element name: ";
                        cin >> newElement;
                        elements[i] = newElement;
                        cout << "Element updated successfully!\n";
                        isFound = true;
                        break;
                    }
                }

                if (isFound == false) {
                    cout << "Element not found to update.\n";
                }
                break;
            }
            case 5: {
                string deleteElement;
                cout << "Enter the element you want to delete: ";
                cin >> deleteElement;
                bool isFound = false;

                for (int i = 0; i < currentElementsCount; i++) {
                    if (elements[i] == deleteElement) {
                        for (int j = i; j < currentElementsCount - 1; j++) {
                            elements[j] = elements[j + 1];
                        }
                        currentElementsCount--; 
                        cout << "Element deleted successfully!\n";
                        isFound = true;
                        break;
                    }
                }

                if (isFound == false) {
                    cout << "Element not found to delete.\n";
                }
                break;
            }
            case 6: {
                cout << "Exiting the program...\n";
                break;
            }
            default: {
                cout << "Wrong choice. Please try again.\n";
                break;
            }
        }

    } while (choice != 6);

    return 0;
}
