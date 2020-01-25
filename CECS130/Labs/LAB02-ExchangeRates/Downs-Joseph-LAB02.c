/*
Joseph Downs
Lab 02
2020.01.24

This program outputs a table showing how much a user-given amount of money would be in other curriencies
*/

#include <stdio.h>
#include <string.h>

void print_table(float currency_unit);
float exchange_currencies(char given_currency,
			  char desired_currency,
			  float amount);
float exchange_non_USD(float given_rate,
		       float desired_rate,
		       float amount);

int main()
{
  /*Initialization and definition of exchange rates from 1 USD to each foreign currency
   Current as of 2020-01-23T18:09 UTC
   Source: bloomberg.com*/
  float usd_eur = 0.9050;    //Euro
  float usd_jpy = 109.3800;  //Japanese Yen
  float usd_krw = 1168.7000; //South Korean Won
  float usd_mxn = 18.8159;   //Mexican Peso
  float usd_nok = 9.0051;    //Norwegian Krone
  float usd_npr = 113.9200;  //Nepalese Rupee

  float amount;
  float desired_amount;
  float given_rate;
  float desired_rate;
  scanf("Enter the units of currency to be converted: %f, amount");
  float exchange_currencies(char given_currency,
			    char desired_currency,
			    float amount)
  {
    if (desired_currency == "eur")
      if (given_currency == "usd")
	{
	  return amount * usd_eur;
	}
      else
	{
	  float given_rate = usd_eur;
	}
    if (desired_currency == "jpy")
      if (given_currency == "usd")
	{
	  return amount * usd_jpy;
	}
      else
	{
	  float given_rate = usd_jpy;
	}
    if (desired_currency == "krw")
      if (given_currency == "usd")
	{
	  return amount * usd_krw;
	}
	else
	  {
	    float given_rate = usd_krw;
	  }
    if (desired_currency == "mxn")
      if (given_currency == "usd")
	{
	  return amount * usd_mxn;
	}
      else
	{
	  float given_rate = usd_mxn;
	}
    if (desired_currency == "nok")
      if (given_currency == "usd")
	{
	  return amount * usd_nok;
	}
      else
	{
	  float given_rate = usd_nok;
	}
    if (desired_currency == "npr")
      if (given_currency == "usd")
	{
	  return amount * usd_npr;
	}
      else
	{
	  float given_rate = usd_npr;
	}
    if (desired_currency == "usd")
      if (given_currency == "usd")
	{
	  return amount;
	}
      else
	{
	  printf("Converting *FROM* USD? Something went wrong.\n");
	}
    
        
    if (given_currency == "eur")
      {
	float desired_rate = usd_eur;
      }
    if (given_currency == "jpy")
      {
	float desired_rate = usd_jpy;
      }
    if (given_currency == "krw")
      {
	float desired_rate = usd_krw;
      }
    if (given_currency == "mxn")
      {
	float desired_rate = usd_mxn;
      }
    if (given_currency == "nok")
      {
	float desired_rate = usd_nok;
      }
    if (given_currency == "npr")
      {
	float desired_rate = usd_npr;
      }
      
    float usd_amount = amount / given_rate;
    float desired_amount = usd_amount * desired_rate;
    return desired_amount;    
  }

  char currencies[7][4] = {"eur","jpy","krw","mxn","nok","npr","usd"};
  char column_one[7][4] = {"EUR","JPY","KRW","MXN","NOK","NPR","USD"};
  /* char row_two[] = {"EUR", "", "", "", "", "", "", ""};
  char row_three[] = {"JPY", "", "", "", "", "", "", ""};
  char row_four[] = {"KRW", "", "", "", "", "", "", ""};
  char row_five[] = {"MXN", "", "", "", "", "", "", ""};
  char row_six[] = {"NOK", "", "", "", "", "", "", ""};
  char row_seven[] = {"NPR", "", "", "", "", "", "", ""};
  char row_eight[] = {"USD", "", "", "", "", "", "", ""};*/

  int n;
  int i;
  float max = 0;
  int max_index = 0;
  int max_row = 0;
  for (n = 0; n <= 7; ++n)
    {
      char given_currency = currencies[n];
      float converted_amounts[7] = {0,0,0,0,0,0,0};
      for (i = 0; i <= 7; ++i)
	{
	  char desired_currency = currencies[i];
	  float converted_amount = exchange_currencies(given_currency,
						       desired_currency,
						       amount);
	  printf("10f", converted_amount);
	  /*if (converted_amount > max)
	    {
	      float max = converted_amount;
	      int max_index = i;
	      int max_row = n + 1;
	      }  */
	}   
      /*      char currency = column_one[n];
      printf("%3s", currency);
      for (i = 0; i <= 7; ++i)
	{
	  printf("10.4f", converted_amounts[i]);
	}
      printf("\n");*/
      
    }
}
