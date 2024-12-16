#include <stdio.h>
#include <math.h>
#include <string.h>

extern double add_numbers(double a, double b);
extern double subtract_numbers(double a, double b);
extern double multiply_numbers(double a, double b);
extern double divide_numbers(double a, double b);
extern double calculate_sqrt(double x);
extern double get_pi(void);
extern double get_e(void);
extern double calculate_abs(double x);

double parse_input(const char* input) {
    if (strcasecmp(input, "pi") == 0) {
        return get_pi();
    } else if (strcasecmp(input, "e") == 0) {
        return get_e();
    }
    
    double value;
    sscanf(input, "%lf", &value);
    return value;
}

int main() {
    int choice;
    char input1[20], input2[20];
    double num1, num2, result;

    printf("Scientific Calculator\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("5. Square Root\n6. Absolute Value\n7. Sqaured \n8. Cubed\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // Consume newline

    if (choice >= 1 && choice <= 4) {
        printf("Enter two numbers: ");
        scanf("%s %s", input1, input2);
        
        num1 = parse_input(input1);
        num2 = parse_input(input2);

        switch (choice) {
        case 1: result = add_numbers(num1, num2); break;
        case 2: result = subtract_numbers(num1, num2); break;
        case 3: result = multiply_numbers(num1, num2); break;
        case 4:
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = divide_numbers(num1, num2);
            break;
        }
    }
    else if (choice >= 5 && choice <= 8) {
        printf("Enter a number: ");
        scanf("%s", input1);
        
        num1 = parse_input(input1);

        switch (choice) {
        case 6: result = calculate_abs(num1); break;
        case 7: result = calculate_squared(num1); break;
        case 5:
            if (num1 < 0) {
                printf("Error: Square root of a negative number is not allowed.\n");
                return 1;
            }
            result = calculate_sqrt(num1);
            break;
        case 8: result = calculate_cubed(num1); break;
        }
    }
    else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Result: %lf\n", result);
    return 0;
}
