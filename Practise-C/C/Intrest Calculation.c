#define Period 10
#define Principal 5000.00

main()
{
    int year;
    float amount, value, inrate;

    amount = Principal;
    inrate = 0.11;
    year = 0;

    while(year <= Period)
    {
        printf("%2d   %8.2f\n", year, amount);
        value = amount + inrate * amount;
        year = year + 1;
        amount = value;
    }
}
