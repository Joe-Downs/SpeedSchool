/*
Joseph Downs
Lab 02
2020.01.24

This program outputs a table showing how much a user-given amount of money would be in other curriencies
*/

#include <stdio.h>

int main()
{
  /*Initialization and definition of exchange rates from 1 USD to each foreign currency
   Current as of 2020-01-23T18:09 UTC
   Source: bloomberg.com*/
  float usd_cad_rate = 1.3143;    /*Canadian Dollars*/
  float usd_eur_rate = 0.9050;    /*Euro*/
  float usd_jpy_rate = 109.3800;  /*Japanese Yen*/
  float usd_mxn_rate = 18.8159;   /*Mexican Peso*/
  float usd_nok_rate = 9.0051;    /*Norwegian Krone*/
  float amount;
  
  printf("Enter the units of currency to be converted: ");
  scanf("%f", &amount);

  /*Variables for each combination of currencies*/
  float cad_cad = amount;
  float cad_eur = (amount / usd_cad_rate) * usd_eur_rate;
  float cad_jpy = (amount / usd_cad_rate) * usd_jpy_rate;
  float cad_mxn = (amount / usd_cad_rate) * usd_mxn_rate;
  float cad_nok = (amount / usd_cad_rate) * usd_nok_rate;
  float cad_usd = (amount / usd_cad_rate);
  float eur_cad = (amount / usd_eur_rate) * usd_cad_rate;
  float eur_eur = amount;
  float eur_jpy = (amount / usd_eur_rate) * usd_jpy_rate;
  float eur_mxn = (amount / usd_eur_rate) * usd_mxn_rate;
  float eur_nok = (amount / usd_eur_rate) * usd_nok_rate;
  float eur_usd = (amount / usd_eur_rate);
  float jpy_cad = (amount / usd_jpy_rate) * usd_cad_rate;
  float jpy_eur = (amount / usd_jpy_rate) * usd_eur_rate;
  float jpy_jpy = amount;
  float jpy_mxn = (amount / usd_jpy_rate) * usd_mxn_rate;
  float jpy_nok = (amount / usd_jpy_rate) * usd_nok_rate;
  float jpy_usd = (amount / usd_jpy_rate);
  float mxn_cad = (amount / usd_mxn_rate) * usd_cad_rate;
  float mxn_eur = (amount / usd_mxn_rate) * usd_eur_rate;
  float mxn_jpy = (amount / usd_mxn_rate) * usd_jpy_rate;
  float mxn_mxn = amount;
  float mxn_nok = (amount / usd_mxn_rate) * usd_nok_rate;
  float mxn_usd = (amount / usd_mxn_rate);
  float nok_cad = (amount / usd_nok_rate) * usd_cad_rate;
  float nok_eur = (amount / usd_nok_rate) * usd_eur_rate;
  float nok_jpy = (amount / usd_nok_rate) * usd_jpy_rate;
  float nok_mxn = (amount / usd_nok_rate) * usd_mxn_rate;
  float nok_nok = amount;
  float nok_usd = (amount / usd_nok_rate);
  float usd_cad = amount * usd_cad_rate;
  float usd_eur = amount * usd_eur_rate;
  float usd_jpy = amount * usd_jpy_rate;
  float usd_mxn = amount * usd_mxn_rate;
  float usd_nok = amount * usd_nok_rate;
  float usd_usd = amount;

  /*Table outputs three decimals of precision*/
  printf("||\t   \t||\tCAD\t||\tEUR\t||\tJPY\t||\tMXN\t||\tNOK\t||\tUSD\t||\n");
  printf("||\tCAD\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||\n", cad_cad, cad_eur, cad_jpy, cad_mxn, cad_nok, cad_usd);
  printf("||\tEUR\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||\n", eur_cad, eur_eur, eur_jpy, eur_mxn, eur_nok, eur_usd);
  printf("||\tJPY\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||\n", jpy_cad, jpy_eur, jpy_jpy, jpy_mxn, jpy_nok, jpy_usd);
  printf("||\tMXN\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||\n", mxn_cad, mxn_eur, mxn_jpy, mxn_mxn, mxn_nok, mxn_usd);
  printf("||\tNOK\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||\n", nok_cad, nok_eur, nok_jpy, nok_mxn, nok_nok, nok_usd);
  printf("||\tUSD\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||    %.3f\t||\n", usd_cad, usd_eur, usd_jpy, usd_mxn, usd_nok, usd_usd);
}
