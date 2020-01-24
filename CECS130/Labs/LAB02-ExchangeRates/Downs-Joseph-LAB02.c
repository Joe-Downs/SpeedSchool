/*
Joseph Downs
Lab 02
2020.01.24

This program outputs a table showing how much a user-given amount of money would be in other curriencies
*/

#include <stdio.h>

void print_table(float currency_unit);
float exchange_currencies(char given_currency,
			  char desired_currency,
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

  float exchange_currencies(char given_currency,
			    char desired_currency,
			    float amount)
  {
    if (given_currency == "usd")
      {
	switch (desired_currency)
	  {
	  case "eur":
	    return amount * usd_eur;
	    break;
	  case "jpy":
	    return amount * usd_jpy;
	    break;
	  case "krw":
	    return amount * usd_krw;
	    break;
	  case "mxn":
	    return amount * usd_mxn;
	    break;
	  case "nok":
	    return amount * usd_nok;
	    break;
	  case "npr":
	    return amount * usd_npr;
	    break;
	  }
      }
  }  
}
