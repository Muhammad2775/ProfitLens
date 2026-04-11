# ProfitLens

## A Business Point-of-Sale Insight System

ProfitLens is a C++ project built around a simple but practical Point-of-Sale (POS) workflow, with a strong focus on business logic, data handling, and sales insight generation. The system is intentionally designed with a minimal graphical interface so that the core logic remains clear, structured, and easy to evaluate.

## Project Purpose

The purpose of ProfitLens is to simulate a real-world retail transaction system capable of managing sales, calculating totals, storing transactional data, and generating meaningful business insights.

Rather than focusing on UI complexity, the project emphasizes the internal architecture and logic that power a POS system, making it ideal for demonstrating Object-Oriented Programming principles in a practical context.

## Core Features

### Transaction Management

* Add products to a current bill or cart
* Update item quantity
* Remove items from the cart
* Clear the current transaction
* Calculate total sale value
* Calculate total cost and profit
* Complete a sale and store the transaction

### Order Tracking

* Each transaction is assigned a unique **Order ID**
* Each order is recorded with a **timestamp**
* Retrieve a complete summary of any order using its ID

### File Persistence & Data Retrieval

* Load an existing CSV file (acts as the system database)
* Store all transactions in a structured CSV format
* Retrieve specific records using Order ID (testing & validation supported)
* Data persists across program executions

### Analytics Engine

#### Order-Level Analytics

* Retrieve a specific order using Order ID
* Display all items within the order
* Calculate total revenue, cost, and profit

#### Business-Level Analytics

* Calculate total revenue across all orders
* Calculate total cost
* Calculate total profit
* Determine total number of orders

## Data Model

All transactions are stored in a unified CSV format:

```
OrderID, Timestamp, ProductName, Quantity, CostPrice, SellingPrice, Subtotal
```

### Example:

```
1001, 2026-04-10 14:32, Milk, 2, 100, 120, 240
1001, 2026-04-10 14:32, Bread, 1, 60, 80, 80
1002, 2026-04-10 15:10, Eggs, 12, 15, 20, 240
```

## Design Philosophy

ProfitLens is intentionally kept simple on the surface and structured beneath the surface. The objective is not to build a visually complex application, but to design a system where logic, data flow, and architecture are clear and explainable.

The interface remains minimal and functional, while the system focuses on accurate data handling, transaction flow, and meaningful business computations.

## Main Components

### Product

Stores the basic information of an item, including name, cost price, and selling price.

### Cart

Represents the current transaction. It stores selected products, manages quantities, and prepares data for checkout.

### StoreManager

Acts as the central logic controller:

* Manages the cart
* Assigns Order IDs
* Generates timestamps
* Handles transaction completion

### FileManager

Responsible for:

* Loading existing CSV data
* Writing transaction data to CSV
* Retrieving order-specific records

### Analytics

Processes stored data to generate:

* Order-level summaries
* Business-level performance metrics

### UI

Provides a minimal graphical interface using SFML and connects user interaction with system logic.

## Project Structure

The project follows a structured directory layout to separate concerns and improve maintainability.

```
ProfitLens/
├─ Program Files/
│  ├─ Header Files/
│  │  ├─ Internal Headers/
│  │  │  ├─ Product/
│  │  │  │  └─ Product.hpp
│  │  │  ├─ Cart/
│  │  │  │  └─ Cart.hpp
│  │  │  ├─ StoreManager/
│  │  │  │  └─ StoreManager.hpp
│  │  │  ├─ Analytics/
│  │  │  │  └─ Analytics.hpp
│  │  │  ├─ FileManager/
│  │  │  │  └─ FileManager.hpp
│  │  │  └─ GUI/
│  │  │     └─ GUI.hpp
│  │  └─ External Headers/
│  │     └─ SFML/
│  │        ├─ include/
│  │        ├─ lib/
│  │        └─ bin/
│  │
│  ├─ Source Files/
│  │  ├─ Product/
│  │  │  └─ Product.cpp
│  │  ├─ Cart/
│  │  │  └─ Cart.cpp
│  │  ├─ StoreManager/
│  │  │  └─ StoreManager.cpp
│  │  ├─ Analytics/
│  │  │  └─ Analytics.cpp
│  │  ├─ FileManager/
│  │  │  └─ FileManager.cpp
│  │  └─ GUI/
│  │     └─ GUI.cpp
│  │
│  └─ ProfitLens.cpp
│
├─ Documentation/
│  └─ README.md
```

## Planned Module Breakdown

The system is divided into the following functional areas:

* Product Management
* Cart / Transaction Handling
* Sales Calculation
* Profit & Revenue Analysis
* File-based Persistence & Retrieval
* Minimal Graphical Presentation

## Intended Workflow

1. The user selects or enters a product
2. The product is added to the cart
3. Quantities can be modified or items removed
4. The system calculates totals dynamically
5. The user completes the transaction
6. The system assigns an Order ID and timestamp
7. The transaction is saved to CSV
8. The system can load and retrieve specific records for analysis or testing

## Development Notes

* Developed using Visual Studio 2026
* Uses `.cpp` and `.hpp` files
* Business logic is fully separated from the UI layer
* SFML is used for minimal graphical rendering
* External dependencies are isolated within the project structure
* Documentation is maintained in the `Documentation/` directory
* Panels for user facing and admin facing could be added later as it is not yet an intended feature
