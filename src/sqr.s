.text
.globl _raiz
.p2align 2

// d0 = a
// d1 = parada
// d2 = x
// 'd3, d4 , d5, d6' são variaveis auxiliares
_raiz:
    ldr d1, parada

    fmov d6, d0 // aux = a
    fmov d2, d0 // x = a


.L2:
    fmul d5, d2, d2       // d5 = x * x
    fsub d5, d5, d6       // d5 = (x² - a)
    fcmp d5, d1           // Compara (x² - a) com parada
    ble .L3               // Se for maior, continua iterando

    fdiv d3, d6, d2       // d3 = a / x
    fadd d3, d2, d3       // d3 = x + (a / x)
    fmov d4, #2.0         // d4 = 2.0
    fdiv d2, d3, d4       // x = (x + (a / x)) / 2
    fmov d0, d2           // a = x

    b .L2
    
.L3:
    ret

.align 3
parada: 
    .double 0.0000001