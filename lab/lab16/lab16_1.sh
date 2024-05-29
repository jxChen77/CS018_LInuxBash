#!/bin/bash

echo -n "Enter the amount of the loan: "
read loan
echo -n "Enter the interest rate: "
read rate
rate=`echo "$rate/100" | bc -l`
echo -n "Enter the term in years: "
read t
n=12

pay=`echo "( $loan * ( $rate / $n) / (1-(1+$rate/$n)^($n * $t * -1)) ) "| bc -l`
pay=`echo "scale=3; $pay/1.00" | bc -l`
echo "You should pay \$$pay each month for $t years."
