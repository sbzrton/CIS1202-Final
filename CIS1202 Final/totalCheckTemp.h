#pragma once
#include "BaseShop.h"
#include <cmath>
//Generic template

template <typename Total>
Total finalPrice(Total subtotal)
{
	Total finalTotal;
	Total netTotal;
	netTotal= subtotal * .060;
	
	finalTotal = subtotal + netTotal;
	return finalTotal;
}

template <typename Tax>
Tax getTax(Tax subtotal) {
	Tax net;
	net = subtotal * 0.060;
	return net;
}

