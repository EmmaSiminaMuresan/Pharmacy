# Pharmacy Management System

This is a comprehensive pharmacy management system developed using **C**. The system provides both **client** and **employee** functionality. Clients can browse through the pharmacy's stock, make purchases, and request deliveries, while employees can manage the stock, check for out-of-stock items, and add new items to the inventory.

## Features

### For Clients:
- **Add Medicines to Cart**: Customers can add medicines to their cart by searching through available items.
- **Discounts**: The system applies discounts based on whether the current date is an odd or even day.
- **Birthday Special**: If the client’s birthday falls in the current month, they are eligible for a free gift from the pharmacy.
- **Delivery Option**: Customers can choose to have their order delivered, with variable delivery fees depending on the total cost of their order.
  
### For Employees:
- **Stock Management**: Employees can view the current stock, including information on medicines and quantities available.
- **Out-of-Stock Alert**: Employees can easily see which products are out of stock.
- **Add Products**: Employees can restock medicines and update the inventory.
- **Authentication**: Employees are required to input a password to access stock management features.

## Project Structure

- **`main.c`**: Entry point for the program, managing the overall flow of the system for both clients and employees.
- **`cart.c`**: Handles operations related to the client's shopping cart, including adding items, calculating totals, and displaying cart content.
- **`client.c`**: Manages customer data input and processing, including the selection of medicines and personal details.
- **`medicine.c`**: Contains functions for handling the pharmacy's medicine stock, searching for medicines, and adding new stock.
- **`pharmacy.c`**: Provides functionalities for both clients and employees, including stock display, out-of-stock alerts, and employee-specific operations.

## File Descriptions

- **`client.h`**: Defines structures and functions related to the client (customer).
- **`cart.h`**: Contains functions for managing the shopping cart.
- **`medicine.h`**: Defines structures and functions for pharmacy stock operations.
- **`pharmacy.h`**: Includes employee functionalities and inventory management.
- **`pharmacy_stock.txt`**: A text file that holds the current inventory data for the pharmacy.

## How It Works

### For Clients:
1. **Start the System**: When the client starts the system, they are greeted and asked for their personal details.
2. **Medicine Selection**: Clients can either provide a **quick list** of medicines they need or input the medicines from their **prescription**.
3. **Cart Management**: After selecting the medicines, they are added to the client's cart, and the total cost is calculated.
4. **Discounts and Gifts**: The system checks the current date and applies any eligible discounts or gifts based on the client's birthday month.
5. **Delivery Option**: The client can opt for delivery or view the pharmacy's schedule for in-store pickups.

### For Employees:
1. **Login**: Employees need to enter the correct password to access the stock management functions.
2. **Stock Operations**:
   - View current stock.
   - Display out-of-stock products.
   - Add new medicines to the inventory.

## Installation and Setup

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/yourusername/pharmacy-management-system.git
    cd pharmacy-management-system
    ```

2. **Compile the Code**:
    ```bash
    gcc main.c cart.c client.c medicine.c pharmacy.c -o pharmacy_system
    ```

3. **Run the Program**:
    ```bash
    ./pharmacy_system
    ```

## Key Functions

### Client Functions:
- **customer_data()**: Captures the client's personal information.
- **choise()**: Allows the client to choose between quick-list or prescription-based shopping.
- **cart_display()**: Displays the contents of the client's cart.
- **discount()**: Applies a discount based on the current date.
- **birthmonth()**: Offers a free gift if it’s the client’s birthday month.
- **transport()**: Calculates the delivery fee and finalizes the shipping process.

### Employee Functions:
- **stock_display()**: Displays the current stock available in the pharmacy.
- **no_stock()**: Displays a list of items that are out of stock.
- **add_product()**: Allows employees to add products to the stock.
- **employee()**: Authenticates employees and allows access to the stock management menu.

## Customization

- **Delivery Fee**: You can change the delivery fee structure in the `transport()` function inside `cart.c` based on different conditions:
  - Less than 50 lei → 15 lei delivery fee.
  - Between 50 and 100 lei → 7 lei delivery fee.
  - Greater than 100 lei → Free delivery.

## Acknowledgments

- **Developers**: Muresan Emma Simina, Sucala Paula Ilinca.
- **Institution**: Technical University of Cluj-Napoca.

