.global add_numbers
.global subtract_numbers
.global multiply_numbers
.global divide_numbers
.global calculate_sine
.global calculate_cosine
.global calculate_tangent
.global calculate_sqrt
.global get_pi
.global get_e
.global calculate_abs
.global calculate_power
.global calculate_nth_root
.global calculate_natural_log
.global main

.data
pi_value: .double 3.14159265359
e_value: .double 2.71828182846

.text

add_numbers:
    fadd d0, d0, d1  
    ret

subtract_numbers:
    fsub d0, d0, d1  
    ret

multiply_numbers:
    fmul d0, d0, d1  
    ret

divide_numbers:
    fdiv d0, d0, d1 
    ret

calculate_sqrt:
    fsqrt d0, d0   
    ret

calculate_sine:
    bl sin
    ret

calculate_cosine:
    bl cos
    ret

calculate_tangent:
    bl tan
    ret

get_pi:
    adrp x8, pi_value
    add x8, x8, :lo12:pi_value
    ldr d0, [x8]
    ret

get_e:
    adrp x8, e_value
    add x8, x8, :lo12:e_value
    ldr d0, [x8]
    ret

calculate_abs:
    fabs d0, d0
    ret

calculate_power:
    bl pow            
    ret

calculate_nth_root:
    fdiv d1, d1, d0   // Compute 1/root
    bl pow            
    ret

calculate_natural_log:
    bl log           
    ret

main:
        printStr "Please input a value in degrees :"
        ldr x0, =theta
        bl get_double
        ldr x1, =theta
        str d0, [x1]
        
        // Compute and print sine
        bl get_sin
        fmov d10, d0          // d10 = sin(theta)
        bl printdouble
        
        printStr "cos: "
        // Restore original input before cosine
        ldr x1, =theta
        ldr d0, [x1]
        bl get_cos
        fmov d10, d0          // d10 = cos(theta)
        bl printdouble
        
        printStr "tan: "
        // Restore original input before tangent
        ldr x1, =theta
        ldr d0, [x1]
        bl get_tan
        fmov d10, d0          // d10 = tan(theta)
        bl printdouble

.data
u:      .fill 1, 8, 0
theta:  .fill 1, 8, 0
g:      .double 9.8
t:      .fill 1, 8, 0
