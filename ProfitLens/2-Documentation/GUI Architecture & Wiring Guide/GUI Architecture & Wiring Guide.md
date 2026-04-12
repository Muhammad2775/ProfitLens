# ProfitLens POS: GUI Architecture & Wiring Guide

## Overview

The ProfitLens GUI is built using SFML (Simple and Fast Multimedia Library) and modern C++ concepts. The design intentionally decouples the visual presentation (front-end) from the business logic (back-end), passing data via pointers (`StoreManager*`, `FileManager*`, `Analytics*`). This results in a scalable, maintainable, and portfolio-ready architecture.

---

## 1. Core Architecture & Components

The GUI is driven by `GUI.hpp` and `GUI.cpp`. It uses custom-built structs to manage UI components dynamically without relying on external UI frameworks like ImGui or Qt.

### GUI::Button

A self-contained struct handling interactive elements.

- **State Management**: Tracks `isHovered` and `isClicked` states
- **Color Transitions**: Switches between `normalColor` and `hoverColor` inside `update()`
- **Event Callbacks**: Uses `std::function<void()>` to execute assigned logic

This design ensures buttons are reusable and decoupled from application logic.

---

### GUI::TableCell

A lightweight struct for rendering grid-based data.

- **Dynamic Sizing**: Uses `sf::Vector2f` for flexible layouts
- **Typography Control**: Applies bold styling for headers
- **Auto-Centering**: Aligns text vertically within the cell using local bounds

---

### Main Loop (`initGUI`)

The central loop of the application:

- Runs at 60 FPS (`setFramerateLimit(60)`)
- Handles window events (close, input)
- Tracks mouse movement for hover states
- Detects clicks and triggers button callbacks
- Renders UI components every frame

---

## 2. Built-in Features & Enhancements

### Dynamic Word Wrapping (`wrapText`)

SFML does not support word wrapping natively. This custom function:

- Reads text word-by-word using `std::istringstream`
- Measures rendered width
- Inserts `\n` when exceeding `maxWidth`

Ensures long text (like analytics output) fits within UI boundaries.

---

### Currency Formatting (`formatCurrency`)

Uses `<iomanip>` to format values consistently:

```
120.0 → Rs. 120.00
```

---

### Generic Table Engine (`drawTable`)

A reusable function for rendering tabular data.

Inputs:
- `std::vector<std::vector<std::string>>` (data)
- Column headers
- Column widths

This eliminates duplication across cart and database views.

---

## 3. Wiring Guide: Connecting Business Logic

The GUI currently uses placeholder data. Replace it with actual backend logic as follows.

---

### 3.1 Wiring the Cart (StoreManager)

**Location**: `GUI::drawCartSection`

#### Remove Dummy Data

```cpp
std::vector<std::vector<std::string>> rows(8, { "---", "0", "0.00", "0.00" });
rows[0] = { "Samosa", "2", "120.00", "240.00" };
```

#### Replace with Logic

```cpp
std::vector<std::vector<std::string>> rows = sm->getCartItemsForDisplay();
```

#### Wire Total Value

```cpp
sf::Text total(font, "Total: " + formatCurrency(sm->getCartTotal()), 16);
```

---

### 3.2 Wiring the Database (FileManager)

**Location**: `GUI::drawDatabaseSection`

#### Remove Dummy Data

```cpp
std::vector<std::vector<std::string>> rows(8, { "---", "---", "---", "0", "0.00" });
rows[0] = { "14:32", "1001", "Samosa", "1", "40.00" };
```

#### Replace with Logic

```cpp
std::vector<std::vector<std::string>> rows = fm->getRecentTransactionsForDisplay();
```

---

### 3.3 Wiring the Analytics (Analytics)

**Location**: `GUI::drawAnalyticsSection`

#### Remove Dummy Text

```cpp
std::string str = "Analytics will appear here...";
```

#### Replace with Logic

```cpp
std::string str = an->getBusinessInsights();
```

The `wrapText` function will handle formatting automatically.

---

### 3.4 Wiring Controls (Buttons)

**Location**: `GUI::setupControls`

#### Example: Clear Cart Button

```cpp
buttons.emplace_back(..., [sm]() { sm->clearCart(); });
```

#### Example: Add Item

```cpp
[sm, n = items[i]]() { sm->addItemToCart(n, 1); }
```

#### Example: Run Analytics

```cpp
[an, fm]() { an->runAnalysis(fm->getDatabaseRecords()); }
```

---

## 4. Implementation Guidelines

### Backend Design First

Before modifying GUI logic:
- Define `StoreManager`, `FileManager`, and `Analytics`
- Implement required interface functions

---

### Use String-Based Interfaces

The GUI expects:

```
std::vector<std::vector<std::string>>
```

Ensure backend converts all data into formatted strings.

---

### Handle Edge Cases

- Always return exactly 8 rows for tables
- Fill empty rows with `"---"`
- Prevent out-of-bounds errors in rendering

---

## 5. Summary

This architecture ensures:

- Clean separation between UI and logic
- High modularity and maintainability
- Reusable UI components
- Scalable system design

The GUI is now ready to be fully integrated with backend logic for a complete POS system.

