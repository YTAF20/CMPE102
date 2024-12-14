#include <stdio.h>
#include <math.h>


extern double add_numbers(double a, double b);
extern double subtract_numbers(double a, double b);
extern double multiply_numbers(double a, double b);
extern double divide_numbers(double a, double b);
extern double calculate_sine(double x);
extern double calculate_cosine(double x);
extern double calculate_tangent(double x);
extern double calculate_sqrt(double x);

int main() {
    int choice;
    double num1, num2, result;

    printf("Scientific Calculator\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("5. Sine\n6. Cosine\n7. Tangent\n8. Square Root\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

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
        scanf("%lf", &num1);

        switch (choice) {
        case 5: result = calculate_sine(num1); break;
        case 6: result = calculate_cosine(num1); break;
        case 7: result = calculate_tangent(num1); break;
        case 8:
            if (num1 < 0) {
                printf("Error: Square root of a negative number is not allowed.\n");
                return 1;
            }
            result = calculate_sqrt(num1);
            break;
        }
    }
    else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Result: %lf\n", result);
    return 0;
}
