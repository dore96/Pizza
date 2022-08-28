#define _CRT_SECURE_NO_WARNINGS
#define PIZZA_40X50_PRICE (70/2000.0)            //pizza price as defult.
#define OLIVES_40X50_PRICE (10/2000.0)           //olive price as defult.
#define MUSHROOMS_40X50_PRICE (12/2000.0)        //mushrooms price as defult.
#define TOMATO_40X50_PRICE (9/2000.0)            //tomatos price as defult.
#define PINEAPPLE_40X50_PRICE (14/2000.0)        //pineapple price as defult.
#define DOUGH_40X50_PRICE (1/2000.0)             //dough price as defult.
#define VAT 1.17                                 //v.a.t price as defult in israel.
#define MAX_TOPPING 1.0                          //the max amount of topping on a pizza (1).
#define NO_TOPPING 0                             //the number of choice for the user to choose none pizza topping.
#define WHOLE_PIZZA_TOPPING 1                    //the number of choice for the user to choose whole pizza topping. 
#define HALF_PIZZA_TOPPING 2                     //the number of choice for the user to choose half pizza topping.
#define QUARTER_PIZZA_TOPPING 3                  //the number of choice for the user to choose quarter pizza topping.
#define NONE 0.0                                 //double type none - no topping - for later multiply. uses to extra calculations.
#define HALF 0.5                                 //double type none - half pizza topping - for later multiply.
#define QUARTER 0.25                             //double type none - quarter pizza topping - for later multiply.
#define TEN_COIN 10                              //a change coin , of ten , for mathematic culculation.
#define FIVE_COIN 5                              //a change coin , of five , for mathematic culculation.
#define TWO_COIN 2                               //a change coin , of two , for mathematic culculation.
#define ONE_COIN 1                               //a change coin , of one , for mathematic culculation.
#define NO_CHAR ' '								 //initiation char to the pizza topping.
#define HALF_PIZZA_TOPPING 2                     //half topping pizza left.
#define QUARTER_PIZZA_LEFT 1                     //quarter topping pizza left.
#define THREE_QUARTER_PIZZA 3                    //three quarter topping pizza left.
#define WHOLE_PIZZA_LEFT 4                       //whole topping pizza left.
#define MUSHROOM_CHAR 'M'                        //the mushroom char to the pizza topping.
#define OLIVE_CHAR 'O'                           //the olive char to the pizza topping.
#define PINEAPPLE_CHAR 'P'                       //the pineapple char to the pizza topping.
#define TOMATO_CHAR 'T'                          //the tomato char to the pizza topping.
#define REGULAR_DOUGH 'r'                        //regular dough char.
#define VEGAN_DOUGH 'v'                          //vagan dough char.
#define WHOLE_WHEAT_DOUGH 'w'                    //whole wheat dough char.
#define GLUTAN_FREE_DOUGH 'f'                    //glutan free dough char.
#define INITIATE_ZERO 0							 //zero initiation for sums and other variables.
#define INITIATE_ONE 1							 //one initiation for variables.
#define LAST_DIG 10					     		 //the 10s menipulation on a long int. 
#define TWO 2									 //number two check for even numbers.
#define INT_NONE 0                               //double type none - no topping - for later multiply. uses to extra calculations.
#define MAX_ID_LEANGTH 9                         //the maximum digit for an ID.
#include <stdio.h> 
#include <stdbool.h>
const int MIN_NUM_OF_PIZZAS = 1;                 //minimum number of pizza to order (1)
const int MIN_PIZZA_LENGTH_AND_WIDTH = 10;       //minimum pizza length and width (10 cm)
const int MAX_PIZZA_LENGTH = 40;                 //maximum pizza length (40 cm)
const int MAX_PIZZA_WIDTH = 80;                  //maximum pizza width (80 cm)
const int YES_TO_DELIVER = 1;                    //the costumer picked to deliver (1)
const int NOT_TO_DELIVER = 0;                    //the costumer picked not to deliver (0)
const int DELIVERY_MULTI_15 = 15;                //a multiply number to determin the price of delivery.
const int REGULAR_DOUGH_PRICE = 0;               //the price of regular dough (extra)
const int VEGAN_DOUGH_PRICE = 5;                 //the price of vegan dough (extra)
const int WHOLE_WHEAT_DOUGH_PRICE = 3;           //the price of whole wheat dough (extra)
const int GLUTAN_FREE_DOUGH_PRICE = 4;           //the price of glutan free dough (extra)

/*The program purpose is to get a multy or singel pizza order.
to print each pizza details and paint the pizza looks.
output a full order receipt with details.
and deal with the finance payment*/

typedef struct pizza  //orgenized whole pizza details
{
	char quarter1, quarter2, quarter3, quarter4;											  //the chars for the pizza topping quarter draw.
	double topping_sum;																		  //the sum of all topping.
	double current_topping_price, current_top_size, current_dough_price, current_pizza_price; //pizza price, topping price, topping size, dough price.
	int current_choice, pizza_length, pizza_width, pizza_size;                                //pizza sizes , topping size choice.
	char dough_type;                                                                          //dough type choice.
}pizza; 

int greeting_and_ID();															      //the function purpose is to print greeting welcome, returns the ID from user.
int id_check(int id);                                                                 //the function purpose is to check the ID validation. returns the ID.
int check_id_length(int id);														  //the function purpose is to check the ID leangth.returns the ID.
void menu_print();																	  //the function purpose is to print the main menu to user.
int check_number_of_pizzas(int num_of_pizzas);										  //the function purpose is to check number of pizza validation. returns number of pizza.
int check_pizza_width_validation(int pizza_width);									  //the function purpose is to check pizza width validation.returns pizza width.
int check_pizza_length_validation(int pizza_length);								  //the function purpose is to check pizza length validation.returns pizza length.
void print_dough_menu();															  //the function purpose is to pring dough menu.
int dough_type_to_price(char dough_char);                                             //the function purpose is to convert dough char to priceand returns it.
char check_dough_char(char dough_char);												  //the function purpose is to check dough char validation.and returns the char.
double topping_size_on_pizza(int amount_topping);									  //the function purpose is to checks validation , place the amount of topping to the real size, and returns the size.
void print_olives_topping_menu();													  //the function purpose is to print the olive menu.
void print_mushrooms_topping_menu();												  //the function purpose is to print the mushrooms menu.
void print_tomato_topping_menu();													  //the function purpose is to print the tomato menu.
void print_pineapple_topping_menu();												  //the function purpose is to print the pineapple menu.
pizza check_topping_max_execciding(double topping1, double topping2, pizza p);		  //the function purpose is to checks topping is not exeeding max and returns the whole pizza back.
double calculate_topping_price(double topping_size, int pizza_size, double const_price);//the function purpose is to calculate the topping price and returns it.
bool topping_is_not_max(double topping1);											  //the function purpose is to check if there is steel room for more toppings. returns T\F.
int delivery_or_not(int delivery_input);											  //the function purpose is to check if the user would like a delivery, returns the chpice by number.
void pizza_draw(pizza p);															  //the function purpose is to draw the pizze.
char get_quarter_char(pizza p, int i, int j);										  //the function purpose is to place topping to their place (size wize). returns the char
pizza update_quarters(pizza p, int quarters_num, int avail_quarters, char ch);	      //the function purpose is to updates the topping quarters, returns the pizza struct.
int number_of_quarters(int size_type);												  //the function purpose is to check how many quarters left to "fill",  returns the number of them.
int pay_all(int payment, int bill);													  //the function purpose is to checks the user pays all the bill back.
void coin_print(int change);														  //the function purpose is to print the coins to return to the user, as little coins as possible.
void print_whole_order(int delivery, int id, int number_of_pizzas, double total_price, int total_price_with_vat);//the function purpose is to print the whole pizzas order.
void print_single_pizza_order(int i, pizza p);										  //the function purpose is to print a single pizza order.
int sum_current_number(int current_num);											  //the function purpose is to sum of digits of the the number multy by 1\2, and returns it.
pizza get_topping(pizza p, int number_quarter_available, double const_top_price, char current_char);//the function purpose is to get a topping , check validations and updates prices, return pizza struct.
pizza initialize_values(pizza p);													  //the function purpose is to initialize basic values every loop start.


void main()
{
	int id, delivery, total_price_with_vat, number_of_pizzas, i, change;//arguments for details
	int payment;                                                        //money for bill 
	double total_price = NONE;                                          // sum of all the pizzas initiate 0.0.
	int number_of_quarers, number_quarter_available;

	id = greeting_and_ID();												//print greeting welcome, returns the ID from user.
	id = id_check(id);													//check the ID validation. returns a good ID.

	menu_print();														
	printf("How many pizzas would you like to order?");                 //get a number of pizzas from costumer
	scanf("%d", &number_of_pizzas);

	number_of_pizzas = check_number_of_pizzas(number_of_pizzas);		//check number of pizza validation. returns number of pizza.

	for (i = INITIATE_ONE; i <= number_of_pizzas; i++)                  // a loop thats gets a singel pizza oredr at a time.
	{
		pizza p = { NO_CHAR,NO_CHAR,NO_CHAR,NO_CHAR, NONE,NONE };						 //initialize basic values every loop start.
                                  
		number_quarter_available = WHOLE_PIZZA_LEFT;

		printf("\n*************************************************\n"
			"Pizza #%d:\n\n", i);

		printf("Please enter your pizza's length (cm): ");				//get a pizza length from user
		scanf("%d", &p.pizza_length);
		p.pizza_length = check_pizza_length_validation(p.pizza_length); //check pizza leangth validation.returns pizza leangth.

		printf("Please enter your pizza's width (cm): ");			    //get a pizza width from user
		scanf("%d", &p.pizza_width);
		p.pizza_width = check_pizza_width_validation(p.pizza_width);	//check pizza width validation.returns pizza width.

		p.pizza_size = p.pizza_length * p.pizza_width;

		print_dough_menu();                                                
		scanf(" %c", &p.dough_type);
		p.dough_type = check_dough_char(p.dough_type);                  //check dough char validation.and returns a good char.
		p.current_dough_price = dough_type_to_price(p.dough_type);		//convert dough char to price and returns it.

		p.current_dough_price = DOUGH_40X50_PRICE * p.pizza_size * p.current_dough_price; //CALCULATION of dough price

		print_olives_topping_menu();
		scanf("%d", &p.current_choice);

		p = get_topping(p, number_quarter_available, OLIVES_40X50_PRICE, OLIVE_CHAR);     //get a topping , check validations and updates prices, return pizza struct.
		number_of_quarers = number_of_quarters(p.current_choice);                         //update how many topping quarter left after cheking validation.
		number_quarter_available -= number_of_quarers;


		if (topping_is_not_max(p.topping_sum))                                            //checks if ther is space for more topping to get.
		{ 
			print_mushrooms_topping_menu();
			scanf("%d", &p.current_choice);

			p = get_topping(p, number_quarter_available, MUSHROOMS_40X50_PRICE, MUSHROOM_CHAR); //get a topping , check validations and updates prices, return pizza struct.
			number_of_quarers = number_of_quarters(p.current_choice);							//update how many topping quarter left after cheking validation.
			number_quarter_available -= number_of_quarers;

			if (topping_is_not_max(p.topping_sum))
			{
				print_tomato_topping_menu();
				scanf("%d", &p.current_choice);
				p = get_topping(p, number_quarter_available, TOMATO_40X50_PRICE, TOMATO_CHAR); //get a topping , check validations and updates prices, return pizza struct.
				number_of_quarers = number_of_quarters(p.current_choice);					   //update how many topping quarter left after cheking validation.
				number_quarter_available -= number_of_quarers;

				if (topping_is_not_max(p.topping_sum))
				{
					print_pineapple_topping_menu();
					scanf("%d", &p.current_choice);
					p = get_topping(p, number_quarter_available, PINEAPPLE_40X50_PRICE, PINEAPPLE_CHAR); //get a topping , check validations and updates prices, return pizza struct.
					number_of_quarers = number_of_quarters(p.current_choice);							 //update how many topping quarter left after cheking validation.
					number_quarter_available -= number_of_quarers;
				}
			}
		}
		p.current_pizza_price += (PIZZA_40X50_PRICE * p.pizza_size) + p.current_dough_price;      //whole pizza calculation.

		print_single_pizza_order(i, p);															  //prints a single pizza order.
		pizza_draw(p);																			  //prints a single pizza draw.

		total_price += p.current_pizza_price;												      // sums all the pizzas
	}

	printf("\n*************************************************\n"
		"Do you want delivery for the price of 15 NIS? Enter 1 for delivery or 0 for pick-up: "); //ger a delivery request
	scanf("%d", &delivery);

	delivery = delivery_or_not(delivery) * DELIVERY_MULTI_15;									  //getting the user input for delivery or not, and returns it as price.

	total_price += delivery;
	total_price_with_vat = total_price * VAT;													  //a double outcome for a int type to round down.

	print_whole_order(delivery, id, number_of_pizzas, total_price, total_price_with_vat);         //prints a whole order.

	printf("Please enter your payment: ");													      //gets a payment amount from the client
	scanf("%d", &payment);

	change = pay_all(payment, total_price_with_vat);											  //checks if user pays all the bill back, and returns the change.

	coin_print(change);																			  //print the coins to return to the user, as little coins as possible.

}										  

pizza initialize_values(pizza p)  //the function purpose is to initialize basic values every loop start.
{
	p.quarter1 = NO_CHAR;
	p.quarter2 = NO_CHAR;
	p.quarter3 = NO_CHAR;
	p.quarter4 = NO_CHAR;
	p.topping_sum = NONE;
	p.current_pizza_price = NONE;
	return p;
}                                             

int greeting_and_ID()  //the function purpose is to print greeting welcome, returns the ID from user.
{
	int id;
	printf(" Welcome to MTA-Pizza!\n\n"  //greeting output and asking for ID.
		"*****\n"
		" ***\n"
		"  *\n\n"
		"Please enter your ID number:\n");
	scanf("%d", &id);
	return id;
}

int id_check(int id)  //the function purpose is to check the ID validation. returns the ID.
{
	int i = INITIATE_ZERO, sum = INITIATE_ZERO, current_num, securi_num = INITIATE_ZERO, shuold_be_securi = INITIATE_ONE, first = INITIATE_ONE, try_id;
	
	id = check_id_length(id);                                              //check the ID leangth.returns a good leangthed ID.
	while (shuold_be_securi != securi_num)								   //a loop that check the ID security number , wont stop until gets a valid ID.
	{
		if (first != INITIATE_ONE)										   //a loop that request a new ID, if it isnt the first loop round.   
		{
			printf("Invalid check digit! Try again.\n"
				"Please enter your ID number:\n");
			scanf("%d", &id);
			id = check_id_length(id);
		}
		try_id = id;
		securi_num = (id % LAST_DIG);
		sum = INITIATE_ZERO;

		for (i = INITIATE_ZERO; try_id != INITIATE_ZERO; i++)              //a loop that sums all the ID digits sum in an requaered order. 9 iterations.
		{
			try_id /= LAST_DIG;
			current_num = (try_id % LAST_DIG);

			if ((i % TWO) == INITIATE_ZERO)
				sum += sum_current_number(current_num * TWO);
			else
				sum += sum_current_number(current_num);
		}
		if ((sum % LAST_DIG) != INITIATE_ZERO)                             //check if the right digit is the security one.
			shuold_be_securi = (LAST_DIG - (sum % LAST_DIG));
		else
			shuold_be_securi = (sum % LAST_DIG);
		first = INITIATE_ZERO;
	}
	return id;
}

int check_id_length(int id)  //the function purpose is to check the ID leangth.returns the ID.
{
	int i, try_id = id;
	while (id <= INT_NONE)
	{
	    printf("Invalid ID number! Try again.\n"
			"Please enter your ID number:\n");
		scanf("%d", &id);
	}
	while (try_id > INT_NONE)                                 
	{
		for (i = INITIATE_ONE; i <= MAX_ID_LEANGTH; i++)         //checks if the id leangth is valid.
		{
			try_id = try_id / LAST_DIG;
			if ((i == MAX_ID_LEANGTH) && (try_id > INT_NONE))
			{
				printf("Invalid ID number! Try again.\n"
					"Please enter your ID number:\n");
				scanf("%d", &id);
				try_id = id;
			}
		}
	}
	return id;
}

void menu_print()  //the function purpose is to print the main menu to user.
{
	printf("\nOur menu:\n"              //menu output 
		"*********\n"
		"Basic pizza: 70.00 NIS for 40x50 size pizza\n\n"
		"Toppings for basic size pizza:\n"
		"Olives: 10 NIS\n"
		"Mushrooms: 12 NIS\n"
		"Tomatoes: 9 NIS\n"
		"Pineapple: 14 NIS\n\n"
		"Dough type for basic size pizza:\n"
		"Regular: 0 NIS\n"
		"Vegan: 5 NIS\n"
		"Whole wheat: 3 NIS\n"
		"Gluten free: 4 NIS\n\n");
}

int check_number_of_pizzas(int num_of_pizzas)  //the function purpose is to check number of pizza validation. returns number of pizza.
{
	while (num_of_pizzas < MIN_NUM_OF_PIZZAS)
	{
		printf("Invalid choice! Try again.\n"
		"How many pizzas would you like to order? ");
		scanf("%d", &num_of_pizzas);
	}
	return num_of_pizzas;
}

int check_pizza_width_validation(int pizza_width)  //the function purpose is to check pizza width validation.returns pizza width.
{
	while (pizza_width > MAX_PIZZA_WIDTH || pizza_width < MIN_PIZZA_LENGTH_AND_WIDTH || ((pizza_width % TWO) != INT_NONE))
	{                                                                          //check if pizza width is between 10-80 cm and even number.
		printf("Invalid width! Try again.\n"
		        "Please enter your pizza's width (cm): ");
		scanf("%d", &pizza_width);
	}
	return pizza_width;
}

int check_pizza_length_validation(int pizza_length)  //the function purpose is to check pizza leangth validation.returns pizza leangth.
{
	while ((pizza_length > MAX_PIZZA_LENGTH) || (pizza_length < MIN_PIZZA_LENGTH_AND_WIDTH) || ((pizza_length % TWO) != INT_NONE))
	{                                                                          //check if pizza length is between 10-40 cm and even number. 
		printf("Invalid length! Try again.\n"
		       "Please enter your pizza's length (cm): ");
		scanf("%d", &pizza_length);
	}
	return pizza_length;
}

void print_dough_menu()  //the function purpose is to pring dough menu.
{
	printf("\nPlease enter the pizza's dough type:\n"         //get a dough type
		"r - for regular\n"
		"v - for vegan\n"
		"w - for whole wheat\n"
		"f - for gluten-free\n");
}

int dough_type_to_price(char dough_char)  //the function purpose is to convert dough char to priceand returns it.
{
	int dough_price = REGULAR_DOUGH_PRICE;

	switch (dough_char) //place the right price for the right dough type.
	{
	case REGULAR_DOUGH:
		dough_price = REGULAR_DOUGH_PRICE;
		break;
	case VEGAN_DOUGH:
		dough_price = VEGAN_DOUGH_PRICE;
		break;
	case WHOLE_WHEAT_DOUGH:
		dough_price = WHOLE_WHEAT_DOUGH_PRICE;
		break;
	case GLUTAN_FREE_DOUGH:
		dough_price = GLUTAN_FREE_DOUGH_PRICE;
		break;
	}
	return dough_price;
}

char check_dough_char(char dough_char)  //the function purpose is to check dough char validation.and returns the char.
{
	while ((dough_char != REGULAR_DOUGH) && (dough_char != WHOLE_WHEAT_DOUGH) && (dough_char != GLUTAN_FREE_DOUGH) && (dough_char != VEGAN_DOUGH))
	{
		printf("Invalid choice! Try again.\n");
		print_dough_menu();
		scanf(" %c", &dough_char);
	}
	return dough_char;
}

double topping_size_on_pizza(int amount_topping)  //the function purpose is to checks validation , place the amount of topping to the real size, and returns the size.
{
	double size_topping_on_pizza;
	switch (amount_topping) //place the right size for the right amount of topping , and checks validation.
	{
	case NO_TOPPING:
		size_topping_on_pizza = NONE;
		return size_topping_on_pizza;
		break;
	case WHOLE_PIZZA_TOPPING:
		size_topping_on_pizza = MAX_TOPPING;
		return size_topping_on_pizza;
		break;
	case HALF_PIZZA_TOPPING:
		size_topping_on_pizza = HALF;
		return size_topping_on_pizza;
		break;
	case QUARTER_PIZZA_TOPPING:
		size_topping_on_pizza = QUARTER;
		return size_topping_on_pizza;
		break;
	default:
		printf("Invalid choice! Current topping not added.\n");
		size_topping_on_pizza = NONE;
		return size_topping_on_pizza;
	}
}

void print_olives_topping_menu()  //the function purpose is to print the olive menu.
{
	printf("\nPlease choose the toppings:\n\n" // get an olives topping order 
		"Olives (choose 0-3):\n"
		"0. None\n"
		"1. Whole pizza\n"
		"2. Half pizza\n"
		"3. Quarter pizza\n");
}

void print_mushrooms_topping_menu() //the function purpose is to print the mushrooms menu.
{
	printf("\nMushrooms (choose 0-3):\n"   
		"0. None\n"
		"1. Whole pizza\n"
		"2. Half pizza\n"
		"3. Quarter pizza\n");
}

void print_tomato_topping_menu()  //the function purpose is to print the tomato menu.
{
	printf("\nTomatos (choose 0-3):\n"   
		"0. None\n"
		"1. Whole pizza\n"
		"2. Half pizza\n"
		"3. Quarter pizza\n");
}

void print_pineapple_topping_menu()  //the function purpose is to print the pineapple menu.
{
	printf("\nPineapple (choose 0-3):\n"   
		"0. None\n"
		"1. Whole pizza\n"
		"2. Half pizza\n"
		"3. Quarter pizza\n");
}

pizza check_topping_max_execciding(double topping1, double topping2, pizza p)  //the function purpose is to checks topping is not exeeding max and returns the whole pizza back.
{
	while ((topping1 + topping2) > MAX_TOPPING) //checks if the topping over all cross the whole pizza limit
	{
		printf("You have exceeded the maximum amount of toppings allowed on one pizza! Try again.\n"
			"0. None\n"
			"1. Whole pizza\n"
			"2. Half pizza\n"
			"3. Quarter pizza\n");
		scanf("%lf", &topping2);
		p.current_choice = (int)topping2;
		p.current_top_size = topping_size_on_pizza((int)topping2);
		topping2 = topping_size_on_pizza((int)topping2);
	}
	return p;
}

double calculate_topping_price(double topping_size, int pizza_size, double const_price)  //the function purpose is to calculate the topping price and returns it.
{
	double topping_price;
	topping_price = topping_size * const_price * pizza_size; //topping price calculation
	return topping_price;
}

bool topping_is_not_max(double topping1)  //the function purpose is to check if there is steel room for more toppings. returns T\F.
{
	if (topping1  == MAX_TOPPING)
		return false;
	else
		return true;
}

int delivery_or_not(int delivery_input)  //the function purpose is to check if the user would like a delivery, returns the chpice by number.
{ 
	while ((delivery_input != YES_TO_DELIVER) && (delivery_input != NOT_TO_DELIVER)) //checks valid delivery input
	{
		printf("Invalid choice! Try again.\n"
		       "Do you want delivery for the price of 15 NIS? Enter 1 for delivery or 0 for pick-up:");
		scanf("%d", &delivery_input);
	}
	return delivery_input;
}

int pay_all(int payment, int bill)  //the function purpose is to checks the user pays all the bill back.
{
	while (payment < bill) //if the payment is smaller then the price 
	{
		bill = bill - payment;
		printf("Your remaining balance is: %d\n"
			"Please enter your payment: ", bill);
		scanf("%d", &payment);
	}
	return (payment - bill);
}

void coin_print(int change)  //the function purpose is to print the coins to return to the user, as little coins as possible.
{
	if (change != NONE)
	{
		printf("Your change is %d NIS using:\n", change);

		if ((change / TEN_COIN) > NONE) {                              //place the correct amount of coins to the custumer (the least possible)
			printf("%d coin(s) of ten\n", (change / TEN_COIN));
			change %= TEN_COIN;
		}
		if ((change / FIVE_COIN) > NONE) {
			printf("%d coin(s) of five\n", (change / FIVE_COIN));
			change %= FIVE_COIN;
		}
		if ((change / TWO_COIN) > NONE) {
			printf("%d coin(s) of two\n", (change / TWO_COIN));
			change %= TWO_COIN;
		}
		if ((change / ONE_COIN) > NONE) {
			printf("%d coin(s) of one\n", (change / ONE_COIN));
		}
		printf("Thank you for your order!");
	}
	else
		printf("Thank you for your order!");
}

void print_whole_order(int delivery, int id, int number_of_pizzas, double total_price, int total_price_with_vat)  //the function purpose is to print the whole pizzas order.
{
	if (delivery != NONE)
	{
		printf("\nYour order details:\n" //print the entire order with delivery
			"*******************\n"
			"ID number: %09d\n"
			"Number of pizzas: %d\n"
			"Delivery\n"
			"Total price: %.2lf\n"
			"Total price with tax (rounded down): %d\n\n", id, number_of_pizzas, total_price, total_price_with_vat);
	}
	else
	{
		printf("\nYour order details:\n" //print the entire order without delivery
			"*******************\n"
			"ID number: %09d\n"
			"Number of pizzas: %d\n"
			"Pick-up\n"
			"Total price: %.2lf\n"
			"Total price with tax (rounded down): %d\n\n", id, number_of_pizzas, total_price, total_price_with_vat);
	}
}

void print_single_pizza_order(int i, pizza p) //the function purpose is to print a single pizza order.
{
	printf("\nPizza #%d details:\n" // print a pizza order for a singel pizza
		"*******************\n"
		"Pizza size: %dx%d\n"
		"Pizza price (without tax): %.2lf\n", i, p.pizza_length, p.pizza_width, p.current_pizza_price);
}

void pizza_draw(pizza p)  //the function purpose is to draw the pizze.
{
	int i, j;
	for (i = INITIATE_ONE; i <= p.pizza_length; i++)             //rows char print
	{
		for (j = INITIATE_ONE; j <= p.pizza_width; j++)          //coloms char print
		{
			if ((i == INITIATE_ONE) || (i == p.pizza_length) || (j == INITIATE_ONE) || (j == p.pizza_width))  //dough print
				printf("%c", p.dough_type);
			else
			    printf("%c", get_quarter_char(p, i, j));         //choose a correct topping to print
		}
		printf("\n");
	}
}

char get_quarter_char(pizza p, int i, int j)  //the function purpose is to place topping to their place (size wize). returns the char
{
	char res;
	if (i <= (p.pizza_length) / HALF_PIZZA_TOPPING)                     //a term to print on the upper pizza part
	{
		if (j <= (p.pizza_width) / HALF_PIZZA_TOPPING)                  //a term to print on the right\left side
			res = p.quarter4;
		else
			res = p.quarter1;
	}  
	else                                                                //a term to print on the lower pizza part
	{
		if (j <= (p.pizza_width) / HALF_PIZZA_TOPPING)                  //a term to print on the right\left side
			res = p.quarter3;
		else
			res = p.quarter2;
	}

	return res;
}

pizza update_quarters(pizza p, int quartersNum, int avail_quarters, char ch)  //the function purpose is to updates the topping quarters, returns the pizza struct.
{
	switch (avail_quarters)                             //a switch to determen how many pizza quarters left
	{
	case WHOLE_PIZZA_LEFT:
		switch (quartersNum)                            //a switch to decide in wich quarters to print by choice and avalability.
		{
		case QUARTER_PIZZA_TOPPING:
			p.quarter1 = ch;
			break;
		case HALF_PIZZA_TOPPING:
			p.quarter1 = ch;
			p.quarter2 = ch;
			break;
		case WHOLE_PIZZA_TOPPING:
			p.quarter1 = ch;
			p.quarter2 = ch;
			p.quarter3 = ch;
			p.quarter4 = ch;
			break;
		}
		break;
	case THREE_QUARTER_PIZZA:							//a switch to decide in wich quarters to print by choice and avalability.
		switch (quartersNum)
		{
		case QUARTER_PIZZA_TOPPING:
			p.quarter2 = ch;
			break;
		case HALF_PIZZA_TOPPING:
			p.quarter2 = ch;
			p.quarter3 = ch;
			break;
		}
		break;
	case HALF_PIZZA_TOPPING:
		switch (quartersNum)                             //a switch to decide in wich quarters to print by choice and avalability.
		{
		case QUARTER_PIZZA_TOPPING:
			p.quarter3 = ch;
			break;
		case HALF_PIZZA_TOPPING:
			p.quarter3 = ch;
			p.quarter4 = ch;
			break;
		}
		break;
	case QUARTER_PIZZA_LEFT:
		switch (quartersNum)                            //a switch to decide in wich quarters to print by choice and avalability.
		{
		case QUARTER_PIZZA_TOPPING:
			p.quarter4 = ch;
			break;
		}
		break;
	}
	return p;
}

int number_of_quarters(int size_type)  //the function purpose is to check how many quarters left to "fill",  returns the number availble ones.
{
	int num = NO_TOPPING;
	switch (size_type)
	{
	case NO_TOPPING:
		num = NO_TOPPING;
		break;
	case WHOLE_PIZZA_TOPPING:
		num = WHOLE_PIZZA_LEFT;
		break;
	case HALF_PIZZA_TOPPING:
		num = HALF_PIZZA_TOPPING;
		break;
	case THREE_QUARTER_PIZZA:
		num = QUARTER_PIZZA_LEFT;
		break;
	}
	return num;
}

int sum_current_number(int current_num) //the function purpose is to sum of digits of the the number multy by 1\2, and returns it.
{
	int sum = INITIATE_ZERO;
	while (current_num != INITIATE_ZERO)
	{
		sum += current_num % LAST_DIG;
		current_num /= LAST_DIG;
	}
	return sum;
}

pizza get_topping(pizza p, int number_quarter_available, double const_top_price, char current_char) //the function purpose is to get a topping , check validations and updates prices, return pizza struct.
{
	p.current_top_size = topping_size_on_pizza(p.current_choice);                                            //checks what is the real size topping on pizza by user input. 
	p = check_topping_max_execciding(p.topping_sum, p.current_top_size, p);                                  //checks topping is not exeeding max and returns the updeted whole pizza back.
	p.current_topping_price = calculate_topping_price(p.current_top_size, p.pizza_size, const_top_price);	 //calculate the topping price and returns it.
	p.topping_sum += p.current_top_size;																	 //sums all the topping place on the pizza.
	p.current_pizza_price += p.current_topping_price;														 //sums all the pizza price.
	p = update_quarters(p, p.current_choice, number_quarter_available, current_char);						 //updates the topping quarters, returns the pizza struct.
	return p;
}
