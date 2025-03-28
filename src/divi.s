.text
.globl	_divi                           
.p2align	2

_divi:
    fdiv d0, d0, d1
    ret