
.text
.global calls
.global redirect_print
.type redirect_print,@function
.global redirect_printall
.type redirect_printall,@function
.global redirect_to
.type redirect_to,@function

.literal .call, calls

redirect_print:
    l32r a7, .call
    l32i a7, a7, 0
    jx a7
    
redirect_printall:
    l32r a7, .call
    l32i a7, a7, 8
    jx a7
    
redirect_to:
    jx a10
    
