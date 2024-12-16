.global add_numbers
.global subtract_numbers
.global multiply_numbers
.global divide_numbers
.global calculate_sqrt
.global get_pi
.global get_e
.global calculate_abs

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
