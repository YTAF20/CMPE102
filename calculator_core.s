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

//new
calculate_power:
    //x0 = base, x1 = exponent
    fmov d0, d0       // Move base to D0
    fmov d1, d1       // Move exponent to D1
    bl pow           
    ret

//new
calculate_nth_root:
    //x0 = number, x1 = root
    fmov d0, d0       // Move number to D0
    fmov d1, d1       // Move root to D1
    frecpe d1, d1     // Compute 1/root
    bl pow            // Call pow(number, 1/root)
    ret

//new
calculate_natural_log:
    //x0 = number
    fmov d0, d0       // Move number to D0
    bl log            
    ret
