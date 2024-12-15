.global add_numbers
.global subtract_numbers
.global multiply_numbers
.global divide_numbers
.global calculate_sine
.global calculate_cosine
.global calculate_tangent
.global calculate_sqrt
.global get_pi

.data
pi_value: .double 3.14159265359

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
