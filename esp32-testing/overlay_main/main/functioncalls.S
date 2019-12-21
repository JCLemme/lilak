
.text
.global calls
.global redirect_print
.type redirect_print,@function
.global redirect_printall
.type redirect_printall,@function
.global redirect_to
.type redirect_to,@function

.literal .call, calls
.literal .flsh, 0x3f800000

redirect_print:
    l32r a7, .flsh
    #movi a6, 0xdeadbeef
    #s32i a6, a7, 0
    
    l32i a10, a7, 0
    
    l32r a7, .call
    l32i a7, a7, 0
    jx a7
    
redirect_printall:
    l32r a7, .call
    l32i a7, a7, 8
    jx a7
    
redirect_to:
    jx a10
    
