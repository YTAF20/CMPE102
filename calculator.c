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
extern double calculate_natural_log(double num);
extern double calculate_nth_root(double base, double root);
extern double calculate_power(double number, double exponent);
extern void main(void);

void printdouble (double a)
{
    printf ("%lf\n", a);
    return;
}

double get_double (double* a)
{   
    scanf (" %lf", a);
    return *a;
}


double get_sin (double a)
{   
    double radians = a * (get_pi() / 180.0);
    printf ("a =  %lf\n", a);
    return (sin(radians));
}

double get_cos (double a)
{   
    double radians = a * (get_pi() / 180.0);
    printf ("a =  %lf\n", a);
    return (cos(radians));
}

double get_tan (double a)
{   
    double radians = a * (get_pi() / 180.0);
    printf ("a =  %lf\n", a);
    return (tan(radians));
}

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
    printf("5. Trig Functions\n6. Square Root\n7. Absolute Value\n8. Nth Root\n9. Exponential\n10. Natural Log\n11. Log with custom base");
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
    else if (choice >= 5 && choice <= 9 || choice == 12) {
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
                return 1;
            }
            result = calculate_sqrt(num1);
            break;
        case 9: result = calculate_abs(num1); break;
        case 12: 
            if (num1 <= 0) {
                printf("Error: Natural logarithm undefined for non-positive numbers.\n");
                return 1;
            }
            result = calculate_natural_log(num1); 
            break;
        }
    }
    else if (choice == 10 || choice == 11) {
        printf("Enter your first number: ");
        scanf("%s", input1);
        num1 = parse_input(input1);
        
        printf("Enter your second number: ");
        scanf("%s", input2);
        num2 = parse_input(input2);
        switch (choice) {
        case 10:
            if (num2 == 0) {
                printf("Error: Nth root with root 0 is undefined.\n");
                return 1;
            }
            result = calculate_nth_root(num1, num2);
            break;
        case 11: result = calculate_power(num1, num2); break;
        }
    }
	else if (choice == 13) {
		printf("Enter your number: ");
		scnaf("%s", input1);
		num1 = parse_input(input1);
		
		if (num1 <= 0) {
			printf("Error: Logarithm is undefined for non-positive numbers.\n");
			return 1;
		}
		
		printf("Enter the logarithm base: ");
		scnaf("%s", input2);
		num2 = parse_input(input2);
		
		if (num2 < 0) {
			printf("Error: Base cannot be a non-positive number.\n");
			return 1;
		}
		
		if (num2 == 0) {
			result = 0;
			break;
		}
		
		double logTemp1, logTemp2;
		logTemp1 = calculate_natural_log(num1);
		logTemp2 = calculate_natural_log(num2);
		
		result = divide_numbers(logTemp1, logTemp2);
		break;
	}
    else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Result: %lf\n", result);
    return 0;
}
