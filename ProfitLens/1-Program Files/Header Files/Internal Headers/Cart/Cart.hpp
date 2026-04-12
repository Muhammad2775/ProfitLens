#pragma once

#include <vector>
#include <Product/Product.hpp>

class Cart { 
public: 
	std::vector<Product> items; 
	float calculateTotal() { return 0.0f; } 
	
	void clear() {}
};