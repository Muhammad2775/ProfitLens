# ProfitLens

ProfitLens is a C++ project built around a simple but practical Point-of-Sale workflow with a strong focus on business logic, data handling, and basic sales insight generation. The project is intentionally designed to keep the user interface minimal so that the core logic remains clear & manageable.

## Project Purpose
The purpose of ProfitLens is to simulate a small business sales system that can manage items in a bill, calculate totals, complete transactions, and preserve transaction data for later use. Instead of spending effort on a complex interface, the project emphasizes the internal logic that powers a real point-of-sale system.

This makes the project suitable for demonstrating core OOP concepts while still reflecting a realistic business problem.

## Core Features
- Add products to a current bill or cart
- Update item quantity
- Remove items from the bill
- Clear the current transaction
- Calculate total sale value
- Calculate total cost and profit
- Complete a sale and store the transaction
- Save and load records through file handling
- Present a minimal SFML-based GUI Interface

## Design Philosophy
ProfitLens is intentionally kept simple on the surface and structured beneath the surface. The goal is not to build a visually heavy application, but to build a clean and explainable system where the logic is easy to follow.

The interface is expected to remain basic and functional. The main value of the project comes from how the data is handled, how the transaction flow is managed, and how the system computes meaningful business results from simple inputs.

<!-- Commented out for now may change later
## OOP Concepts Used
- **Encapsulation**: each class keeps its own data and exposes only the required operations
- **Abstraction**: the UI interacts with high-level operations instead of internal details
- **Composition**: larger parts of the system are built by combining smaller classes
- **Inheritance**: can be applied where product categorization is needed
- **Modularity**: each major responsibility is kept in its own module
-->

## Main Components
### Product
Stores the basic information of an item, such as its identity, name, cost, and selling price.

### SaleItem
Represents one entry in the current bill and stores the selected product along with its quantity.

### StoreManager
Acts as the central logic hub of the system. It manages the current cart, applies changes to items, and handles the overall sales flow.

### Analytics
Calculates business-related values such as revenue, total cost, and profit.

### FileManager
Handles saving and loading of sales data so that records can persist between sessions.

### UI
Provides the minimal graphical layer for user interaction and connects the interface with the business logic.

## Project Structure
The project is organized into a clear folder hierarchy to separate source code, headers, and documentation.

### Main Project Folder
- **ProfitLens**: Root folder of the project

### Program Files
Contains all source code used by the application.

### Header Files
Split into two categories:
- **Internal Headers**: project-created headers used for the application’s own classes and logic
- **External Headers**: headers for SFML and any other external APIs used by the project

### Source Files
Contains the implementation files for the project modules, arranged into separate folders according to their purpose.

### Documentation
Contains the project documentation, including this README and any other supporting documents created during development.

## Project Structure
    ProfitLens/
    ├─ Program Files/
    │  ├─ Header Files/
    │  │  ├─ Internal Headers/
    │  │  │  ├─ Product/
    │  │  │  │  └─ Product.hpp
    │  │  │  ├─ Cart/
    │  │  │  │  └─ SaleItem.hpp
    │  │  │  ├─ StoreManager/
    │  │  │  │  └─ StoreManager.hpp
    │  │  │  ├─ Analytics/
    │  │  │  │  └─ Analytics.hpp
    │  │  │  ├─ FileManager/
    │  │  │  │  └─ FileManager.hpp
    │  │  │  └─ GUI/
    │  │  │     └─ GUI.hpp
    │  │  └─ External Headers/
    │  │     └─ (SFML and other dependencies)
    │  ├─ Source Files/
    │  │  ├─ Product/
    │  │  │  └─ Product.cpp
    │  │  ├─ Cart/
    │  │  │  └─ SaleItem.cpp
    │  │  ├─ StoreManager/
    │  │  │  └─ StoreManager.cpp
    │  │  ├─ Analytics/
    │  │  │  └─ Analytics.cpp
    │  │  ├─ FileManager/
    │  │  │  └─ FileManager.cpp
    │  │  └─ GUI/
    │  │     └─ GUI.cpp
    │  └─ ProfitLens.cpp
    └─ Documentation/
       └─ ReadMe.md

## Planned Module Breakdown
The project is organized around the following functional areas:
- Product Management
- Cart/Transaction Handling
- Sales Calculation
- Profit & Revenue Analysis
- File-based Persistence
- Minimal Graphical Presentation

## Intended Workflow
1. The user enters or selects a product.
2. The product is added to the current bill.
3. Quantity and item details can be adjusted if needed.
4. The system calculates the bill total and related business values.
5. When the sale is completed, the transaction is stored.
6. The stored data can later be used for review and analysis.

## Development Notes
- The project will be developed in Visual Studio 2026
- The codebase will use `.cpp` and `.hpp` files
- Business logic will be kept separate from the graphical layer
- The README and other documentation will remain inside the Documentation folder
- SFML-related external headers will be managed separately in the external dependency area

<!-- 
## Expected Outcome
By the end of the project, ProfitLens should function as a clean and understandable point-of-sale system that can:
- Manage transaction items
- Calculate totals and profit
- Preserve sales records
- Demonstrate Solid Object-Oriented Design
-->
