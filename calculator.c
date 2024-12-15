#include <stdio.h>
#include <math.h>
#include <string.h>

extern double add_numbers(double a, double b);
extern double subtract_numbers(double a, double b);
extern double multiply_numbers(double a, double b);
extern double divide_numbers(double a, double b);
extern double calculate_sine(double x);
extern double calculate_cosine(double x);
extern double calculate_tangent(double x);
extern double calculate_sqrt(double x);
extern double get_pi(void);
extern double get_e(void);
extern double calculate_abs(double x);

//new
extern double calculate_power(double base, double exponent);
extern double calculate_nth_root(double number, double root);
extern double calculate_natural_log(double number);

double parse_input(const char* input) {
    if (strcasecmp(input, "pi") == 0) {
        return get_pi();
    } else if (strcasecmp(input, "e") == 0) {
        return get_e();
    }
    
    double value;
    scanf(input, "%lf", &value);
    return value;
}

int main() {
    int choice;
    char input1[20], input2[20];
    double num1, num2, result;

    while (1) {
        printf("\n--- Scientific Calculator ---\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
        printf("5. Sine\n6. Cosine\n7. Tangent\n8. Square Root\n");
        printf("9. Absolute Value\n10. Power\n11. Nth Root\n12. Natural Log\n");
        printf("0. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        if (choice == 0) {
            printf("Exiting...\n");
            break;
        }

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
                        continue;
                    }
                    result = divide_numbers(num1, num2);
                    break;
            }
        }
        else if (choice >= 5 && choice <= 12) {
            if (choice == 10 || choice == 11) {  // Power or Nth Root
                printf("Enter base (or number for Nth Root): ");
                scanf("%s", input1);
                printf("Enter exponent (or root for Nth Root): ");
                scanf("%s", input2);

                num1 = parse_input(input1);
                num2 = parse_input(input2);

                if (choice == 10)
                    result = calculate_power(num1, num2);
                else if (choice == 11)
                    result = calculate_nth_root(num1, num2);
            } else {
                printf("Enter a number: ");
                scanf("%s", input1);

                num1 = parse_input(input1);

                switch (choice) {
                    case 5: result = calculate_sine(num1); break;
                    case 6: result = calculate_cosine(num1); break;
                    case 7: result = calculate_tangent(num1); break;
                    case 8:
                        if (num1 < 0) {
                            printf("Error: Square root of a negative number is not allowed.\n");
                            continue;
                        }
                        result = calculate_sqrt(num1);
                        break;
                    case 9: result = calculate_abs(num1); break;
                    case 12:
                        if (num1 <= 0) {
                            printf("Error: Natural log is undefined for non-positive values.\n");
                            continue;
                        }
                        result = calculate_natural_log(num1);
                        break;
                }
            }
        } else {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Result: %lf\n", result);
    }

    return 0;
}
