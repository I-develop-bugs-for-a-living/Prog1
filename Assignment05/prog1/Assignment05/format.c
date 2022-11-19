// Real c formating
// int f(int i)
// {
//     printf("called f\n");
//     if (i < 0)
//         return -i;
//     else
//         return 3 * i;
// }

/*  
The function takes an int and if the int is negativ it return the absoulte value and if it is positiv it returns 3 times the value.
*/
int f(int i) { 
    printf("called f\n"); 
    if (i < 0) 
        return -i; 
    else
        return 3 * i; 
}