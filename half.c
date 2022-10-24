/* You are eating out at a restaurant with a friend and want to split the bill evenly. You may want to anticipate the amount you’ll owe before the bill arrives with tax added. In this problem, you’ll complete a function to calculate the amount each of you owes based on the bill amount, the tax, and the tip.
Ask the user for the bill amount, the tax rate, and the tip rate!
Print the result as a bill.
Pseudocode:
Start
Input bill_amount
Input tax_percent
Input tip_percent
Create "half" function which calculates applies tax_percent, tip_percent to bill amount and divides by two
Compute half of bill_amount, tax_percent, and tip_percent, assign to cost_for_one
Assign variables cost_for_one, total, tax_total, and tip_total
Using printf, print the bill in terms of subtotal, tax, tip, total, and share
End
*/

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, float tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent as a decimal: ");
    float tip_percent = get_float("Tip percent as a decimal: ");
    float cost_for_one = half(bill_amount, tax_percent, tip_percent);
    float total = (2 * half(bill_amount, tax_percent, tip_percent));
    float tax_total = (bill_amount * (tax_percent / 100));
    float tip_total = (bill_amount * (tip_percent / 100));

    printf("\n\tB i l l\n");
    printf("\tSubtotal: \t$%.2f\n", bill_amount);
    printf("\tTax %.2f%%:\t $%.2f\n", tax_percent, tax_total);
    printf("\tTip:   \t\t$%.2f\n", tip_total);
    printf("\t—————————————————\n");
    printf("\tTotal: \t\t$%.2f\n", total);
    printf("\tShare: \t\t$%.2f\n\n", (total/2));

}

// Function
float half(float bill, float tax, float tip)
{
    float result; // Final result to be returned, after calculation of bill
    result = (bill + (tax / 100 * bill) + (tip / 100 * bill)) / 2;

    return result;
}
