.text
.globl	_power                   
.p2align	2

// d0 = return
// d1 = resultado
// d2 = base
// w0 = expoente
// w1 = exp
// w2 e d3 = auxiliar

_power:
    fmov d2, d0     // d2 = base
    fmov d1, #1.0   // resultado = 1.0
    fmov d3, #1.0   // d3 = 1.0
    mov w1, w0      // exp = expoente
    cmp w1, #0      // compara exp com 0
    blt .L_negativo // se exp for menor que 0, pula para .L_negativo


.L2:
    cmp w1, #0      // compara exp com 0
    beq .L1         // caso seja igual a zero, pula para .L1
    tst w1, 1       // compara o bit menos significativo de w2 com 1 
    bne .L3         // se o bit menos significativo for 1, pula para .L3
    b .L4           // se o bit menos significativo for 0, pula para .L4

.L3:
    fmul d1, d1, d2 // resultado = resultado * base
    b .L4           // pula para .L4

.L4:
    lsr w1, w1, #1  // move os bits de w2 uma vez para a direita
    fmul d2, d2, d2 // base = base * base
    b .L2           // volta para .L2

.L5:
    fdiv d0, d3, d1 // resultado = 1.0 / resultado
    ret

.L1: 
    cmp w0, #0      // compara expoente com zero
    blt .L5         // se expoente for menor que zero, pula para .L5
    fmov d0, d1     // d0 = d1
    ret

.L_negativo:
    neg w1, w0      // exp = -(expoente)
    b .L2           // volta para .L2

