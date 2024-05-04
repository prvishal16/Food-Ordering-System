#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Structure to represent a food item 
struct FoodItem { 
char name[50]; 
float price; 
}; 
// Structure to represent a hotel with a menu 
struct Hotel { 
char name[50]; 
struct FoodItem menu[50]; 
int menuSize; 
}; 
// Structure to represent a user 
struct User { 
char username[50]; 
char password[50]; 
struct FoodItem cart[50]; 
int cartSize; 
Page | 6 
}; 
// Function to display the menu for a given hotel 
void displayMenu(struct Hotel* hotel) { 
printf("Menu for %s:\n", hotel->name); 
for (int i = 0; i < hotel->menuSize; i++) { 
printf("%s ($%.2f)\n", hotel->menu[i].name, hotel->menu[i].price); 
} 
} 
// Function to search for a food item in the menu 
struct FoodItem* searchFood(struct Hotel* hotel, char itemName[50]) { 
for (int i = 0; i < hotel->menuSize; i++) { 
if (strcmp(hotel->menu[i].name, itemName) == 0) { 
return &hotel->menu[i]; 
} 
} 
return NULL; 
} 
// Function to add an item to the user's cart 
void addItemToCart(struct User* user, struct FoodItem* item) { 
strcpy(user->cart[user->cartSize].name, item->name); 
user->cart[user->cartSize].price = item->price; 
user->cartSize++; 
Page | 7 
} 
// Function to display the user's cart 
void displayCart(struct User user) { 
printf("Cart Contents:\n"); 
for (int i = 0; i < user.cartSize; i++) { 
printf("%s ($%.2f)\n", user.cart[i].name, user.cart[i].price); 
} 
float totalCost = 0; 
for (int i = 0; i < user.cartSize; i++) { 
totalCost += user.cart[i].price; 
} 
printf("Total Cost: $%.2f\n", totalCost); 
} 
int main() { 
// Sample data 
struct Hotel hotelA = {"Hotel A", {{"Burger", 5.00}, {"Pizza", 8.00}}, 2}; 
struct User user; 
// Menu-driven program 
int choice; 
do { 
printf("Menu:\n"); 
printf("1. Login\n"); 
Page | 8 
printf("2. Signup\n"); 
printf("3. Search for Food\n"); 
printf("4. Search for Hotels\n"); 
printf("5. Add Item to Cart\n"); 
printf("6. Display Cart\n"); 
printf("7. Order\n"); 
printf("8. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter your username: "); 
scanf("%s", user.username); 
printf("Enter your password: "); 
scanf("%s", user.password); 
printf("Login successful!\n"); 
break; 
case 2: 
printf("Enter desired username: "); 
scanf("%s", user.username); 
printf("Enter password: "); 
scanf("%s", user.password); 
printf("Signup successful!\n"); 
Page | 9 
break; 
case 3: 
printf("Enter the food item you want to search: "); 
char searchFoodName[50]; 
scanf(" %49[^\n]", searchFoodName); 
struct FoodItem* foundFood = searchFood(&hotelA, searchFoodName); 
if (foundFood != NULL) { 
printf("Food found at %s: %s ($%.2f)\n", hotelA.name, foundFood->name, 
foundFood->price); 
} else { 
printf("Food not found.\n"); 
} 
break; 
case 4: 
printf("Enter the hotel name to view the menu: "); 
char hotelName[50]; 
scanf(" %49[^\n]", hotelName); 
if (strcmp(hotelName, hotelA.name) == 0) { 
displayMenu(&hotelA); 
} else { 
printf("Hotel not found.\n"); 
} 
break; 
Page | 10 
case 5: 
printf("Enter the food item you want to add to the cart: "); 
char addItemName[50]; 
scanf(" %49[^\n]", addItemName); 
struct FoodItem* itemToAdd = searchFood(&hotelA, addItemName); 
if (itemToAdd != NULL) { 
addItemToCart(&user, itemToAdd); 
printf("%s added to the cart.\n", itemToAdd->name); 
} else { 
printf("Item not found in the menu.\n"); 
} 
break; 
case 6: 
displayCart(user); 
break; 
case 7: 
displayCart(user); 
printf("Thank you for placing your order!\n"); 
// Reset the cart after placing the order 
user.cartSize = 0; 
break; 
Page | 11 
case 8: 
printf("Exiting...\n"); 
break; 
default: 
printf("Invalid choice. Please enter a valid option.\n"); 
break; 
} 
} while (choice != 8); 
return 0; 
}